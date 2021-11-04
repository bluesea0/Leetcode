#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年7月12日下午9:49:24
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+((right-left)>>1);
            if(nums[mid]==target)return mid;
            if(nums[mid]>nums[right]){//左半部分有序
                if(target>=nums[left]&&target<nums[mid])
                    right=mid-1;
                else left=mid+1;
            }else{//右半部分有序
                if(target>nums[mid]&&target<=nums[right])
                    left=mid+1;
                else right=mid-1;
            }
        }
        return -1;
    }
};
/*
 * 1.一下子AC了，太开心啦。
 * 2.要点：如果==nums[mid]那么就直接返回下表，判断左半部分是否有序，右半部分是否有序。
 * */
int main(){

    return 0;
}
