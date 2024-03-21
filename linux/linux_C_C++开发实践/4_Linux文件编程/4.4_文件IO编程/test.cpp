#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    cout << "fileno(stdin) = " << fileno(stdin) << endl;
    cout << "fileno(stdout) = " << fileno(stdout) << endl;
    cout << "fileno(stderr) = " << fileno(stderr) << endl;

    return 0;
}