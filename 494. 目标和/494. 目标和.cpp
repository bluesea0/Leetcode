#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<numeric>
using namespace std;
//2021年2月18日上午10:31:08
//class Solution {
//public:
//    int findTargetSumWays(vector<int>& nums, int S) {
//        //套用01背包问题，状态包括两个，选[0,i]的组和能否构成和S
//        //我也不知道靠不靠谱，就先这样了
//        //其实首先想到的是dfs，但是我是从0-1背包来的，所以dfs肯定还是要写一个的
//
//        //dp数组的含义：dp[i][j]=表示前i个数能组成和为j的方法数，好像通了啊通了
//        //而现在的选择不是选或不选，而是要选但是是正是负要做选择
//        int m=nums.size();
//        if(S<0)S=-S;
//        vector<vector<int>> dp(m,S+1);
//        //base case是什么？
//        //S是负数，则转换为正数
//        //看这道题的时候就一直被负值困扰，和肯定是有正有负的
//    }
//};

//2-18
//class Solution {
//public:
//    int findTargetSumWays(vector<int>& nums, int S) {
//        //初始数组的和不超过1000，那么对应的负值也不会小于-1000，所以采用数组下标+1000
//        //那申请一个2000的数组，以1000作为原点
//        int m=nums.size(),n=abs(S);
//        vector<vector<int>> dp(m,vector<int>(2001,0));//不对，就算数组短，也有可能
//        //部分和会超过S，所以还是得固定的1000
//        dp[0][n-nums[i]]=1;
//        dp[0][n+nums[i]]=1;
//        for(int i=1;i<m;i++){//遍历物品
//            for(int j=n;j<n*2+1;j++){//遍历背包,从移动后下标为0开始？
//                dp[i][j]=dp[i-1][j-nums[i]]+dp[i-1][j+nums[i]];
//            }
//        }
//        return dp[m-1][1000+S];
//    }
//};
/*
 * 1.按照题解的思路我还是没写下去，官方题解写的不好，另一个题解写得好，按照它的思路我来一下。
 * 2.下面的AC了，可真不容易啊！太难了。
 * */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n=accumulate(nums.begin(),nums.end(),0);
        if(abs(S)>n)return 0;
        int m=nums.size();
        //如果S是负值的话，那么返回谁呢？
        vector<vector<int>> dp(m,vector<int>(2*n+1,0));
        dp[0][n+nums[0]]=1;//就相当于所有的和（下标）都往右平移了n位以保证下标是非负值
        dp[0][n-nums[0]]+=1;//这里是是个坑，如果nums[0]=0的话，那么就需要加上的！
        for(int i=1;i<m;i++){//i表示的是物品
            for(int j=0;j<2*n+1;j++){//j表示的是和，也就是背包容量
                if(j-nums[i]>=0&&j-nums[i]<=2*n)
                    dp[i][j]+=dp[i-1][j-nums[i]];
                if(j+nums[i]>=0&&j+nums[i]<=2*n)
                    dp[i][j]+=dp[i-1][j+nums[i]];
            }
        }
//        for(int i=0;i<m;i++){
//        	for(int j=0;j<2*n+1;j++){
//        		cout<<dp[i][j]<<" ";
//        	}
//        	cout<<endl;
//        }
        return dp[m-1][n+S];
    }
};
//下面是进行空间优化的
class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n=accumulate(nums.begin(),nums.end(),0);
        if(abs(S)>n)return 0;
        int m=nums.size();
        //如果S是负值的话，那么返回谁呢？
        vector<int> dp(2*n+1,0);
        dp[n+nums[0]]=1;//就相当于所有的和（下标）都往右平移了n位以保证下标是非负值
        dp[n-nums[0]]+=1;//这里是是个坑，如果nums[0]=0的话，那么就需要加上的！
        for(int i=1;i<m;i++){//i表示的是物品
            vector<int> temp(2*n+1,0);//这里要初始化一个全新的！
            for(int j=0;j<2*n+1;j++){//j表示的是和，也就是背包容量
                if(j-nums[i]>=0&&j-nums[i]<=2*n)
                    temp[j]+=dp[j-nums[i]];
                if(j+nums[i]>=0&&j+nums[i]<=2*n)
                    temp[j]+=dp[j+nums[i]];
            }
            dp=temp;
        }
        return dp[n+S];
    }
};
/*
 * 1.优化之后的坑，temp要初始化为全0的，而不是赋值为dp！
 * */
//dfs：
class Solution３ {
public:
    int ans=0;
    int findTargetSumWays(vector<int>& nums, int S) {
        //写一下dfs+记忆数组，grand用了记忆数组，但是它那个结构好复杂，我先不看了
        //朴素版本的dfs，AC了，不过很慢。
        dfs(nums,S,0,0);
        return ans;
    }
    void dfs(vector<int>& nums,int S,int index,int sums){
        if(index==nums.size()){
            if(sums==S)
                ans++;
            return;
        }
        dfs(nums,S,index+1,sums-nums[index]);
        dfs(nums,S,index+1,sums+nums[index]);
    }
};
int main(){
	Solution s;
	vector<int> nums={0,0,0,0,0,0,0,0,1};
	cout<<s.findTargetSumWays(nums, 1);
    return 0;
}
