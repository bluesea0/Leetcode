#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��24������1:46:45
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //����ֻ���뵽һ��O(n^2)��dp�ⷨ��
        vector<int> dp(nums.size(),1);
        int ans=1;
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){//��0������������������һ���ģ�û����
            	//���У����һ��Ҫע�Ⱑ��дforѭ�����ǵ���İ���Ҫ--�ģ���
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(ans,dp[i]);
                }

            }
        }
        return ans;
    }
};
/*
 * 1.AC�ˣ��ռ临�Ӷ���O(n)���´θ�ϰҪдһ��̰��+���֡�
 * */

//1-25
class Solution {
public:
    vector<int> d;
    int lengthOfLIS(vector<int>& nums) {
        d.push_back(nums[0]);//d[i]��ʾ�����������е�ֵ���ǰ���˳������
        for(int i=1;i<nums.size();i++){
            if(nums[i]>d.back())
                d.push_back(nums[i]);
            else {//ͨ�����ֲ����ҵ��պñ�nums[i]������������滻����
                d[helper(nums[i])]=nums[i];
            }
        }
        return d.size();
    }
    int helper(int k){//�����������������ȵ�ֵ�أ�
        int left=0,right=d.size();
        while(left<right){
            int mid=left+(right-left)/2;
            if(k==d[mid])return mid;
            else if(k>d[mid])
                left=mid+1;
            else right=mid;
        }
        return left;
    }
};
int main(){

    return 0;
}
