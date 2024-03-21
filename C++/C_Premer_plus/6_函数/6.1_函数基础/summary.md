# 函数基础
函数三要素(返回类型、函数名、形参类型)描述了函数的接口。

## :sunflower:在头文件中进行函数声明
变量在头文件中声明，在源文件中定义。

函数也应该在头文件中声明而在源文件中定义。

定义函数的源文件应该吧含有函数声明的头文件包含进来，编译器负责验证函数的定义和声明是否匹配。

## :maple_leaf: 指针形参

```C++
void reset(int *ip)
{
    *ip = 0;    //改变指针ip所指对象的值
    ip = 0;     //只改变了ip的局部拷贝，实参未被改变
}

int i = 42;
reset(&i);
cout << "i = "<< i << endl; //输出i=0;
```
## :maple_leaf: 传引用参数

接受的参数是引用类型而非指针：
```C++
void reset(int &i)  //i是传给reset函数的对象的另一个名字
{
    i = 0;  //改变了i所引对象的值
}

int j = 42;
reset(j);
cout << "j = " << j << endl;        //输出j=0
```

## :maple_leaf: 使用引用避免拷贝

拷贝大的类类型对象或者容器对象比较低效，函数可以通过引用形参访问该类型的对象

```C++
//比较两个string对象的长度
bool isShorter(const string &s1,const string &s2)
{
    return s1.size() < s2.size();
}
```

## :maple_leaf: 使用引用形参返回额外信息

一个参数只能返回一个值，引用形参为我们一次返回多个结果提供了有效的途径。

```C++
//返回s中c第一次出现的位置索引
//引用形参occurs负责统计c出现的总次数
string::size_type find_char(const string &s,char c,string::size_type &occurs)
{
    auto ret = s.size();    //第一次出现的位置(若有)
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i)
    {
        if (s[i] == c)
        {
            if (ret == s.size())
                ret = i;    //记录c第一次出现的位置
            ++occurs;       //将出现的次数加1
        }
    }
    return ret;             //出现次数通过occurs隐式地返回
}

auto index = find_char(s,'o',ctr);

```
## :maple_leaf: const形参和实参

## :maple_leaf: 使用标记指定数组长度


## :four_leaf_clover: 使用标准库规范

管理数组实参的第二种技术是`传递指向数组首元素和尾后元素的指针`，可以按照：
```C++
void print(const int *beg, const int *end)
{
    //输出beg到end之间(不含end)的所有元素
    while (beg != end)
        cout << *beg++ << endl;     //输出当前元素并将指针向前移动一个位置
}

//为了调用这个函数，我们需要传入两个指针：一个指向要输出的首元素，另一个指向尾元素的下一位置：
int j[2] = {0,1};
//j转换成指向它首元素的指针
//第二实参是指向j的尾后元素的指针
print(begin(j),end(j));
```
## :four_leaf_clover: 显式传递一个表示数组大小的形参

第三种管理数组实参的方法是专门定义一个表示数组大小的形参，可以将print函数重写成：
```C++
//const int ia[]等价于const int *ia
//size表示数组的大小，将它显式地传给函数用于控制对ia元素的访问
void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i){
        cout << ia[i] << endl;
    }
}

int j[] = {0,1};
print(j,end(j) - begin(j));
```

## :four_leaf_clover: 不要返回局部对象的引用或指针

函数完成后，它所占用的存储空间也随之被释放掉。因此，函数终止意味着局部变量的引用将指向不再有效的内存区域。

## :four_leaf_clover: 返回类类型的函数和调用运算符

## :green_book: 返回数组指针

因为数组不能被拷贝，所以函数不能返回数组。

所以要想返回数组的指针或引用可以使用，类型别名

```C++
typedef int arrT[10];       //arrT是一个类型名，它表示的类型是10个整数的数组
using arrT = int[10];       //arrT的等价声明，
arrT* func(int i);          //func返回一个指向含有10个整数的数组的指针
```

## :green_book: 声明一个返回数组指针的函数

```C++
int arr[10];        //arr是一个含有10个整数的数组
int *p1[10];        //p1是一个含有10个指针的数组
int (*p2)[10] = &arr//p2是一个指针，它指向含有10个整数的数组
```
于是函数的返回类型是指针的数组：
`int (*func(int i))[10]`

可以按照以下的顺序逐层理解：
- func(int i)表示调用func函数时，需要一个int类型的实参
- (*func(int i))意味着我们可以对函数调用的结果执行解引用操作
- (*func(int i))表示解引用func的调用将得到一个大小是10的数组。
- int (*func(int i))[10]表示数组中的元素是int类型。

## :green_book: 使用尾置返回类型

为了简化上述func声明，可以使用尾置返回类型。

尾置返回类型跟在形参列表后面，并以一个`->`符号开头。

为了表示函数真正的返回类型跟形参列表之后，而在本应该出现返回类型的地方放置了一个`auto`

```C++
//func接受一个int类型的实参，返回一个指针，该指针指向含有10个整数的数组
auto func(int i) -> int(*)[10];
```

所以，可以清楚地看到func函数返回的是一个指针，并且该指针指向了含有10个整数的数组。















