#include <unistd.h>
#include <iostream>
using namespace std;

int main(int argc,char* argv[])
{
    execl("/testt",NULL);
    cout << "-----------------\n"
    return 0;
}