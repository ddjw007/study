/*
* 针对CPP第二章的图书销售问题的源码练习
*/
#include <iostream>
#include <string>
#include "sale_data.h"

using namespace std;

int main()
{
    //添加两个sale_data对象
    sale_data data1,data2;
    //初始化图书的单价，用于计算销售收入
    double price = 0;

    //读入第1笔交易：ISBN、销售数量、单价
    cout << "请分别输入ISBN/销售数量、单价" << endl;
    cin >> data1.bookNo >> data1.units_sold >> price;
    //计算销售收入
    data1.revenue = data1.units_sold * price;

    //读入第2笔交易：ISBN、销售数量、单价
    cout << "请分别输入ISBN/销售数量、单价" << endl;
    cin >> data2.bookNo >> data2.units_sold >> price;
    //计算销售收入
    data2.revenue = data2.units_sold * price;

    if (data1.bookNo == data2.bookNo)
    {
        //如果两笔交易设计的ISBN编号相同，相同则输出他们的和，反之则报错
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;

        //输出：ISBN、总销售量、总销售额、平均价格
        cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";

        if (totalCnt != 0)
        {
            cout << totalRevenue / totalCnt << endl;
        }
        else
            cout << "啥也没卖出去" << endl;

        return 0;
    }
    else
    {
        cerr << "Data must refer to the same ISBN" << endl;
        return -1;
    }
}