#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;
//2021年2月2日下午6:52:29
//class Solution {
//public:
//    int characterReplacement(string s, int k) {
//        //这道题我进行了思考，题目标签中有滑动窗口，我想到了模板
//        //这里right向右移动，如果=left的话就计算新的长度，否则k--表示切换。
//        //left移动过=之前字符的位置，又怎么遍历呢？想到这里我就乱了，我真的不会，辞职了。
//    }
//};
/*
 * 1.我是不会做这道题的，看了题解之后直呼牛逼，记录窗口内的字符出现次数哈希表，将问题转换为窗口内除了出现
 *   次数最多的字符最多只能由k个。这样就轻松地解决了。太牛了！！！什么脑子能想出来这种东西啊！
 * 2.https://www.cnblogs.com/grandyang/p/5999050.html 讲的也很好。
 * 3.比较关键的一点是为什么maxN只记录历史最大值，而不用在left指针移动时实时更新窗口内的最大值。
 *   官方题解评论区中说的比较明白：
 *   因为如果比历史最大值小，那么k也是固定的，+k的长度，如果当前最大值比历史maxN小，那么得到的字符串长度
 *   肯定不是最长的，肯定比不过历史，而有新的更大的maxN出现的时时候就说明有新的答案了！
 * 4.grand讲解中：如果没有k的限制，让我们求把字符串变成只有一个字符重复的字符串需要的最小置换次数，
 *   那么就是字符串的总长度减去出现次数最多的字符的个数。如果加上k的限制，
 *   我们其实就是求满足 (子字符串的长度减去出现次数最多的字符个数)<=k 的最大子字符串长度即可。
 *   这个思路也是让人灵光乍现！
 * */

//2-3
class Solution {
public:
    int characterReplacement(string s, int k) {
        //也就是当前窗口内除了出现次数最多的字符之外，其他字符出现字数不能多与k，最多只能等于
        int left=0,right=0,maxn=0,ans=0;
        vector<int> ct(26,0);
        while(right<s.size()){
            int c=s[right]-'A';
            ct[c]++;
            maxn=max(maxn,ct[c]);
            if(right-left+1-maxn>k){
                ct[s[left]-'A']--;
                left++;
            }
            ans=max(ans,right-left+1);//在可能移动left指针后更新ans，也就是每次移动right时更新
            right++;
        }
        return ans;//ans怎么更新呢？
    }
};//又分析了一下k=0，也没什么问题
/*
 * 1.这样的滑动窗口简直不要太难好吗！！！嘤嘤嘤。
 * */
int main(){
	Solution s;
	cout<<s.characterReplacement("ccaabbb", 1);
	//159题，会员题目
	//https://www.cnblogs.com/grandyang/p/5185561.html
//	string s="eceba";
//	unordered_set us;
//	int left=0,right=0,res=0;
//	while(right<s.size()){
//		if(us.count(s[right])){//已经包含了该节点
//			right++;
//			res=max(res,right-left);
//		}else if(us.size()<=2){//出现了一个新的字符
//			us.insert(s[right]);
//			right++;
//			res=max(res,right-left);
//		}else {//移动左窗口
//			//到这里才发现不能用set来存，因为这样在删除的时候就删掉了第一个，但是窗口中仍然有它，
//			//所以说还是得用哈希表来记录啊，然后计算其中非0的个数，来作为有多少个不同的字母
//		}
//	}
	//才反应过来，这个不就是424的k变为1嘛！只能包含两种不同的字符，没有说是只能包含2个！
	//不是不是，我理解错了，这两道题很像，但不是同一道题！
    return 0;
}
