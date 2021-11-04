#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月19日下午5:55:03
//class Solution {
//public:
//    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//        //肯定是需要首先排序，但是要删除点如何表示呢？如果表示它被删除了？
//        //还是不太会，到底怎么搞啊，我哭。
//        //真的太难了，我看官方的题解也是看的非常迷糊，脑袋短路的感觉！
//    }
//};
//太难了，解法包括dp:起点/终点，贪心:起点、终点


//12-24
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //转换为最多有多少个区间的问题。
        if(intervals.size()==0)return 0;
        sort(intervals.begin(),intervals.end());
        vector<int> dp(intervals.size(),1);

        for(int i=1;i<dp.size();i++){
            for(int j=0;j<i;j++){
                if(intervals[j][1]>intervals[i][0])continue;
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        return intervals.size()-dp.back();
    }
};//终于AC了一次，当然太不容易了，不过复杂度是O(n^2)，只超过了5%。
/*
 * 1.区间重复的判断条件是，前一个区间的end>当前区间的begin。
 * 2.ladong的解法也是很厉害啊，让人思路豁然开朗，它的评论也有意思，按照end来排序，并且在重叠区间中
 *   选择end最小的，这样是贪心，能够形成最优的结果
 *   grand的思路是按照start排序，并且有一个pre指向之前的区间，如果当前的区间的start<之前的end，那么
 *   就是重叠，再判断，两者的end哪个更小，选择end更小的那个。
 * */

//12-30
/*
 * 1.其实在看到grand的解法是，疑问是如何记录数量的？虽然说有pre
 * 需要有代码中的判断if (intervals[i][1] < intervals[last][1]) last = i;
 * 因为可能有[1,5][1,6][2,3][3,4]这样的样例，排序小的时候反而区间数目长。
 * 2.思路：计算总共最多能形成多少个区间，用总区间数目减去，就得到至少需要移除的。
先对区间排序，对每个区间遍历，和它之前的每个都判断是否有交叉，start<end，取最大值。复杂度O(n^2)
天哪，O(n)的解法我都忘记了。
	3.看ladong的解法思路，我想象不出来是怎么做的啊。
	  按照end从小到大排序？选择start较大的？但是感觉这个思路并不对
	  按end从大到小，然后取小end是不对的，上面[1,5][1,6][2,3][3,4]就能分析出来。
	  使用end从小到大，得到的是保留的区间的数目。
 * */

//12-31
class Solution2 {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //首先是按照start排序
        if(intervals.empty()) return 0;
        sort(intervals.begin(),intervals.end());
        //如果当前start<end，就保留end较小的值
        int res=0,end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<end){
                res++;
                end=min(end,intervals[i][1]);
            }else
                end=intervals[i][1];
        }
        return res;
    }
};//按照start排序，O(n) O(1)

class Solution3 {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //按照end从小到大排序，倒序遍历，确定最多能形成多少个区间
        //天哪这个我还是不熟，思路不太清楚啊。
        if(intervals.empty()) return 0;
        sort(intervals.begin(),intervals.end(),
        [](vector<int> a,vector<int> b){return a[1]<b[1];});
        int m=1,end=intervals[0][1];
        //关键是要舍弃哪一个
        //如果当前和之前的区间有交叉，那么肯定是舍弃当前，因为之前的区间更短！留给后面的空间更多！
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=end){//不满足这个条件的区间都舍弃
            //因为它更靠后，而且和之前的区间交叉了，选择保留之前的区间
                m++;
                end=intervals[i][1];
            }
        }
        return intervals.size()-m;
    }
};
/*
 * 1.天哪，我真的太棒了，泪目！
 * */

//1-6
/*
 * 1.如果按照start排序从小到大，遇到有重叠的，那么舍弃end值较大的区间
 * 2.如果按照end排序从小到大，那么遇到有重叠的区间，那么直接舍弃当前，也就是end值较大的。
 * 3.总之，两种排序方法都是从小到大，从前往后遍历，遍历到都是舍弃end值较大的，以给后面留下更大的空间。
 * */
int main(){

    return 0;
}
