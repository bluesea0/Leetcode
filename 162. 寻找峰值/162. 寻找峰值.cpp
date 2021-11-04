#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年10月27日下午10:16:55
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //O(n)级别的话，那么就去遍历数组中的每个数
        //首先判断首尾元素
        int n=nums.size();
        if(n==1)return 0;//这里应该return下标
        //判断首尾
        if(nums[0]>nums[1])return 0;
        if(nums[n-1]>nums[n-2])return n-1;
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1])return i;//这里也可以ans=i;break;掉，统一在
            //后面返回。
        }
        return 0;
    }
};
/*
 * 1.O(n)级别的复杂度是比较简单的，但是要求用O(logn)级别的
 * */

//10-28
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //使用二分的方法，
        int left=0,right=nums.size()-1;
        while(left<right){//相等时退出
            int mid=left+(right-left)/2;
            if(nums[mid+1]>nums[mid])left=mid+1;
            // else if(nums[mid-1]>nums[mid])right=mid-1;
            // else if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1])return mid;
            else right=mid;
        }//这样的写法，针对[2,1]这样的长度为2的就不适用，因为mid-1没有啊，是会访问错误的下标的
        //grand是只考虑了mid和mid+1的情况，所以就不会出现越界，因为mid=0的时候，确实是会访问越界，
        //因为mid是比较偏向于left的，如果强制偏向right，那仍然还是会有mid+1下标越界的问题
        return left;
    }
};
/*
 * 1.自己写的还是有问题，在下标返回的时候，grand还是牛！
 * */
int main(){

    return 0;
}
