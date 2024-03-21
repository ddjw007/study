#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

using namespace std;

int main(int argc, char *argv[])
{
    /*
    *获取pid_t的字节长度
    */
    // pid_t pid;
    // cout << sizeof(pid_t) << endl;
    // return 0;
/////////////////////////////////////////////
    /*
    *获取当前进程的ID
    */
    // pid_t pid = getpid();
    // cout << "pid = " << pid << endl;
    // return 0;
/////////////////////////////////////////////
    /*
    *通过PID文件判断进程是否进行
    */
    // pid_t pid = getpid();
    // cout << "pid = " << pid << endl;
    // return 0;
/////////////////////////////////////////////
    /*
    *杀死僵尸进程
    */
    // static char* starter_pid_file_default = "/var/run/test.pid";     //创建一个test.pid文件

    // static bool check_pid(char *pid_file)
    // {
    //     struct stat stb;     //结构体stat存放了文件属性信息
    //     FILE *pidfile;   //C语言标准库中的一个结构类型，用于连接程序和文件。

    //     if (stat(pid_file,&stb) == 0)        //stat()查询文件属性
    //     {
    //         pidfile = fopen(pid_file,"r");   //fopen()返回FILE文件指针
    //         if (pidfile)
    //         {
    //             char buf[64];
    //             pid_t pid = 0;
    //             memset(buf,0,sizeof(buf)); //用于将内存空间的部分位置设定为指定值
    //             if (fread(buf,1,sizeof(buf),pidfile))    //从文件流中读取数据块存储到内从空间中
    //size_t fread(void *ptr, size_t 每个字节大小, size_t count, FILE *stream);
    //             {
    //                 buf[sizeof(buf) - 1] = '\0';
    //                 pid = atoi(buf);
    //             }
    //             fclose(pidfile);
    //             if (pid && kill(pid,0) == 0)
    //             {
    //                 return 1;
    //             }              
    //         }
    //         cout << "removing pidfile" << pidfile << "process not running"; 
            
    //     }
        
        
    // }

/////////////////////////////////////////////
    /*
    *通过fork来创建子进程
    */
    // pid_t fpid;
    // int count = 0;
    // fpid = fork();
    // if ( fpid < 0)
    // {
    //     cout << "failed to fork";
    // }
    // else if (fpid == 0)     //子进程跳入
    // {
    //     cout << "i am the child process,my pid is" << getpid() << endl;
    //     count++;
    // }
    // else            //父进程跳入
    // {
    //     cout << "i am the parent process,my pid is" << getpid() << endl;
    //     cout << "fpid = " << fpid << endl;
    //     count++;
    // }
    // cout << "result: " << " " << count << endl;
    // return 0;
///////////////////////////////////////////// 
    /*
    *使用execl执行不带选项的命令程序pwd
    *程序运行，打印了当前路径，这和执行pwd命令是一样的
    */
    //执行/bin目录下的pwd，注意argv[0]必须要有
    
    // execl("/bin/pwd","asdfaf",NULL);
    // return 0;
//////////////////////////////////////////////////////////////// 
    /*
    *使用execl执行不带选项的命令程序pwd
    *程序运行，打印了当前路径，这和执行pwd命令是一样的
    */

    //执行/bin目录下的ls，注意,argv[0]传入的是程序名ls,argv[1]才传入-al,argv[2]传入的是要查看的文件/etc/passwd
    
    // execl("/bin/ls","ls","-al","/etc/passwd",NULL);
    // return 0;
////////////////////////////////////////////////////////////////
    /*
    *使用execl执行我们的程序
    *程序运行，打印了当前路径，这和执行pwd命令是一样的
    */

    //执行/bin目录下的ls，注意,argv[0]传入的是程序名ls,argv[1]才传入-al,argv[2]传入的是要查看的文件/etc/passwd
    
    int i;
    cout << "argc = " << argc << endl;      //打印一下传进来的参数个数

    for ( i = 0; i < argc; i++)             //打印各个参数
    {
        cout << argv[i] << endl;
    }

    if (argc == 2 && strcmp(argv[1],"-p") == 0)     //判断是否带了参数-p
        cout << "will print all" << endl;
    else
        cout << "will print little" << endl;

    cout << "my program over" << endl;
    return 0;
}