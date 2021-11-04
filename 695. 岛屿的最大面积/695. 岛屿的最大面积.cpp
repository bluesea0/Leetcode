#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��13������3:24:23
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    int res=0;
                    dfs(grid,res,i,j);
                    ans=max(ans,res);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& grid,int& res,int i,int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0)return;
        res++;
        grid[i][j]=0;
        dfs(grid,res,i-1,j);
        dfs(grid,res,i+1,j);
        dfs(grid,res,i,j-1);
        dfs(grid,res,i,j+1);
    }
};
/*
 * 1.���ǱȽ�easy����Ŀ���ܽ�dfs���ģ���ס�Ϳ��ԡ�
 * �´θ�ϰ��һ��BFS��
 * */

//5-21
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0,m=grid.size(),n=grid[0].size();
        queue<int> q;
        int dirX[]={0,0,-1,1},dirY[]={1,-1,0,0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)continue;
                int cur=0;
                q.push(i*n+j);
                grid[i][j]=0;
                while(!q.empty()){
                    int t=q.front();q.pop();
                    int x=t/n,y=t%n;
                    //grid[x][y]=0;//���ܵȵ�������ʱ���ٸ�ֵΪ0���������ظ���ӣ�
                    //��������ӵ�ʱ��͸�ֵΪ0
                    //��Ȼ���1111�������ı��Σ���ô�ͻ����½ǵ�1�ܹ��������Ρ�
                    cur++;
                    for(int k=0;k<4;k++){
                        int xx=dirX[k]+x,yy=dirY[k]+y;
                        if(xx>=0&&yy>=0&&xx<m&&yy<n&&grid[xx][yy]){
                            q.push(xx*n+yy);
                            grid[xx][yy]=0;
                        }
                    }
                }
                ans=max(ans,cur);
            }
        }
        return ans;
    }
};
/*
 * 1.����������һЩ����ģ���Ҫ��ϰ�����ʱ�䣬�����Ϊ0��ʱ�䡣
 * */
int main(){

    return 0;
}
