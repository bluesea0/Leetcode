#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��6��11������6:55:23
class Solution {
public:
    int numSquares(int n) {
        //״̬ת�Ʒ��̣�ö��dp[i]=1+min(dp[i-j^2]),j>=1&&j*j<=i;
        //���״̬ת�Ʒ��̾������Ķ�����
        vector<int> dp(n+1,n+1);
        dp[0]=0,dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
        return dp.back();
    }
};
/*
 * 1.��Ȼ�����Լ���û��д����״̬ת�Ʒ��̵ġ��ͺ��ң��˼�д�����͸о������档
 * */
int main(){

    return 0;
}
