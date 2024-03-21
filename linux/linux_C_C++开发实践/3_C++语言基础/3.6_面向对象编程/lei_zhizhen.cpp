/*
*类的指针
*/
#include <iostream>
using namespace std;

class CRectangle
{
private:
    int width,height;
public:
    void set_values(int, int);
    int area(void){return (width*height);};
};


//定义构造函数
void CRectangle::set_values(int a,int b){
    width = a;
    height = b;
}

int main(){
    //分别定义了三个对象，
    CRectangle a, *b,*c;    
    CRectangle *d = new CRectangle[2];
    //这部分代码使用new操作符在堆上动态分配内存来存储一个CRectangle类型的对象。同时，它会调用CRectangle类的默认构造函数来初始化这个新创建的对象。new操作符返回这个新创建对象的内存地址。
    b = new CRectangle;     //
    c = &a;
    a.set_values(1,2);
    b->set_values(3,4);

    d->set_values(5,6);
    d[1].set_values(7,8);
    cout << "a area: " << a.area() << endl;     //2
    cout << "*b area:" << b->area() << endl;    //12
    cout << "*c area:" << c->area() << endl;    //2
    cout << "d[0] area: " << d[0].area() << endl;      //30
    cout << "d[1] area: " << d[1].area() << endl;      //56
    return 0;
}
