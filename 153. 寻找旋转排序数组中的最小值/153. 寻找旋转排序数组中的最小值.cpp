#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��12������3:30:07
class Solution {
public:
    int findMin(vector<int>& nums) {
        //���ֵ�˼·
        int left=0,right=nums.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            //��Ϊ����Ҫ��right�Ƚϣ�������Ҫ-1������˵��ʼ�������⣿
            if(nums[mid]<=nums[right])//��������mid==right-1
                right=mid;//�ұ�����������
            else //�����������
                left=mid+1;
        }
        return nums[right];
    }//��ôд��Ȼ�����Ⱑ��[2,1]�����ľ�ͨ���������Ҳ�������������д���ˣ�����right��ʼ��������
};
/*
 * 1.AC�ˣ�����ʵҲ���������⣬һ��ʼ��right��ʼ��Ϊsize���Ƚ�ʱ��mid��right-1�Ƚϣ���[2,1]������������
 *   ���������⡣
 * */
int main(){

    return 0;
}
