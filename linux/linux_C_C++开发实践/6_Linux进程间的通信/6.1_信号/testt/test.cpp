#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main()
{
    pid_t childpid;
    int status;
    int retval;

    childpid = fork();      //创建子进程
    if (childpid == -1)     //判断是否创建失败
    {
        perror("fork()");
        exit(EXIT_FAILURE);
    }
    else if (childpid == 0)
    {
        puts("In child process");
        sleep(100);     //让子进程睡眠，以便查看父进程的行为
        exit(EXIT_SUCCESS);
    }
    else
    {
        if ((waitpid(childpid,&status,WNOHANG)) == 0)       //判断子进程是否已经退出
        {
            retval = kill(childpid,SIGKILL);                //发送SIGKILL给子进程，要求其停止运行
            if (retval)                 //判断是否发生信号
            {
                puts("kill failed.");
                perror("kill");
                waitpid(childpid,&status,0);
            }
            else
            {
                cout << childpid << " " << "killed" << endl;
            }
            
        }
        
    }
    exit(EXIT_SUCCESS);
    
}