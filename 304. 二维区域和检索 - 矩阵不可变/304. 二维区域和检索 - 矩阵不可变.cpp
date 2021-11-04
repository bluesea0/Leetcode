#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��3��2������10:39:02
class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
//         ["NumMatrix"]
// [[[]]] ���п�����������û�п��ǰ�
        int m=matrix.size();
        if(m==0)return;
        int n=matrix[0].size();//������ط������Ⱑ��n�޷���õģ�
        //������Ļ����޷����ʵ�0��Ԫ�صģ���������֮ǰû�п��ǵ�����������
        if(n==0)return;
        dp.resize(m,vector<int>(n,0));
        dp[0][0]=matrix[0][0];
        for(int i=1;i<m;i++)
            dp[i][0]=dp[i-1][0]+matrix[i][0];
        for(int j=1;j<n;j++)
            dp[0][j]=dp[0][j-1]+matrix[0][j];
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]+matrix[i][j]-dp[i-1][j-1];//���������Ҫ��ȥ������Ͷ������
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int m=dp.size(),n=dp[0].size();
        if(row1>=m||row2>=m||col1>=n||col2>=n)return 0;//�ж��±겻���ʵ����
        if(row1==0&&col1==0)return dp[row2][col2];
        if(row1==0)return dp[row2][col2]-dp[row2][col1-1];//[0,1][4,3]
        if(col1==0)return dp[row2][col2]-dp[row1-1][col2];//��2.0��[4,3]
        return dp[row2][col2]-dp[row2][col1-1]-dp[row1-1][col2]+dp[row1-1][col1-1];
    }
};
/*
 * 1.˼·���ǱȽϼ򵥵ģ���Ҫ�����ۻ����飬���ǳ�������������
 * 2.��������֪�����˼·�ж�άǰ׺�ͣ����Ҹ�����д���ǽ���+1�����飬�����Ͳ��ö��⿼��=0������ˡ�
 * */
class NumMatrix2 {
public:
    vector<vector<int>> sums;
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size()==0)return;
        int m=matrix.size(),n=matrix[0].size();
        sums.resize(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                sums[i][j]=sums[i-1][j]+sums[i][j-1]+matrix[i-1][j-1]-sums[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1]-sums[row1][col2+1]-sums[row2+1][col1]+sums[row1][col1];
    }
};
/*
 * 1.���Źٷ����д��һ�£���Ȼǰ׺�������СҪ+1�������ż�ࡣ
 * */
int main(){

    return 0;
}
