#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��1������3:29:22
//class Solution {
//public:
//    int swimInWater(vector<vector<int>>& grid) {
//        //�һ��ǲ�̫������⣬��Ϊ������ʱ�����Ƶİ�
//        //�������ֱ�������·����������ôȷ���Ƿ���ʱ��t�������أ�
//    }
//};
class Solution {
public:
    vector<int> visit;
    int swimInWater(vector<vector<int>>& grid) {
        //��дһ�¶��ַ���������DFS
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
 * 1.�����AC�ˣ����˾��ˣ��һ���Ϊresize���ٴθ�ֵ�ء������Ҿ����ˡ��Һ÷�����������ܡ�
 * ����д���鼯����1631һ��
 * */

//2-2
//ʹ��map����¼[0,N*N-1]�ж�Ӧ���±꣬��С������������Ӧ�ĸ��Ӽ���
//�ϲ������Ҳ鿴00��n*n-1����ͨ��
/*
 * 1.��һ��ʼ���뷨�������ģ����ұ���ʱ��Ĺ����н����з��ϵĺ�0ֵ�ϲ������ִ��ˣ�ȷʵ���ˣ���Ϊ����
 *   ��������ͨ�ģ���Ŀ�и��ĵڶ��������ͺ�˵�����⣬0���������ǰ��ŵģ�Ҫ��һ�ξ���ġ�
 * 2.��ȷ��˼·�ǽ�ÿһ�����ϵĵ����������ĸ�������ϵĵ�ϲ���
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
                mp[grid[i][j]]=i*n+j;//ʱ�䵽�����ӳ�䡣
            }
        }
        Union u(n*n);
        for(int k=1;k<n*n;k++){
            int x=mp[k]/n,y=mp[k]%n;//������Ҫ��ʱ��ӳ�䵽�����ϡ�
            for(int i=0;i<4;i++){
                int nx=x+dirX[i],ny=y+dirY[i];
                if(nx<0||ny<0||nx>=n||ny>=n||grid[nx][ny]>k)continue;
                u.merge(mp[k],nx*n+ny);//����Ӧ�úϲ����Ƕ�Ӧʱ���Ϸ��ϵ��������ҵ�����
                //��һ��������Ӧ��ʱ��Ϊk�����꣬�ڶ����������������ҵ����ꡣ
            }
            if(u.connect(0,n*n-1))return k;
        }
        return 0;
    }
};
/*
 * 1.����AC�ˣ��Ҷ��������ˣ�������Ȼ��Hard����Ŀ����
 * 2.Ҫע�����fa�����matrix��ÿһ���Ƿ���ͨ
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
