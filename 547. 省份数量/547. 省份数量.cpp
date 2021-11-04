#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月13日下午4:04:01
//class Solution {
//public:
//    int findCircleNum(vector<vector<int>>& isConnected) {
//        //并查集？那怎么查看呢？怎么查看最后有几个集合呢？
//        //而且我实在是想不通用DFS怎么做？遍历矩阵？不对吧。
//    }
//};
//这种是我没有见过的，不过是有新思路的。

//1-14
class Solution {
public:
    vector<int> visit;
    int findCircleNum(vector<vector<int>>& isConnected) {
        visit.resize(isConnected.size(),0);
        int circle=0;
        for(int i=0;i<isConnected.size();i++){
            if(visit[i]==0){//访问i城市所在的所有节点
                dfs(isConnected,i);
                circle++;
            }
        }
        return circle;
    }
    void dfs(vector<vector<int>>& isConnected,int city){
        visit[city]=1;
        for(int j=0;j<isConnected.size();j++){//只和点比它大的去遍历
            if(visit[j]==0&&isConnected[city][j]==1)
                 dfs(isConnected,j);
        }
        return ;
    }//明白了，j不能初始化为city+1，[[1,0,0,1],[0,1,1,0],[0,1,1,1],[1,0,1,1]]，还真有
    //前面的没遍历过的，遍历第4个点的时候确实前面的没有访问过
};
/*
 * 1.时间复杂度O(n^2)，O(n)，遇到的问题已经写上了，不过遍历到一个城市，然后把和它一起的全都遍历，学到了
 * 2.再来写一下BFS，其实感觉思路不那么清晰。
 * */
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //BFS也有思路了
        vector<int> visit(isConnected.size(),0);
        queue<int> q;
        int circle=0;
        for(int i=0;i<visit.size();i++){
            if(visit[i]==0){
                q.push(i);
                visit[i]=1;
                while(!q.empty()){
                    int k=q.front();q.pop();
                    for(int j=0;j<visit.size();j++){
                        if(visit[j]==0&&isConnected[k][j]==1){
                            q.push(j);
                            visit[j]=1;
                        }
                    }
                }
                circle++;
            }
        }
        return circle;
    }
};//BFS也写出来了，我也太棒了吧。
int main(){

    return 0;
}
