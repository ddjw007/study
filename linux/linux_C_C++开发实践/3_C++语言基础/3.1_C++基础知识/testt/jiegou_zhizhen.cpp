#include <iostream>
#include <stdlib.h>
using namespace std;

struct movies_t
{
    char title[50];
    int year;
};

int main()
{
    char buffer[50];

    movies_t amovie;    //声明一个普通对象
    movies_t *pmovie;   //指针型对象
    pmovie = &amovie;

    cout <<"Enter title: " << endl;
    cin.getline(pmovie->title,50);
    cout << "Enter year:" << endl;

    cin.getline(buffer,50);
    pmovie->year = atoi(buffer);

    cout << "You have entered:" << endl;
    cout << pmovie->title;
    cout << "(" << pmovie->year << ")" << endl;

    return 0;
}