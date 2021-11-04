#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-12
/*
1.那我就写一下DFS和BFS版本的，以示我已经掌握了这类题目。
2.再看题目差点有点被吓蒙了，不知道怎么写了！不过一下子又知道了呢。
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
        //既然这里它是可以被改变的，那改变的操作就在board自身上完成了。
        int m=board.size();
        if(m==0) return;
        int n=board[0].size();
        int j=0;//是真的要写四个循环吗？
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
//        return board;不应该return
    }
};
/*
4.看了官方给的dfs代码，还是人家写的简洁啊：
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
//真的学习了！人家主函数的循环是这么写的：
        for (int i = 0; i < n; i++) {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }
        for (int i = 1; i < m - 1; i++) {
            dfs(board, 0, i);
            dfs(board, n - 1, i);
//比我那两个while好很多。。。
时空都是O(mn)。
5.明天复习写一下BFS吧。主要还是考虑到语法不熟悉，所以要写一遍。
*/
int main(){
    Solution s;
    //如果要初始化那有点恐怖了，我要自己写样例。。。
    cout<<s.solve();
    return 0;
}
