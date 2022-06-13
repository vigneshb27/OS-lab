#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<string.h>

void arms(int n)
{
    printf("Arms\n");
}
void fact(int n)
{
    printf("Fact\n");
}
int main()
{
    int p[2];
    pipe(p);
    if(fork() > 0)
    {
        //parent
        char* num;
        char msg[500];
        for(int i = 0; i < 2; i++)
        {
            scanf("%s", num);
            write(p[1],msg,50);
        }
        wait(NULL);
    }
    else
    {
        //child
        char n[1024];
        for(int i = 0; i < 2; i++)
        {
            read(p[0], n, 50);
            int num = atoi(n);
            if(i == 0) arms(n);
            else fact(n);
        }
        
    }

    return 0;
}
