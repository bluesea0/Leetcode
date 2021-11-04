#include <iostream>
#include<vector>
#include<queue>
#include<limits.h>//INT_MIN
using namespace std;
//10-10
/*
1.�о���ϰ��C++д�����������������﷨���ᰡ������˵��������C++�е�minֵ��������α�ʾ�أ�
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=INT_MIN,cur=0;
        //maxAns = nums[0];�ٷ����ĳ�ʼ��Ϊ��0���е���������Ҫʲô��Сֵ�ģ�
        for(int i=0;i<nums.size();i++){
                //for (const auto &x: nums) �ٷ�����autoָ������ģ�ѧ���ˡ�
            cur=max(cur+nums[i],nums[i]);
            res=max(res,cur);
        }
        return res;
    }
};
/*
2.Wow��һ��AC�ˣ��ⲻ��
3.���Ӷȣ�O(n),O(1).
*/


//12-30
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())return 0;
        int cur=nums[0],res=cur;
        for(int i=1;i<nums.size();i++){
            cur=max(cur+nums[i],nums[i]);
            //���ģ��Ҿ�Ȼ����������⣬��Ϊ�Ҳ�֪��cur����ô���£������������д���������µĻ�
            //�Ͳ����������������ˣ���ô��֤���������أ�
            //���ѹ��������ֲ����ˡ�
            //�Ҿ�����������ѡ�񣺶�Ӧ��ǰ�������ģ����+num[i]ֵ�����ˣ���ô�ͼ���
            //���ֵ��С�ˣ���ô�Ͳ��ӣ����Ҵӵ�ǰ��ʼ����������
            //��ʵһ���ܹؼ��������ǣ��Ҷ���֪�����cur������¼ʲô�ġ�
            res=max(res,cur);
        }
        return res;
    }
};
/*
 * 1.���ģ�AC�ˣ������װ����������������ǰ�ҵ����黹�ǿ�����������ҷ��������ˡ�����
 * ��������Ƕ�̬�滮������ô���������أ������⣿
 * 2.�������ŷ��֣�ԭ�������������⣬dp[i]��ʾ��iΪ��β���������������ͣ���ôҪ��max(f[i])��
 *   Ȼ������Ľⷨ�����˹������飬���˰����ˣ�ԭ������ôdp�ģ������Ժ���ֶ�̬�滮�Ļ�������Ҫ��ľ���
 *   dp[i]�����ʾ��ʲô��
 * 3.https://www.cnblogs.com/grandyang/p/4377150.html�����ֵĽⷨ��grandд�����õģ��´θ�ϰдһ�¡�
 * 4.�ٷ�����ᵽ���������ԶԲ�����������ѯ�������ڲ�ѯ�����ʱ���ӶȽ���logn
 *   ����ԭ�����Ӷ�����ô��İ�������ǰ����֪��Ϊʲô��������ÿһ���ڵ㸴�Ӷ���O(n)��
 *   ԭ���Ǹ��ݸ߶ȶ�ÿ���ڵ�����ˣ�ÿ���ڵ���ʵĸ��Ӷ���O(logn)!!!
 * */


//5-23
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //һ��ʼ���뵽����˫ָ�룬���ǣ��ǻ������ڵĽⷨ�����������벻��leftָ�����ô�ƶ�
        //Ȼ�󿴵�����֪������dp�����˰���
        //dp[i]��ʾ��i��β������������ĺ͵����ֵ
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            // if(dp[i-1]>0)dp[i]=dp[i-1]+nums[i];
            // else dp[i]=nums[i];
            dp[i]=max(dp[i-1]+nums[i],nums[i]);//��֮һ��Ҫ��nums[i]
            ans=max(ans,dp[i]);
        }
        //return dp.back();//���ش��ˣ����һ��ֵ����һ�������İ���
        return ans;
    }
};
//��Ȼ�������ö��ַ����Ҳ�̫���ˣ��ø�ϰ����������
int main(){
    Solution s;
    vector<int> v={-2,1,-3,4,-1,2,1,-5,4};
    cout<<s.maxSubArray(v);
    return 0;
}
