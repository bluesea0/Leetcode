#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年10月12日下午10:22:41
int bfs(vector<vector<char>>& graph,int x,int y){
	int m=graph.size(),n=graph[0].size();
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));
	int count=0;
	int dirX[]={0,0,-1,1},dirY[]={1,-1,0,0};
	vector<vector<int>> visit(m,vector<int>(n,0));
	visit[x][y]=1;
	while(!q.empty()){
		int len=q.size();
		count++;
		while(len--){
			auto top=q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int nx=top.first+dirX[i];
				int ny=top.second+dirY[i];
				if(nx<0||ny<0||nx>=m||ny>=n||graph[nx][ny]=='#'||visit[nx][ny])continue;
				if(graph[nx][ny]=='*')return count;
				q.push(make_pair(nx,ny));
				visit[nx][ny]=1;
			}
		}
	}
	return -1;
}
int main(){
	int m,n;
	while(cin>>m>>n){
		if(m==0&&n==0)break;
		vector<vector<char>> graph(m,vector<char>(n));
		int start_x,start_y;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>graph[i][j];
				if(graph[i][j]=='@'){
					start_x=i;
					start_y=j;
				}
			}
		}
		cout<<bfs(graph,start_x,start_y)<<"\n";
	}
	/*
	 * Yes!AC啦！
	 *http://noi.openjudge.cn/ch0205/2727/，题目地址。
	 * */
    return 0;
}
