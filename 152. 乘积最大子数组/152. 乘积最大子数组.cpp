#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年9月29日上午1:10:36
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP=nums[0],minP=nums[0],res=nums[0];
        for(int i=1;i<nums.size();i++){
            int mx=maxP,mn=minP;
            maxP=max(mx*nums[i],max(mn*nums[i],nums[i]));
            minP=min(mn*nums[i],min(mx*nums[i],nums[i]));
            res=max(res,maxP);
        }
        return res;
    }
};
/*
 * 1.一开始很疑惑觉得只需要取max(mx*nums[i],mn*nums[i])两者，但是想到它是选取子数组，所以就包括
 *   只从当前i开始作为一个新的子数组这样的结果。
 * */
int main(){

    return 0;
}
