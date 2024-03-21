#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>




using namespace std;

int main()
{
    // cout << "fileno(stdin) = " << fileno(stdin) << endl;
    // cout << "fileno(stdout) = " << fileno(stdout) << endl;
    // cout << "fileno(stderr) = " << fileno(stderr) << endl;
///////////////////////////////////////////

    /*创建一个只读文件
    *
    */
    // int fd = -1;
    // char filename[] = "/home/djw/study/linux/linux_C_C++开发实践/4_Linux文件编程/testt/test.txt";
    // fd = creat(filename,0666);
    // if (fd == -1)
    // {
    //     cout << "fail to open file" << filename << endl;
    // }
    // else
    //     cout << "create file" << filename << "successfully" << " " <<  endl;
    
    // return 0;

///////////////////////////////////////////////////////////
    /*创建一个只读文件
    *
    */
    // int fd = -1;
    // char filename[] = "test.txt";    //相对路径,当前目录下
    // fd = open(filename,O_CREAT | O_RDWR, S_IRWXU);
    // if (fd == -1)
    //     cout << "fail to open file" << endl;
    // else
    //     cout << "open file successfully" << endl;
    //     cout << "fd:" << fd << endl;
    
    // close(fd);
    // return 0;
///////////////////////////////////////////////////////////
    /*
    *循环打开文件，而不关闭
    */
    // int i = 0;
    // int fd = 0;
    // for ( i = 1; fd >= 0; i++)
    // {
    //     fd = open("test.txt",O_RDONLY);
    //     if (fd > 0)
    //     {
    //         cout << "fd:" << fd << endl;
    //     }
    //     else
    //     {
    //         cout << "error,can't open file" << endl;
    //         exit(1);
    //     } 
    // }
    // return 0;
///////////////////////////////////////////////////////////
    /*
    *读取文件中的数据
    */   
    // int fd = -1,i;
    // ssize_t size = -1;
    // char buf[10];
    // char filename[] = "test.txt";    //需要读取的文件

    // fd = open(filename,O_RDONLY);
    // if (fd ==-1)
    // {
    //     cout << "open file" << " " << filename << "failure,fd: " << fd << endl;
    //     return -1;
    // }
    // else
    //     cout << "open file" << " " << filename << "successfully,fd: " << fd << endl;
    
    // //循环读取数据，直到文件末尾或者出错
    // while (size)
    // {
    //     //读取文件中的数据，10的意思是希望读取10个字节，但真正读取到的字节数是函数返回值
    //     size = read(fd,buf,10);
    //     if (size == -1)
    //     {
    //         close(fd);
    //         cout << "read file" << "  " << filename << "occurs errors" << endl;
    //         return -1;
    //     }
    //     else
    //     {
    //         if (size > 0)
    //         {
    //             cout << "read" << " " << size << "bytes" << " ";

    //             for ( i = 0; i < size; i++)
    //             {
    //                 cout << *(buf+i);
    //             }  
    //             cout << endl;
    //         }
    //         else
    //         {
    //             cout << "reach the end of file" << endl;
    //         }
            
    //     }
        
    // }
    // return 0;
///////////////////////////////////////////////////////////
    /*
    *向文件中写入文件
    */      
    // int fd = -1,i;
    // ssize_t size = -1;
    // int input = 0;

    // char buf[] = "boys and girls\n hi, children!";
    // char filename[] = "test.txt";

    // fd = open(filename,O_RDWR|O_APPEND);    //以追加和读写方式打开一个文件
    // if (fd == -1)
    // {
    //     cout << "Open file" << " " << filename << " " << "failure" << endl;
    // }
    // else
    //     cout << "Open file" << " " << filename << " " << "success" << endl;
    
    // size = write(fd,buf,sizeof(buf));
    // cout << "write" << " " << size << " " << "bytes to file" << " " << filename << endl;
    // close(fd);
    // return 0;
///////////////////////////////////////////////////////////
/*
*有时候需要从文件中某个位置开始读写，此时需要让文件读写位置移动到新的位置。
*所以有了设定文件偏移量的函数
*文件偏移量指的是当前文件操作位置相对于文件开始位置的偏移。
*用来设定文件偏移量的系统函数是lseed
*/
//对空文件设置偏移量到5处，写入字符串"boys"
    // int fd = -1;
    // ssize_t size = -1;
    // off_t offset = -1;
    
    // char buf[] = "boys";
    // char filename[] = "test.txt";

    // fd = open(filename,O_RDWR);
    // if (fd == -1)
    // {
    //     cout << "open file fail,fd: " << fd << endl;
    //     return -1;
    // }
    // offset = lseek(fd,5,SEEK_SET);      //重新定义文件偏移量到5处
    // if ( offset == -1)
    // {
    //     cout << "lseek file failure" << endl;
    //     return -1;
    // }
    // size = write(fd,buf,sizeof(buf));       //向文件写入数据
    // if (size != sizeof(buf))
    // {
    //     cout << "write file failure" << endl;
    //     return -1;
    // }
    // close(fd);
    // return 0;
///////////////////////////////////////////////////////////
    /*
    *用C++流的方式读写文件
    */
    char data[100];

    //以写模式打开文件
    ofstream outfile;
    outfile.open("afile.bat");

    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data,100);      //从外部读取一行

    //向文件写入用户输入的数据
    outfile << data << endl;

    cout << "Enter your age :";
    cin >> data;
    cin.ignore();       //忽略之前语句留下的多余字符

    //再次向文件写入用户输入的数据
    outfile << data << endl;

    //关闭打开的文件
    outfile.close();

    //以读模式打开文件
    ifstream infile;
    infile.open("afile.bat");

    cout << "Reading from the file" << endl;
    infile >> data;

    //在屏幕上写出数据
    cout << data << endl;

    //再次从文件读取数据，并显示它
    infile >> data;
    cout << data << endl;

    //关闭打开的文件
    infile.close();

    return 0;


}
