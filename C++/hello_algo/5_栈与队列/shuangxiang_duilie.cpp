/*
*双向链表实现双向队列
*/


//双向链表节点
struct DoublyListNode
{
    int val;        //节点值
    DoublyListNode *next;   //后继节点指针
    DoublyListNode *prev;   //前驱节点指针
    DoublyListNode(int val):val(val),prev(nullptr),next(nullptr){}
};

//双向队列
class LinkedListDeque
{
private:
    /* data */
    DoublyListNode *front,*rear;
    int queSize = 0;
public:
    //构造方法
    LinkedListDeque():front(nullptr),rear(nullptr){}
    //析构方法
    ~LinkedListDeque(){
        //遍历链表删除节点，释放内存
        DoublyListNode *pre,*cur = front;
        while (cur != nullptr)
        {
            pre = cur;
            cur = cur->next;
            delete pre;
        }
    }

    //获取双向队列的长度
    int size(){
        return queSize;
    }

    //判断双向队列是否为空
    bool isEmpty(){
        return size() == 0;
    }

    //入队操作
    void push(int num, bool isFront){
        DoublyListNode *node = new DoublyListNode(num);
        //若链表为空，则令front,rear都指向node
        if (isEmpty())
        {
            front = rear = node;
        }
        //队首入队
        else if(isFront){
            //将node添加至链表头部
            front->prev = node;     //将front的前驱指针指向node
            node->next = front;     //将node的后继指针指向front
            front = node;   //更新头节点
        //队尾入队操作
        }
        else{
            //将node添加至链表尾部
            rear->next = node;
            node->prev = rear;
            rear = node;
        }

        queSize++;      //更新队列长度
        
    }

    //队首入队
    void pushFirst(int num){
        push(num,true);
    }

    //队尾入队
    void pushLast(int num){
        push(num,false);
    }

    //出队操作
    int pop(bool isFront){
        //若队列为空，直接返回-1
        if (isEmpty())
        {
            return -1;
        }

        int val;
        //队首出队操作
        if (isFront)
        {
            /* code */
            val = front->val;   //暂存头节点值
            //删除头节点
            DoublyListNode *fNext = front->next;
            if (fNext != nullptr)
            {
                fNext->prev = nullptr;
                fNext->next = nullptr;
                delete front;
            }

            front = fNext;  //更新头节点          
        }
        else{
            //队尾出队操作
            val = rear->val;    //暂存尾结点值
            //删除尾结点
            DoublyListNode *rPrev = rear->prev;
            if (rPrev != nullptr)
            {
                rPrev->next = nullptr;
                rear->prev = nullptr;
                delete rear;
            }
            rear = rPrev;   //更新尾结点
        }
        queSize--;      //更新队列长度
        return val;
    }

    //访问队首元素
    int peekFirst(){
        return isEmpty()?-1:front->val;
    }

    //访问队尾元素
    int peekLast(){
        return isEmpty()?-1:rear->val;
    }

    

};

