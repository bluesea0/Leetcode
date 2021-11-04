#include <iostream>
#include<vector>
#include<queue>
#include<limits.h>//INT_MIN
using namespace std;
//10-10
/*
1.感觉复习用C++写代码最大的阻力就是语法不会啊，比如说这里想用C++中的min值，那是如何表示呢？
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=INT_MIN,cur=0;
        //maxAns = nums[0];官方给的初始化为了0，有道理啊，不需要什么最小值的！
        for(int i=0;i<nums.size();i++){
                //for (const auto &x: nums) 官方是用auto指针遍历的，学到了。
            cur=max(cur+nums[i],nums[i]);
            res=max(res,cur);
        }
        return res;
    }
};
/*
2.Wow，一下AC了，这不错。
3.复杂度：O(n),O(1).
*/


//12-30
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())return 0;
        int cur=nums[0],res=cur;
        for(int i=1;i<nums.size();i++){
            cur=max(cur+nums[i],nums[i]);
            //天哪，我居然不会了这道题，因为我不知道cur该怎么更新，如果像我上面写的这样更新的话
            //就不是连续的子数组了，怎么保证是连续的呢？
            //好难过啊，我又不会了。
            //我觉得是有两种选择：对应当前遍历到的，如果+num[i]值更大了，那么就加上
            //如果值更小了，那么就不加，并且从当前开始计数子数组
            //其实一个很关键的问题是，我都不知道这个cur用来记录什么的。
            res=max(res,cur);
        }
        return res;
    }
};
/*
 * 1.天哪，AC了，不容易啊。。哭唧唧，五分钟前我的心情还是快崩溃，不过我分析出来了。。。
 * 但是这个是动态规划吗？我怎么看不出来呢？子问题？
 * 2.看了题解才发现，原来是子数组问题，dp[i]表示以i为结尾的连续子数组最大和，那么要求max(f[i])。
 *   然后上面的解法是用了滚动数组，绝了啊绝了，原来是这么dp的，所以以后出现动态规划的话，首先要想的就是
 *   dp[i]这个表示了什么。
 * 3.https://www.cnblogs.com/grandyang/p/4377150.html，二分的解法，grand写的蛮好的，下次复习写一下。
 * 4.官方题解提到，这样可以对部分区间做查询，并且在查询量大的时候复杂度降低logn
 *   而且原来复杂度是这么算的啊，我以前都不知道为什么访问树的每一个节点复杂度是O(n)，
 *   原来是根据高度对每个节点求和了，每个节点访问的复杂度是O(logn)!!!
 * */


//5-23
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //一开始我想到的是双指针，不是，是滑动窗口的解法，但是死活想不到left指针该怎么移动
        //然后看到题解才知道是用dp，悟了啊。
        //dp[i]表示以i结尾的连续子数组的和的最大值
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            // if(dp[i-1]>0)dp[i]=dp[i-1]+nums[i];
            // else dp[i]=nums[i];
            dp[i]=max(dp[i-1]+nums[i],nums[i]);//总之一定要有nums[i]
            ans=max(ans,dp[i]);
        }
        //return dp.back();//返回错了，最后一个值并不一定是最大的啊。
        return ans;
    }
};
//居然还可以用二分法？我不太懂了，得复习啊。。。。
int main(){
    Solution s;
    vector<int> v={-2,1,-3,4,-1,2,1,-5,4};
    cout<<s.maxSubArray(v);
    return 0;
}
