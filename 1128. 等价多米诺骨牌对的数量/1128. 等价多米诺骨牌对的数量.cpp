#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月26日下午2:07:19
class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        //在比较之前先交换内部的元素
        if(a[0]>a[1])swap(a[0],a[1]);
        if(b[0]>b[1])swap(b[0],b[1]);
        if(a[0]<b[0])return true;
        else if(a[0]==b[0])return a[1]<b[1];//仍需要加这个判断，
        return false;//并且必须有所返回！
    }
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        sort(dominoes.begin(),dominoes.end(),cmp);//默认不都从小到大吗？
        //默认排序排出来有问题，前两项仍是[1,2],[2,1]，不会排好啊
        // sort(dominoes.begin(),dominoes.end(),[](){});//这样也不行，因为只顾到了第一个
        int res=0,m=dominoes.size();
        //这我就不明白了，如果是连着的3个的话，那么该怎么计算呢？
        //算有3对？这？
        // for(auto p:dominoes)
        //     cout<<p[0]<<" "<<p[1]<<endl;
        for(int i=0;i+1<m;i++){
            int t=0;
            while(i+1<m&&((dominoes[i][0]==dominoes[i+1][0]&&dominoes[i][1]==dominoes[i+1][1])||(dominoes[i][0]==dominoes[i+1][1]&&dominoes[i][1]==dominoes[i+1][0]))){
                i++;t++;
            }
            while(t){
                res+=t;
                t--;
            }
        }
        return res;
    }
};
/*
 * 1.上面是我非常错误的思路，真的就能从这道题看出来算法水平，我真是算法水平太低了吧。。。
 *  因为比如这个例子[[2,1],[5,4],[3,7],[6,2],[4,4],[1,8],[9,6],[5,3],[7,4],[1,9],[1,1],[6,6],[9,6],[1,3],
 *  [9,7],[4,7],[5,1],[6,5],[1,6],[6,1],[1,8],[7,2],[2,4],[1,6],[3,1],[3,9],[3,7],[9,1],[1,9],[8,9]]
 *  排序之后的部分结果：1 1   1 3    1 6    1 6    1 8   1 8    1 9   1 9   2 1   2 4   3 1  3 7  3 7
 *  明白了吧，13 和31根本就比不到。。。我到底在想什么呢。。其实也可以改的，全都排序成第一个元素大，第二个元素小。
 * 2.重写了cmp函数之后我通过了！我的cmp函数一开始写的有问题！真的！ 从这个希望你能学到点东西。
 *   我的解法复杂度是排序的复杂度O(nlogn)。
 * 3.不过有个很大的问题是，其实我也注意到了1 <= dominoes[i][j] <= 9，题目给的，但是我不知道怎么用啊！你说
 *   该怎么用！我哭泣了都！
 *   但是如果是没有这个范围的话，就用哈希表来统计，绝了绝了，对啊，哈希表是个pair，真绝了，下次复习我要手
 *   写一下，必须搞起来。
 * 4.官方用拼接形成单个数的方法真挺厉害的哈，我试试。
 *
 * */
class Solution2 {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> nums(100,0);
        int res=0;
        for(auto p:dominoes){
            int t=p[0]<p[1]?(p[0]*10+p[1]):(p[1]*10+p[0]);//大*10或小*10都是一样的。
            res+=nums[t];//这个相加、更新的顺序真是绝了
            nums[t]++;
        }
        return res;
    }
};

//1-27
//class Solution {
//public:
//    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
//        unordered_map<pair<int,int>,int> um;
//        int res=0;
//        for(auto d:dominoes){
//            auto p1=make_pair(d[0],d[1]);
//            auto p2=make_pair(d[1],d[0]);
//            if(um.count(p1)){
//                res+=um[p1];
//                um[p1]+=1;
//            }else if(um.count(p2)){
//                res+=um[p2)];
//                um[p2]+=1;
//            }else um[p2]==1;
//        }
//        return res;
//    }
//};
/*
 * 1.上面的代码是错误的，map不能用pair作为key，如果要用的话，还要添加hash函数？不太懂。
 * 2.题解中说的，使用哈希，应该是获取key之后，也就是将一数*10+另一个数，我昨天理解错了。
 * */
int main(){

    return 0;
}
