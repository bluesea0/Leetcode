#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月4日下午1:42:48
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size();
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                left=mid+1;
            else right=mid;
        }
        return -1;
    }
};
//最朴素的二分法，AC了。
//1，2，3，4，5
//left=0,right=4,且用left<right来判断会出现什么问题呢？
/*
 * left=0,right=4,mid=2,
 * left=3,right=4,mid=3,
 * left=4,right=4，退出循环，很明显就查找不到right4的时候了。
 * */

//9-19
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target)return mid;
            if(target>nums[mid])left=mid+1;
            else right=mid-1;
        }
        return -1;
    }
};
/*
 * 1.目前还是更习惯用闭区间。
 * */
int main(){
	int a=6;
	cout<<(a<<-1);
    return 0;
}
