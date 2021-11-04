#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年6月18日上午2:52:06
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        //对这个规则其实有点迷惑，看了题解来写一下
        unordered_set<int> us;
        int maxn=INT_MIN,minn=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)continue;
            if(us.count(nums[i]))return false;
            us.insert(nums[i]);
            minn=min(minn,nums[i]);
            maxn=max(maxn,nums[i]);
        }
        return maxn-minn<5;
    }
};
/*
 * 1.规则：除0外不能有重复的，所以用set去重；最大值最小值差值不能>=5；
 *
 * */
int main(){

    return 0;
}
