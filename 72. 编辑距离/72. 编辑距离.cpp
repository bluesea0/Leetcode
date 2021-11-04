#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��28������7:31:30
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> edit(m+1,vector<int>(n+1,0));
        for(int i=0;i<m+1;i++)//�������г�ʼ��
            edit[i][0]=i;
        for(int i=0;i<n+1;i++)
            edit[0][i]=i;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1])
                    edit[i][j]=edit[i-1][j-1];
                else{
                    edit[i][j]=min(edit[i-1][j],edit[i][j-1]);
                    edit[i][j]=min(edit[i][j],edit[i-1][j-1]);
                    edit[i][j]++;//��ʾ�϶�����һ�β���
                }
            }
        }
        return edit[m][n];
    }
};
/*
 * 1.���츴ϰ��һ�±༭���룬�Ҳŷ������ж�ô�ؼ򵥰���
 * */
int main(){

    return 0;
}
