#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string_view>
#include <unordered_set>
#include <numeric>
using namespace std;
using std::vector;
using std::accumulate;
using std::unordered_set;
// using std::string_view;

// class Solution
// {
// private:
//     /* data */
// public:
//     vector<int> twosum(vector<int>& nums,int target){
//         unordered_map<int,int> m;       //初始化一个哈希表对象
//         for (int i = 0; i < nums.size(); i++)           //遍历数组，完成数组nums和哈希表的转换
//         {
//             m[nums[i]] = i;            //哈希表m的key是数组的value，哈希表的value是数组的索引
//         }
//         for (int i = 0; i < nums.size(); i++)
//         {
//             auto complement = m.find(target - nums[i]);
//             if (complement != m.end() && complement ->second > i)
//             {
//                 return(i,complement->second);
//             }
//         }
//         return (-1,-1);
//     }
// };
// Two Sum
// 方法2：HashMap + 两次遍历。用一个哈希表，存储每个数对应的下标
// Time Complexity: O(n)，Space Complexity: O(n)
// class Solution {
// public:
//     vector<int> twosum(vector<int>& nums, int target) {
//         unordered_map<int, int> m;
//         for (int i = 0; i < nums.size(); i++) {
//             m[nums[i]] = i;
//         }
//         for (int i = 0; i < nums.size(); i++) {
//             auto complement = m.find(target - nums[i]);
//             if (complement != m.end() && complement->second > i) {
//                 return {i, complement->second};
//             }
//         }
//         return {-1, -1};
//     }
// };

//88合并两个有序数组
// class Solution
// {
// public:
//     void merge(vector<int>& nums1,int m,vector<int>& nums2,int n){
//             int pos = m-- + n-- - 1;
//             while (m >=0 && n >=0)
//             {
//                 nums1[pos--] = nums1[m]>nums2[n]?nums1[m--]:nums2[n--];
//             }
//             while (n >= 0)
//             {
//                 nums1[pos--] = nums2[n--];
//             } 
//     }
// };

//142 环形链表2**************************************************

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x),next(nullptr){}      //构造函数
// };


// ListNode *detectCycle(ListNode *head){
//     ListNode *slow = head,*fast = head;
//     //循环判断是否存在环路
//     do
//     {
//         if (!fast || !fast->next)
//         {
//             return nullptr;
//         }
//         fast = fast->next->next;      //fast指针一次走两步
//         slow = slow->next;
//     } while (fast != slow);
//     //如果存在环路
//     fast = head;    //fast指针回归头节点
//     while (fast != slow)
//     {
//         slow = slow->next;
//         fast = fast->next;
//     }
//     return fast;
// }

//76 最小覆盖子串**************************************************

// string minWindow(string S, string T) {
//     vector<int> chars(128, 0);
//     vector<bool> flag(128, false);
//     // 先统计T中的字符情况
//     for(int i = 0; i < T.size(); ++i) {    
//         flag[T[i]] = true;              //A的ascii码是65        flag表示是否存有该位置ascii码的字符
//         ++chars[T[i]];                  //char表示该位置的字符的数量
//     }
//     // 移动滑动窗口，不断更改统计数据
//     int cnt = 0, l = 0, min_l = 0, min_size = S.size() + 1;
//     for (int r = 0; r < S.size(); ++r) {       //min_size = 13+1 = 14   遍历S字符串中所有位置的字符
//         if (flag[S[r]]) {                      //若存在的话，
//             if (--chars[S[r]] >= 0) {          //若数目非0的话
//                 ++cnt;
//                 }
//                 // 若目前滑动窗口已包含T中全部字符，
//                 // 则尝试将l右移，在不影响结果的情况下获得最短子字符串
//                 while (cnt == T.size()) {
//                     if (r - l + 1 < min_size) {
//                         min_l = l;
//                         min_size = r - l + 1;
//                     }
//                     if (flag[S[l]] && ++chars[S[l]] > 0) {
//                         --cnt;
//                     }
//                     ++l;
//                 }
//             }
//         }
//     return min_size > S.size()? "": S.substr(min_l, min_size);      //提取字符串的子字符串
// }


//76 最小覆盖子串********************************哈希+滑动窗口********************************
// class Solution {
// public:
//     //定义两个哈希表，tstr用来存放t中元素的出现次数信息，sstr用来存放滑动窗口中元素的出现次数信息
//     unordered_map<char,int> tstr,sstr;

//     //检查当前的窗口是否是合格的窗口，即：
//     //检查当前滑动窗口中元素是否完全覆盖了字符串t中的所有元素（重点是某元素的出现次数必须不小于t中对应元素的出现次数）
//     bool check()
//     {
//         for(auto tchar : tstr)
//             {
//                 if(tchar.second > sstr[tchar.first]) return false;//注意这里的判断条件是大于
//                 //只要sstr中元素的second值不小于tchar中对应元素的second值就行
//             }
//         return true;
//     }

//     string minWindow(string s, string t) {
//         int n1 = s.size(),n2 = t.size();
//         if(n1<n2) return "";//如果t串比s串还长，s中肯定不能找到相应的子串
//         int len = 0;//最小窗口的长度
//         int ans_left = -1;//最小窗口的左边界指针
//         //构造哈希表
//         for(auto tchar : t)
//             ++tstr[tchar];
        
//         int left = 0,right = 0;//窗口的左右两端指针
//         //滑动窗口右端指针遍历整个s串
//         for(int right = 0;right<n1;right++)
//         {   
//             //每遍历一个元素，更新sstr中的元素信息
//             ++sstr[s[right]];
//             //如果当前遍历到的元素在tstr中也有，说明此次遍历的更新是有效的更新，否则不用管，直接继续遍历
//             if(tstr.find(s[right]) != tstr.end())
//             { 
//                 //对于每一次有效的更新，检查当前窗口中的子串是否是一个合格的子串
//                 while(check() && left<=right)
//                 {
//                     //如果当前子串是合格的，那么判断是否是最小的窗口
//                     if(len > right - left +1)
//                     {
//                         //如果是最小的窗口，那么更新窗口信息
//                         ans_left = left;
//                         len = right - left + 1;
//                     }

//                     //当前子串如果是合格的，那么尝试移进窗口的左边界缩短窗口的长度
//                     --sstr[s[left]];//窗口左边界的元素信息从哈希表sstr中删除
//                     left++;//移进窗口左边界

//                     //移进之后，继续while判断移进后的子串是否是合格的，如果是合格的，继续重复同样的操作，更新窗口的信息
//                 }

//                 //一旦窗口不合格，窗口右边界的指针就继续往后遍历，拓宽窗口的长度
//             }
//         }
//         if(ans_left == -1) return "";
//         else return s.substr(ans_left,len);
//     }
// };

//680 验证回文串II***********************************************************************************
//大佬
class Solution {
public:
    bool palindrome(const std::string& s, int i, int j)
    {
        for ( ; i < j && s[i] == s[j]; ++i, --j);
        return i >= j;
    }

    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        for ( ; i < j && s[i] == s[j]; ++i, --j);        
        return palindrome(s, i, j - 1) || palindrome(s, i + 1, j);
    }
};


//官方：贪心算法
class Solution {
public:
    bool checkPalindrome(const string& s, int low, int high) {
        for (int i = low, j = high; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int low = 0, high = s.size() - 1;
        while (low < high) {
            char c1 = s[low], c2 = s[high];
            if (c1 == c2) {
                ++low;
                --high;
            } else {
                return checkPalindrome(s, low, high - 1) || checkPalindrome(s, low + 1, high);
            }
        }
        return true;
    }
};

//伟吉复刻
class Solution {
public:
    bool check(string s,int left, int right)
    {
        for( int i = left, j = right; i < j; i++,j--)
        {
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left = 0,right = s.size() - 1;
        while(left <  right)
        {
            if (s[left] == s[right]){
                ++left;
                --right;
            }
            else{
                return (check(s,left + 1, right) || check(s,left,right - 1));
            }
        }
        return true;
    }
};

//680 验证回文串II***********************************************************************************


//524 通过杉树字母匹配到字典里最长单词***********************************************************************************
//大佬
bool cmp(string &x,string &y){
        if(x.size()==y.size())
            return x < y;
        return x.size() > y.size();
    }
class Solution {
public:
    bool check(string &s,string &str){      //s:s字符串   str:字典字符串
        int base=0;
        //利用双指针，结合find()函数，两个字符串中检索公共字符
        for(int i=0;i<str.length();++i){        //逐一扫描当前dictions字符串中的每个字符，是否在s中出现
            //从s中的base开始第一次出现str[i]的位置，若没有出现，则代表
            //str中有s中所没有的字符，当前str并不是s的最大子字符串，反之
            if(s.find(str[i],base)==string::npos)       
                return false;
            else{
                //如果存在的话，s中的扫描指针往后移动一个单位。
                base = s.find(str[i],base)+1;
            }
        }
        return true;
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(),dictionary.end(),cmp);
        for(int i=0;i<dictionary.size();++i){
            if(check(s,dictionary[i]))
                return dictionary[i];
        }
        return "";
    }
};


//455 分发饼干***********************************************************************************
//伟吉复刻
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int children = 0, binggan = 0;
        while(children < g.size() && binggan < s.size()){
            if(g[children] <= s[binggan])
            {
                ++children;
                
            }
            ++binggan;
        }
        return children;
    }
};

//大佬
class Solution {
public:

    void quick(vector<int>& nums,int l,int r){
        if(l>=r) return ;
        int i=l-1,j=r+1,x=nums[l+r>>1];
        while(i<j){
            do i++; while(nums[i]<x);
            do j--; while(nums[j]>x);
            if(i<j) swap(nums[i],nums[j]);
        }
        quick(nums,l,j);
        quick(nums,j+1,r);
    }

    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans=0;
        int glen=g.size(),slen=s.size();
        //quick(g,0,glen-1);
        //quick(s,0,slen-1);
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(int i=0,j=0;i<glen&&j<slen;){
            if(s[j]>=g[i]) {
                ans++;
                i++;
                j++;
            }
            else j++;
        }
        return ans;
    }
};
//455 分发饼干***********************************************************************************

//135 分发糖果***********************************************************************************
//伟吉复刻
class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if(size < 2)
            return size;
        vector<int> num(size,1);        //将每个孩子的苹果数目先初始化为1
        for(int i = 0;i < size-1; ++i){
            if(ratings[i] < ratings[i+1])   //从左向右遍历，后边的更新
                num[i+1] = num[i] + 1;
        }

        for(int i = size-1; i >0 ; --i){
            if(ratings[i-1] > ratings[i])
                num[i-1] = max(num[i-1],num[i]+1);           // ++num[i-1];
        }
        //#include <numeric>
        //using std::accumulate;
        return  accumulate(num.begin(),num.end(),0);        
    }

};

//大佬
class Solution {
public:
    //首先构造一个数组表示每个孩子的糖果数量，初始为1
    //如何遍历？
    //把孩子们的表现想象成一条上下波动的折线，那么总的来说，只有单调增和单调减两种情况
    //修改孩子们糖果的数量要看当前孩子和两侧的表现情况，两侧都看会很混乱，可以两次遍历，一次解决单调增，一次解决单调减
    //只有表现更大才会修改糖果数量，否则不会改，因此判断条件永远是当前孩子的表现大于左边或者右边的
    //对单调增，如1-2-3-4，想要据此修改糖果只能右减左，且必须从前往后遍历；如果从后往前，糖果数量会变成1-2-2-2，不符合题意
    //同理对单调减只能从后往前遍历，其实就是必须从表现较小的遍历到表现较大的，否则无法把低层的比较信息传到高层
    //因此，分两次遍历，方向也要相反
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1) return 1;
        vector<int> candyNum(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            //处理单调增
            if (ratings[i] > ratings[i - 1]) candyNum[i] = candyNum[i - 1] + 1;
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {
            //处理单调减
            if (ratings[i] > ratings[i + 1]) {
                candyNum[i] = max(candyNum[i], candyNum[i + 1] + 1);
                //max是为了保留第一次遍历的信息
            }
        }
        int sum = 0;
        for (int n : candyNum) {
            sum += n;
        }
        return sum;
    }
};

//135 分发糖果***********************************************************************************

//435 无重叠区间***********************************************************************************
//伟吉复刻
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if(intervals.empty())
            return 0;
        //注意a,b前的引用，能让代码有质的提升
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){ return a[1] < b[1];});        //lambda表达式，按照右边界排序  

        int total = 0, prev = intervals[0][1];
        for(int i = 1;i < size; ++i ){
            if(intervals[i][0] < prev){
                ++total;
            }
            else{
                prev = intervals[i][1];
            }

        }

        return total;
    }
};

//大佬1
class Solution {
public:
    static bool cmp(const vector<int>&a,const vector<int>&b){       //为sort函数设定了一个排序规则
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);                //按照区间尾部进行升序排列
        int result=1;
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=end){                               //result存放的是最终不重叠数组的个数
                result++;                                           //不重叠，数目+1，指针后移
                end=intervals[i][1];
            }
        }
        return intervals.size()-result;


    }
};

//大佬2
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //新一个的start < 前一个的尾  说明有重叠
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){return a[1] < b[1];});
        int ans = 0;
        int prev_tail = intervals[0][1];
        for(int i = 1;i < intervals.size();i++)
        {
            if(intervals[i][0] < prev_tail){
                ans++;
            }else{
                prev_tail = intervals[i][1];
            }
        }
        return ans;
    }
};
//435 无重叠区间***********************************************************************************

//605 种花问题***********************************************************************************
//伟吉复刻
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0,len = flowerbed.size();
        for(int i=0;i<len;i++){
            if(flowerbed[i]==0){
                bool a = i-1<0? true:flowerbed[i-1]==0;
                bool b = i+1>=len? true:flowerbed[i+1]==0;
                if(a && b){
                    flowerbed[i]=1;
                    cnt++;
                }
            }
        }
        return cnt>=n;
    }
};
//605 种花问题***********************************************************************************

//452 用最少数量的箭引爆气球***********************************************************************************
//大佬1
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() <= 1) {
            return points.size();
        }
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        // 发射点设置为区间最右侧的点
        int pos = points[0][1];
        int arrows = 1;
        for (int i = 1; i < points.size(); i++) {
            auto curr = points[i];
            if (curr[0] > pos) {
                pos = curr[1];      //增加箭束，移动指针
                ++arrows;
            }
        }

        return arrows;
    }
};
//大佬二
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& u, vector<int>& v){
            return u[1] < v[1];
        });
        int ans = 1;
        int pos = points[0][1];         
        for(int i = 0; i < points.size(); i++){
            if(points[i][0] > pos){             //一旦不满足区间重叠，剑束的数目+1，pos指针切换到当前point
                ans++;
                pos = points[i][1];
            }
        }
        return ans;
    }
};
//452 用最少数量的箭引爆气球***********************************************************************************

//122 买卖股票的最佳时机II***********************************************************************************
//大佬
class Solution {

public:

    int maxProfit(vector<int>& prices) {

        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {

            int tmp = prices[i] - prices[i - 1];

            if (tmp > 0) profit += tmp;

        }

        return profit;

    }

};

//伟吉
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 1; i < prices.size(); i++){
            int tmp = prices[i] - prices[i-1];
            if (tmp > 0)
            {
                profit += tmp;
            }
            
        }
        return profit;

    }
};
//122 买卖股票的最佳时机II***********************************************************************************

//763 划分字母区间***********************************************************************************
//大佬
class Solution {
public:
    vector<int> partitionLabels(string s) {

        vector<int> al(26,0);       //针对26个字母初始化

        for(int i=0;i<s.size();++i)al[s[i]-'a']++;      //相对位置索引存放频率直方图

        int st=0;                       //输出数目
        vector<int> ret;
        unordered_set<char> us;         //不重复字符容器

        for(int i=0;i<s.size();++i)     //开始遍历字符串
        {   
            char c=s[i];
            us.insert(c);       //插入元素
            al[c-'a']--;        //相对位置索引去频率
            //判断频率直方图中当前字母是否频率为0
            //若为0，
            if(al[c-'a']==0)    
            {
                 bool flag=true;
                 for(auto &it:us)
                 {
                     if(al[it-'a']!=0)flag=false;       //则开始判断是否当前容器中所有字符串都不会再出现
                 } 
                 if(flag)       //若不会再出现，则向量存储容器中字符数目
                 {
                    ret.push_back(i-st+1);
                    st=i+1;
                    us.clear();     //移除所有元素
                 }      
            }
        }
        return ret;
    }
};

//大佬
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26];
        int n = s.size();
        for (int i = 0; i < n; ++i){
            last[s[i]-'a'] = i;
        }
        int max_end = 0;
        int start = 0;
        vector<int> ret;
        for (int i = 0; i < n; ++i){
            max_end = std::max(max_end, last[s[i]-'a']);
            if (i == max_end){
                ret.emplace_back(max_end - start+1);
                start = i+1;
            }
        }
        return ret;
    }
};

//伟吉
class Solution {
public:
    vector<int> partitionLabels(string s) {
            vector<int> pin_lv(26,0);
            for(int i = 0; i < s.size(); i++)
                pin_lv[s[i] - 'a']++;

            int jishu = 0;
            vector<int> output;     //默认初始化
            unordered_set<char> zifu;   //初始化存放字符的容器
            for(int i = 0;i < s.size();i++){
                char c = s[i];
                zifu.insert(c);
                pin_lv[c - 'a']--;
                if(pin_lv[c - 'a'] == 0){               //检查之前的所有字符是否都达到了频率零值
                    bool flag = true;
                    for(auto &t : zifu){
                        if (pin_lv[t - 'a'] != 0) {      //当前容器中有字符没有达到
                            flag = false;
                        }    
                    } 
                    if(flag){
                            output.push_back(i - jishu + 1 );
                            jishu = i + 1;
                            zifu.clear();
                        }
                    }
            }
            return output; 
    }
};
//763 划分字母区间***********************************************************************************



//665 非递减数列***********************************************************************************
//伟吉(笨的离谱) 击败 18.59%
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int positive = 0;       //存储正增长个数
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i+1]){
                positive++;
                if((i < nums.size() -2) && (nums[i] > nums[i+2]) && (i >=1 ) && (nums[i-1] > nums[i+1]))
                positive++;
            }
            
        }
        return (positive <= 1);
    }
};

//大佬
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                //nums[i]不符合要求
                cnt++;
                if(cnt>1) return false;
                if(i-2>=0 &&nums[i]<nums[i-2]){     //此时反正已经是下降了
                    nums[i]=nums[i-1];              //那就修改一次，因为此时的cnt如果没有false，必定是1，下次再有下降就直接跳false了，
                }else{                              //兼顾前面第二个的值，如果比他小的话，就改前一个值，这样就可以保证修正后的非递减了
                    nums[i-1]=nums[i];              //如果比他大的话，改这个值
                }
            }
        }
        return true;

    }
};
//665 非递减数列***********************************************************************************

//贪心算法专题
//11 盛最多水的容器***********************************************************************************
//伟吉
/****************************************************************************************************
*明确：1、本题的贪心算法的局部最优，从哪里找？
*     2、为什么每次移动数值偏小的指针~~~
*
*
*
*
****************************************************************************************************/
class Solution {
public:
    int maxArea(vector<int>& height) {
        //无敌双指针，启动！！！
        int l = 0, r = height.size() - 1;
        int ans = 0,mianji = 0;
        

        while(l < r){
            mianji = min(height[l],height[r]) * (r - l);    //初始化面积
            ans = max(ans,mianji);
            if(height[l] <= height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};
//11 盛最多水的容器***********************************************************************************

//11 盛最多水的容器***********************************************************************************
/****************************************************************************************************
*明确：1、本题的局部
*     2、
*
*
*
*
*
****************************************************************************************************/
//伟吉:写得挺好，就是没有应付得了000000000的超时，下次别写了
class Solution {
public:

    bool areAllZeros(const std::vector<int>& vec) {  
        return std::all_of(vec.begin(), vec.end(), [](int n) { return n == 0; });}  

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int c = 0;
            
            if(areAllZeros(gas) || areAllZeros(cost)) return 0;

            for(int i = 0; i < gas.size(); ++i){       //遍历加油站
                bool chufa = false;
                if(gas[i] >= cost[i]){       //如果满足起始发车条件
                    chufa = true;
                }
                if(chufa){
                    int j = i;
                    int count = 0;              //存放加油站数目
                    int youliang = 0;
                    while(youliang >= 0){
                        youliang += gas[j];         //加油
                        if(count == gas.size())     //遍历加油站，跳出
                            return i;
                        youliang -= cost[j];     //耗油
                        j++;
                        count++;
                        if(j == gas.size())      //开启回环
                            j = 0;
                        }
                    }
        }
        return -1;    
    }
};

//大佬
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n) {
            int sumOfGas = 0, sumOfCost = 0;
            int cnt = 0;
            while (cnt < n) {
                int j = (i + cnt) % n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if (sumOfCost > sumOfGas) {
                    break;
                }
                cnt++;
            }
            if (cnt == n) {
                return i;
            } else {
                i = i + cnt + 1;
            }
        }
        return -1;
    }
};


//15 三数之和***********************************************************************************
/****************************************************************************************************
*明确：1、本题的局部
*     2、
*
****************************************************************************************************/
//大佬
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举 a
        for (int first = 0; first < n; ++first) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            // 枚举 b
            for (int second = first + 1; second < n; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};

//大佬
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    //    重点注意需要去重
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            int left=i+1,right=n-1;
            if(i>0&&nums[i]==nums[i-1])continue;
            while(left<right){
                if(nums[i]+nums[left]+nums[right]>0)
                    right--;
                else if(nums[i]+nums[left]+nums[right]<0)
                    left++;
                else{
                    res.push_back({nums[i],nums[left],nums[right]});
                    while(left<right&&nums[left]==nums[left+1])left++;
                    while(right>left&&nums[right]==nums[right-1])right--;
                    right--;
                    left++;
                }
            }
        }
        return res;
    }
};
//15 三数之和***********************************************************************************
//伟吉
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sizee = nums.size();
        vector <vector<int>> ans;
        for( int first = 0; first < sizee;first++){
            //保证这次与上次指向的数目不同
            if(first > 0 && nums[first] == nums[first-1])
                continue;           //跳过剩余程序
            int third = sizee - 1;      //
            int count = -nums[first];           //将三值问题转换为两值的双指针
            //枚举b
            for (int second = first+1; second < sizee; second++){
                if(second > first +1 && nums[second] == nums[second - 1]){
                    continue;
                }
                //保证bc指针的排位顺序
                while(second < third && nums[second] + nums[third] > count)
                    --third;
                
                //如果指针重合，随着b后续增加，无论如何都不会有second + third = -first
                if(second == third)
                    break;      //退出本次的second循环
                
                if(nums[second] + nums[third] == count)
                    ans.push_back({nums[first],nums[second],nums[third]});
            }
        }
        return ans;
    }
};

//26 删除有序数组的重复项***********************************************************************************
/****************************************************************************************************
*Author：ddjw007 
*明确：1、本题的局部
*     2、
*
****************************************************************************************************/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int check =1,keep = 1;      //初始化双指针
        while(check < nums.size()){
            if(nums[check] != nums[check-1]){
                nums[keep] = nums[check];
                ++keep;
            }
            ++check;
        }
        return keep;
    }
};

//31 下一个排列***********************************************************************************
//官方
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

//大佬
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size=nums.size();
        int cur=size-2;     //指向倒数第2个值的索引
        while(cur>=0&&nums[cur]>=nums[cur+1]) cur--;
        if(cur<0)
            sort(nums.begin(),nums.end());          //排序
        else{
            int pos=size-1;
            while(pos>=0&&nums[pos]<=nums[cur]) pos--;
            swap(nums[pos],nums[cur]);              //交换
            reverse(nums.begin()+cur+1,nums.end()); //翻转
        }
    }
};
//31 下一个排列***********************************************************************************


//3014 输入单词需要的最少按键次数***********************************************************************************
//伟吉
class Solution {
public:
    int minimumPushes(string &word) {
        int len = word.length();
        int k = len / 8;
        return (4 * k + len % 8) * ( k + 1);
    }
};
//3014 输入单词需要的最少按键次数***********************************************************************************

//1663 具有给定数值的最小字符串***********************************************************************************
//伟吉
class Solution {
public:
    string getSmallestString(int n, int k) {
        // 思路：贪心，先尽可能的填z
        string ans(n, 'a');
        k -= n;
        for(int i = n- 1; i>=0; i--){
            if(k > 25){
                k-= 25;
                ans[i] = 'z';
            }else{
                ans[i] = (char)('a' + k);
                break;
            }
        }
        return ans;
    }
};

//75 颜色分类***********************************************************************************
//冒泡排序 时空间复杂度：   O(n^2 / 1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 通过bool类型进行优化
        bool flag = true;
        // 冒泡排序
        int n = nums.size();

        // 利用flag判断是否提前排序完毕
        for (int i = 0; i < n && flag; i++) {
            flag = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    int tmp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = tmp;
                    // 如果发生了交换，则说明数组还未有序，需要继续遍历
                    flag = true;
                }
            }
        }
    }
};

//快速排序  时空间复杂度O(nlogn / 1)
class Solution {
public:
    // 快速排序
    void QuickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int start = left, end = right;
        // 设定交换基准
        int pivot = nums[left];

        while (left < right) {
            while (left < right && nums[right] >= pivot) right--;
            nums[left] = nums[right];
            while (left < right && nums[left] <= pivot) left++;
            nums[right] = nums[left];
        }
        // 最后基准左侧都比它小，右侧则大
        nums[left] = pivot;

        // 分治法划分两个部分，分别再次排序
        QuickSort(nums, start, left - 1);
        QuickSort(nums, left + 1, end);
    }

    void sortColors(vector<int>& nums) {
        QuickSort(nums, 0, nums.size() - 1);
    }
};

//插入排序  时空间复杂度O(n^2 / 1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 插入排序
        // ps.插入排序是将一个个元素排好位置最终有序的
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] > nums[j + 1]) {
                    int tmp = nums[j + 1];
                    nums[j + 1] = nums[j];
                    nums[j] = tmp;
                }
            }
        }
    }
};

//双指针    时空间复杂度O(n/1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 双指针法
        int n = nums.size();
        int p0 = 0, p2 = n - 1;
        // 以p2为循环终点
        for (int i = 0; i <= p2; i++) {
            while (i <= p2 && nums[i] == 2) {
                swap(nums[i], nums[p2]);
                --p2;
            }
            while (p0 <= i && nums[i] == 0) {
                swap(nums[i], nums[p0]);
                ++p0;
            }
        }
    }
};


// int main(){
    
//     // Solution solution;
//     // vector<int> nums = {2,7,11,15};
//     // int target = 9;
//     // vector<int> result = solution.twosum(nums,target);
//     // cout<< "[" ;
//     // auto dd = result.begin();
//     // for (auto t : result)
//     // {
//     //     cout<< t ;
//     //     if ( dd != result.end())
//     //     {
//     //         cout <<",";
//     //     }
//     // }
//     // cout << "]" << endl;
//     // // int a =0;
//     // // int b=11;
//     // // cout << "Hello World!" << endl;
//     // // return 0;
//     ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//     // Solution Solution;
//     // vector<in

//     //76 最小覆盖子串**************************************************
//     // string S = "ADOBECODEBANC";
//     // string T = "ABC";
//     // string m = minWindow(S,T);
//     // // for (auto c : m)
//     // // {
//     // //     cout << m;
//     // // }
//     // cout << m << endl;


    

    
// }