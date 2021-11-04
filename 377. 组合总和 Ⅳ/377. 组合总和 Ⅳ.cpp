#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年6月19日下午7:43:09
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //背包问题，回溯会超时
        //dp[i]容量为i的组合数，dp[i]=dp[i]+dp[i-j]
        vector<int> dp(target+1,0);
        dp[0]=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<=target;i++){//遍历容量
            for(auto& n:nums){
                if(n>i||dp[i-n]>INT_MAX-dp[i])break;
                dp[i]+=dp[i-n];
            }
        }
        return dp.back();
    }
};
/*
 * 1.过了14/15个用例，题目说“题目数据保证答案符合 32 位整数范围。”，但是中间结果可能会超INT表示范围。
 *   所以添加上了if判断，dp[i-n]>INT_MAX-dp[i]则break掉。
 * 2.是排序的完全背包问题，需要考虑物品的先后顺序，可以重复，那么就遍历容量，如果不让结果重复，那就先遍历
 *   物品，保证物品放入的顺序有先后就不会重复。
 * */
int main(){

    return 0;
}
