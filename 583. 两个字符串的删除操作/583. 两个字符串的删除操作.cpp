#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��28������7:48:01
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> edit(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++)
            edit[i][0]=i;
        for(int j=0;j<=n;j++)
            edit[0][j]=j;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1])
                    edit[i][j]=edit[i-1][j-1];
                else edit[i][j]=min(edit[i-1][j],edit[i][j-1])+1;
            }
        }
        return edit[m][n];
    }
};
/*
 * 1.ֻҪ���˱༭���룬��������������⣬���ֻ��ɾ��������û�и��Ĳ�����
 * 2.���ˣ�������⣬����༭�����д����������ʹ�ù������顣������һ��˼·��������������С�
 * */

//1-29
/*
 * 1.����дһ��ʹ�ù�������+�༭�������ķ�������дһ��ʹ��LCS�Ľⷨ��
 * */
class Solution2 {
public:
    int minDistance(string word1, string word2) {
        int n=word2.size();
        vector<int> dp(n+1,0);
        for(int i=0;i<=n;i++)
            dp[i]=i;
        for(int i=1;i<=word1.size();i++){
            vector<int> t(n+1,0);//�ȶ���һ����ʱ��
            for(int j=0;j<=n;j++){
                if(j==0){t[j]=i;continue;}
                if(word1[i-1]==word2[j-1])
                    t[j]=dp[j-1];
                else
                    t[j]=min(t[j-1],dp[j])+1;
            }
            dp=t;
        }
        return dp.back();
    }
};
//LCS�ⷨ��
class Solution3 {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> lcs(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1])
                    lcs[i][j]=lcs[i-1][j-1]+1;
                else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);//�ֱ��ʾɾ��i��j
            }
        }
        return m+n-2*lcs[m][n];
    }
};
/*
 * 1.����O(mn)�Ľⷨ������ʱ�䶼�����Ƶġ���Ȼ���Ҳ�����ù������顣
 * */
int main(){

    return 0;
}
