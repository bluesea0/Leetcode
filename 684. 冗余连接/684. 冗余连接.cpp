#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月13日下午3:00:52
class Solution {
public:
    vector<int> fa;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //并查集，对给定边的两个节点，判断是否已经在一个联通分量中，则删去
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
        return {-1,-1};//象征性的返回
    }
    int find(int x){
        return fa[x]==x?x:(fa[x]=find(fa[x]));//又是find写错了
    }
    void merge(int i,int j){
        fa[find(i)]=find(j);
    }
};
/*
 * 1.我find这是第二次写错了。。。如果当前不是集的代表员，那么就要去找它的fa[x]，而不是直接find(x)，这样
 *   会导致无限递归的。上一次是忘记压缩路径导致超时了。
 * 2.但其实我一开始并没有想到并查集的用法，看到官解给的解法，反应了一会才想到要怎么用这个并查集。
 * 3.时间复杂度，就并查集来说，好像是比较难分析？官解中的分析真不错，N是图中节点的个数，对于每条边，
 *   需要find两次+合并一次，总时间复杂度是O(2NlogN)，N是图中节点的个数，对于使用路径压缩的并查集来说，
 *   最坏情况下是O(NlogN)。空间是O(N)，因为使用了fa数组。
 * */
int main(){

    return 0;
}
