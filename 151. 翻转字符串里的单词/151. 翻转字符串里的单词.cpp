#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年3月21日下午11:26:50
class Solution {
public:
    string reverseWords(string s) {
        //考察find函数
        //这到底是用find还是直接遍历就行？我懵了
        string ans;
        // int index=0;
        // while(s.find(" ",index)!=string::npos){
        //     int t=s.find(" ",index);
        // }
        //似乎不用find直接for循环就行了
        int i=0,m=s.size();
        while(i<m){
            while(s[i]==' '&&i<m)i++;//int和size_type不能直接比较
            if(i==m)break;
            int j=i;
            while(s[i]!=' '&&i<m)i++;
            ans=" "+s.substr(j,i-j)+ans;
        }
        //烦死了，C++处理字符串好麻烦啊，一点都没有py简洁
        //需要处理空字串的情况“   ”
        return ans.size()==0?"":ans.substr(1);//去掉开头的空格
    }
};
/*
 * 1.AC了，太棒了！但是我看到题目要求，O(1)额外空间复杂度原地解法？erase？不太懂了。
 * 2.官解中给的是先reverse整个，通过idx来去掉空格，并且识别出单词的首位，直接将部分单词再翻转过来。
 * */

//6-16
/*
 * 1.处理字符串的都挺琐碎的。
 * 2.通过i遍历去掉前导空格，然后遇到空格之后再找单词，找到之后substr。
 * */

//9-27
class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        while(s[i]==' ')i++;
        s=s.substr(i);
        i=s.size()-1;
        while(s[i]==' ')i--;
        s=s.substr(0,i+1);
        //先去除掉首部和末尾的空格
        if(s.size()==0)return "";
        int index=0;
        s+=" ";
        string res,temp;
        for(int i=0;i<s.size();i++){
            // if(s[i]==' '&&s[i-1]!=' '){//遇到第一个空格操作
            //     string temp=s.substr(pre,i);
            //     res=temp+res;
            //     pre=//这样写pre不好记录啊，因为可能有多个空格，pre不好控制！哎！
            // }
            if(s[i]==' '&&s[i-1]==' '){//遇到连续空格，第二个空格不处理
                continue;
            }else if(s[i]==' '){
                res=" "+temp+res;
                temp="";
            }else temp+=s[i];//遇到普通字符添加
        }
        return res.substr(1);
    }
};
int main(){
	Solution s;
	cout<<s.reverseWords("  ");
    return 0;
}
