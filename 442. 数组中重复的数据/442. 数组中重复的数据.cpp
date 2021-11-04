#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年5月20日下午11:00:59
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            while(nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
            // if(i+1!=nums[i])//不必在这里统计，之后统一统计就可以了
            //     ans.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(i+1!=nums[i])
                ans.push_back(nums[i]);
        }
        return ans;
    }
};
/*
 * 1.利用41题第二种解法解决了。利用数组创建哈希。
 * */
//class Solution {
//public:
//    vector<int> findDuplicates(vector<int>& nums) {
//        //尝试将对应位置变为负值
//        vector<int> ans;
//        for(int i=0;i<nums.size();i++){
//            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
//        }
//        for(int i=0;i<nums.size();i++)
//            if(nums[i]>0)
//                ans.push_back(i+1);
//        return ans;
//    }
//};
/*
 * 2.上述为失败的尝试，因为有出现两次的，经过两次取负变为负数，还有没有出现过的也是负数，不能这么统计。
 *   应该在for循环内统计。
 * */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //尝试将对应位置变为负值
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]<0)
                ans.push_back(abs(nums[i]));
            else nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        }
        return ans;
    }
};//其实也没有快多少，swap的是68ms，这个是52ms，不过还是快了一点。

//2021-6-8
/*
 * 1.今天复习出现的问题是，我只能想到用swap来解决，这个变成负数的不好想啊。
 *
 * */
int main(){

    return 0;
}
