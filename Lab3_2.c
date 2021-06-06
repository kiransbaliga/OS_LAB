#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>

int main()
{
        printf("Using stat() function: size of a text file\n");
        struct stat sfile;
        stat ("sample.txt", &sfile);
        printf("Size of the file: %li\n\n",sfile.st_size);

        printf("Using the opendir() function: opening the folder '/home/ubuntu/coding'\n");
        DIR* folder;
        struct dirent* dir;
        folder=opendir("/home/ubuntu/coding");
        if(folder==NULL){
                printf("Failed to open!");
        }
        else
        {
                printf("Opened Successfully\n\n");

                printf("Using readdir() function: reading files in the dir");
                for(;;)
                {
                        dir=readdir(folder);
                        if(dir==NULL) break;
                        printf("%s\n",dir->d_name);
                }
                printf("Files completed!\n\n");
        }
        printf("Using the close() function: ");
        close(folder);
        printf("Closed Successfully\n");
        return 0;
}