/*
*把可连接线程转换为分离线程(C++和POSIX)
*/

#include <iostream>
#include <thread>
using namespace std;
using std::thread;

void thfunc(int n,int m,int *k,char s[]){
    cout << "in thfunc:n=" << n << ",m=" << m << ",k = " << *k << endl;
    cout << "str= " << s << endl;
}

int main(int argc,char *argv[]){
    int n =110,m = 200,k = 5;
    char str[] = "hello world";
    thread t(thfunc,n,m,&k,str);
    t.detach();         //可分离线程

    cout << "k = " << k << endl;
    //在main线程中调用pthread_exit(NULL)时，将结束main进程，但进程并不会立即退出，要等所有的进程全部结束后才会退出，
    pthread_exit(NULL);         //main线程结束，但进程不会节数，下面这句不会执行

    cout << "this line will not run" << endl;
    return 0;
}