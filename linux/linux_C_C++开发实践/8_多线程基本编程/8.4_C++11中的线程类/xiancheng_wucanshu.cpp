/*
*创建一个线程，不传参数
*/

#include <iostream>
#include <thread>
#include <unistd.h>     //sleep

using namespace std;
using std::thread;

typedef struct 
{
    int n;
    const char *str;    //注意这里要有const，否则会有警告
}MYSTRUCT;

// void thfunc(void *arg)      //线程函数
// {
//     MYSTRUCT *p = (MYSTRUCT*)arg;
//     cout << "in func:n=" << p->n << ",str=" << p->str << endl;
// }


// void thfunc(int i){
//         cout << "thfunc:" << i << endl;
// }

void thfunc(int n,int m,int *pk,char s[]){
    cout << "in thfunc:n=" << n << ",m=" << m << ",k = " << *pk << endl;
    cout << "str= " << s << endl;
}


int main(int argc, char *argv[]){
    MYSTRUCT mystruct;
    mystruct.str = "hello world";
    mystruct.n = 110;

    int n = 110, m = 200, k = 5;
    char str[] = "hello world";


    thread t(thfunc,n,m,&k,str);
    // thread t(thfunc,&mystruct);       //定义线程对象，并把线程函数指针传入
    t.join();               //主线程挂机1min
    cout << "k = " << k << endl;
    return 0;
}


// void thfunc(char *s){
//     cout << "thfunc: " << s << endl;
// }

// int main(int argc, char *argv[]){
//     char s[] = "boy and girl";      //定义一个字符串
//     thread t(thfunc,s);             //传递字符串作为参数
//     t.join();
//     return 0;
// }

