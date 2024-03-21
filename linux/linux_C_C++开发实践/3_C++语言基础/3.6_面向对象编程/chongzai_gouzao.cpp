/*
*重载类的构造函数
*/

#include <iostream>
using namespace std;

class CRectangle
{
private:
    int width,height;
public:
    CRectangle();
    CRectangle(int, int);
    int area(void){return (width * height);};
};

CRectangle::CRectangle(){
    width = 5;
    height = 5;
}

CRectangle::CRectangle(int a,int b){
    width = a;
    height =b;
}

int main(){
    CRectangle rect(3,4);
    CRectangle rectb;       //如果不想传入参数，不需要写()
    cout <<" rect area" << rect.area() << endl;
    cout << "rectb area" << rectb.area() << endl;
}