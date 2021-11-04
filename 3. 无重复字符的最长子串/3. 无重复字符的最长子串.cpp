#include <iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;
//10-13
/*
1.感觉好难，我只能想到一个O(n2)的方法。。。
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                string t=s.substr(i,j-i);
                //写着自己都感觉会超时，算了，写不下去了
                //建立一个字典？判断是否会有重复？好麻烦。。
            }
        }
    }
};
/*
2.https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/hua-dong-chuang-kou-by-powcai/
看了评论区的题解，是真的不错，还有滑动窗口题目的汇总！学到了。这几天我要做一下这个滑动窗口
感觉还是有难度的，把这几个先破解了！
*/
//10-14
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int ans=0,start=0;
        for(int i=0;i<s.size();i++){
            if(st.count(s[i])){//我这么写是错的，我明白了。原来是这样啊。
                st.erase(s[i]);//是删除它左边的，从start开始删，一直删到它自身。
                start=i;//明天还是得复习啊。
            }
            st.insert(s[i]);
            ans=max(ans,i-start+1);
        }
        return ans;
    }
};
/*
1.上面2中给出的链接中有很多滑动窗口的题目，但是好多都是hard啊，只有209、567是m，所以只做这两个吧。
*/
//10-15
/*
1.对应剑指offer48题。
2.AC了。
*/
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,left=0,len=s.size();
        unordered_set<char> st;
        for(int i=0;i<len;i++){
            while(st.find(s[i])!=st.end()){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[i]);
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};
//10-22
/*
1.经验1，最长子串的问题就想到滑动窗口，最长子数组在没有负数的情况下也考虑滑动窗口解法。
*/

//11-16
class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,left=0,right=0;
        unordered_set<char> st;
        while(right<s.size()){
            char c=s[right];
            right++;
            if(st.count(c)==0){
                ans=max(ans,right-left);//这里就不用+1了
            }else{
                while(st.count(c)){
                    st.erase(s[left]);
                    left++;
                }
            }
            st.insert(c);
        }
        return ans;
    }
};
/*
 * 1.按照模板的思路做的，行吧，反正能AC就行，自己也明白用滑动窗口来做。
 * */

//2-10
/*
 * 1.需要记住的是在调整left的时候不一定是更新ans的时候！每次移动right也会更新ans！
 * */

//5-26
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,left=0,right=0;
        unordered_set<char> us;
        while(right<s.size()){
            char c=s[right];
            right++;

            while(us.count(c)){//缩小滑窗左边界
                us.erase(s[left]);
                left++;
            }
            us.insert(c);
            ans=max(ans,right-left);//right已经向右移动了，不需要再+1了。
        }
        return ans;
    }
};
/*
 * 1.滑窗题目相对来说还是比较简单，记住三个步骤，while循环内：移动right+是否满足条件移动left+更新ans
 *   这三个步骤是并行的，同等地位的。
 * */
int main(){
    Solution2 s;
    cout<<s.lengthOfLongestSubstring("pwwkew");
    return 0;
}
