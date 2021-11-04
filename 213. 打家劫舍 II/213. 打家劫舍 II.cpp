#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月1日上午11:53:38
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        return max(helper(0,nums.size()-2,nums),helper(1,nums.size()-1,nums));
    }
    int helper(int fr,int to,vector<int>&nums){
        if(fr==to)return nums[fr];
        int dp0=nums[fr];
        int dp1=max(nums[fr+1],dp0);
        for(int i=fr+2;i<=to;i++){
            int t=max(dp0+nums[i],dp1);
            dp0=dp1;
            dp1=t;
        }
        return dp1;
    }
};//AC了
int main(){

    return 0;
}
