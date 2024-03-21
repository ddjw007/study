#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <iostream>
#include <fcntl.h>

using namespace std;

void sys_err(const char *str)
{
    perror(str);
    exit(1);
}

int main()
{
    /*
    *父子进程使用管道通信
    */
    // pid_t pid;
    // char buf[1024];
    // int fd[2];
    // char *p = "test for pipe\n";

    // if (pipe(fd) == -1)     //创建管道
    // {
    //     sys_err("pipe");
    // }
    
    // pid = fork();           //创建子进程
    // if (pid < 0)
    // {
    //     sys_err("fork err");
    // }
    // else if (pid ==0 )
    // {
    //     close(fd[1]);       //关闭写描述符
    //     cout << "child process wait to read: \n";
    //     int len = read(fd[0],buf,sizeof(buf));      //等待管道上的数据
    //     write(STDOUT_FILENO,buf,len);
    //     close(fd[0]);
    // }
    // else{
    //     close(fd[0]);       //关闭读描述符
    //     write(fd[1],p,strlen(p));       //向管道写入字符串数据
    //     wait(NULL);
    //     close(fd[1]);
    // }
    // return 0;
////////////////////////////////////////////////////////////////////////////////
    /*
    *read阻塞10秒后读数据
    *代码中，我们让子进程先睡眠10秒，父进程因为没有数据从管道中读出，
    *被阻塞了，直到子进程睡眠结束，向管道中写入数据，父进程才读到数据。
    */
    int fds[2];
    if (pipe(fds) == -1)
    {
        perror("pipe error");
        exit(EXIT_FAILURE);
    }
    pid_t pid;
    pid = fork();
    if (pid == -1)
    {
        perror("fork error");
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        close(fds[0]);
        sleep(10);          //睡眠10秒
        write(fds[1],"hello,djw",5);    //子进程写数据给管道
        exit(EXIT_SUCCESS);
    }

    close(fds[1]);      //父进程关闭写端
    char buf[10] = { 0 };
    read(fds[0],buf,10);        //等待读数据
    cout << "receive data = " << " " << buf << endl;
    return 0; 
    
}