#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年9月2日下午7:43:03
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs(graph,0,path);
        return ans;
    }
    void dfs(vector<vector<int>>& graph,int n,vector<int> path){
        path.push_back(n);
        if(n+1==graph.size()){
            ans.push_back(path);
            path.pop_back();
            return ;
        }
        for(int i=0;i<graph[n].size();i++){
            dfs(graph,graph[n][i],path);
        }
        path.pop_back();
    }
};
/*
 * 1.看了labu的题解，但是我看不明白这个path的push_back和pop的先后顺序操作。我需要手动的运行一下才可以。
 * 2.graph = [[1,2,3],[2],[3],[]]
 *   那么：dfs(0,{}):
 *   		  dfs(1,{0}):
 *   		     dfs(2,{0,1}):
 *   		        dfs({0,1,2},3):
 *   		        	dfs({0,1,2,3});//到n了pop_back()3然后return
 *   		        dfs({0,1,2});遍历完2所联通的点然后pop_back2然后return
 *   		     dfs({0,1});遍历完了1联通的点然后pop_back1然后return
 *   		  dfs({0},2):
 *   		     dfs({0,2},3):#似乎通了。
   3.我觉得labu的套路我还是记一下，要先在for循环外遍历根节点，可以这么认为，然后for循环遍历的都是它所联通的
     节点，结束之后再pop出根节点。
 * */
int main(){

    return 0;
}
