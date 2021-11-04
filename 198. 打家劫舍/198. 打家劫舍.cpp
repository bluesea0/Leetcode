#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��1������10:11:55
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size(),0);
        //û���жϱ߽�case
        dp[0]=nums[0];
        dp[1]=max(nums[1],dp[0]);
        for(size_t i=2;i<dp.size();i++){
            //��������i==1ʱ��δ�������Ҫ���ж������ţ�
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp.back();
    }
};
/*
 * 1.AC�ˣ������������ģ��߽�����Ĵ����forѭ����ȷʵ����ô��ʼ�ģ��ٷ����Ľ����Ҳ����ô����ģ�
 * 2.��Ϊ���㵱ǰ��ֻ��i-2��i-1�й�ϵ������ֻ��Ҫ�ж�������������ɡ�
 * */
//��������
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        int dp0=nums[0];
        int dp1=max(nums[1],dp0);
        for(size_t i=2;i<nums.size();i++){
            int t=max(dp0+nums[i],dp1);
            dp0=dp1;
            dp1=t;
        }
        return dp1;
    }
};//ʱ���ϻ�����100%������
int main(){

    return 0;
}
