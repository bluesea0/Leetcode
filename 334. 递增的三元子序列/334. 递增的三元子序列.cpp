#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��25������4:20:32
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //�ⲻ��easy�𣿣����жϵ�3ֱ�ӷ��أ�
        vector<int> dp(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])dp[i]=max(dp[i],dp[j]+1);
            }
            if(dp[i]==3)return true;
        }
        return false;
    }
};
/*
 * 1.��д�������û���κμ�������ȥ����Ϣ�ɡ�
 * 2.��Ŀ��Ҫ����ʱ�临�Ӷ���O(n)������ҵ�Ȼ�ﲻ���ˣ���ֻ������7%�ġ�
 * 3.������˫ָ����ôָ�أ���β��ײָ�룿�����Ҿ��ò��У���������ƶ�left��right�أ�������˫ָ�붼��0��ʼ
 *   �ߣ�������Ҳ����O(n^2)�ĸ��ӶȰ�������Ҫ�жϳ����е������
 * 4.��������������⣬Ҳ̫ţ���˰ɣ�����small��mid��λ��֮����ô֮��������mid��ģ�Ҳ��������Ԫ��������
 *   ��Ϊ��˵������mid֮ǰһ��������һ����small���midС��ǰ��Сֵ�����ˡ�
 * */

//1-26
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small=INT_MAX,mid=INT_MAX;
        for(auto n:nums){
            if(n<=small)small=n;
            else if(n<=mid) mid=n;
            else return true;
        }
        return false;
    }
};
/*
 * 1.����ⷨ���ţ����ֻ��8ms�������������400+ms���������Ǿ��ˡ�
 * */
