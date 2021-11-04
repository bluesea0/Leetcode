#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��7��12������9:49:24
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+((right-left)>>1);
            if(nums[mid]==target)return mid;
            if(nums[mid]>nums[right]){//��벿������
                if(target>=nums[left]&&target<nums[mid])
                    right=mid-1;
                else left=mid+1;
            }else{//�Ұ벿������
                if(target>nums[mid]&&target<=nums[right])
                    left=mid+1;
                else right=mid-1;
            }
        }
        return -1;
    }
};
/*
 * 1.һ����AC�ˣ�̫��������
 * 2.Ҫ�㣺���==nums[mid]��ô��ֱ�ӷ����±��ж���벿���Ƿ������Ұ벿���Ƿ�����
 * */
int main(){

    return 0;
}
