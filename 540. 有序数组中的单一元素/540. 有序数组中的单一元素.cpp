#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��12������2:30:04
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //��û�п���base case����
        if(nums.empty())return 0;//����ǣ�
        int left=0,right=nums.size();
        while(left<right){
            int mid=left+(right-left)/2;
            if(mid>0&&nums[mid]==nums[mid-1]){//����ע���жϷ�Χ��ʱ��û��=��
                //��Ҫ�ж������ĸ�����Ϊ��������������Ϊ�����Ĳ���
                if((mid-left-1)%2==0){//����Ƿ���ż������
                    left=mid+1;
                }else{//��߳���Ϊ����
                    right=mid-1;
                }
            }else if(mid+1<nums.size()&&nums[mid]==nums[mid+1]){//�жϷ�Χ��Խ��
                if((mid-left)%2==0) left=mid+2;
                else right=mid;
            }else return nums[mid];
        }
        return nums[right];
    }
};
/*
 * 1.�ύһ�γ��ֵ���������ǣ�[1]�����ĳ���Ϊ1�ĳ����ˣ��ж��±귶Χʱ������=��
 * 2.�ٽ��е����ֽⷨ��ֻ��ż���±���ж��ֱ���������ⷨ��ľ���ѧ���ˣ��´θ�ϰҪдһ�¡�
 * */
int main(){

    return 0;
}
