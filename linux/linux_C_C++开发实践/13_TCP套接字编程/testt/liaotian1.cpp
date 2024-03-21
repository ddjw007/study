/*
*聊天程序，客户端
*/
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
    int cfd;
    int recbytes;
    int sin_size;
    char buffer[1024] = {0};
    struct sockaddr_in s_add,c_add;
    unsigned short portnum = 10051;
    // char ip="172.20.220.131";

    printf("this is client\r\n");

    cfd = socket(AF_INET,SOCK_STREAM,0);
    if (cfd == -1)
    {
        printf("socket fail!\r\n");
        return -1;
    }
    printf("socket ok!\r\n");

    bzero(&s_add,sizeof(struct sockaddr_in));
    s_add.sin_family = AF_INET;
    s_add.sin_addr.s_addr = inet_addr("172.20.220.131");
    s_add.sin_port = htons(portnum);

    if (connect(cfd,(struct sockaddr*)(&s_add),sizeof(struct sockaddr) == -1))
    {
        printf("connect fail!\r\n");
        return -1;
    }
    printf("connect ok!\r\n");

    buffer[recbytes] = '\0';
    printf("%s\r\n",buffer);

    printf("press any key to quit");
    getchar();
    close(cfd);     //关闭套接字
    return 0;
}