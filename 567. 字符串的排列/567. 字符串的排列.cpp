#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-14
/*
1.这个好难，我去，一看就没有什么思路，难道要一一判断字符串所有的排列？有点难度。
2.这个也不是双指针的题目吧？如果我来写的话会一一判断每个全排列是否在s2中，就很暴力。
3.看了grandyang的解法，还是觉得挺复杂的，我来手动运行一下吧。
s1=ab,s2=eidbaooo
a=1,b=1
l=0,r=0:m[e]=-1,l=1,m[i]=1
l=1,r=1:m[i]
我哭了，我明白了，我是因为没有搞清楚前++和后++的关系。


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size(), left = 0;
        vector<int> m(128);
        for (char c : s1) ++m[c];
        for (int right = 0; right < n2; ++right) {
            m[s2[right]]--;
            if ( m[s2[right]]< 0) {//注意前++和后++的区别。
                m[s2[left]]++;
                while (m[s2[left]]!= 0) {//这里我稍微更改了一下
                    left++;
                }
                //这里我迷惑的是，判断了right不在s1中，但你移动left，你怎么确定left
                //有没有超过right呢？就很奇怪啊！
            } else if (right - left + 1 == n1) return true;
        }
        return n1 == 0;
    }
};
明天再来复习吧。
*/
//10-15
/*
1.还是写不太出来，我不明白原理，就很尴尬，还有一种两个哈希表的解法，我也想不起来是怎么写的了。
太难了，难到头秃啊！吐血，好难！放弃。
2.明天要写一下两个数组的方法，这种方法是好多博客都是这么写的。
3.https://zhuanlan.zhihu.com/p/76887991，终于找到一个我能看懂的写法了！
4.grand的写法我是真的看不懂，算了算了，别逼自己了。。
*/

//11-16

//class Solution {
//public:
//    bool checkInclusion(string s1, string s2) {
//        //是包含子串、不是包含子序列。
//        //就像第二个样例，它是子序列包含了ab的排列。
//        unordered_map<char,int> need;//s1可以直接初始化吗？
//        for(auto c:s1)
//            need[c]++;
//        int left=0,right=0;
//        while(right<s2.size()){
//            //但是这个和76题并不一样，这个是子串啊，感觉这个比那个更加复杂了。
//            if(need.count(s2[i])!=0){//这个判断肯定是不对的，ba是
//                left=i;
//                //这里肯定不能操作need吧？
//                //需要记录当前框内所包含的字母类别。放弃。
//            }
//        }
//    }
//};
//
/*
 * 1.绝了，原来我以前人家的解法都看不懂啊。
 * 2.和76题主要的区别就是在缩小left的时候的判断，前者是通过valid==need.size()，而后者是通过
 * */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> need;
        unordered_map<char,int> win;
        for(auto c:s1)
            need[c]++;
        int left=0,right=0,valid=0;
        while(right<s2.size()){
            char c=s2[right++];
            if(need.count(c)){
                win[c]++;//要注意这里先++
                if(win[c]==need[c])
                    valid++;
            }
            while(right-left>=s1.size()){
                if(valid==need.size())
                    return true;
                c=s2[left++];
                if(need.count(c)){
                    if(win[c]==need[c])
                        valid--;
                    win[c]--;//这里后--；
                }
            }
        }
        return false;
    }
};//终于AC了，模板题了这种就是！

//12-7复习
/*
 * 1.还是没有清晰的思路，因为不知道left怎么移动。
 * while(right-left>=s1.size())，这个移动left的while判断真的太牛逼了好吗！！！！我还是得复习
 * 还是不太行啊！
 * */

//12-23
/*
 * 1.思路：滑动窗口，首先对s1中各个字符出现的次数记录哈希表，对s2窗口遍历，窗口缩小的条件是right-left>=s1.size()，判断窗口内是否能覆盖s1，不能覆盖的话left向左移动。
复杂度：O(n),O(m+n)
  是进来就有思路的。
 * */

//2021-6-10
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //滑动窗口求解
        int n1=s1.size(),n2=s2.size();
        int valid=0;
        //统计s1中出现的字符
        unordered_map<char,int> um1,win;
        for(auto&c :s1)
            um1[c]++;

        int left=0,right=0;
        while(right<n2){
            char c=s2.at(right++);
            if(um1.count(c)){
                win[c]++;
                if(win[c]==um1[c])
                    valid++;
            }
            if(right-left==n1){//需要移动左窗口
                if(valid==um1.size())return true;//这里需要和不同的个数比较，注意不是和n1比较
                c=s2[left++];
                if(um1.count(c)){
                    if(win[c]==um1[c])
                        valid--;
                    win[c]--;
                }
            }
        }
        return false;
    }
};
/*
 * 1.复习写出来了，但是只打败了8%，这是怎么回事？
 * 2.在评论区看到下面的解法，相当简洁啊，学习了。但是我还是更喜欢我上面的解法。
 * */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // 排除异常的边界情况，也限定了模式串的长度
        if(s1.size() > s2.size()) return false;

        // 匹配采用的窗口大小为模式串大小
        int windowSize = s1.size();

        // 模式串的字典：可以看做一种频率分布
        vector<int> hashmap1(26, 0);
        // 动态更新的匹配窗口字典
        vector<int> hashmap2(26, 0);

        // 构建字典
        for(int i = 0; i < windowSize; i++) {
            hashmap1[s1[i] - 'a']++;
            hashmap2[s2[i] - 'a']++;
        }

        // 对于每一轮滑窗查询，如果两个字典相等(频率分布一致)，则命中
        for(int i = windowSize; i < s2.size(); i++) {
            // 两个字典相等(频率分布一致)，则命中
            if(hashmap1 == hashmap2) return true;

            // 否则，向右滑窗：滑窗对于 hash 表的操作变为对应频率的增减
            hashmap2[s2[i - windowSize] - 'a']--;
            hashmap2[s2[i] - 'a']++;
        }

        // 整个算法采用左闭右开区间，因此最后还有一个窗口没有判断
        return hashmap1 == hashmap2;
    }
};
int main(){
    Solution s;
    cout<<s.checkInclusion("ab","eidbaooo");
    return 0;
}
