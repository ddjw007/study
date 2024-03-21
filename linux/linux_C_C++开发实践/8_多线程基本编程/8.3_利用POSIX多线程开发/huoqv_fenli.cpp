/*
*创建一个可连接线程，然后获取其分离状态，再把它转换为可分离线程
*再获取其分离状态属性
*/

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

// #define handle_error_en(en,msg) \
//         do
//         {
//             errno = en;
//             perror(msg);
//             exit(EXIT_FAILURE);
//         } while (0);
        