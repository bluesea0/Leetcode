#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月17日下午2:22:23
//class Solution {
//public:
//    bool canPartition(vector<int>& nums) {
//        sort(nums.begin(),nums.end());
//        int left=0,right=nums.size()-1;
//        int sums=accumulate(nums.begin(),nums.end(),0);
//        while(left<right){
//            //天哪忽然感觉这样不行，因为针对
//            //[1,5,5,11]这个是前后分开的，应该用滑动窗口
//            //[1,5,5,9]这个样例是滑窗肯定不行了，似乎应该用双指针，所以我的解法是错的啊
//            //这个题目又怎么能和背包问题牵扯起来呢？
//        }
//    }
//};
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //状态是：元素和目标值，0/1数组
        //dp[i][j]表示前i个元素能否组合成和为j的子集
        if(nums.size()<2)return false;//如果只有一个元素或者没有元素，那么不能分成两个子集
        //那其中一个子集为空可以吗？
        int sums=accumulate(nums.begin(),nums.end(),0);
        if(sums&1)return false;//如果是奇数拿肯定不行
        //求数组中的最大值，如果最大值>sums/2
        int target=sums/2;
        int maxn=nums[0],m=nums.size();
        for(int i=1;i<nums.size();i++)
            maxn=max(maxn,nums[i]);
        if(maxn>target)return false;//因为只包含正整数，所以不能分割为两个了
        vector<vector<int>> dp(m,vector<int>(target+1,0));//这里要target+1吧？
        dp[0][nums[0]]=1;//当只能选第0个元素时，能形成和为nums[0]的背包
        for(int i=0;i<m;i++)
            dp[i][0]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<=target;j++){
                if(nums[i]<=j){//可以放下当前元素，那么就放或者不放
                    //我忽然又对这个dp数组状态的含义模糊了，不太懂怎么计算啊
                    dp[i][j]=dp[i-1][j-nums[i]]||dp[i-1][j];//放或者不放
                }else{//如果放下当前的nums[i]，那肯定会超j，超出容量，
                    dp[i][j]=dp[i-1][j];//只能不放
                }
            }
        }
        return dp[m-1][target];
    }
};
/*
 * 1.AC了，不过还是挺难的啊，接下来写一下状态压缩的，节省空间的
 * */
class Solution2 {
public:
    bool canPartition(vector<int>& nums) {
        //状态是：元素和目标值，0/1数组
        //dp[i][j]表示前i个元素能否组合成和为j的子集
        if(nums.size()<2)return false;//如果只有一个元素或者没有元素，那么不能分成两个子集
        //那其中一个子集为空可以吗？
        int sums=accumulate(nums.begin(),nums.end(),0);
        if(sums&1)return false;//如果是奇数拿肯定不行
        //求数组中的最大值，如果最大值>sums/2
        int target=sums/2;
        int maxn=nums[0],m=nums.size();
        for(int i=1;i<nums.size();i++)
            maxn=max(maxn,nums[i]);
        if(maxn>target)return false;//因为只包含正整数，所以不能分割为两个了
        vector<int> dp(target+1,0);//这里要target+1吧？
        dp[0]=1;
        dp[nums[0]]=1;//当只能选第0个元素时，能形成和为nums[0]的背包
        for(int i=1;i<m;i++){
            for(int j=target;j>=1;j--){
                if(nums[i]<=j){//可以放下当前元素，那么就放或者不放
                    //我忽然又对这个dp数组状态的含义模糊了，不太懂怎么计算啊
                    dp[j]=dp[j-nums[i]]||dp[j];//放或者不放
                }
                // else{//如果放下当前的nums[i]，那肯定会超j，超出容量，
                //     dp[j]=dp[j];//如果是只一个状态的话，那这个就不必有了啊
                // }
            }
        }
        return dp[target];
    }
};//非常好改，也AC了。

//6-11
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        /*
        转换为01背包问题，
        dp[i][j]表示前i个数中的和能否==j，布尔数组
        dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i]] nums[i]<=j
        base case:
        dp[0][0]=1
        dp[i][0]=0
        */
        if(nums.size()==1)return false;
        int sums=accumulate(nums.begin(),nums.end(),0);
        if(sums%2)return false;
        int maxn=*max_element(nums.begin(),nums.end());//如果最大的元素比target大，那肯定组成不了。
        if(maxn>sums/2)return false;
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(sums/2+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sums/2;j++){
                //if(nums[i-1]>j)continue;
                if(nums[i-1]>j) dp[i][j]=dp[i-1][j];//只能是不放。
                else dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][sums/2];
    }
};
/*
 * 1.状态更新出现了问题，当物品容量过大时，直接continue居然不行？好吧，想想确实是，就是需要更新的。
 * 2，状态初始化也和官解不一样，我认为是dp[0][j]表示只取前0个数，也就是不取，组成肯定只有dp[0][0]=1
 *   其他都为false，如果是dp[i][0]，取前i个数和为0，我认为为false，因为都是正整数，所以不行，但肯定要
 *   构造。这样的理解也能AC，所以就先这样吧，我不太理解官解，他认为能不取？
 * 3.可以进行空间优化。
 * */
int main(){

    return 0;
}
