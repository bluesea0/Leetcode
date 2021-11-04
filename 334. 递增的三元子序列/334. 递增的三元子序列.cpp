#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月25日下午4:20:32
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //这不很easy吗？？？判断到3直接返回？
        vector<int> dp(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])dp[i]=max(dp[i],dp[j]+1);
            }
            if(dp[i]==3)return true;
        }
        return false;
    }
};
/*
 * 1.我写的这个就没有任何技术，回去等消息吧。
 * 2.题目的要求是时间复杂度是O(n)，这个我当然达不到了，我只超过了7%的。
 * 3.但是用双指针怎么指呢？首尾对撞指针？但是我觉得不行，那你如何移动left和right呢？就算是双指针都从0开始
 *   走，但是总也得是O(n^2)的复杂度啊，不是要判断出所有的情况吗？
 * 4.看了评论区的题解，也太牛逼了吧，就算small在mid的位置之后，那么之后遇到比mid大的，也能满足三元的条件，
 *   因为那说明，在mid之前一定存在着一个比small大比mid小的前最小值。绝了。
 * */

//1-26
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small=INT_MAX,mid=INT_MAX;
        for(auto n:nums){
            if(n<=small)small=n;
            else if(n<=mid) mid=n;
            else return true;
        }
        return false;
    }
};
/*
 * 1.这个解法如此牛批，只用8ms，而上面的用了400+ms，绝了真是绝了。
 * */
