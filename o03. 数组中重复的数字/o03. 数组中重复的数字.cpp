#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年5月22日上午8:33:25
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        //可以通过swap将其放回原位，如果原位已经有了，说明是重复的
        //还可以通过加负号来判断，如果对应位置已经变负，那么就是该数重复
        for(int i=0;i<nums.size();i++){
            // if(nums[abs(nums[i])]<0)ans.push_back(abs(nums[i]));//不对不对，这样就发现了问题
            // //针对0呢？-0负0？所以还是取swap比较靠谱。

            // else nums[abs(nums[i])]=-nums[abs(nums[i])];
            while(nums[nums[i]]!=nums[i])
                swap(nums[i],nums[nums[i]]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i)
                return nums[i];
        }
        return 0;
    }
};
/*
 * 1.太悲哀了做这道题的时候，本来打算取负值，但是发现有0，遂放弃。然后用swap准备返回的时候，发现函数返回只需要
 *   返回一个就可以。。。彻底凉凉。不用那么麻烦的。
 * 2.
 * */
int main(){

    return 0;
}
