# 数组
## 定义和初始化内置数组

数组的声明形如`a[d]`,其中，维度说明了数组中元素的个数，必须大于0。数组中元素的个数也属于数组类型的一部分，编译的时候维度应该是已知的，也就是说维度必须是一个常量表达式。

```C++
unsigned cnt = 42;      //不是常量表达式
constexpr unsigned sz = 42;     //常量表达式
int arr[10];        //含有10个整数的数组
int *parr[sz]       //含有42个整型指针的数组
string bad[cnt]     //错误；
string strs[get_size()];
```

### :orange_book:显式初始化数组元素
```C++
int ial[sz] = {0,1,2};
int a2[] = {0,1,2};
int a3[5] = {0,1,2}     //等价于a3[] = {0,1,2,0,0}
string a4[3] = {"hi","bye"};    //等价于a4[]={"hi","bye",""}
```
### :orange_book: 字符数组的特殊性
```C++
char a1[] = {'C','+','+'};      //列表初始化
char a2[] = {'C','+','+','\0'};
char a3[] = 'C++';
const char a4[6] = "Daniel";
```

### :orange_book: 理解复杂的数组声明

因为数组本身就是对象，所以允许定义数组的指针和数组的引用。其中，定义存放指针的数组比较简单和直接，但是定义数组的指针或数组的引用就稍微复杂了：

```C++
int *ptrs[10]；               //ptrs是含有10个整型指针的数组
int &refs[10] = /* ? */     //错误：不存在引用的数组
//Parray是个指针，它指向一个int数组，数组中包含10个元素
int (*Parray)[10] = &arr；   //Parray指向一个含有10个整数的数组
//arrRef是一个引用，它引用的对象是一个大小为10的数组，数组中元素的类型是int
int (&arrRef)[10] = arr；     //arrRef引用一个含有10个整数的数组
//array是一个含有10个int型指针的数组的引用
int *(&array)[10] = ptrs；
```
默认情况下，类型修饰符从右向左依次绑定。

### :orange_book: 访问数组元素

在使用数组下标时，通常将其定义为`size_t`类型。

用数组来记录各个分数段的成绩个数

```C++
//以10分为一个分数段统计成绩的数量
unsigned scores[11] = {};       //11个分数段，全部初始化为0
unsigned grade;
while (cin >> grade)
{
    if (grade <=100 )
        ++scores[grade/10];
}

```

与`vector`和`string`一样，当需要遍历数组的所有元素时，最好使用范围`for`语句：
```C++
for (auto i : scores)
    cout << i << " ";
cout << endl;
```

### :nut_and_bolt: 指针和数组

像其他对象一样，对数组的元素使用`取地址符`就能得到指向该元素的指针：
```C++
string nums[] = {"one","two","three"};
string *p = &nums[0];
```
在很多使用数组名字的地方，使用数组类型的对象其实是使用一个指向该数组首元素的指针。

### :nut_and_bolt: 指针也是迭代器

```C++
int arr[] = {0,1,2,3,4,5,6,7,8};
int *p = arr;       //p指向arr的第一个元素
++p;                //p指向arr[1]
```

### :nut_and_bolt: 标准库函数begin 和 end

正常的使用形式是将数组作为它们的参数
 ```C++
int ia[] = {0,1,2,3,4,5,6,7,8};
int *beg = begin(ia);       //指向ia首元素的指针
int *last = end(ia)         //指向arr尾元素的下一个位置的指针
 ```

 ```C++
//找寻arr中的第一个负数
int *pbeg = begin(arr), *pend = end(arr);
//寻找第一个负值元素，如果已经检查完就结束循环
while (pbeg != pend && *pbeg >= 0)
    ++pbeg;
 ```

 > Note：尾后指针不能执行解引用和递增操作。

### :closed_book: 指针运算










