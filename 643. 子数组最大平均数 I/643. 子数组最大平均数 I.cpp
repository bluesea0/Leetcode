#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��4������3:05:30
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left=0,right=0,ans=INT_MIN,cur=0;//[-1] 1 �������İ����������ʼ��������
        while(right<nums.size()){
            cur+=nums[right++];
            if(right-left==k){
                ans=max(ans,cur);
                cur-=nums[left++];
            }
        }
        return ans*1.0/k;
    }
};
/*
 * 1.ע���ʼ�������Ⱑ���ҵ��죬�㽫ans��ʼ��Ϊ0�������������ȫ�Ǹ������ⲻ�����һ�����������������ˣ�
 *   ��ʼ��ΪINT_MIN��������������Ѱ�644�⣬�����ǻ�Ա���㿴��grand�Ľⷨ�ɡ�
 * */
int main(){

    return 0;
}
