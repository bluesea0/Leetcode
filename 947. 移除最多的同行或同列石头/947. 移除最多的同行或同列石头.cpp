#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月15日下午4:06:39
//class Solution {
//public:
//    int removeStones(vector<vector<int>>& stones) {
//        //不太会，既然要移除最大，那么就是保留最少？
//        //想到了用dp，贪心？但是dp[i]又能表示什么呢？
//        //又想到了用两个哈希表分别保存行和列对应的位置，但是也并不能保证移除石子数量最大。
//    }
//};
/*
 * 1.我确实是不太行，我根本想不到并查集的思路啊，我的妈。
 * */
class Solution {
public:
    unordered_map<int,int> fa;
    int count=0;
    int removeStones(vector<vector<int>>& stones) {
        //原来father数组可以用哈希表啊，我还以为只能用向量表示，那该得多大啊。
        for(int i=0;i<stones.size();i++){
            merge(stones[i][0]+10001,stones[i][1]);
        }
        return stones.size()-count;
    }
    void merge(int i,int j){
        int fi=find(i);
        int fj=find(j);
        if(fi==fj)return;
        fa[fi]=fj;
        count--;//合并了一个连通分量
        //if(fi!=fj)res--;//该怎么控制呢？就算相等有可能是i和j本身相等？
        //而且i和j同属于一个坐标，这我就不明白了，到底该怎么操作呢？
    }
    int find(int x){
        if(fa.count(x)==0){
            count++;
            return fa[x]=x;
        }//如果没有的话，那就建立映射
        return fa[x]==x?x:(fa[x]=find(fa[x]));
    }
};//挺难的，我的妈，差点自闭。
/*
 * 1.将横纵坐标都合并在一起，并且这个集合数量计算也有技巧。这里没有用数组，因为坐标的跨度是很大的，
 *   可以用哈希表代替定长的fa数组。集合数量计算首先每新来一个节点，计算结果+1，当合并的时候-1.绝了。
 *   如果本身同属于一个连通分量，那么就返回。
 * */
int main(){

    return 0;
}
