// /*
// *基于链表实现的队列
// */

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x),next(nullptr){}    //构造函数
// };





// class LinkedListQueue
// {
// private:
//     /* data */
//     private:
//     //头节点front 尾节点rear
//     ListNode *front,*rear;  
//     int queSize;
    
// public:
//     LinkedListQueue(){
//         front = nullptr;
//         rear = nullptr;
//         queSize = 0;
//     }
//     //遍历链表删除节点，释放内存
//     ~LinkedListQueue(){
//         // freeMemoryLinkedList(front);
//     }
//     int size(){
//         return queSize;
//     }

//     //入队(从尾节点)
//     void push(int num){
//         //尾结点添加num
//         ListNode *node = new ListNode(num);
//         //如果队列不为空，则将该节点添加到尾结点之后
//         if(front == nullptr){
//             front = node;
//             rear = node;
//         }
//         else{
//             rear->next = node;  //此时的尾节点的下一个元素
//             rear = node;    //将该节点确定为尾结点

//         }
//         queSize++;
//     }

//     //出队(从头结点)
//     void pop(){
//         int num = peek();

//         //删除头节点
//         ListNode *tmp = front;
//         front = front->next;

//         //释放内存
//         delete tmp;
//         queSize;
//     }

//     //访问队首元素
//     int peek(){
//         if(size() == 0)
//             throw out_of_range("队列为空");
//     }
// };
