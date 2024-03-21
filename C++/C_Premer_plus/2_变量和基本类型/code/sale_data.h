#ifndef SALES_DATA_H
#define SALES_DATA_H

// #include "Version_test.h"
#include <string>

//定义sales_data的结构体
struct sale_data
{
    std::string bookNo;

#ifdef IN_CLASS_INITS
        unsigned units_sold = 0;
        double revenue = 0.0;
#else
        unsigned units_sold;
        double revenue;
#endif
};
#endif