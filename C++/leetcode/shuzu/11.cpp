#include <vector>
#include <iostream>
using std::vector;
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0,r = 0;
        int count = 1,r_ = 0;
        bool flag = true;
        while(r < nums.size()){
            if(!flag)
                l = r_;
            for( r = l+1; r < nums.size();r++){
                if(nums[l] == nums[r])
                    continue;               //r指针只有两种结果，值相同，计数+1，值不同，左指针移动
                else
                    ++count;
                    flag = false;
                    r_ = r;
                    break;
            }
        }
        return count;
    }
};


int main(){
    Solution solution;
    // vector<int> gas = {0,0,1,1,1,2,2,3,3,4};
    vector<int> gas = {1,1,2};
    vector<int> cost = {3,4,5,1,2};
    cout << solution.removeDuplicates(gas) << endl;
    
    

}