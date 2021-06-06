#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main ()
{
        printf("getpid() function:\n");
        printf("Process ID: %d\n\n",getpid());

        printf("fork() function: creating a child process\n");

        if(fork()!=0)
        {
                printf("{Parent Process Start}\n");
                printf("wait() function:\n");
                wait(NULL);
                printf("{wait() function complete}\n");
                printf("{exec() function: executing 'ls'}\n");
                char *args[]={"ls",NULL};
                execvp(args[0],args);
                exit(0);
                printf("{Exit Function not executed!}");
                printf("{Parent Process End}");
        }else{
                printf("{Child Process Start}\n");
                printf("{Child Process End}\n");
        }

        printf("Exit Function:");
        exit(0);
        printf("Exit not executed!");
        return 0;
}