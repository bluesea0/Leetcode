#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��9��11������1:14:54
class Solution {
public:
    vector<int> vis,path,ans;
    bool cycle;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //˼·����ͼ���ж��Ƿ��޻���DFS���������ת������������
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
        if(cycle)return {};//����л����޷������������
        //����dfs
        //�п���ȫ���γ̲�����ͨ��һ��ģ������ô����
        //���ȼ�����������ͨ�İ�
        // for(int i=0;i<numCourses;i++){
        //     if(vis[i]==0)
        // }
        //���Ǳ���Ҳ��һ����0��ʼ�ɣ��ǵģ�����ֱ�Ӷ��ŵ�һ��ans��û��ϵ��
        vis.assign(numCourses,0);//������Ҫ����Ƿ���ʹ���
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
