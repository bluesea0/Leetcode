#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月4日下午4:52:03
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0,cur=0;
        for(auto n:nums){
            if(n){
                cur++;
                ans=max(ans,cur);
            }else cur=0;
        }
        return ans;
    }
};
/*
 * 1.其实这个是非常简单的吧？我看官方题解给的是在遇到0的时候才计算max，我觉得比我好哭泣。我这里每次都要max
 * 2.但是评论区却有人说用双指针？非得搞这么麻烦吗？非得这么卷吗？那我写一下吧。
 * */
class Solution2 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left=0,right=0,ans=0;
        while(right<nums.size()){
            if(nums[right++])continue;
            else{
                //移动左指针
                ans=max(right-left-1,ans);
                left=right;
            }
        }
        return max(ans,right-left);
    }
};
/*
 * 3.双指针解法，实在是太卷了。
 * */
int main(){

    return 0;
}
