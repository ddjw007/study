#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    char input[100];
    int i,n;
    long *l;
    cout << "How many numbers do you want to type in?";
    cin.getline(input,100);
    i = atoi(input);      //将数字字符串转为整数
    l = new long[i];
    if (l == NULL)
    {
        exit(1);
    }
    for ( n = 0; n < i; n++)
    {
        cout << "Enter number:";
        cin.getline(input, 100);
        l[n] = atol(input);
    }
    cout << "You have entered: ";
    for ( n = 0; n < i; n++)
    {
        cout << l[n] << "," << endl;
    }
    delete[] l;
    return 0;
}