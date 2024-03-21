#include <stdio.h>
#include <stdlib.h>

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;
using std::thread;


void thfunc(int n)  //线程函数
{
    cout << "thfunc: " << n << endl;
}

int main(int argc, const char *argv[]){
    thread threads[5];      //定义5个thread对象，但此时并不会执行线程
    cout << "create 5 threads..." << endl;

    for (int i = 0; i < 5; i++)     //遍历创建5个线程
    {
        threads[i] = thread(thfunc,i+1);    //开始执行线程函数
    }

    for (auto& t : threads)         //迭代器等待线程结束
    {
        t.join();
    }
    cout << "All threads joined." << endl;

    return EXIT_SUCCESS;
    
    
}