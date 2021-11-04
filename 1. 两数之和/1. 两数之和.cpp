#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月27日上午11:52:42
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        unordered_map<int,int> um;
//        for(size_t i=0;i<nums.size();i++)
//            um[nums[i]]=i;
//        sort(nums.begin(),nums.end());
//        size_t i=0,j=nums.size()-1;
//        while(i<j){
//            if(nums[i]+nums[j]==target) return {um[nums[i]],um[nums[j]]};
//            else if(nums[i]+nums[j]<target)i++;
//            else if(nums[i]+nums[j]>target)j--;
//        }
//        return {-1,-1};//表示不存在
//    }
//};
/*
[3,2,4]
6
1.卧槽，大意了啊，因为它排完序中之后id是改变的！！！
  本来想的是将它存入map中，但是如果有重复的元素怎么办？
  其实有重复的无所谓，那么就相当于选择其中一个了。
2.又错了，没考虑到[3,3] 6，应该是0，1，我这种写法就会输出1，1 绝了，工作没了。
3.我大意了，太难了，为什么我写的不对呢？哭天抢地！
4.看了官方题解，觉得自己基本思路都错了啊。
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++){
            if(um.count(target-nums[i])){
                return {um[target-nums[i]],i};
            }
            um[nums[i]]=i;//这里放的是自身，而不是补数！
        }
        return {-1,-1};
    }
};
/*
 * 5.天哪这个还是按照官方题解写出来的，实在是唏嘘。
 *   时间空间都是O(n)。
 * */

int main(){

    return 0;
}
