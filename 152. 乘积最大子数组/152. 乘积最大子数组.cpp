#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��9��29������1:10:36
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP=nums[0],minP=nums[0],res=nums[0];
        for(int i=1;i<nums.size();i++){
            int mx=maxP,mn=minP;
            maxP=max(mx*nums[i],max(mn*nums[i],nums[i]));
            minP=min(mn*nums[i],min(mx*nums[i],nums[i]));
            res=max(res,maxP);
        }
        return res;
    }
};
/*
 * 1.һ��ʼ���ɻ����ֻ��Ҫȡmax(mx*nums[i],mn*nums[i])���ߣ������뵽����ѡȡ�����飬���ԾͰ���
 *   ֻ�ӵ�ǰi��ʼ��Ϊһ���µ������������Ľ����
 * */
int main(){

    return 0;
}
