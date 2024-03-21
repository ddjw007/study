/*
本文件主要为了练习黑马C++课程的P28，三只小猪称体重问题
*/
#include <iostream>

using namespace std;
int main()
{
    //三只小猪称体重，判断哪只最重
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;

    cout << "第一只小猪的重量是：" << endl;
    cin >> num1;
    cout << "第二只小猪的重量是：" << endl;
    cin >> num2;
    cout << "第三只小猪的重量是：" << endl;
    cin >> num3;
    if (num1 >num2)
    {
        //第一只小猪比第二只猪重
        if (num1 > num3)
        {
            //第一只小猪比第三只猪重
            cout<<"一号小猪最重"<<endl;

        }
        else
        {
            cout<<"三号小猪最重"<<endl;
        }
        
    }
    else
    {
        //第二只小猪比第一只猪重
    }
    

    return 0;

}