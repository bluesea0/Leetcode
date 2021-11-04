#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��4������1:42:48
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
//�����صĶ��ַ���AC�ˡ�
//1��2��3��4��5
//left=0,right=4,����left<right���жϻ����ʲô�����أ�
/*
 * left=0,right=4,mid=2,
 * left=3,right=4,mid=3,
 * left=4,right=4���˳�ѭ���������ԾͲ��Ҳ���right4��ʱ���ˡ�
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
 * 1.Ŀǰ���Ǹ�ϰ���ñ����䡣
 * */
int main(){
	int a=6;
	cout<<(a<<-1);
    return 0;
}
