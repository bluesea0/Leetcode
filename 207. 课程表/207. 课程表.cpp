#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#define MAX(a,b) (X>Y?X:Y)
using namespace std;
//2021年9月8日下午10:14:58
//class Solution {
//public:
//    vector<int> vis;
//    bool cycle;
//    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//        //即查看是否存在环，如果存在环相当于死锁。
//        vis.resize(numCourses,0);
//        cycle=false;
//        //构建图
//        vector<vector<int>> graph(numCourses,vector<int>());//怎么初始化？
//        for(int i=0;i<prerequisites.size();i++){
//            int fr=prerequisites[i][1];
//            int to=prerequisites[i][0];
//            graph[fr].push_back(to);
//        }
//        for(int i=0;i<numCourses;i++){
//            if(vis[i]==0)
//                dfs(i,graph);
//        }
//        return !cycle;
//    }
//    void dfs(int index, vector<vector<int>>& graph){
//        if(vis[index]){
//            cycle=true;
//            return;
//        }
//        vis[index]=1;
//        for(int i=0;i<graph[index].size();i++){
//            dfs(graph[index][i],graph);
//        }
//        //还需要置0吗？我觉得没必要啊。
//        vis[index]=0;//需要，如样例2,[[0,1]]，在完成0之前要先完成1，但是根据下标
//        //先遍历的是0，在遍历到1时，0已经被标记了，这里回溯的目的是为了保证1只是在当前一次的dfs中
//        //才会才会有结果。
//    }
//};
/*
 * 1.上面的代码是错的，不止要有vis数组，vis标记是否已经访问过，还要有个path来记录当前遍历到的路径，
 *   如果只有vis的话，只标记1，就像上面的样例，先后顺序会发生改变。
 *   如果vis标记回0的话，那么假设只有一条路径，它就会仍然下次去遍历，所以就会产生超时。
 * 2.图中的节点有三种状态：「未搜索」：我们还没有搜索到这个节点；
 *   「搜索中」：我们搜索过这个节点，但还没有回溯到该节点，即该节点还没有入栈，还有相邻的节点没有搜索完成）；
 *   「已完成」：我们搜索过并且回溯过这个节点，即该节点已经入栈，并且所有该节点的相邻节点都出现在栈的
 *    更底部的位置，满足拓扑排序的要求。
 * */
class Solution {
public:
    vector<int> vis,path;
    bool cycle;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //即查看是否存在环，如果存在环相当于死锁。
        vis.resize(numCourses,0);
        path.resize(numCourses,0);
        cycle=false;
        //构建图
        vector<vector<int>> graph(numCourses,vector<int>());//怎么初始化？
        for(int i=0;i<prerequisites.size();i++){
            int fr=prerequisites[i][1];
            int to=prerequisites[i][0];
            graph[fr].push_back(to);
        }
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0)
                dfs(i,graph);
        }
        return !cycle;
    }
    void dfs(int index, vector<vector<int>>& graph){
        if(path[index]){
            cycle=true;
            return;
        }
        if(cycle||vis[index])return;//我还是不太懂这里的判断。可能要明天学完拓扑排序之后吧
        vis[index]=1;
        path[index]=1;
        for(int i=0;i<graph[index].size();i++){
            dfs(graph[index][i],graph);
        }
        path[index]=0;
        //还需要置0吗？我觉得没必要啊。
        //vis[index]=0;//需要，如样例2,[[0,1]]，在完成0之前要先完成1，但是根据下标
        //先遍历的是0，在遍历到1时，0已经被标记了，这里回溯的目的是为了保证1只是在当前一次的dfs中
        //才会才会有结果。
    }
};
int main(){

    return 0;
}
