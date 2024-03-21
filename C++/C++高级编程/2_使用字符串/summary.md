# C风格的字符串

在C语言中，字符串表示为字符的数组，字符串的最后一个字符时空字符`\0`,这样就知道字符串的结束位置。

获取字符串的长度`strlen()`
```C++
char* copyString(const char* str){
    //先分配内存
    //对于字符串"Hello"，需要在strlen()返回的字符串长度的前提下再+1(空字符\0).
    char* result = new char[strlen(str)+1];
    strcpy(result,str);
    return result;
}
```

> C和C++中的sizeof()操作符可用于获得给定数据类型或变量的大小(不是字符数目)。但是，在C风格的字符串中，`sizeof()和strlen()是不同的`，绝对不要通过`sizeof()`获得字符串的大小
```C++
char text1[] = "abcdef";
//char的大小是1字节，除了正常字符串，'\0'也有1字节
size_t s1 = sizeof(text1);  //内存大小7
size_t s2 = strlen(text1);  //字符串长度6
```

