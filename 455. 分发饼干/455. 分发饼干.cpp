#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月17日下午3:01:44
//class Solution {
//public:
//    int findContentChildren(vector<int>& g, vector<int>& s) {
//        //第一感觉就是需要同时遍历两个数组，排序+双指针？对于每一个gi都要在s中找到刚好>=gi的值
//        //同时保证这个没有被分发出去，这个和贪心有什么关系？？
//        //思路：分别排序+二分查找，O(nlogn+mlogm+nlogm)
//        //这真的是一道easy题目？？？
//    }
//};
/*
 * 1.看了评论区的题解，绝了绝了，我是傻逼，我是傻逼。
 * 2.利用贪心算法：局部最优解=》全局最优解
 *   而dp是：子问题=》大问题。一样吗？好像差不多啊也是。局部最优解=》全局最优解。
 * 3.本问题的局部最优：就是把大的分给大胃口，其实和我上面理解的是一样的。
 * */

//12-18
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());//胃口
        sort(s.begin(),s.end());//饼干
        int ans=0;
        //遍历饼干，将最大的饼干分给胃口最大的
        int k=g.size()-1;
        for(int i=s.size()-1;i>=0;i--){
            if(g[k]<=s[i])ans++;
            else i++;
            k--;
            if(k<0)break;
        }
        return ans;
    }
};//当然能够看出来写的很垃圾了。下面写一下从小的分起
class Solution2 {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0)return 0;
        sort(g.begin(),g.end());//胃口
        sort(s.begin(),s.end());//饼干
        int ans=0;
        //从胃口开始遍历，从小的分
        int k=0;
        for(int i=0;i<g.size();i++){
            if(g[i]<=s[k])ans++;
            else i--;//这里主要针对的是g=[7,8,9,10]，s=[5,6,7,8]这样的样本
            k++;
            if(k==s.size())break;
        }
        return ans;
    }
};//实在是太垃圾了写的，
/*
 * 1.我写的解法和人家评论区给的两次遍历过程都完全相反，绝了绝了。
 * class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (int i = 0; i < s.size() && j < g.size(); ++i) {
            if (s[i] >= g[j]) ++j;
        }
        return j;
    }
};//这个grand的解法真不错！遍历饼干，同时对胃口也是，直接控制条件就是两者的size，返回的是指向胃口的
下标。
 * */
int main(){

    return 0;
}
