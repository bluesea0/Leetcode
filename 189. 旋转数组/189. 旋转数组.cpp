#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月3日上午10:13:16
//class Solution {
//public:
//    void rotate(vector<int>& nums, int k) {
//        //(i+k)%n就是移动后的最终位置
//        //但如果像[1,2,3,4]，k=2这样的，就会只移动偶数位，那奇数位怎么办呢？我不懂。我跪了
//        int i=0,ct=0;
//        while(ct<nums.size()){
//            int j=(i+k)%n;
//
//        }
//    }
//};
/*
 * 1.不得不说，这个真的好难好难啊！
 * */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //先用反转来写一下
        int n=nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k%n);//其实这里不用-1，因为它是指向待反转的后一个位置
        reverse(nums.begin()+k%n,nums.end());
    }
};
//再来写一下环状替换的解法
class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        int idx=0,temp=nums[0],start=0,n=nums.size();
        if(k==0||k%n==0) return;//这里直接加个判断来将那些不移动的返回掉，grand也是这么写的
        for(int i=0;i<n;i++){
            int nid=(idx+k)%n;//将要放置的位置
            swap(temp,nums[nid]);
            idx=nid;
            if(idx==start){//这里如果相等的话，针对样本[1] 0就会出现idx=1的情况，就会访问不存在的下标
                start++;
                idx++;
                temp=nums[idx];
            }
        }
    }
};//这个题目我很难定位到哪个类别，就先不往博客里放了。


//6-19
/*
 * 1.今天复习只想到直接通过%找到下标，但是并不知道怎么循环，而且根本也没有想到有可能会只移动偶数位，如果
 *   k是偶数的话。太难了实在是。
 * 2.第一个思路是，使用一个新的数组，放到最后旋转的位置。另外如果不能用额外空间的话，那么就需要一个变量来
 *   保存前一个数。
 * */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k%n==0)return;
        int start=0,pre=nums[0],idx=0;
        for(int i=0;i<n;i++){
            idx=(idx+k)%n;
            int t=nums[idx];
            nums[idx]=pre;
            pre=t;//保存pre的结果，不被覆盖。
            if(idx==start){//控制不只在一个圈里循环，跳出该圈，重新开始一个圈
                start++;
                idx++;
                pre=nums[idx];
            }
        }
    }
};
int main(){

    return 0;
}
