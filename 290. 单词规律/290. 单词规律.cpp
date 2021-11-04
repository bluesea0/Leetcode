#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include <typeinfo>
using namespace std;
//2020年12月27日下午5:13:55
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> c2s;
        unordered_map<string,char> s2c;
        int start=0;
        //天哪，我没有注意到这个也是双向的连接
        for(int i=0;i<pattern.size();i++){
            int end=s.find(" ",start);//因为到最后一个串，就没有空格分割了，所以会出现npos
            if(end==string::npos&&start>s.size())return false;//这里判断出现了问题
            //天哪我上面这个判断有问题啊，既然end已经=了npos，那么又如何和start建立联系？？？
            else if(end==string::npos)end=s.size();
            string str=s.substr(start,end-start);
            if((c2s.count(pattern[i])!=0&&c2s[pattern[i]]!=str)||(s2c.count(str)!=0&&s2c[str]!=pattern[i]))return false;
            c2s[pattern[i]]=str;
            s2c[str]=pattern[i];
            start=end+1;
        }
        //果真，有这样的样例：
        //"aaa"
        //"aa aa aa aa" 也就是说s没有遍历完
        return start==s.size()+1;
        //"jquery"
        //"jquery" 哭了这是什么鬼样例？throwing an instance of 'std::out_of_range'
    }
};
//天哪，终于AC了，心疼地想让人哭，提交了五次才通过，你回家等消息吧
/*
 * 1.看了官方解答，思路是差不多的，不过没有用find函数。
 * */

//12-29
/*
 * 1.主要存在的点就是pattern和str的长度不匹配，p不够匹配str，str太短不够匹配p，分别需要判断。
 *   前者是要判断遍历完p之后，指向str的指针是是否末尾了
 *   后者是要判断是否找不到end？
 * */
int main(){
	cout<<typeid(string::npos).name();
    return 0;
}
