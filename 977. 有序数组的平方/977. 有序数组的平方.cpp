#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月31日下午3:40:26
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //我只能想到排序。。。这是双指针的题目？难为我胖虎
        vector<int> ans;
        for(auto n:nums)
            ans.push_back(n*n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
/*
 * 1.看了官方题解，真的很绝！绝了！下次复习要写一下，简洁又易懂的代码。grand的解法是和官方第三种相同的。
 * */

//1-5复习
class Solution2 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //记得其中一个思路是找到正数和负数的分界线，如果全是正数，那么就是递增的，全是负数就是
        //递减的，否则的话，两者再进行分别的合并。
        //第二个思路是头尾比较，头尾指针，选择较大的放入
        //因为正数部分肯定是递增，负数部分是递减
        vector<int> ans(nums.size(),0);
        int i=0,j=nums.size()-1;
        for(int k=ans.size()-1;k>=0;k--){
            int ni=nums[i]*nums[i],nj=nums[j]*nums[j];
            if(ni>=nj){
                ans[k]=ni;i++;
            }else{
                ans[k]=nj;j--;
            }
        }
        return ans;
    }
};//个人觉得官方第二种解法写的太长，所以就不写了，掌握这个就ok了。
int main(){

    return 0;
}
