#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年3月2日下午5:16:07
class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int>& nums) {
        //非常简单，计算前缀和数组就ok了
        if(nums.size()==0)return;
        int m=nums.size();
        sums.resize(m+1,0);
        for(int i=1;i<=m;i++)
            sums[i]+=sums[i-1]+nums[i-1];
    }

    int sumRange(int i, int j) {
        return sums[j+1]-sums[i];
    }
};

int main(){

    return 0;
}
