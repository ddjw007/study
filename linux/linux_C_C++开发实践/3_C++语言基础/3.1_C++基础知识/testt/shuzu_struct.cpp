/*
*数组结构体
*该函数
*/


#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define N_MOVIES 5

struct movies_t
{
    char title[50];
    int year;
}films[N_MOVIES];       //数组结构体

void printmovie(movies_t movie);

int main()
{
    char buffer[50];
    int n;
    for ( n = 0; n < N_MOVIES; n++)         //N_MOVIES ：5
    {
        cout << "Enter title:";
        cin.getline(films[n].title, 50);
        cout << "Enter year: ";
        cin.getline(buffer,50);
        films[n].year = atoi(buffer);
    }

    cout << "You have entered these movies:" << endl;
    for ( n = 0; n < N_MOVIES; n++)
        printmovie(films[n]);
    return 0; 
}

void printmovie(movies_t movie){
    cout << movie.title;
    cout << "(" << movie.year << ")" << endl;
}