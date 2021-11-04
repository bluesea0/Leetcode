#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��6��11������11:17:42
class Solution {
public:
    bool isMatch(string s, string p) {
        //dp[i,j]��ʾs�ĵ�i���ַ���p�еĵ�j���Ƿ�ƥ��
        /*
        1.��s[i]==p[j] dp[i][j]=dp[i-1][j-1]
        2.��p[j]==? dp[i][j]=dp[i-1][j-1]
        3.��p[j]==* dp[i][j]=dp[i-1][j]|dp[i][j-1]

        base case:
        ��s.size()==0����ôpǰ�����ַ���*Ϊtrue������Ϊfalse
        ��p.size()==0��s==0Ϊtrue������Ϊfalse��
        */
        int m=s.size(),n=p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0]=1;
        for(int i=0;i<n;i++)
            if(p[i]=='*')dp[0][i+1]=1;
            else break;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(s[i]==p[j])dp[i+1][j+1]=dp[i][j];//��ѽԭ�����±�����
                else if(p[j]=='?')dp[i+1][j+1]=dp[i][j];
                else if(p[j]=='*')dp[i+1][j+1]=dp[i][j+1]||dp[i+1][j];//ƥ��*||��ƥ��*��*��ʾ�մ�
            }
        }
        return dp[m][n];
    }
};
/*
 * 1.��tm������;��ⶣ������˺ü���С���⡣
 * 2.������״̬���µ���⣬��p[j]Ϊ*��ʱ������õ�j��ô����dp[i-1][j]��j��û�ж���ʱ��˵��Ҫ��jȥƥ��
 *   ǰ���i-1���ַ�������Ŀǰ�Ѿ��õ���j�����Ծ�ʵ����ƥ�����ַ������û����j����ô����jĿǰƥ����
 *   �մ���
 * 3.forѭ��ʱp���±�д���ˣ����һ��else��Ȼ��Ҫ�жϣ�����"ab""?c"��������Ϊb��=c���ǲ�û���ж�p�Ƿ�Ϊ
 *   *���ͻᵼ�³���
 * */

//9-20
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        //dp[i][j]��ʾs��ǰi���ַ���p��ǰj���ַ��ܷ�ƥ��

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            if(p[i-1]=='*')dp[0][i]=1;
            else break;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1]||p[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                    dp[i][j]=dp[i][j-1]||dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};
/*
 * 1.��ϰ��һЩд�����ؼ���������dp[i][j]��ʾs��ǰi���ַ���p��ǰj���ַ��ܷ�ƥ�䡣
 * */
int main(){

    return 0;
}
