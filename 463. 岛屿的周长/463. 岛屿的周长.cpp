#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年10月30日上午1:23:00
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        //思路：遍历，判断1的上下左右；如果是边缘的1，按情况+1/+2
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        if(n==0) return 0;//包含空向量的时候
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                if(i==0 || grid[i-1][j]==0) ans++;//上
                if(i==m-1 || grid[i+1][j]==0) ans++;//下
                if(j==0 || grid[i][j-1]==0) ans++;
                if(j==n-1 || grid[i][j+1]==0) ans++;
            }
        }
        return ans;
    }
};
/*
 * 1.每日一题，AC了，就是个easy的题目而已。上面用的迭代的方法。看了grand的解法，和他的第一个一样的！
 * 2.本来这是一道easy的题，但是DFS的解法我居然一时都想不出来怎么写，看啦就要写一下DFS了。
 * */
//class Solution {
//public:
//    int ans=0;
//    int islandPerimeter(vector<vector<int>>& grid) {
//        //DFS：
//        if(grid.size()==0)return 0;
//        if(grid[0].size()==0) return 0;//我要看一下官方有没有写这个判断
//        for(int i=0;i<grid.size();i++)
//            for(int j=0;j<grid[0].size();j++){
//                if(grid[i][j]==1){
//                    dfs(i,j,grid);break;
//                }
//            }
//        return ans;
//    }
//    int dfs(int i,int j,vector<vector<int>> &grid;){//怎么判断呢？忽然懵了。
//        if(i<0 || j<0 || i>=grid.size()|| j>=grid[0].size()) return 0;
//        //先判断四周
//        if(i==0 || grid[i-1][j])ans++;//好难啊，这方向怎么转啊，放弃。
//        //卧槽我是真的不会了。好难写啊。我是废物。
//    }
//};
/*
 * 1.DFS的思想是什么呢？去递归计算，先计算出来当前的是几，然后再去递归上下左右判断？
 *   返回的值是上下左右和当前的相加？有道理吧。
 * */
class Solution1 {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        //DFS：
        if(grid.size()==0)return 0;
        if(grid[0].size()==0) return 0;//我要看一下官方有没有写这个判断
        int ans=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    ans=dfs(i,j,grid);break;
                }
            }
        return ans;
    }
    int dfs(int i,int j,vector<vector<int>> &grid){//怎么判断呢？忽然懵了。
        int m=grid.size(),n=grid[0].size();
        if(i<0 || j<0 || i>=m|| j>=n|| grid[i][j]==2||grid[i][j]==0) return 0;
        //先判断四周
        int ans=0;
        if(i==0 || grid[i-1][j]==0)ans++;//好难啊，这方向怎么转啊
        //卧槽我是真的不会了。好难写啊。我是废物。
        if(i==m-1 || grid[i+1][j]==0)ans++;
        if(j==0 || grid[i][j-1]==0) ans++;
        if(j==n-1 || grid[i][j+1]==0) ans++;
        grid[i][j]=2;
        //下面递归去判断
        //C++里如何有效的控制上下左右的方向呢？
        int dirX[]={0,0,1,-1},dirY[]={1,-1,0,0};
        for(int k=0;k<4;k++){
            ans+=dfs(i+dirX[k],j+dirY[k],grid);
        }
        return ans;
    }
};//Yes,AC了！理清了思路之后感觉还蛮不错的！
//我去，看了一下官方的解答人家写的才厉害啊。。。
/*
 *         if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) {//这里只判断0的话，
            return 1;//如果是边界或者是0，那么直接返回。
        }
        if (grid[x][y] == 2) {//如果是2，则返回0，绝了！
            return 0;
        }

这样来判断是否返回，这不就比我的牛批多了吗。。。
 * */

//12-4复习
class Solution {
    constexpr static int dx[4] = {0, 1, 0, -1};
    constexpr static int dy[4] = {1, 0, -1, 0};
public:
    int dfs(int x, int y, vector<vector<int>> &grid, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) {
            return 1;//越界的或者是0的，就返回1
        }
        if (grid[x][y] == 2) {//是已经访问过的1，那么就返回0
            return 0;
        }
        grid[x][y] = 2;
        int res = 0;
        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            res += dfs(tx, ty, grid, n, m);
        }
        return res;
    }
    int islandPerimeter(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ans += dfs(i, j, grid, n, m);
                }
            }
        }
        return ans;
    }
};
/*
 * 1.贴一下官方的题解。
 * 2.我在复习口述思路的时候居然只想到了DFS，没有想到BFS，有病病了这就。已经总结到博客了。
 * 3.我觉得我的DFS辣鸡代码还是不要看了，还是学习官方给的吧。
 * 4.并且时间复杂度不是什么O(n^2)，而是O(mn)和矩阵相关的。
 * 5.下次复习的话可以写一下代码了。
 * */

//12-25
//官方的解写的真是优美啊，这就是优雅的代码，我这次复习并没有写，不过这次复习我没有想到可以用迭代
//直接想到的是dfs。其实真正上机的时候就迭代就ok了啊，多简洁。
int main(){

    return 0;
}
