#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��10��2������11:50:33
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        //base case����i=0��j=0ʱ���������ַ�����һ��Ϊ��ʱ����ôĬ�ϳ�ʼ��Ϊ0
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
/*
 * 1.һ��ʼû���뵽��dp�������⣬�����������ָ��ָ���������飬Ȼ���������������Ӧ�ò��С�
 *   �������֮�󣬻�Ȼ���򣬼�dp��
 * */
int main(){

    return 0;
}
