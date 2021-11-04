#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月7日下午3:47:43
//class Solution {
//public:
//    string findLongestWord(string s, vector<string>& d) {
//        //这不是在难为我？这能是双指针可解决的问题？为什么我没有思路呢？
//        //我是真的不会啊
//    }
//};
//看了题解真是跪了！四种方法层层递进，呜呜呜。

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        //思路：判断d中的每个是否是s的子序列，从中选择最长的
        //渐进复杂度:O(m*n*c)？c是d种字符串的平均长度 O(1)空间
        string ans="";
        for(auto dstr:d){
            if(subStr(dstr,s)&&(dstr.size()>ans.size()||(dstr.size()==ans.size()&&dstr<ans)))
                //返回长度最长且字典顺序最小的字符串
                ans=dstr;
        }
        return ans;
    }
    bool subStr(string d,string s){
        int i=0;
        for(int j=0;j<s.size();j++){
            if(d[i]==s[j]){//注意i指示d的下标
                i++;
                if(i==d.size())return true;
            }
        }
        return false;
    }
};
/*
 * 1.这个还包含一个隐藏知识点，就是判断一个字符串是否是另一个字符串的子序列。其实是这么简单，双指针
 *   学到了。
 * 2.人家判断子序列的函数：
 *  public boolean isSubsequence(String x, String y) {
        int j = 0;
        for (int i = 0; i < y.length() && j < x.length(); i++)//这里条件判断有意思
            if (x.charAt(j) == y.charAt(i))
                j++;
        return j == x.length();
    }
	我写的似乎就不太行，每次都要判断i==d.size()增加运行时间。
 * */

//12-23
/*
 * 1.bool subStr(string d,string s){
        int i=0,j=0;//这个j就完全不必在这里定义啊。
        for(i=0,j=0;i<d.size()&&j<s.size();j++){//i不必出现在初始化里。
            if(d[i]==s[j])
                i++;
        }
        return i==d.size();
    }
    今天复习重写了判断子序列函数，似乎还是太傻了。
   2.时间复杂度我也想错了！因为这个函数比较的复杂度就是所有字符串的平均长度x吧。
     O(nx)，n是d中字符串的个数。我一开始这个判断子序列的复杂度给想错了，还以为是m*n*c呢。。
 * */

//1-16
/*
 * 1.天啦，比较函数我又忘了，知道是双指针分别指向，但是for循环的退出条件还是忘记了，可以用两个同时遍历，
 *   然后退出，这样比较速度更快。
 * */
int main(){

    return 0;
}
