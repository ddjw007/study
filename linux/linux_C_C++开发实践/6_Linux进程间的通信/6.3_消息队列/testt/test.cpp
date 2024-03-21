#include <stdio.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <string>
#include <sys/stat.h>
#include <cstring>
#include <iostream>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

using namespace std;

struct my_msg_st
{
    long int my_msg_type;
    char some_text[BUFSIZ];
};




int main()
{
    //////////////////////////////////////////////////////////////////////////////
    /*
    *生成一个键值
    *
    */
    // key_t semkey;
    // if ((semkey == ftok("test",123)) < 0)     //若执行成功则返回key_t键值，否则返回-1
    // {
    //     cout << "ftok failed" << endl;
    //     exit(EXIT_FAILURE); 
    // }
    // cout << "ftok ok,semkey = " << " " << semkey << endl;
    // return 0;
    //////////////////////////////////////////////////////////////////////////////
    /*
    *解开ftok产生键值的内幕
    *
    */
    // char filename[50];
    // struct stat buf;
    // int ret;
    // strcpy(filename,"test");    //需要包含头文件cstring
    // ret = stat(filename,&buf);
    // if (ret)
    // {
    //     cout << "stat error" << endl;
    //     return -1;
    // }

    // cout << "the file info:ftok(filename,0x27) = " << ftok(filename, 0x27) << "st_ino=" << buf.st_ino << "st_dev=" << buf.st_dev << endl;
    // return 0;  
    //////////////////////////////////////////////////////////////////////////////
    /*
    *消息队列的发送和接收
    *接受者，使用msgget来获得消息队列标识符，并且等待接受消息，直到接收到特殊消息end,
    *然后使用msgctl删除消息队列进行一些清理工作
    */
    // int running = 1;
    // int msgid;
    // struct my_msg_st some_data;
    // long int msg_to_receive = 0 ;   //读取消息队列中的全部消息

    // //创建消息队列
    // msgid = msgget((key_t)1234,0666|IPC_CREAT);
    // if (msgid == -1)
    // {
    //     cout << "msgget failed with error" << " " << errno << endl;
    //     exit(EXIT_FAILURE);
    // }

    // //接受信息队列中的消息直到遇到一个end消息。最后，消息队列被删除
    // while (running)
    // {       //以阻塞方式等待接受消息
    //     if (msgrcv(msgid,(void*)&some_data,BUFSIZ,msg_to_receive,0) == -1)
    //     {
    //         cout << "msgrcv failed with errno" << errno << endl;
    //         exit(EXIT_FAILURE);
    //     }
        
    //     cout << "You wrote" << some_data.some_text << endl;
    //     if (strncmp(some_data.some_text,"end",3) == 0)      //如果收到的是end，就退出循环
    //     {
    //         running = 0;
    //     }        
    // }
    // if (msgctl(msgid,IPC_RMID,0) == -1)
    //     {
    //         cout << "msgctl(IPC_RMID failed)" << endl;
    //         exit(EXIT_FAILURE);
    //     }
    
    // exit(EXIT_SUCCESS);   
    //////////////////////////////////////////////////////////////////////////////
    /*
    *获取消息队列的属性
    *接受者，使用msgget来获得消息队列标识符，并且等待接受消息，直到接收到特殊消息end,
    *然后使用msgctl删除消息队列进行一些清理工作
    */ 
}