#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
extern int errno;
int main(){
        char c[100];
int firstFile= open ("sample.txt",O_RDONLY | O_CREAT);
int secondFile=open("empty.txt",O_CREAT|O_WRONLY);//0644
printf("Saving data from sample4.txt to nothing.txt\nContents written:");
int no_chars=0,result=0;
while((no_chars=read(firstFile,c,10)))
{
        result=write(secondFile,c,no_chars);
        c[no_chars]='\0';
        printf("%s",c);
}


return 0;
}