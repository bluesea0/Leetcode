#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��16������3:25:02
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i+=2)
            ans+=nums[i];
        return ans;
    }
};
/*
 * 1.�ǳ�easy
 * */
int main(){

    return 0;
}
