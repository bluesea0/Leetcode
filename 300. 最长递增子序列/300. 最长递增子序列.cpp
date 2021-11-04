#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月24日下午1:46:45
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //那我只能想到一个O(n^2)的dp解法？
        vector<int> dp(nums.size(),1);
        int ans=1;
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){//从0正序或者这样倒序就是一样的，没区别
            	//还有，你可一定要注意啊，写for循环你是倒序的啊，要--的！！
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(ans,dp[i]);
                }

            }
        }
        return ans;
    }
};
/*
 * 1.AC了，空间复杂度是O(n)，下次复习要写一下贪心+二分。
 * */

//1-25
class Solution {
public:
    vector<int> d;
    int lengthOfLIS(vector<int>& nums) {
        d.push_back(nums[0]);//d[i]表示递增子序列中的值，是按照顺序来的
        for(int i=1;i<nums.size();i++){
            if(nums[i]>d.back())
                d.push_back(nums[i]);
            else {//通过二分查找找到刚好比nums[i]大的数，并且替换它。
                d[helper(nums[i])]=nums[i];
            }
        }
        return d.size();
    }
    int helper(int k){//如果传进来的是有相等的值呢？
        int left=0,right=d.size();
        while(left<right){
            int mid=left+(right-left)/2;
            if(k==d[mid])return mid;
            else if(k>d[mid])
                left=mid+1;
            else right=mid;
        }
        return left;
    }
};
int main(){

    return 0;
}
