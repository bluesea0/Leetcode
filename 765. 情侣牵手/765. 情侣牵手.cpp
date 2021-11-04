#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月14日下午4:40:22
/*
 * 1.看到这个其实想到了并查集，但是想不到具体怎么用，看了题解明白了一些，ans是每个连通分量的大小-1是
 *   交换次数，这个才是题眼。
 * */

//2-15
class Solution {
public:
    vector<int> fa;
    int minSwapsCouples(vector<int>& row) {
        //用并查集做一下
        int total=row.size()/2;
        fa.resize(total,0);
        for(int i=0;i<total;i++)
            fa[i]=i;
        //接下来合并
        for(int i=0;i<row.size();i+=2){
            int x=row[i]/2;//除以2是为了确认它属于哪个group
            int y=row[i+1]/2;
            merge(x,y);
        }
        unordered_map<int,int> um;
        for(int i=0;i<total;i++){
            //这里还要再查询一下！
            fa[i]=find(i);
            um[fa[i]]++;
        }
        int ans=0;
        for(const auto& [k,v]:um){
            ans+=(v-1);
        }
        return ans;
    }
    void merge(int x,int y){//我这样merge，它不一定每个都是指向根节点的一层树
        //[5,4,2,6,3,1,0,7] 这样得出来的fa数组是[0,3,2,0]就出现了错误
        //懂了，每次都要再查询一下！
        int fx=find(x);
        int fy=find(y);
        if(fx==fy)return;
        fa[fx]=fy;
    }
    int find(int i){
        return fa[i]==i?i:(fa[i]=find(fa[i]));
    }
};//明天来写一下BFS

//3-25
/*
 * 1.这个题目还是有点难度的，它将每对情侣视为一起的，那么最后计算每个联通子集下的个数的时候是通过哈希表来统计
 *   的，当然如果要计算有多少个联通的话，是可以有一个变量来记录，在merge的时候--。
 * */
int main(){

    return 0;
}
