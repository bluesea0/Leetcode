#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年5月22日上午10:53:47
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]<nums[right])//和right比较
                right=mid;
            else if(nums[mid]>nums[right])
                left=mid+1;
            else right--;//相等时针对重复度的数据
        }
        return nums[left];
    }
};
/*
 * 1.
 * */
int main(){

    return 0;
}
