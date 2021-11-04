#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月1日上午10:11:55
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size(),0);
        //没有判断边界case
        dp[0]=nums[0];
        dp[1]=max(nums[1],dp[0]);
        for(size_t i=2;i<dp.size();i++){
            //但是这里i==1时如何处理？还需要再判断正负号？
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp.back();
    }
};
/*
 * 1.AC了，本来是这样的，边界情况的处理和for循环，确实是这么开始的！官方给的解答中也是这么处理的！
 * 2.因为计算当前，只和i-2和i-1有关系，所以只需要判断这两种情况即可。
 * */
//滚动数组
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        int dp0=nums[0];
        int dp1=max(nums[1],dp0);
        for(size_t i=2;i<nums.size();i++){
            int t=max(dp0+nums[i],dp1);
            dp0=dp1;
            dp1=t;
        }
        return dp1;
    }
};//时间上击败了100%！！！
int main(){

    return 0;
}
