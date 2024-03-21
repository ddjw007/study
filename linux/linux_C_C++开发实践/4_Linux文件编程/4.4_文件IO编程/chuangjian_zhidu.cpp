#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


using namespace std;

int main(){
    int fd = -1;
    char filename[] = "test.txt";
    fd = creat(filename,0666);
    if (fd == -1)
    {
        // cout << "fail to open file" << endl;
        printf("fail to open file %s\n",filename);
    }
    else
        printf("create file %s successfully\n",filename);

    return 0;
    
}