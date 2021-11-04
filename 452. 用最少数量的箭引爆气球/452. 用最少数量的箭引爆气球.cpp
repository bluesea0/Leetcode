#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月23日下午4:21:52
//class Solution {
//public:
//    int findMinArrowShots(vector<vector<int>>& points) {
//        //思路：本质就是一个合并区间的问题，我去，但是其实也不是单纯的区间合并，还需要结合贪心
//        //有点难度。正好我可以开始集中解决区间方面的问题了。
//        //那么dp[i]需要和i-1比较，也要和i-2比较，不，要和i之前所有的比较，那就是O(n2)
//        //比较和之前是否有重叠
//    }
//};
//太难了，实在是难，我不会，当然看了题解之后似乎明白了。

//11-24
class Solution {
public:
	//这个函数必须要写成const，这是为什么呢？我之前遇到过
    static bool cmp(vector<int>a,vector<int>b){//这个函数写的太丑了啊
        if(a[1]<b[1])return true;
        else if(a[1]==b[1]&&a[0]<b[0])return true;//右端点相同，左端点越小说明跨度越大
        return false;
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)return 0;
        //这里的函数也太难写了。。。
        sort(points.begin(),points.end(),cmp);
        int ans=1,coor=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]>coor){
                coor=points[i][1];
                ans++;
            }
        }
        return ans;
    }
};
/*
 * 1.提交时因为cmp不是static的，所以出现了一次问题。
 * 2.时间是O(nlogn)排序的，空间O(logn)排序所需的栈空间。但是我老是忽略这个排序的过程，总觉得它是
 *   O(n),O(1)，你真是够了。
 * 3.关于这个排序函数，其实只关注右边界即可，例如[1,2],[3,4],[1,4]不论排不排第一个答案都是2.
 *   不过去掉之后提交，也没快多少。
 * 4.思路是贪心算法，局部最优解就是全局最优解。
 * */

//12-19
/*
 * 1.我觉了，隔了25天才复习，完全忘记了当时是怎么写的了。
 * https://www.cnblogs.com/grandyang/p/6050562.html，grand的这个贪心思路和官方的不一样，不过也很不错！
 * */

//12-20
class Solution2 {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //这里记得学习一下匿名函数怎么写
        if(points.size()==0)return 0;
        sort(points.begin(),points.end());//这里是不是不用写？我记得是会自动有规则排序的
        int end=points[0][1];
        int ans=1;
        for(auto p:points){
            if(p[0]>end){
                end=p[1];
                ans++;
            }else end=min(end,p[1]);//这里就表示要共用啊！所以就得取较小值
            //比如样例：[[10,16],[2,8],[1,6],[7,12]]
            //排序后：[7,12] [10,16] .就需要是12的是两者中的较小值的
        }
        return ans;
    }
};//ohyes，AC了！天哪！这个是grand的思路
//复杂度：O(nlogn)天哪，我又以为是O(n)。。。你又忽略了排序！空间O(logn)
/*
 * 1.sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[1] < v[1];
        });
	匿名函数这么写。
	[]需要在外面传进来的
	()函数形参
	{}函数体，最后也需要加个分号
 * */
int main(){

    return 0;
}
