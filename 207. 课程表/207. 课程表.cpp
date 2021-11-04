#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#define MAX(a,b) (X>Y?X:Y)
using namespace std;
//2021��9��8������10:14:58
//class Solution {
//public:
//    vector<int> vis;
//    bool cycle;
//    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//        //���鿴�Ƿ���ڻ���������ڻ��൱��������
//        vis.resize(numCourses,0);
//        cycle=false;
//        //����ͼ
//        vector<vector<int>> graph(numCourses,vector<int>());//��ô��ʼ����
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
//        //����Ҫ��0���Ҿ���û��Ҫ����
//        vis[index]=0;//��Ҫ��������2,[[0,1]]�������0֮ǰҪ�����1�����Ǹ����±�
//        //�ȱ�������0���ڱ�����1ʱ��0�Ѿ�������ˣ�������ݵ�Ŀ����Ϊ�˱�֤1ֻ���ڵ�ǰһ�ε�dfs��
//        //�Ż�Ż��н����
//    }
//};
/*
 * 1.����Ĵ����Ǵ�ģ���ֹҪ��vis���飬vis����Ƿ��Ѿ����ʹ�����Ҫ�и�path����¼��ǰ��������·����
 *   ���ֻ��vis�Ļ���ֻ���1������������������Ⱥ�˳��ᷢ���ı䡣
 *   ���vis��ǻ�0�Ļ�����ô����ֻ��һ��·�������ͻ���Ȼ�´�ȥ���������Ծͻ������ʱ��
 * 2.ͼ�еĽڵ�������״̬����δ�����������ǻ�û������������ڵ㣻
 *   �������С�����������������ڵ㣬����û�л��ݵ��ýڵ㣬���ýڵ㻹û����ջ���������ڵĽڵ�û��������ɣ���
 *   ������ɡ����������������һ��ݹ�����ڵ㣬���ýڵ��Ѿ���ջ���������иýڵ�����ڽڵ㶼������ջ��
 *    ���ײ���λ�ã��������������Ҫ��
 * */
class Solution {
public:
    vector<int> vis,path;
    bool cycle;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //���鿴�Ƿ���ڻ���������ڻ��൱��������
        vis.resize(numCourses,0);
        path.resize(numCourses,0);
        cycle=false;
        //����ͼ
        vector<vector<int>> graph(numCourses,vector<int>());//��ô��ʼ����
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
        if(cycle||vis[index])return;//�һ��ǲ�̫��������жϡ�����Ҫ����ѧ����������֮���
        vis[index]=1;
        path[index]=1;
        for(int i=0;i<graph[index].size();i++){
            dfs(graph[index][i],graph);
        }
        path[index]=0;
        //����Ҫ��0���Ҿ���û��Ҫ����
        //vis[index]=0;//��Ҫ��������2,[[0,1]]�������0֮ǰҪ�����1�����Ǹ����±�
        //�ȱ�������0���ڱ�����1ʱ��0�Ѿ�������ˣ�������ݵ�Ŀ����Ϊ�˱�֤1ֻ���ڵ�ǰһ�ε�dfs��
        //�Ż�Ż��н����
    }
};
int main(){

    return 0;
}
