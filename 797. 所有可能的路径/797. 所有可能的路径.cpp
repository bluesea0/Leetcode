#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��9��2������7:43:03
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
 * 1.����labu����⣬�����ҿ����������path��push_back��pop���Ⱥ�˳�����������Ҫ�ֶ�������һ�²ſ��ԡ�
 * 2.graph = [[1,2,3],[2],[3],[]]
 *   ��ô��dfs(0,{}):
 *   		  dfs(1,{0}):
 *   		     dfs(2,{0,1}):
 *   		        dfs({0,1,2},3):
 *   		        	dfs({0,1,2,3});//��n��pop_back()3Ȼ��return
 *   		        dfs({0,1,2});������2����ͨ�ĵ�Ȼ��pop_back2Ȼ��return
 *   		     dfs({0,1});��������1��ͨ�ĵ�Ȼ��pop_back1Ȼ��return
 *   		  dfs({0},2):
 *   		     dfs({0,2},3):#�ƺ�ͨ�ˡ�
   3.�Ҿ���labu����·�һ��Ǽ�һ�£�Ҫ����forѭ����������ڵ㣬������ô��Ϊ��Ȼ��forѭ�������Ķ���������ͨ��
     �ڵ㣬����֮����pop�����ڵ㡣
 * */
int main(){

    return 0;
}
