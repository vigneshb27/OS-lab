#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    int p1[2], p2[2];
    pipe(p1);
    pipe(p2);
    
    //p2 parent to child pipe
    //p1 child to parent pipe
    if(fork() > 0)
    {
        //parent
        char s[1024];
        
        close(p2[0]);
        char *msg;
        scanf("%[^\n]s", msg);
        write(p2[1], msg, strlen(msg) + 1);
        close(p2[1]);
        close(p1[1]);
        wait(NULL);
        
        read(p1[0], s, 100);
        printf("%s", s);
        close(p2[0]);
    }
    else
    {
        //child
        char buff[1024];
        char b[100];
        close(p1[0]);
        close(p2[1]);
        read(p2[0], buff, 100);
        close(p2[0]);
        int si = strlen(buff);
        int i;
        for( i = 0; i < si; i++)
        {
            if(buff[i] >= 65 && buff[i] <= 90)
            {
                buff[i] = buff[i] + 32;
            }
            else if(buff[i] >= 97 && buff[i] <= 122)
            {
                buff[i] = buff[i] - 32;
            }
        }
        buff[i] = '\0';
        write(p1[1], buff, strlen(buff) + 1);
        close(p1[1]);
        exit(0);
    }

    return 0;
}
