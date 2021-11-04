#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月15日下午4:46:44
//class Solution {
//public:
//    string removeKdigits(string num, int k) {
//        //看完题感觉真的不会，仅有的思路就是去掉每一位试试？
//        //从高位开始去？但是像样例1，就没有仅仅说是去掉最高位的1，那就暴力枚举吗，
//        //但是长度是10002，这太长了啊，我不会，头像。。就是要我死。
//    }
//};
/*
 * 1.题解的思路真的是绝了，数学原理是：两个数字的大小，取决于不同的最高位数字大小。
 * 2.本题目与316相似。
 * */

//11-22
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==0)return num;
        vector<char> v;
        //那就从最早开始移动
        for(size_t i=0;i<num.size();i++){
            // if(k==0)break;
            while(v.size()&&num[i]<v.back()&&k){
                v.pop_back();
                k--;
            }
            v.push_back(num[i]);
            cout<<num[i]<<" ";
        }
        for(;k>0;k--)//如果k不为0，那么说明栈中是递增的，就删掉后面的就好
            v.pop_back();
        cout<<endl;
        string ret="";
        for(size_t i=k;i<v.size();i++){//这里之所以选择从k遍历，是因为有"9" 1这样的样例
//            if(v[i]=='0')continue;//这里写的也不对啊，应该是忽略了首位0，而不是所有的0！
        	//天哪，怎么忽略首位0啊
        	if(v[i]=='0'&&ret.size()==0)continue;
            ret+=v[i];
            cout<<v[i]<<" ";
        }
        return ret==""?"0":ret;
    }
};
/*
 * 1.输入"10" 2这样的样例，需要返回0啊，所以在return的时候做了判断
 *  又提交一次，有"9" 1这样的样例，我哭了，我这次面试跪了啊就。
 *  出现了"112" 1样例，我发现我写的逻辑是错误的，我哭了。怎么这么不顺呢。
 *  我知道了应该把while中的=号去掉，我一开始以为1432219，去掉=也没用，我的逻辑就是混乱的。。。
 *  我放弃。
 * 2.提交过程中遇到的问题：
 *   vector的是pop_back不是pop函数；初始化应该用{}，也就是今天学到的uninitialized_list初始化列表
 *   而不是()，那样就出现意想不到的错误啊。
 * */

//11-23
//我明白了，看了解法，我终于明白了，如果k不为0，那么栈中的数是单调递增的，直接将后几个给排除就可以了！
//以此来学习单调栈的知识。
//https://www.cnblogs.com/grandyang/p/5883736.html

//11-24
//终于AC了，不容易啊。

//12-20
class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stk;
        for(auto c:num){
            if(stk.size()==0)
                stk.push_back(c);
            else{
                while(stk.size()!=0&&k>0&&stk.back()>c){stk.pop_back();k--;}
                //上面的判断不能有=号啊！如"112" 1这样的
                stk.push_back(c);
            }
        }
        while(k--)stk.pop_back();
        string ans="";
        for(auto c:stk){
            if(ans.size()==0&&c=='0')continue;//去除掉首位0
            ans+=c;//我是傻逼，我写成了stk+char？看错了
        }
        return ans.size()==0?"0":ans;//这个就是针对像"10" 2这样的
    }
};

//2021-8-31
class Solution {
public:
    string removeKdigits(string num, int k) {
        //单调栈，非严格递增，我的天，我一直都想错了，弹出的时机啊
        stack<char> stk;
        for(int i=0;i<num.size();i++){
            while(k&&!stk.empty()&&num[i]<stk.top()){//表示删除
                k--;
                stk.pop();
            }
            stk.push(num[i]);
        }//这个单调栈怎么形成我都给忘了啊。怎么回事。
        while(k--&&!stk.empty())stk.pop();
        if(stk.empty()) return "0";
        string ans="";
        while(!stk.empty()){
            ans=stk.top()+ans;
            stk.pop();
        }
        //这样的话怎么删除前导0呢？
        int j=0;
        while(ans[j]=='0')j++;
        return j==ans.size()?"0":ans.substr(j);
    }
};

int main(){
	Solution s;
	cout<<s.removeKdigits("112", 1);
    return 0;
}
