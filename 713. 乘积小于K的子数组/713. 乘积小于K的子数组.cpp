#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月10日下午4:33:24
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0,right=0,ans=0,cur=1;
        if(k==0)return 0;
        while(right<nums.size()){
            cur*=nums[right++];
            while(cur>=k&&left<right){//当k=0的时候base case没有考虑到
            //当k=1时，[1,2,3]在i=0时也会陷入死循环
                cur/=nums[left];
                left++;
            }
            ans+=right-left;//关键的地方就在这里！
        }
        return ans;
    }
};
/*
 * 1.太棒了，学了第992题之后这个就会做了！太棒了吧！
 * */
int main(){

    return 0;
}
