/*
*写一个守护进程
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>

#define MAXFILE 65535

volatile sig_atomic_t running = 1;

void sigterm_handler(int arg)
{
    running = 0;
}

int main(){
    pid_t pc;
    int i,fd,len;
    char *buf = "this is a Dameon\n";
    len = sizeof(buf);
    pc = fork();        //第一步：创建新进程，子进程继承了父进程的会话周期

    if (pc < 0)         //进程创建失败
    {
        printf("error fork\n");
        exit(1);
    }
    else if (pc > 0 )   //父进程
    {
        exit(0);        //退出父进程
    }

    setsid();   //第二步：创建一个新的会话，并担任该会话组的组长(从父进程的会话周期中独立出来)
    chdir("/"); //第三步：改变当前目录为根目录，让"/"作为守护进程的当前工作目录
    umask(0);    //第四步：重设文件权限掩码
    for (int i = 0; i < MAXFILE; i++)   //第五步：删除文件描述符
    {
        close(i);
    }

    signal(SIGTERM,sigterm_handler);    //     
}


