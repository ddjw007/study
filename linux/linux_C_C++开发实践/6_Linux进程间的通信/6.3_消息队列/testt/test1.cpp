//消息发送程序
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

#define MAX_TEXT 512

using namespace std;

struct my_msg_st
{
    long int my_msg_type;
    char some_text[MAX_TEXT];
};

int main()
{
    int running = 1;
    struct my_msg_st some_data;
    int msgid;
    char buffer[BUFSIZ];

    msgid = msgget((key_t)1234,0666|IPC_CREAT);     //用一个整数作为键值
    if (msgid == -1)
    {
        cout << "msgget failed with errno: " << " " << endl;
        exit(EXIT_FAILURE);
    }
    while (running)
    {
        cout << "Enter some text :" << " " << endl;
        fgets(buffer,BUFSIZ,stdin);
        some_data.my_msg_type = 1;
        strcpy(some_data.some_text,buffer);
        if (msgsnd(msgid,(void*)&some_data,MAX_TEXT,0) == -1)
        {
            cout << "msgsnd failed" << endl;
            exit(EXIT_FAILURE);
        }
        if (strncmp(buffer,"end",3) == 0)
        {
            running = 0;
        }
    }
    exit(EXIT_SUCCESS);
}

