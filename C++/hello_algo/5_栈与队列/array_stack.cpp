#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stack>

using namespace std;
using std::vector;

//基于数组实现的栈
class ArrayStack
{
private:
    vector<int> stack;      //存储栈元素
public:
    //获取栈的长度
    int size(){
        return stack.size();
    }

    //判断栈是否为空
    bool empty(){
        return stack.empty();
    }

    //入栈
    void pop(){
        int oldTop = top();
        stack.pop_back();
    }

    //访问栈顶元素
    int top(){
        if (empty())
        {
            throw out_of_range("栈为空");
        }
        return stack.back();
    }

    //返回vector
    vector<int> toVector(){
        return stack;
    }

};
