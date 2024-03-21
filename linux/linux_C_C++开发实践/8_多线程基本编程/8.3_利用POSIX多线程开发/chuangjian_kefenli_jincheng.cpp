/*
*创建一个可分离线程，main线程先退出
*/

#include <iostream>
#include <pthread.h>

using namespace std;

void *thfunc(void *arg)
{
    cout << "sub thread is running" << endl;
    return NULL; 
}

int main(int argc, char *argv[]){
    pthread_t thread_id;
    pthread_attr_t thread_attr;
    struct sched_param thread_param;
    size_t stack_size;
    int res;

    res = pthread_attr_init(&thread_attr); //初始化结构体属性
    if (res)
    {
        cout << "1" << endl;
    }

    res = pthread_attr_setdetachstate(&thread_attr,PTHREAD_CREATE_DETACHED);    //设置分离状态

    if (res)
    {
        cout << "2" << endl;
    }

    res = pthread_create(&thread_id,&thread_attr,thfunc,NULL);

    if (res)
    {
        cout << "3" << endl;/* code */
    }
    
    cout << "main thread will exit" << endl;
    pthread_exit(NULL);     //主线程退出，但进程不会立刻退出，
    cout << "main thread has exited, this line will not run" << endl;
    return 0;
    
    

}