#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��6��19������7:43:09
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //�������⣬���ݻᳬʱ
        //dp[i]����Ϊi���������dp[i]=dp[i]+dp[i-j]
        vector<int> dp(target+1,0);
        dp[0]=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<=target;i++){//��������
            for(auto& n:nums){
                if(n>i||dp[i-n]>INT_MAX-dp[i])break;
                dp[i]+=dp[i-n];
            }
        }
        return dp.back();
    }
};
/*
 * 1.����14/15����������Ŀ˵����Ŀ���ݱ�֤�𰸷��� 32 λ������Χ�����������м������ܻᳬINT��ʾ��Χ��
 *   �����������if�жϣ�dp[i-n]>INT_MAX-dp[i]��break����
 * 2.���������ȫ�������⣬��Ҫ������Ʒ���Ⱥ�˳�򣬿����ظ�����ô�ͱ���������������ý���ظ����Ǿ��ȱ���
 *   ��Ʒ����֤��Ʒ�����˳�����Ⱥ�Ͳ����ظ���
 * */
int main(){

    return 0;
}
