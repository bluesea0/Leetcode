#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月13日下午2:11:19
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans=0,m=grid.size();
        if(grid[0][0]==1||grid[m-1][m-1]==1)return -1;//没想到还有样例[0][0]是这样的啊。
        queue<pair<int,int>> que;
        que.push({0,0});
        grid[0][0]=1;
        //那就需要搞8个不同的方向
        int dir_X[]={-1,-1,0,1,1,1,0,-1};
        int dir_Y[]={0,1,1,1,0,-1,-1,-1};
        while(!que.empty()){
            int len=que.size();
            for(int k=0;k<len;k++){
                int x=que.front().first,y=que.front().second;
                que.pop();//发现对队列的操作还不是特别熟悉啊。
                if(x==m-1&y==m-1)return ans+1;
                for(int i=0;i<8;i++){//朝8个方向推断
                    int tx=x+dir_X[i];
                    int ty=y+dir_Y[i];
                    if(tx>=0&&tx<m&&ty>=0&&ty<m&&grid[tx][ty]==0){
                        que.push({tx,ty});
                        grid[tx][ty]=1;//只要push进去了就为1
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
/*
 * 1.没有什么技术难度，时间是O(mn)，但是空间呢？O(m+n)，是的，因为BFS扩展最多保存的是一行+一列的点，那就是
 *   m+n。
 * 2.
 * */
int main(){

    return 0;
}
