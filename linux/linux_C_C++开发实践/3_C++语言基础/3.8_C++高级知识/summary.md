# 预处理命令

## #define
### define可以被用来生成宏定义常量
`define name value`

常这样使用：
```c++
#define MAX_WIDTH 100
char str1[MAX_WIDTH];
char str2[MAX_WIDTH];
```

也可以被用来定义宏函数：
```C++
#define getmax(a,b) a>b?a:b
int x = 5,y;
y = getmax(x,2);
```
## #undef

#undef完成与#define相反的工作，它取消对传入的参数的宏定义：

```C++
#define MAX_WIDTH 100
char str1[MAX_WIDTH];
#undef MAX_WIDTH
```

## #ifdef #ifndef #if #endif #else 和 #elif

> #ifdef可以使一段程序只有在某个指定常量已经被定义了的情况下才被编译，无论被定义的值是什么？它的操作是：

```C++
#ifdef name
//code here
#endif
```
例如：
```C++
#ifdef MAX_WIDTH        //只有宏定义常量MAX_WIDTH已经被定义的情况下才被编译器考虑
char str[MAX_WIDTH];
#endif
```

>#ifndef作用相反：在指令#ifdef和#endif之间的代码只有在某个常量没有被定义的情况下才被编译：

```C++
#ifndef MAX_WIDTH       //如果MAX_WIDTH没有被宏定义，则宏定义给他一个值100
#define MAX_WIDTH 100
#endif
```

>指令#if、#else和#elif用来使得后面的程序只有在特定条件下才被编译。这些条件只能是常量表达式：

```C++
#if MAX_WIDTH > 200
#undef MAX_WIDTH
#define MAX_WIDTH 100
```

### #line

### #error



