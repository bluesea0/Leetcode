#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月16日下午3:39:55
//class Solution {
//public:
//    string minWindow(string s, string t) {
//        //思路：使用双指针滑动窗口，一个map记录s窗口中的字母数，另外map记录t中需要的字母数，
//        //遍历来判断，O(n)，O(k)，k为t中的字符集大小。
//        //感觉自己上来这么分析一通，还挺有算法内味呢！
//        unordered_map<char,int> needed;
//        unordered_map<char,int> win;
//        for(auto s:t)
//            needed[s]++;
//        int left=0,right=0,ct=0;
//        int start=-1,len=s.size()+1;
//        while(right<s.size()){
//            win[s[right]]++;
//            if(needed.count(s[right])){
//                if(++win[s[right]]==needed[s[right]]){
//                    //计数+1，但是总数又是怎样呢？ct是和needed的大小关联的？
//                    if(++ct==needed.size()){//说明到了这个窗口。
//                        if(right-left<len)
//                            len=min(len,right-left);//那还需要另一个
//                            start=left;
//                    }
//                }//总感觉我曾经写过这个，似曾相识的感觉。
//            }
//            //然后试图缩小left？怎么个缩小法？绝了。
//        }
//    }
//};
/*
 * 1.自己写着写着还是卡住了，
 *   https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/hua-dong-chuang-kou-ji-qiao-jin-jie
 * 2.步骤，首先是增大right，进行数据更新，判断是否要缩小左窗口，进行窗口记录的数据更新。
 * */
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> needed;
        unordered_map<char,int> win;
        for(auto c:t)
            needed[c]++;
        int left=0,right=0,ct=0;
        int start=-1,len=s.size()+1;
        while(right<s.size()){
            char c=s[right++];
//            cout<<c<<" ";
            if(needed.count(c)){//数据更新
                win[c]++;//注意，只有在窗口内的才加啊
                if(win[c]==needed[c]){
                    ct++;
//                    if(ct==needed.size()&&right-left<len){//不可以在这里判断，会出现问题
//                        len=right-left;
//                        start=left;
//                    }
                }
            }
            //判断是否缩小left，怎么缩小啊，我又抽象了。。。
            while(ct==needed.size()){//到底是哪里出现的问题啊。。。
            	if(right-left<len){//需要在这里判断啊大哥！因为这里出的时候只要进入循环就是满足
            		len=right-left;//ct==需要的！
            		start=left;
            	}
                c=s[left++];
//                cout<<" left "<<c<<" ";
                if(needed.count(c)){
                    if(win[c]==needed[c])
                        ct--;
                    win[c]--;
                }
            }
//            cout<<endl;
        }
        return start==-1?"":s.substr(start,len);
    }
};
/*
 * 1.Yes,上面的终于AC了。。
 * */

//12-7复习
/*
 * 1.仍是要注意窗口缩小的条件，有ct来记录窗口内满足t字母数目的个数，缩小窗口时要更新。
 * */

//12-22
/*
 * 1.需要注意在缩小窗口时，这里只能判断是否相等，不能先-再判断是否<，
 *   那样可能ct会多次减！就出错了！只能判等。
 * */
int main(){
	Solution s;
	cout<<s.minWindow("a", "a");
    return 0;
}
