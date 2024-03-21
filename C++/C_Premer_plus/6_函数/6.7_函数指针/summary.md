# 函数指针

函数指针指向的是函数而非对象，

有一个函数是：
`bool lengthCompare(const string &,const string &)`

要想声明一个可以指向该函数的指针，只需要用指针替换函数名即可
`bool (*pf)(const string &,const string &)`

## 使用函数指针
