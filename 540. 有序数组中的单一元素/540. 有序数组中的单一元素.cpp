#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月12日下午2:30:04
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //又没有考虑base case啊，
        if(nums.empty())return 0;//如果是？
        int left=0,right=nums.size();
        while(left<right){
            int mid=left+(right-left)/2;
            if(mid>0&&nums[mid]==nums[mid-1]){//这里注意判断范围的时候没有=号
                //需要判断左右哪个长度为奇数，继续遍历为奇数的部分
                if((mid-left-1)%2==0){//左边是否是偶数长度
                    left=mid+1;
                }else{//左边长度为奇数
                    right=mid-1;
                }
            }else if(mid+1<nums.size()&&nums[mid]==nums[mid+1]){//判断范围不越界
                if((mid-left)%2==0) left=mid+2;
                else right=mid;
            }else return nums[mid];
        }
        return nums[right];
    }
};
/*
 * 1.提交一次出现的意外情况是，[1]这样的长度为1的出错了，判断下标范围时不能有=。
 * 2.官解中第三种解法，只对偶数下标进行二分遍历，这个解法真的绝，学到了，下次复习要写一下。
 * */
int main(){

    return 0;
}
