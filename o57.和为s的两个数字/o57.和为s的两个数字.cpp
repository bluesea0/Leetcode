#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月31日下午3:21:34
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.empty())return {};//其实这个也不必要有。
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]==target)return {nums[i],nums[j]};
            else if(nums[i]+nums[j]<target)i++;
            else j--;
        }
        return {};
    }
};
/*
 * 1.很简单的一道题，没什么难度。
 * 2.看到评论区中给出的有可能nums[i]+nums[j]相加之后会溢出，有道理，比较极端的情况就是：
 *   INT_MAX+某值，就会溢出，同时如果更改为target-nums[j]也可能会溢出，因为可能存在负值
 *   某正值-INT_MIN，那么就会溢出，所以这里最好改为long long。强制转换一下
 * */
int main(){

    return 0;
}
