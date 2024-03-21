#include <iostream>
#include <stdlib.h>
#include <vector>


using namespace std;
using std::vector;


/*
*使用链表实现的时候，将头节点作为栈顶
*/

struct ListNode
{
    int val;        //节点值
    ListNode *next;
    ListNode(int x) : val(x),next(nullptr){}    //构造函数
};



//基于链表实现的栈
class LinkedListStack
{
private:
    ListNode *stackTop;     //初始化头节点，将头节点作为栈顶
    int stkSize;            //栈的长度

public:
    LinkedListStack(){
        stackTop = nullptr;
        stkSize = 0;
    }
    ~LinkedListStack(){
        //遍历链表删除节点，释放内存
        freeMemoryLinkedList(stackTop);
    }
    
    //获取栈的长度
    int size(){
        return stkSize;
    }

    //判断栈是否为空
    bool empty(){
        return size() == 0;
    }

    //入栈
    void push(int num){
        ListNode *node = new ListNode(num);
        node->next = stackTop;
        stackTop = node;    //将栈顶指针指向node
        stkSize++;
    }

    //出栈
    void pop(){
        int num = top();
        ListNode *tmp = stackTop;
        stackTop = stackTop ->next; //将栈顶指针指向当前头节点的下一个节点，将前任头节点弹出
        //释放内存
        delete tmp;
        stkSize--;
    }

    //将List转化为Array并返回
    vector<int> toVector(){
        ListNode *node = stackTop;
        vector<int> res(size());
        for(int i = res.size() - 1; i >= 0;i--){
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
};
