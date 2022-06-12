#include <stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
   // program for one parent two child
   int arr[] = {'v','i','g','n','e','s','h','b'};
   pid_t id;
   id = fork();
   if(id == 0)
   {
       //child 1
       printf("Even index characters...\n");
       for(int i = 0; i < 8; i++)
       {
            if(i % 2 == 0)
            {
                printf("%c ", arr[i]);
            }
        }
       printf("\n");
   }
   else if(id > 0)
   {
       wait(NULL);
       id = fork();
       if(id == 0)
       {
           //child 2
           printf("Odd index characters...\n");
           for(int i = 0; i < 8; i++)
           {
               if(i % 2)
               {
                   printf("%c ", arr[i]);
               }
           }
           printf("\n");
       }
       else if(id > 0)
       {
           //parent
           wait(NULL);
           printf("Parent ID : %d\n", getppid());
       }
   }

    return 0;
}
