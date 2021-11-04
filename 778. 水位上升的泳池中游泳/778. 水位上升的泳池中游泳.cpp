#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月1日下午3:29:22
//class Solution {
//public:
//    int swimInWater(vector<vector<int>>& grid) {
//        //我还是不太懂这个题，因为它加了时间限制的啊
//        //那如果是直接求最短路径，那又怎么确保是符合时间t的限制呢？
//    }
//};
class Solution {
public:
    vector<int> visit;
    int swimInWater(vector<vector<int>>& grid) {
        //我写一下二分法，并且用DFS
        int N=grid.size();
        int left=0,right=N*N;
        visit.resize(N*N,0);
        while(left<right){
            int mid=left+(right-left)/2;
            fill(visit.begin(),visit.end(),0);
            if(grid[0][0]<=mid)
                dfs(0,0,mid,grid);
            if(visit[N*N-1])
                right=mid;
            else left=mid+1;
        }
        return left;
    }
    void dfs(int x,int y,int k,vector<vector<int>>& grid){
        int n=grid.size();
        if(x<0||x>=n||y<0||y>=n||visit[x*n+y]||grid[x][y]>k)return;
        visit[x*n+y]=1;
        dfs(x-1,y,k,grid);
        dfs(x+1,y,k,grid);
        dfs(x,y-1,k,grid);
        dfs(x,y+1,k,grid);
    }
};
/*
 * 1.上面的AC了，绝了绝了，我还以为resize能再次赋值呢。。。我绝望了。幸好发现了这个秘密。
 * 明天写并查集，和1631一起。
 * */

//2-2
//使用map来记录[0,N*N-1]中对应的下标，从小到大遍历将其对应的格子加入
//合并，并且查看00和n*n-1的连通性
/*
 * 1.我一开始的想法是这样的，而且遍历时间的过程中将所有符合的和0值合并，发现错了，确实错了，因为可能
 *   并不是连通的，题目中给的第二个样例就很说明问题，0和其他不是挨着的，要走一段距离的。
 * 2.正确的思路是将每一个符合的点上下左右四个方向符合的点合并。
 * */
class Union{
public:
    vector<int> fa;
    Union(int n){
        fa.resize(n);
        for(int i=0;i<fa.size();i++)
            fa[i]=i;
    }
    void merge(int x,int y){
        int fx=find(x);
        int fy=find(y);
        if(fx==fy)return;
        fa[fx]=fy;
    }
    int find(int x){
        return fa[x]==x?x:(fa[x]=find(fa[x]));
    }
    bool connect(int x,int y){
        int fx=find(x);
        int fy=find(y);
        if(fx==fy)return true;
        return false;
    }
};
class Solution2 {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int dirX[]={0,0,1,-1},dirY[]={1,-1,0,0};
        int n=grid.size();
        vector<int> mp(n*n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[grid[i][j]]=i*n+j;//时间到坐标的映射。
            }
        }
        Union u(n*n);
        for(int k=1;k<n*n;k++){
            int x=mp[k]/n,y=mp[k]%n;//这里需要将时间映射到坐标上。
            for(int i=0;i<4;i++){
                int nx=x+dirX[i],ny=y+dirY[i];
                if(nx<0||ny<0||nx>=n||ny>=n||grid[nx][ny]>k)continue;
                u.merge(mp[k],nx*n+ny);//这里应该合并的是对应时间上符合的上下左右的坐标
                //第一个参数对应到时间为k的坐标，第二个参数是上下左右的坐标。
            }
            if(u.connect(0,n*n-1))return k;
        }
        return 0;
    }
};
/*
 * 1.终于AC了，我都给整懵了！！！果然是Hard的题目啊！
 * 2.要注意的是fa存的是matrix的每一格是否连通
 * */
int main(){
//	Solution s;
//	vector<vector<int>> grid={{0,2},{1,3}};
//	vector<int> a;
//	a.resize(5,0);
//	for(int i=0;i<a.size();i++){
//		a[i]=5;
//	}
//	a.resize(5,0);
//	for(auto b:a)
//		cout<<b<<" ";
	cout<<(85&192)<<endl;
    return 0;
}
