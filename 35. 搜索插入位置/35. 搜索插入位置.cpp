#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��9��23������12:01:52
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //���������ҵ�>=target��λ��
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target)right=mid-1;
            else left=mid+1;
        }
        return left;
    }
};
/*
 * 1.�Ƚϻ����Ķ���
 * */
int main(){

    return 0;
}
