#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月5日上午12:29:38
class Solution {
public:
    bool isSubsequence(string s, string t) {
        //只能想到暴力解法
        if(s=="")return true;//需要考虑到边界例子，
        int k=0;
        for(int i=0;i<t.size();i++){
            //判断每个s[k]==t[i]
            if(k<s.size()&&s[k]==t[i])k++;
            if(k==s.size())return true;
        }
        return false;
    }
};//AC了，时间O(n)
/*
 * 1.这个教程里说是用二分，但是left和right如何去对应呢？指向t，但是它也不是排序的啊？？？你也不能
 *   比较大小吧？小了往左？大了往右？应该是不成立的，但是后续问题，有大量S如何去判断呢？我不知道啊。。
 * 2.看了题解，原来人家都用双指针写的啊，你这写的也太丑陋了。。。
 * 3.官方题解给出了双指针（一个指向s，一个指向t），和dp，教程里给的后续解法是二分法。
 *   官方题解的dp解法真的牛批。下次复习。我都真的不一定会写，但是你要知道它的思想。
 * */

//11-18
/*
 * 1.其实我上面写的也是双指针的思想。
 * 2.官方的dp解法和https://labuladong.gitbook.io/algo/gao-pin-mian-shi-xi-lie/4.2-qi-ta-jing-dian-wen-ti/er-fen-cha-zhao-pan-ding-zi-xu-lie
 *   教程中的二分解法，都很好，dp是建立二维数组dp[i][j]表示从位置i开始第一个字符j出现的位置，如果没有
 *   则记为t字符串的长度，这样去建立一个哈希表；复杂度主要为O(kn)，k为查询字符串s的个个数，n为s的长度
 *   二分解法，是通过哈希来记录每个字符出现的位置，对s中每个字符遍历找到它是否存在下标，绝!
 *   两个方法都能高效地解决大量s查询的问题，学到了！
 * */

class Solution2 {
public:
    bool isSubsequence(string s, string t) {
        //对t做预处理，从后往前地更新
        if(s=="")return true;
        int m=t.size();
        if(m==0)return false;
        //又没有注意base case就提交了，傻逼
        //""    ""
        vector<vector<int>> dp(m,vector<int>(26,m));
        dp[m-1][t[m-1]-'a']=m-1;
        for(int i=m-2;i>=0;i--){
            //这怎么更新啊，好难啊
            for(int j=0;j<26;j++){
                if(j==t[i]-'a')dp[i][j]=i;
                else dp[i][j]=dp[i+1][j];
            }
        }
        int p=0;
        for(int i=0;i<s.size();i++){
        	if(p==m||dp[p][s[i]-'a']==m)return false;
            p=dp[p][s[i]-'a']+1;//这里得+1才行，因为要从它开始往后找，之前能找到它就说明已经包括它了，不能
            //再从本位置开始找了。
            //这里p会得到6可是什么意思呢？
        }
        return true;
    }
};
/*
 * 1.AC了，还是比较开心的。
 * */
int main(){
	Solution2 s;
	cout<<s.isSubsequence("aaaaaa", "bbaaaa");//需要+1，不然一直会在t的第一个a那不往前走。
    return 0;
}
