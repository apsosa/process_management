#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int fd[2];
    pid_t pidC;
    char buf[10];
    
    pipe(fd);
    pidC = fork();
    switch (pidC)
    {
    case 0:     /* hijo */
        close(fd[0]);
        write(fd[1],"abcde",5);
        close(fd[1]);
        _exit(0);
        break;
    case -1:
    /*TODO: error*/
    default:    /*Padre*/
        close(fd[1]);
        int num = read(fd[0],buf,sizeof(buf));
        printf("Father read %d bytes: %s \n",num,buf);
        close(fd[0]);
        break;
    }
    return 0;
}
