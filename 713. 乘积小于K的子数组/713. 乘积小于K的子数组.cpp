#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��10������4:33:24
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0,right=0,ans=0,cur=1;
        if(k==0)return 0;
        while(right<nums.size()){
            cur*=nums[right++];
            while(cur>=k&&left<right){//��k=0��ʱ��base caseû�п��ǵ�
            //��k=1ʱ��[1,2,3]��i=0ʱҲ��������ѭ��
                cur/=nums[left];
                left++;
            }
            ans+=right-left;//�ؼ��ĵط��������
        }
        return ans;
    }
};
/*
 * 1.̫���ˣ�ѧ�˵�992��֮������ͻ����ˣ�̫���˰ɣ�
 * */
int main(){

    return 0;
}
