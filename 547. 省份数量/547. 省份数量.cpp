#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��13������4:04:01
//class Solution {
//public:
//    int findCircleNum(vector<vector<int>>& isConnected) {
//        //���鼯������ô�鿴�أ���ô�鿴����м��������أ�
//        //������ʵ�����벻ͨ��DFS��ô�����������󣿲��԰ɡ�
//    }
//};
//��������û�м����ģ�����������˼·�ġ�

//1-14
class Solution {
public:
    vector<int> visit;
    int findCircleNum(vector<vector<int>>& isConnected) {
        visit.resize(isConnected.size(),0);
        int circle=0;
        for(int i=0;i<isConnected.size();i++){
            if(visit[i]==0){//����i�������ڵ����нڵ�
                dfs(isConnected,i);
                circle++;
            }
        }
        return circle;
    }
    void dfs(vector<vector<int>>& isConnected,int city){
        visit[city]=1;
        for(int j=0;j<isConnected.size();j++){//ֻ�͵�������ȥ����
            if(visit[j]==0&&isConnected[city][j]==1)
                 dfs(isConnected,j);
        }
        return ;
    }//�����ˣ�j���ܳ�ʼ��Ϊcity+1��[[1,0,0,1],[0,1,1,0],[0,1,1,1],[1,0,1,1]]��������
    //ǰ���û�������ģ�������4�����ʱ��ȷʵǰ���û�з��ʹ�
};
/*
 * 1.ʱ�临�Ӷ�O(n^2)��O(n)�������������Ѿ�д���ˣ�����������һ�����У�Ȼ��Ѻ���һ���ȫ��������ѧ����
 * 2.����дһ��BFS����ʵ�о�˼·����ô������
 * */
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //BFSҲ��˼·��
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
};//BFSҲд�����ˣ���Ҳ̫���˰ɡ�
int main(){

    return 0;
}
