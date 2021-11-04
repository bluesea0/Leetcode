#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年3月7日下午2:40:40
class Solution {
public:
    int strToInt(string str) {
        if(str.empty())return 0;
        string s;
        for(char& c:str){
            if(c==' '){
            	if(s.size()==0)continue;
            	else break;
            }//天哪，这道题就是写if else判断，真的好烦人啊，搞死我。
            if(s.empty()){
                if(c=='-'||c=='+'||(c>='0'&&c<='9'))
                    s+=c;
                else break;
            }
            else{
                if(c>='0'&&c<='9')s+=c;
                else break;
            }
        }
        if(s.empty())return 0;
        long long res=0;//该怎么比较是否超过了INT_MAX呢？似乎是个知识点啊
        int i=(s[0]=='-'||s[0]=='+')?1:0;
        for(;i<s.size();i++){//不对啊，写错了，烦死了，明天再搞，现在脑子不清楚。
            res=res*10+(s[i]-'0');
            if(res>INT_MAX){
                res=INT_MAX;
                if(s[0]=='-')res+=1;
                break;
            }
        }
        return s[0]=='-'?-1*res:res;
    }
};
//天哪，这里还不一样的啊，INT_MAX =2^31 − 1， INT_MIN =−2^31
//那么-INT_MAX=-2^31+1，还应该再减一才能=INT_MIN啊
//天哪，这个返回判断有点复杂了
//天哪，居然还有+，是我审题看戳了，绝望了。
/*
 * 1.天哪，居然有单个加号的例子啊，我的天，，
 * 2."   +0 123"这个数据应该输出0啊，OMG子，真的被这种东西整吐了给。
 * 3."-2147483647"，题目说的是闭区间！！！
 * 4.AC了终于，但是看官方题解，居然是用什么状态机，原来还可以解这种问题？不好意思，我不看了，
 *   我比较赶时间，谢谢。
 * */

//6-18
class Solution {
public:
    int strToInt(string str) {
        long res=0; bool negative=false;
        int i=0;
        while(str[i]==' ')//去除开头空格
        i++;
        if(!isdigit(str[i])&&str[i]!='+'&&str[i]!='-')//开头若不为数字或正负号返回
            return 0;
        if(str[i]=='-'){negative=true; i++;}//判断正负
        else if(str[i]=='+') i++;
        while(isdigit(str[i]))//累加
        {
            res=res*10+str[i]-'0';
            if(negative==false&&res>INT_MAX)//判断是否越界
                return INT_MAX;
            else if(negative==true&&-res<INT_MIN)
                return INT_MIN;
            i++;
        }
        return negative?-res:res;
    }
};
/*
 * 1.关于这里越界的判断，如果是负数则标记，然后判断-res是否越界，这个绝了。因为是用long存储的。
 *   我一开始想的越界是说用res存储，然后如果正数变为了负数，那么就是越界，但如果它是-号呢？关于边界值的
 *   处理，-0的那个判断就很迷，所以就用上面的方法来判断很好。
 * 2.我好像明白了，定义res为int，如果<0说明>INT_MAX，那么针对负数来说最小=INT_MAX+1,那么就正好=INT_MIN啊！
 *
 * 3.在力扣上如果越界就会像下面一样提示报错，但是在这个IDE里就不会报错，所以还是直接可能越界时
 *   将res定义为long long就行了。
 *      for(;i<s.size();i++){//不对啊，写错了，烦死了，明天再搞，现在脑子不清楚。
            res=res*10+(s[i]-'0');//但是这里就overflow了。
            // signed integer overflow: 912834723 * 10 cannot be represented in type 'int'
            //说明也就是说不让存储越界的东西？不是会自动变负吗？
            if(res<0){//忽然变为负数说明越界了
                res=INT_MAX;
                if(s[0]=='-')res=INT_MIN;
                return res;//这里直接return就好
            }
        }
 * */

int main(){
	Solution s;
	cout<<s.strToInt("-2147483647");
    return 0;
}
