#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    int nNum = 0x12345678;
    char *p = (char*) &nNum;    //p指向存储nNum的内存的低地址

    if (*p == 0x12)
    {
        cout << "this mechine is big endian." << endl;
    }
    else
        cout << "this mechine is small endian." << endl;

    return 0;
    
}