# 成员访问运算符
## 点运算符 和 箭头运算符都可以用于访问对象。

### :shower: 点运算符

获取类对象的一个成员；

### :seat: 箭头运算符

`ptr->mem`等价于(*ptr).mem

```C++
string s1 = "a string", *p = &s1;
auto n = s1.size();     //运行string对象s1的size成员
n = (*p).size();        //运行p所指对象的size成员
n = p -> size();        //等价于前者
```