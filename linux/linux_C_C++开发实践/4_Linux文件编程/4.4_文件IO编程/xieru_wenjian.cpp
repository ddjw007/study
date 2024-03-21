#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    int fd = -1,i;
    ssize_t size = -1;
    int input = 0;
    char buf[] = "boys and girls\n hi,children!\n";
    char filename[] = "test.txt";

    fd = open(filename,O_RDWR|O_APPEND);
    if (fd == -1)
    {
        printf("Open file %s failure \n",filename);
    }
    else{
        printf("Open file %s successfully \n",filename);
    }
    size = write(fd,buf,sizeof(buf));

    printf("write %d bytes to file %s\n",size,filename);

    close(fd);
    return 0;
    
}