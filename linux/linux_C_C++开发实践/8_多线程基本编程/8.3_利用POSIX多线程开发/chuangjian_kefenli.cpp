#include <iostream>
#include <pthread.h>
#include <bits/stdc++.h>

using namespace std;

void *thfunc(void *arg){
    cout << "sub thread is running" << endl;
    return NULL;
}

int main(int argc, char *argv[]){
    pthread_t thread_id;
    pthread_attr_t thread_attr;     //线程属性联合体
    struct sched_param thread_param;
    size_t stack_size;
    int res;

    res = pthread_attr_init(&thread_attr);  //  初始化属性结构体
    if (res)        //执行失败，返回1
    {
        cout << "pthread_attr_init failed:" << res << endl;
    }
    res = pthread_attr_setdetachstate(&thread_attr,PTHREAD_CREATE_DETACHED);

    if (res)
    {
        cout << "pthread_attr_setdetachstate failed:" << res << endl;
    }

    res = pthread_create(&thread_id,&thread_attr,thfunc, NULL);

    if (res)
    {
        cout << "pthread_create failed:" << res << endl;
    }
    cout << "main thread will exit" << endl;
    
    // sleep(1);
    return 0;
       
}