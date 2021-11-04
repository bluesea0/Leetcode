#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-12
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid);//ͨ��������������������ֵ��
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){//��Ҫд��i/j���𣬵�������ѭ����������ġ�
                if(i==0&&j==0)continue;
                if(i==0)
                    dp[i][j]=dp[i][j-1]+dp[i][j];
                else{
                    if(j==0)dp[i][j]=dp[i-1][j]+dp[i][j];
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1])+dp[i][j];
                }
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};
/*
1.AC�ˣ����ǱȽϻ�����DP����ʵд��ʱ���Ҿ��뵽�˿���ֻ����һά��������Ϊ�����Ļ����Ҳ���д
�Ǹ��Ƶ���ʽ���������У��ҿ�һ�¡�
2.�����и����˶�����һ�пռ䣬���ܸ���һ�㡣
int[][] dp = new int[row + 1][column + 1];
3.����һά���飬���������飬����ⷨ����
https://blog.csdn.net/qq_15711195/article/details/96995494
�´θ�ϰ��ʱ��Ҫ��һ�¡�
*/
//10-12
class Solution1 {
public:
    int maxValue(vector<vector<int>>& grid) {
        //ͨ��һά�Ĺ������������
        vector<int> dp(grid[0]);
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){//i��j=0����ô�죿
                if(i==0 && j==0)continue;
                if(i==0){
                    dp[j]=dp[j-1]+grid[i][j];
                }else{
                    if(j==0)
                        dp[j]+=grid[i][j];
                    else
                        dp[j]=max(dp[j-1],dp[j])+grid[i][j];
                }
            }
        }
        return dp[n-1];
}};
/*
1.������д�����ʹ�ù�������ҲAC�ˣ�����զд����ô�鷳�ء�
2.�������ӵĴ���
class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        if(board.empty()) return 0;
        int n = board[0].size();
        vector<int> dp(n);//���ڵ�0�е�ʱ�򣬳�ʼ��Ϊ0��dp[i]�൱�ڼ�����0�����˾��ˣ�Ĥ�ݡ�
        for(auto val: board) {
            dp[0] += val[0];
            for(int i=1; i<n; ++i) dp[i] = max(dp[i], dp[i-1])+val[i];

        }
        return dp[n-1];
    }
};
���ţ���������������ܿ��������㷨������񰡣�����һ���ˡ�
*/

//10-22
//��ϰһ�£�д�˳���������Ҫ�ٸ�ϰһ�¸о����������������ؿɲ�̫���ˡ�
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {//�Ա߽�ֵ���ж�
        vector<int> dp(grid[0].size(),0);
        for(auto g:grid){
            dp[0]+=g[0];
            for(int j=1;j<grid[0].size();j++){
                dp[j]=max(dp[j],dp[j-1])+g[j];
            }
        }
        return dp[grid[0].size()-1];
    }
};

//5-26
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        //���������￴���ж�����һ�пռ䣬Ȼ���±�����ͺܷ��㣬�����ҷ�Ӧ������
        //�Ǹ��µ�ʱ������Ҫgrid[i-2]�ˣ���������Ȳ���1���������ͷ��ʲ����ڵ��±��ˣ���
        //�������֮���Ҷ��ˣ��㻹��û��עת�Ʒ���
        //dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1]���������grid���ʵ�i-2��j-2
        //�����������Ļ�����ôת�Ʒ��̾��ǣ�
        //dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i][j];
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1];
            }
        }
        return dp[m][n];
    }
};//������ڶ�����һ��һ�е���Ҫ�����ա�
//�ռ��Ż��汾
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int> dp(n,0);
        dp[0]=grid[0][0];
        for(int i=1;i<n;i++)
            //dp[i]=grid[0][i];//�����ʼ�������⣬Ӧ�����ۼӺͰ�
            dp[i]=dp[i-1]+grid[0][i];
        for(int i=1;i<m;i++){
            // for(int j=n-1;j>=0;j--){
            //     dp[j]=max(dp[j],dp[j-1])+grid[i][j];
            // }//���Ǵ�ǰ������°����ҵ��죬������ʲô������
            for(int j=0;j<n;j++){
                if(j==0)
                    dp[j]+=grid[i][j];
                else
                    dp[j]=max(dp[j],dp[j-1])+grid[i][j];
            }
        }
        return dp.back();
    }
};
/*
 * 1.Ҳ�������˺ܶ�С���⣬̫�ֲ��˰�����������������������Թ�����Ļ���濴���Ҵ���룬�Ҿͽ��Ű���
 *   ��˼·�Ͳ��Ҷ��룬�����Ӷ������Ǿͺ������Թٰɣ��͵���һ��ˢ���ˡ�
 * 2.��ʼ�����⡢������£����ֲ���ʲô��Ʊ���⣬������������£����ԾͲ�Ҫ����һ��dp���ڿռ��Ż���
 *   ��ֱ��˵jҪ������£��㲻��Ҫ��ô�����������������������˼����̫�����ˣ��¿հס�
 * */
int main(){
    Solution1 s;
    vector<vector<int>> g={{1,3,1},{1,5,1},{4,2,1}};
    cout<<s.maxValue(g);
    return 0;
}
