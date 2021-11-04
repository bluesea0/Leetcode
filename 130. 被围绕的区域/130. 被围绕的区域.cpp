#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-12
/*
1.���Ҿ�дһ��DFS��BFS�汾�ģ���ʾ���Ѿ�������������Ŀ��
2.�ٿ���Ŀ����е㱻�����ˣ���֪����ôд�ˣ�����һ������֪�����ء�
*/
class Solution {
private:
    void dfs(vector<vector<char>>& board,int i,int j){
        int m=board.size(),n=board[0].size();
        board[i][j]='#';
        int dirX[]={0,0,-1,1},dirY[]={-1,1,0,0};
        for(int k=0;k<sizeof(dirX)/sizeof(dirX[0]);k++){
            int x=i+dirX[k],y=j+dirY[k];
            if(x>=0 && y>=0 && x<m && y<n && board[x][y]=='O')
                dfs(board,x,y);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        //��Ȼ�������ǿ��Ա��ı�ģ��Ǹı�Ĳ�������board����������ˡ�
        int m=board.size();
        if(m==0) return;
        int n=board[0].size();
        int j=0;//�����Ҫд�ĸ�ѭ����
        while(j<n){
            if(board[0][j]=='O')
                dfs(board,0,j);
            if(board[m-1][j]=='O')
                dfs(board,m-1,j);
            j++;
        }
        int i=0;
        while(i<m){
            if(board[i][0]=='O')
                dfs(board,i,0);
            if(board[i][n-1]=='O')
                dfs(board,i,n-1);
            i++;
        }
        for(auto &bo:board){
            for(auto &b:bo){
                if(b=='O')
                    b='X';
                if(b=='#')
                    b='O';
            }
        }
//        return board;��Ӧ��return
    }
};
/*
4.���˹ٷ�����dfs���룬�����˼�д�ļ�డ��
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'A';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }
//���ѧϰ�ˣ��˼���������ѭ������ôд�ģ�
        for (int i = 0; i < n; i++) {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }
        for (int i = 1; i < m - 1; i++) {
            dfs(board, 0, i);
            dfs(board, n - 1, i);
//����������while�úܶࡣ����
ʱ�ն���O(mn)��
5.���츴ϰдһ��BFS�ɡ���Ҫ���ǿ��ǵ��﷨����Ϥ������Ҫдһ�顣
*/
int main(){
    Solution s;
    //���Ҫ��ʼ�����е�ֲ��ˣ���Ҫ�Լ�д����������
    cout<<s.solve();
    return 0;
}
