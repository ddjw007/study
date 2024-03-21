#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd = -1;        //文件描述符
    ssize_t size = -1;  //读取字节数
    char buf[10];
    char filename[] = "test.txt";

    fd = open(filename,O_RDONLY);

    if (fd == -1)
    {
        printf("Open file %s failure,fd:%d\n",filename,fd);
    }
    else
        printf("Open file %s success,fd:%d\n",filename,fd);

    //循环读取数据，直到文件末尾或者出错
    while (size)
    {
        size = read(fd,buf,10);
        if (size == -1)
        {
            close(fd);
            printf("Read file %s error occurs\n",filename);
            return -1;
        }
        else{
            if (size > 0)
            {
                printf("read %d bytes:",size);
                printf("\"");
                for ( int i = 0; i < size; i++)
                {
                    printf("%c",*(buf+i));
                }
                // printf("\"\n");
                
            }
            else
            {
                printf("reach the end of file\n");
            }
            }
    }
    return 0;
}