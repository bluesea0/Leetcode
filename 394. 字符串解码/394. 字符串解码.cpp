#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<stack>
using namespace std;
//2021年10月31日下午11:50:10
class Solution {
public:
    string decodeString(string s) {
        if(s.empty())return s;
        stack<string> stk;//应该存储字符串的，因为拼接之后仍然要放进来的。
        int n=s.size();
        if(n<4)return s;
        for(int i=0;i<n;i++){
            if(s[i]!=']')stk.push(string(1,s[i]));//傻子忘了把字符添加进来了。。
            //初始化时，出现了问题：
            /*
            如果字符串只包含一个字符，使用构造函数对其初始化时，使用以下两种形式比较合理：
            std::string s('x');    //错误
            std::string s(1, 'x');    //正确
            */
            else{
                //遇到右括号
                string str="",num="";
                while(!stk.empty()&&stk.top()!="["){
                    str=stk.top()+str;
                    stk.pop();
                }
                stk.pop();
                while(!stk.empty()&&isdigit(stk.top()[0])){
                    num=stk.top()+num;
                    stk.pop();
                }//不能直接+=，然后reverse，因为有可能是内部拼接呀！天哪！懂了吗！！
                //一层套一层的，那样反转就错了，你还是别哆嗦了，就直接后加就行。。。
                int c=stoi(num);
                string res="";
                while(c--)res+=str;
                stk.push(res);
            }
        }
        //再遍历stack
        string ret="";
        while(!stk.empty()){
            ret=stk.top()+ret;
            stk.pop();
        }
        //reverse(ret.begin(),ret.end());
        return ret;
    }
};
int main(){
	Solution s;
	cout<<s.decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef");
    return 0;
}
