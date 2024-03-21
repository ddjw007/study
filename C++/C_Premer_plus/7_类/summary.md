# 类

类的基本思想是数据抽象(data abstraction)和封装(encapsulation)。

数据抽象是一种依赖于接口(interface)和实现(implementation)分离的编程技术。

类的接口包括用户所能执行的操作：类的实现则包括类的数据成员、负责接口实现的函数体以及定义类所需的各种私有函数。

封装实现了类的接口和实现的分离。

#### 改进Sales_data类
```C++
struct Sales_data{
    //新成员：关于Sales_data对象的操作
    std::string isbn() const{ return bookNO; }      //常量成员函数
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
//Sales_data的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
```

##### 在类外部定义成员函数
```C++
double Sales_data::avg_price() const{
    if(units_sold)
        return revenue/units_solds;
    else
        return 0;
}
```
##### 定义一个返回this对象的函数

### 定义类相关的非成员函数

定义非成员函数的方式与定义其他函数一样，通常把函数的声明和定义分离开来。

#### 定义read和print函数



### 构造函数

每个类都分别定义了它的对象被初始化的方式，类通过一个或几个特殊的成员函数来控制其对象的初始化进程，这些函数叫做构造函数。

构造函数的任务是初始化类对象的数据成员，无论何时只要类的对象被创建，就会执行构造函数。

构造函数的名字和类名相同，只是没有返回类型，有一个(可以为空)的参数列表和一个(可以为空)的函数体。类可以有多个构造函数。

#### 合成的默认构造函数

如果我们的类没有显式地定义构造函数，那么编译器就会为我们隐式地定义一个默认构造函数。


#### 定义Sales_data的构造函数

### 拷贝、赋值和析构


## 访问控制与封装

在C++中，我们使用访问说明符(access specifiers)加强类的封装性：
- 定义在*public*说明符之后的成员在整个程序内可被访问，public成员定义类的接口。
- 定义在*private*说明符之后的成员可以被类的成员函数访问，但是不能被使用该类的代码访问，private部分封装了类的实现细节。









