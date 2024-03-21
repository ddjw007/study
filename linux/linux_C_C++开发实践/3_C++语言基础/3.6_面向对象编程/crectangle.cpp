#include <iostream>
using namespace std;

class crectangle
{
private:
    int x, y;
public:
    void set_values(int ,int);
    int area(void) {return (x*y);};
};

void crectangle::set_values(int a, int b){
    x = a;
    y = b;
}

int main()
{
    crectangle rect;
    rect.set_values(3,4);
    cout << "area:" << rect.area() << endl;
    return 0;
}
