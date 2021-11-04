#include <iostream>
#include<vector>
#include<queue>
using namespace std;

class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    ++count;
                }
                else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            --count;
        }
    }

    int getCount() const {
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        UnionFind uf(grid);
        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    grid[r][c] = '0';
                    if (r - 1 >= 0 && grid[r-1][c] == '1') uf.unite(r * nc + c, (r-1) * nc + c);
                    if (r + 1 < nr && grid[r+1][c] == '1') uf.unite(r * nc + c, (r+1) * nc + c);
                    if (c - 1 >= 0 && grid[r][c-1] == '1') uf.unite(r * nc + c, r * nc + c - 1);
                    if (c + 1 < nc && grid[r][c+1] == '1') uf.unite(r * nc + c, r * nc + c + 1);
                }
            }
        }

        return uf.getCount();
    }
};

//5-20
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() or grid[0].empty()) return 0;
        int m=grid.size();
        int n=grid[0].size();
//        int visit[m][n]={{0},{0}};
        vector<vector<bool>> visit(m,vector<bool>(n));
        //que=queue();
        queue<int> que{};//这里声明了只能装int类型的//queue存储的是下标展开
        int ct=0;
        int dirX[]={-1,0,1,0},dirY[]={0,1,0,-1};
        for(int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if(grid[i][j]=='0' || visit[i][j]) continue;
                que.push(i*n+j);
                visit[i][j]=true;
                ct++;
                while(!que.empty()){//每次会遍历完一个岛屿
                    int t=que.front();que.pop();
                    for(int k=0;k<4;k++){
                        int xx=t/n+dirX[k],yy=t%n+dirY[k];
                        if(xx>=0 && yy>=0 && xx<m && yy<n &&grid[xx][yy]=='1' and !visit[xx][yy]){
                            que.push(xx*n+yy);
                            visit[xx][yy]=true;
                        }
                    }
                }
                }
            }
        return ct;
    }
};
//DFS模板
class Solution {
public:
    int ans=0;
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    ans++;
                }
            }
        return ans;
    }
    void dfs(vector<vector<char>>& grid,int x,int y){
        if(x<0||y<0||x>=grid.size()||y>=grid[0].size()||grid[x][y]=='0')return;
        grid[x][y]='0';
        dfs(grid,x-1,y);
        dfs(grid,x+1,y);
        dfs(grid,x,y-1);
        dfs(grid,x,y+1);
    }
};
/*
 * 1.在写dfs解法的时候出现了问题，人家是字符数组好吗！！！以为是整数，所以提交错了一次。
 * */
int main()
{
    Solution s;
    cout<<x<<endl;
    return 0;
}
