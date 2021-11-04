#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��21������1:53:58
//�����ύ
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,1);
        for(int i=2;i<dp.size();i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp.back();
    }
};
//�Ż��ռ�󣬳�����100%��
class Solution2 {
public:
    int climbStairs(int n) {
        if(n<2)return n;
        int dp0=1,dp1=1;
        for(int i=2;i<n+1;i++){
            int t=dp0+dp1;
            dp0=dp1;
            dp1=t;
        }
        return dp1;
    }
};

//2-20
class Solution3 {
public:
    int climbStairs(int n) {
        //ʹ����ȫ����˼�������
        vector<int> stairs={1,2};
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){//�������⣬����ÿ��������������Ʒ˳��
            for(int j=0;j<stairs.size();j++){
                if(stairs[j]>i)continue;
                dp[i]+=dp[i-stairs[j]];
            }
        }
        return dp[n];
    }
};
/*
 * 1.��Ȼ����д�ܵ�Ч�����������ͳһ����ȫ�����������������Ľⷨ����ѧϰ��518��֮������ġ�
 * */
int main(){

    return 0;
}
