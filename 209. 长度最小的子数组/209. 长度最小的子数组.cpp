#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-14
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans=nums.size()+1,start=0,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<s)continue;
            while(sum-nums[start]>=s){
                sum-=nums[start];
                start++;
            }
            ans=min(ans,i-start+1);
        }
        return ans==nums.size()+1?0:ans;
    }
};
/*
1.�Բۣ������Ҿ�Ȼһ����AC�ˣ��������İ�����������������Ȼ��û��סȥ�˶��鿴���Ǹ���ȥ��
�о��������⣬��Ҳ���ý��飬���ǽ��飬Ϊɶ������Ҫ�����Ȱ�������
2.�ٷ��Ĵ𰸣�
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        int start = 0, end = 0;
        int sum = 0;
        while (end < n) {
            sum += nums[end];
            while (sum >= s) {//�����������жϣ�ѧ���ˡ�
                ans = min(ans, end - start + 1);
                sum -= nums[start];//�����������дһ�¡�
                start++;
            }
            end++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
3.���ж��ֽⷨ����Ҫ��һ�¡�
*/
//10-21
/*
1.��ϰ��һ�¶��ֽⷨ����ĺ���������̫�����ˣ��Ҷ��ˣ�ǰ׺��Ȼ���ҵ�bound���ټ�ȥ���൱��
  ��>=s��
2.����grand�Ľⷨ������и����Ļ������ַ���ʧЧ��������ף����ǻ�������Ҳ��ʧЧ��
  �����ˣ����������3,{2,-3,1,4}����Ϊ�и�������������͵Ĺ����п��ܻ����0�������ڼ���4��ʱ��
  ��>3�����Ǽ�����Ǵ�0��ʼ�ĳ��ȡ�����Ҫ��ô���أ������⣿ǰ׺��ֻ���ڶ���������
*/

//2-10
/*
 * 1.����ϰһ��ǰ׺��+���ֵĽⷨ��˳��ѧϰһ��C++�ı�׼�⣬������֣��������OJ����ô�Ͳ����Լ���д�ˡ�
 * 2.ǰ׺���и����ɣ�sums[i]��ʾǰi�����ĺͣ�i=0ʱΪ0����ʾ���Ǻ͡�
 * */
int main(){
    Solution s;
    vector<int> nums={2,-3,1,4};
    cout<<s.minSubArrayLen(3,nums);
    return 0;
}
