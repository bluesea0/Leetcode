#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年9月11日上午1:14:54
class Solution {
public:
    vector<int> vis,path,ans;
    bool cycle;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //思路：建图、判断是否无环、DFS后序遍历反转后即拓扑排序结果
        if(numCourses==0)return{};
        vector<vector<int>> graph(numCourses,vector<int>());
        for(auto& p:prerequisites){
            int fr=p[1];
            int to=p[0];
            graph[fr].push_back(to);
        }
        vis.resize(numCourses,0);
        path.resize(numCourses,0);
        cycle=false;
        for(int i=0;i<numCourses;i++){
            hasCycle(graph,i);
        }
        if(cycle)return {};//如果有环就无法完成拓扑排序
        //进行dfs
        //有可能全部课程不是连通在一起的？这个怎么处理？
        //我先假设它都是连通的吧
        // for(int i=0;i<numCourses;i++){
        //     if(vis[i]==0)
        // }
        //但是遍历也不一定从0开始吧？是的！所以直接都放到一个ans里没关系的
        vis.assign(numCourses,0);//还是需要标记是否访问过的
        for(int i=0;i<numCourses;i++)
            dfs(graph,i);
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void dfs(vector<vector<int>>&graph,int ind){
        if(vis[ind])return;
        vis[ind]=1;
        for(int i=0;i<graph[ind].size();i++)
            dfs(graph,graph[ind][i]);
        ans.push_back(ind);
    }
    void hasCycle(vector<vector<int>>&graph,int ind){
        if(path[ind]){
            cycle=true;
            return;
        }
        if(vis[ind]||cycle)return;
        vis[ind]=1;
        path[ind]=1;
        for(int i=0;i<graph[ind].size();i++){
            hasCycle(graph,graph[ind][i]);
        }
        path[ind]=0;
    }
};
int main(){

    return 0;
}
