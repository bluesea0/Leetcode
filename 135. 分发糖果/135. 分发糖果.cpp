#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月24日下午2:09:50
//class Solution {
//public:
//    int candy(vector<int>& ratings) {
//        //感觉这个是环环相扣的啊。一个孩子分多少不仅仅是和左右有关的，是和全体有关的
//        //我能想到的是贪心？但是我觉得这个局部最优不是全局最优，因为一旦有一个新的孩子加入，那所有
//        //的人可能都会受到影响？
//        //比如[1,2,2,0]，一开始1 2 1，但是0来了之后就需要更改前面的每个，就会有个整体的波动
//    }
//};
/*
 * 1.常数空间遍历的情况：例:[1,3,5,3,2,1]
 *   i=1: pre=2,ret=3,inc=2
 *   i=2: pre=3,ret=6,inc=3
 *   i=3: dec=1,ret=7,pre=1
 *   i=4: dec=2,ret=8,pre=1
 *   i=5: dec=3,dec=4,ret=12,pre=1.
 *   明白了一些，这里inc记录的是递增的长度，如果当前dec==inc的话，那么就是当前递减的长度是大于=递增的
 *   长度了，那么dec++表示了两个部分吧，一部分的dec-1（这里的dec已经在if判断中++了）的长度是对之前的
 *   递增序列每个都+1，剩余的1是当前自己的数。
 *   如果上述例子中最后再多一个0，那么
 *   i=6: dec=5, ret=17,pre=1//pre这里只是记录自增的长度
 *   if判断的目的还是将降序中头一个的元素，包括之前增序的最后一个元素，这样而已。
 * 2.所以这个常数空间，一次遍历的好难，我还是比较适合两次遍历的
 *		[1,3,5,3,2,1],left=[1,2,3,1,1,1]
 *		right=[1,2,4,3,2,1]。拆分为了两个规则。
 * */

//12-29
class Solution {
public:
    int candy(vector<int>& ratings) {
        //看过题解，只记得拆分为两个条件，并且两次遍历，其他的都不记得了。
        //从左到右，如果ratings[i+1]>ratings[i]，则ratings[i+1]=ratings[i]+1
        int m=ratings.size();
        if(m==0)return 0;
        vector<int> ans(m,1);
        for(int i=1;i<m;i++)
            if(ratings[i]>ratings[i-1])
                ans[i]=ans[i-1]+1;
        int ret=0;
        for(int i=m-1;i>=1;i--){
            if(ratings[i-1]>ratings[i]){
                ans[i-1]=max(ans[i]+1,ans[i-1]);//天哪这里不对,[1,3,4,5,2]通不过！
            }//这里要取个最值来满足条件
            ret+=ans[i];
        }
        ret+=ans[0];
        return ret;
    }
};
/*
 * 1.AC了，我太开心了，时间空间都是O(n)，官方给的题解中倒序遍历时是通过right来记录：
 *           int right = 0, ret = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1 && ratings[i] > ratings[i + 1]) {
                right++;
            } else {
                right = 1;
            }
            ret += max(left[i], right);
        }
	//不过我觉得我的写法也是很不错的！上述是两次遍历的写法。
     我上面的写法和grand是一样的。明天看一下遍历一次的解法。
 * */

//12-30
/*
 * 1.今天看了遍历一次的解法，终于明白了，上次看我还不明白的啊！
 * 			int inc = 1, dec = 0, pre = 1;//inc默认初始化为1，dec默认初始化为0
 *             if (ratings[i] >= ratings[i - 1]) {
                dec = 0;
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                ret += pre;
                inc = pre;//这个是一致的，没有毛病
            } else {
                dec++;//这个部分是再对所有当前降序中的元素+1，加入到ret中
                if (dec == inc) {
                    dec++;//这个分布是将升序分布最高的给加了进来。
                }
                ret += dec;
                pre = 1;//这个也是记录当前是降序的最后一个，所以是1
            }
    读懂了之后感觉真的很爽啊。
 * */
int main(){

    return 0;
}
