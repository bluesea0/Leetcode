#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��5��22������10:53:47
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]<nums[right])//��right�Ƚ�
                right=mid;
            else if(nums[mid]>nums[right])
                left=mid+1;
            else right--;//���ʱ����ظ��ȵ�����
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
