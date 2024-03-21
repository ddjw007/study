#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <iostream>

using namespace std;

static void *thread_start(void *arg)
{
    int i,res;
    size_t stack_size;
    pthread_attr_t gattr;

    res = pthread_getattr_np(pthread_self(),&gattr);
    if (res)
    {
        cout << "pthread_getattr_np failed" << endl;
    }
    res = pthread_attr_getstacksize(&gattr,&stack_size);
    if (res)
    {
        cout << "pthread_getattr_np failed" << endl;
    }

    cout << "Default stack size is" << endl;
    

}