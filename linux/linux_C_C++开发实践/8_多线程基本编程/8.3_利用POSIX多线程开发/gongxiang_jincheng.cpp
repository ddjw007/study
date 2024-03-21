/*
*共享进程数据，先在子线程中+1，接着在主线程中+1
*/

#include <pthread.h>
#include <stdio.h>

int gn = 10;    //定义一个全局变量，将会在主线程和子线程中用到
void *thfunc(void *argc)        //线程函数
{
    gn++;
    printf("in thfunc:gn=%d,\n",gn);    //打印全局变量gn值
    return (void *)0;
}

int main(int argc, char *argv[]){
    pthread_t tidp;
    int ret;

    ret  = pthread_create(&tidp, NULL, thfunc,NULL);

    if (ret)
    {
        printf("pthread_create failed: %d\n",ret);
        return -1;
    }

    pthread_join(tidp, NULL);   //等待子进程结束
    gn++;                       //子线程结束后，gn再递增1
    printf("int main:gn=%d\n",gn);  //再次打印全局变量gn值

    return 0;
    
}

