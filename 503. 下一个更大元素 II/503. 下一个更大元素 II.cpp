#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年3月9日上午1:38:50
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //单调栈
        //1 2 1 1 2 1
        //两次for循环
        if(nums.empty())return {};
        vector<int> stk,ans(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            while(!stk.empty()&&nums[stk.back()]<nums[i]){
                ans[stk.back()]=nums[i];
                stk.pop_back();
            }
            //if(nums.empty()||nums[i]<nums[stk.back()])
            stk.push_back(i);//等于的话还是要进
        }
        for(int i=0;i<nums.size();i++){
            while(!stk.empty()&&nums[stk.back()]<nums[i]){
                ans[stk.back()]=nums[i];
                stk.pop_back();
            }
        }
        return ans;
    }
};
/*
 * 1.一把子AC了，我太棒了，考察单调栈的知识。
 * 2.原来还有循环数组啊，官方写的很牛，用%来做操，就不用写两个for循环了，我要学习这个。
 * */
int main(){

    return 0;
}
