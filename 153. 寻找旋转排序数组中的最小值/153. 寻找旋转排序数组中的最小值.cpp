#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月12日下午3:30:07
class Solution {
public:
    int findMin(vector<int>& nums) {
        //二分的思路
        int left=0,right=nums.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            //因为这里要和right比较，所以需要-1？还是说初始化的问题？
            if(nums[mid]<=nums[right])//最多情况是mid==right-1
                right=mid;//右边有序的情况下
            else //否则左边有序
                left=mid+1;
        }
        return nums[right];
    }//这么写果然有问题啊，[2,1]这样的就通不过，那我不能用我以往的写法了，看来right初始化有问题
};
/*
 * 1.AC了，但其实也遇到了问题，一开始将right初始化为size，比较时用mid和right-1比较，对[2,1]这样的样例就
 *   出现了问题。
 * */
int main(){

    return 0;
}
