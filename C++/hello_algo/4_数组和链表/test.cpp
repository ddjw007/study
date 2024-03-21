
/*
*列表的实现
*/
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
using std::vector;


/*
扩容数组
*/
int *extend(int *nums, int size, int enlarge){
    //初始化一个扩展长度后的数组
    int *res = new int[size+enlarge];
    //将原素组中的所有元素赋值到新数组
    for(int i = 0; i < size; i++){
        res[i] = nums[i];
    }
    //释放内存
    delete[] nums;

    return res;
}

class MyList
{
private:
    /* data */
    int *nums;  //数组(存储列表元素)
    int numsCapacity = 10;  //列表容量
    int numsSize = 0;       //列表长度(当前元素数量)
    int extendRatio = 2;    //每次列表扩容的倍数
public:
    /*构造方法*/
    MyList(){
        nums = new int[numsCapacity];
    }
    /*析构方法*/
    ~MyList(){
        delete[] nums;
    }

    /*获取列表长度(即当前元素数量)*/
    int size(){
        return numsSize;
    }

    //获取列表容量
    int capacity(){
        return numsCapacity;
    }

    //访问元素
    int get(int index){
        //索引如果越界则抛出异常，下同
        if (index < 0 || index >= size())
        {
            throw out_of_range("索引越界");
        }
        return nums[index];
        
    }

    //更新元素
    void set(int index,int num)
    {
        if (index < 0 || index >= size())
        {
            throw out_of_range("索引越界");
        }
        nums[index] = num;
    }
    //中间插入元素
    void insert(int index,int num)
    {
        if (index < 0 || index >= size())
            throw out_of_range("索引越界");
        //元素数量超出容量时，触发扩容机制
        if (size() == capacity())
            extendCapacity();
        //将索引index以及之后的元素都向后移动一位
        for (int j = size() - 1; j >= index; j--)
        {
            nums[j + 1] = nums[j];
        }
        nums[index] = num;

        //更新元素数量
        numsSize++;
    }
    
    //删除元素
    int remove(int index){
        if (index < 0 || index >= size())
            throw out_of_range("索引越界");
        int num = nums[index];

        //索引i之后的元素都向前移动一位
        for (int j = index; j < size() - 1; j++)
        {
            nums[j] = nums[j + 1];
        }
        //更新元素数量
        numsSize--;
        //返回被删除元素
        return num;
        
    }

    //列表扩容
    void extendCapacity(){
        //新建一个长度为原数组extendRatio倍的新数组
        int newCapacity = capacity() * extendRatio;
        int *tmp = nums;
        nums = new int[newCapacity];

        //将原数组的所有元素都复制到新数组
        for (int i = 0; i < size(); i++)
        {
            nums[i] = tmp[i];
        }

        //释放内存
        delete[] tmp;
        numsCapacity = newCapacity;
    }

    //将列表转换为Vector用于打印
    vector<int> toVector(){
        //仅转换有效长度范围内的列表元素
        vector<int> vec(size());
        for (int i = 0; i < size(); i++)
        {
            vec[i] = nums[i];
        }
        return vec;

    }

};

/*
*列表的简易实现
*/

class MyList
{
private:
    /* data */
    int *nums;      //数组(存储列表元素)
    int numsCapacity = 10;
    int numSize = 0;
    int extendRatio = 2;
public:
    /*构造方法*/
    MyList(){
        nums = new int[numsCapacity];
    }
    /*析构方法*/
    ~MyList(){
        delete[] nums;
    }

    //获取列表长度
    int size(){
        return numSize;
    }

    //获取列表容量
    int capacity(){
        return numsCapacity;
    }

    //访问元素
    int get(int index,int num){
        if (index < 0 || index >= size())
            throw out_of_range("索引越界");
        return nums[index];
    }


};
