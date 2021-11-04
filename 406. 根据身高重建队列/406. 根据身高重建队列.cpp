#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月16日下午2:34:29
//class Solution {
//public:
//    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//        //我去，这也难了吧。。。
//        //如果遍历输入的话，那么每插入一个就要考虑所有的之前的输入是否合格。
//        //三分钟了，仍旧没有思路。再待下去也不会有更多思路。。。放弃。
//    }
//};//当然这个我是没有什么思路的，看了官方题解看不太懂，看了grand的比较好。
//https://www.cnblogs.com/grandyang/p/5928417.html。
//评论区还有说用快排的，不知道如何？就是把sort换为了快排吗

//12-20
/*
 * 1.例子分析：[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 *   排序后：[4,4] [5,2] [5,0] [6,1] [7,1] [7,0]
 *   官方解答中，从小到大排我真的没看懂它的题解是什么意思，尽力了。
 *   降序：[7,0] [7,1] [6,1] [5,0] [5,2] [4,4]
 *   从高到低非常好理解，因为后面的人插入对前面的不会有影响，只需要插入第i个位置，第i个位置前有ki个
 *   人就好了！我理解了！！！
 * */
class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        return a[0]>b[0] ||(a[0]==b[0]&&a[1]<b[1]);
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> ans;
        for(auto p:people){
            ans.insert(ans.begin()+p[1],p);
        }
        return ans;
    }
};//还是用最简单的方法给搞定了。。。
int main(){

    return 0;
}
