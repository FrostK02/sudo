exit.c
#include<stdio.h>
#include<stdlib.h>
int main()
{
 printf("Before exit\n");
 exit(0);
 printf("After exit\n");
 return 0;
}
exec.c
#include<stdio.h>
#include<unistd.h>
int main()
{
 char * args[]={"ls","-l",NULL};
 execvp("ls",args);
 perror("exec");
 return 1;
}
close.c
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
 int fd=open("file.txt",O_RDONLY);
 if(fd==-1)
 {
 perror("open");
 return 1;
 }
 close(fd);
 return 0;
}
File: /home/student/Desktop/Anusree/print.c Page 2 of 6
gepid.c
#include<stdio.h>
#include<unistd.h>
int main()
{
 printf("My PID : %d\n",getpid());
 return 0;
}
fork.c
#include<stdio.h>
#include<unistd.h>
int main()
{
 pid_t pid=fork();
 if(pid==0)
 {
 printf("Child process : PID = %d\n",getpid());
 }
 else if(pid>0)
 {
 printf("Parent process : Child PID = %d\n",pid);
 }
 else
 {
 perror("fork");
 }
 return 0;
}
wait.c
include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
 pid_t pid=fork();
 if(pid==0)
 {
 printf("Child process : PID = %d\n",getpid());
 }
 else if(pid>0)
 {
 wait(NULL);
 printf("Parent process : Child process completed\n");
 }
 else
 {
 perror("fork");
 }
 return 0;
}