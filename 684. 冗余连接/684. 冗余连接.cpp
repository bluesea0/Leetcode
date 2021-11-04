#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��13������3:00:52
class Solution {
public:
    vector<int> fa;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //���鼯���Ը����ߵ������ڵ㣬�ж��Ƿ��Ѿ���һ����ͨ�����У���ɾȥ
        int n=edges.size();
        fa.resize(n+1);
        for(int i=0;i<=n;i++)
            fa[i]=i;
        for(auto& edge:edges){
            int fi=find(edge[0]);
            int fj=find(edge[1]);
            if(fi==fj)
                return edge;
            else merge(fi,fj);
        }
        return {-1,-1};//�����Եķ���
    }
    int find(int x){
        return fa[x]==x?x:(fa[x]=find(fa[x]));//����findд����
    }
    void merge(int i,int j){
        fa[find(i)]=find(j);
    }
};
/*
 * 1.��find���ǵڶ���д���ˡ����������ǰ���Ǽ��Ĵ���Ա����ô��Ҫȥ������fa[x]��������ֱ��find(x)������
 *   �ᵼ�����޵ݹ�ġ���һ��������ѹ��·�����³�ʱ�ˡ�
 * 2.����ʵ��һ��ʼ��û���뵽���鼯���÷��������ٽ���Ľⷨ����Ӧ��һ����뵽Ҫ��ô��������鼯��
 * 3.ʱ�临�Ӷȣ��Ͳ��鼯��˵�������ǱȽ��ѷ������ٽ��еķ����治��N��ͼ�нڵ�ĸ���������ÿ���ߣ�
 *   ��Ҫfind����+�ϲ�һ�Σ���ʱ�临�Ӷ���O(2NlogN)��N��ͼ�нڵ�ĸ���������ʹ��·��ѹ���Ĳ��鼯��˵��
 *   ��������O(NlogN)���ռ���O(N)����Ϊʹ����fa���顣
 * */
int main(){

    return 0;
}
