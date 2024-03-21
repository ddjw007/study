/*
*基类集成的例子
*
*daughter (int a)   //没有特别指定：调用默认constructor
*son(int a) : mother (a) //指定了constructor：调用被指定的构造函数
*/
#include <iostream>

using namespace std;

class mother
{
public:
    mother(){ cout << "mother: no parameter" << endl;};
    mother(int a){ cout << "mother: int parameter" << endl;};
};

class daughter : public mother
{
public:
    daughter(int a){cout << "daughter: int parameter" << endl;};
};

class son:public mother
{
public:
    son(int a) : mother(a){cout << "son: int parameter" << endl;};
};

int main(){
    daughter cynthia(1);
    son daniel(1);
    return 0;
}

