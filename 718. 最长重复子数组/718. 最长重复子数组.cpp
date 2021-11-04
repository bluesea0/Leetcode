#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年10月10日下午11:20:29
//class Solution {
//public:
//    int findLength(vector<int>& nums1, vector<int>& nums2) {
//        int m=nums1.size(),n=nums2.size();
//        int maxL=0;
//        for(int i=0;i<m;i++){
//            int k=i;
//            bool flag=false;
//            for(int j=0;j<n;j++){
//                if(k<m&&nums1[k]==nums2[j]){
//                    k++;
//                    flag=true;
//                }
//                else if(flag)break;
//            }
//            maxL=max(maxL,k-i);
//        }
//        return maxL;
//    }
//};
/*
[0,0,0,0,0,0,1,0,0,0]
[0,0,0,0,0,0,0,1,0,0]
输出6，答案是9
我不知道是为什么，我不会。
上面的不知道怎么修改，遂放弃
1.看了官方的dp题解尝试写一下。
*/
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //dp[i][j]表示nums1[i,:]和nums2[j,:]及之后的最长子数组长度
        //那么更新状态公式为dp[i][j]=dp[i+1][j+1]+1 如果nums1[i]==nums2[j]
        //否则是0.最终结果存储在dp[0][0]中。不对，不一定，不一定是从0开始的。
        //因为更新需要用到后面的状态，所以倒序计算
        int m=nums1.size(),n=nums2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int ans=0;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(nums1[i]==nums2[j])dp[i][j]=dp[i+1][j+1]+1;
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
/*
 * 1.也稍微遇到了点问题，以为dp[0][0]是结果，但这个就对dp数组的存储理解产生了偏差。
 *   是包含i和j在内的，它们为起点的子数组。明天写一下滑动窗口的写法。
 * */

//10-11
class Solution {
public:
    int helper(vector<int>& nums1, vector<int>& nums2,int ind1,int ind2){
        int m=nums1.size(),n=nums2.size();
        int k=0,ret=0;
        for(int i=0;i+ind1<m&&i+ind2<n;i++){
            if(nums1[i+ind1]==nums2[i+ind2])
                k++;
            else k=0;
            ret=max(ret,k);
        }
        return ret;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //滑动窗口的解法
        //滑动A
        int m=nums1.size(),n=nums2.size();
        int temp=0,ans=0;
        for(int i=0;i<m;i++){
            temp=helper(nums1,nums2,i,0);
            ans=max(ans,temp);
        }
        for(int i=0;i<n;i++){
            temp=helper(nums1,nums2,0,i);
             ans=max(ans,temp);
        }
        return ans;
    }
};
/*
 * 1.写的时候果然遇到了些问题。
 * */
int main(){

    return 0;
}
