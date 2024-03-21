/*
声明了CRectangle是CSquare的friend
函数输出:16

*/


#include <iostream>
using namespace std;

class CRectangle
{
private:
    int width,height;
public:
    int area(void) {return {width * height};};
    void convert(CSquare a);
};

class CSquare
{
private:
    int side;
public:
    void set_side(int a){side = a;};
    friend class CRectangle;
};

void CRectangle::convert(CSquare a){
    width = a.side;
    height = a.side;
}

int main(){
    CSquare sqr;
    CRectangle rect;
    sqr.set_side(4);
    rect.convert(sqr);
    cout << rect.area() << endl;
    return 0;       
}


