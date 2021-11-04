#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��4������4:35:47
class Solution {
public:
    vector<int> fa;
    vector<double> weight;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //���Ѱ�������������⣬��Ҫ��ʼ��ս�Լ��ˣ�
        unordered_map<string,int> um;
        //�ȶ�equations���ַ�����
        int ct=0;
        for(auto& eq:equations){
            if(um.count(eq[0])==0)um[eq[0]]=ct++;
            if(um.count(eq[1])==0)um[eq[1]]=ct++;
        }
        //���潨�����鼯
        fa.resize(ct);
        weight.resize(ct,1.0);
        for(int i=0;i<fa.size();i++)
            fa[i]=i;
        for(int i=0;i<equations.size();i++){
            int x=um[equations[i][0]];
            int y=um[equations[i][1]];
            merge(x,y,values[i]);//�����߽�����ϵ�ϲ�
        }
        vector<double> ans;
        for(int i=0;i<queries.size();i++){
            double res=-1.0;//��ѽ�������resҲӦ����double�İ����ҿ��ˣ�����
            if(um.count(queries[i][0])&&um.count(queries[i][1])){
                //����Ҫ��һ�����鼯�����ȷ�Ϲ�ϵ��
                res=connect(um[queries[i][0]],um[queries[i][1]]);
            }
            ans.push_back(res);
        }
        // for(int i=0;i<fa.size();i++){
        //     cout<<fa[i]<<" "<<weight[i]<<endl;
        // }
        return ans;
    }
    void merge(int x,int y,double value){
        int fx=find(x);
        int fy=find(y);
        //������Ҫ���ǣ�����Ѿ���һ������������ô�죿
        if(fx==fy)return;
        fa[fx]=fy;
        weight[fx]=weight[y]*value/weight[x];
    }
    int find(int x){//Ѱ�ҵ�ʱ��ѹ��·��
        if(x!=fa[x]){
            int origin=fa[x];
            fa[x]=find(fa[x]);//����father��ʱ�򣬶�Ӧ��Ȩ��ҲҪ���ġ�
            weight[x]*=weight[origin];
        }
        return fa[x];
    }
    double connect(int x,int y){
        int fx=find(x);//�����ڲ��ҵ�ʱ���ǻ�ѹ��·����
        int fy=find(y);
        if(fx==fy){
            // cout<<weight[x]<<" "<<weight[y]<<endl;
            return weight[x]/weight[y];
        }
        return -1.0;
    }
};
/*
 * 1.��Ȩ�صĲ��鼯��̫���ˣ�����˵�ѣ��ǿ϶������׵ģ�
 * 2.�и��ܴ��������ǣ������õ���double����ˢ������У���ʵ����õĲ��࣬����������ͳ���������
 *   res�Ҿ�Ȼ��ʼ������int�ͣ��ǿɲ��ͱ��治��double�𣡣���
 * 3.���Ӷȣ�O((N+Q)logA)��N�����뷽�̳��ȣ�Q�ǲ�ѯ���ȣ�A�Ƿ����в�ͬ�ַ�������O(A)�ռ�
 *   �ڿ��Ǹ��Ӷȵ�ʱ���Ҿ�Ȼû�п���Q��ֻ�뵽��N������
 * */
int main(){

    return 0;
}
