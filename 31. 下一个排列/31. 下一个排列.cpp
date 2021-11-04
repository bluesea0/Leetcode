#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年6月10日下午12:50:21
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty())return;
        next_permutation(nums.begin(),nums.end());//使用库函数来做
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //这个需要观察规律的，但是我忘记了，你让我自己总结？抱歉我不会。
        //好像是从后往前找降序的位置，从前往后找到最后升序的位置然后交换？就得到了下一个排列
        //不知道在干嘛，第一步我是确定的，但是第二步是从j开始找，还是从0开始找？
        //我就摸不清其中的规律了。

        //从后往前找降序的位置i，再从后往前找第一个j>i的位置，交换，之后i及之后是倒序的，直接反转
        int n=nums.size(),i=n-2;
        while(i>=0){
            if(nums[i]>=nums[i+1])i--;//这里需要是非严格降序，
            //如5 1 1，的下一个就是1 1 5，直接在这里reverse。
            else break;
        }
        if(i<0){
            reverse(nums.begin(),nums.end());return;
        }
        int j;
        for(j=n-1;j>i;j--){
            if(nums[j]>nums[i])break;
        }
        swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
    }
};
/*
 * 1.步骤总结：①从后往前找到降序的第一个数字i，②从后往前找到第一个大于i的数字j，交换
 *   ③根据之前遍历的顺序i+1往后都是降序，j被换了一个小于i的数，那么仍然保持降序，所以reverse即可。
 * 2.排列原则：
 *   我们需要将一个左边的「较小数」与一个右边的「较大数」交换，以能够让当前排列变大，从而得到下一个排列。
 *   「较小数」尽量靠右，而「较大数」尽可能小。
 *   当交换完成后，「较大数」右边的数需要按照升序重新排列。
 *   这样可以在保证新排列大于原来排列的情况下，使变大的幅度尽可能小。
 * */
int main(){

    return 0;
}
