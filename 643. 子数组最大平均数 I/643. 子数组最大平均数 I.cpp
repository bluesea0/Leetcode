#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月4日下午3:05:30
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left=0,right=0,ans=INT_MIN,cur=0;//[-1] 1 有这样的啊，那我这初始化有问题
        while(right<nums.size()){
            cur+=nums[right++];
            if(right-left==k){
                ans=max(ans,cur);
                cur-=nums[left++];
            }
        }
        return ans*1.0/k;
    }
};
/*
 * 1.注意初始化的问题啊，我的天，你将ans初始化为0，但是数组可能全是负数，这不是你第一次遇到这样的问题了！
 *   初始化为INT_MIN啊。这个还有困难版644题，不过是会员，你看看grand的解法吧。
 * */
int main(){

    return 0;
}
