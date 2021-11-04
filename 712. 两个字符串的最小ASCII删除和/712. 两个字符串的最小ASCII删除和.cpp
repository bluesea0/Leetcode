#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��29������4:59:34
//class Solution2 {
//public:
//    int minimumDeleteSum(string s1, string s2) {
//        //���ѣ����Ǳ༭�����������̫���˰ɡ�
//        int m=s1.size(),n=s2.size();
//        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
//        for(int i=1;i<=m;i++)//ǰ׺ASCII��
//            dp[i][0]=dp[i-1][0]+s1[i-1];//����ֱ�ӽ��ַ���Ϊint������ok��
//        for(int j=1;j<=n;j++)
//            dp[0][j]=dp[0][j-1]+s2[j-1];
//        for(int i=1;i<=m;i++){
//            for(int j=1;j<=n;j++){
//                //ÿ��ɾ��ʱ�������ϴ��
//                if(s1[i-1]==s2[j-1])
//                    dp[i][j]=dp[i-1][j-1]+s[i-1];
//                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]+s2[j-1]);
//            }
//        }
//        for(int i=0;i<=m;i++){
//            for(int j=0;j<=n;j++){
//            	cout<<dp[i][j]<<" ";
//            }
//            cout<<endl;
//        }
//        return dp[m][0]+dp[0][n]-dp[m][n];
//    }
//};//�����˼·�Ǵ���ģ�������˼·��һ��������ļ�����С��һ���Ƿ���ļ���LCS�����ASCII�롣
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        //���ѣ����Ǳ༭�����������̫���˰ɡ�
        int m=s1.size(),n=s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // for(int i=1;i<=m;i++)//ǰ׺ASCII��
        //     dp[i][0]=dp[i-1][0]+s1[i-1];//����ֱ�ӽ��ַ���Ϊint������ok��
        // for(int j=1;j<=n;j++)
        //     dp[0][j]=dp[0][j-1]+s2[j-1];
        //����LCS��ASCIIֵ����
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                //ÿ��ɾ��ʱ�������ϴ��
                if(s1[i-1]==s2[j-1])//˵����ǰҪ����
                    dp[i][j]=dp[i-1][j-1]+s1[i-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int ct1=accumulate(s1.begin(),s1.end(),0);
        int ct2=accumulate(s2.begin(),s2.end(),0);
        return ct1+ct2-2*dp[m][n];
    }
};
/*
 * 1.�������˼·������һ�¡�dp[i][j]������������ִ���LCS�е����ASCIIֵ����ôһ��ʼ��ֻ�ܳ�ʼ��Ϊ0.
 * 2.�����˼·��ֱ����dp[i][j]��ʾɾ�����ַ�����ASCIIֵ��С
 * */
class Solution2 {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)//ǰ׺ASCII��
            dp[i][0]=dp[i-1][0]+s1[i-1];//����ֱ�ӽ��ַ���Ϊint������ok��
        for(int j=1;j<=n;j++)
            dp[0][j]=dp[0][j-1]+s2[j-1];
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1])//˵����ǰ��ɾ��
                    dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(dp[i-1][j]+s1[i-1],dp[i][j-1]+s2[j-1]);//��ô��ѡ������Aֵ��С��ɾ����
            }
        }
        return dp[m][n];
    }
};
int main(){
	Solution s;
	cout<<s.minimumDeleteSum("s", "ea");
    return 0;
}
