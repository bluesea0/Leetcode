#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年6月10日下午3:04:27
class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        //回溯
        if(s.empty()||s.size()<4)return{};
        vector<string> path;
        helper(s,0,path);
        return ans;
    }
    void helper(string& s,int index,vector<string>& path){
        if(s.size()==index){
            if(path.size()==4){
                string t=path[0];
                for(int i=1;i<path.size();i++){
                    t.push_back('.');//追加单个字符
                    t.append(path[i]);//追加字符串
                }
                ans.push_back(t);
            }
            return;
        }
        if(path.size()>=4)return;//如果没有遍历完s就放了4个，那么return
        for(int i=0;i<3&&i+index<s.size();i++){//i表示从index往后切断几个数的数目
            if(s[index]=='0'&&i>0)break;//不能包含前导0
            string t=s.substr(index,i+1);
            if(check(t)){//如果当前符合条件
                path.push_back(t);
                helper(s,index+i+1,path);
                path.pop_back();
            }
        }
    }
    bool check(string s){
        int n=0;
        for(int i=0;i<s.size();i++){
            n*=10;
            n+=(s[i]-'0');
        }
        if(n>=0&&n<=255)return true;//我的妈，这里应该时&&好吗？
        return false;
    }
};
/*
 * 1.其实也遇到了点问题，就是回溯控制的时候，i的意义没搞懂，表示从index往后截取几个数，还要有范围控制
 * */

//10-2
class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        if(s.size()<4)return {};
        vector<string> path;
        restore(s,0,path);
        return ans;
    }
    void restore(string& s,int index,vector<string>& path){
        if(index==s.size()){
            if(path.size()==4){
                string temp=path[0];
                for(int i=1;i<path.size();i++){
                    temp+=".";
                    temp+=path[i];
                }
                ans.push_back(temp);
            }
            return;
        }
        if(path.size()>=4)return;
        for(int i=index;i-index<3&&i<s.size();i++){
            //i应该初始化为0，而不是index，这里i指的是
        //从index往后偏移是多少。那么我试一下如果初始化为index
            if(i!=index&&s[index]=='0')break;//不能包含前导0
            string temp=s.substr(index,i-index+1);
            if(helper(temp)){
                path.push_back(temp);
                restore(s,i+1,path);
                path.pop_back();
            }
        }
    }
    bool helper(string& s){
        int t=stoi(s);
        return t>=0&&t<=255;
    }
};
/*
 * 1.因为之前只写过一次，感觉如果面试遇到不一定能写出来。结果发现写的和之前惊人的相似，但是关于这个i
 *   和index初始化的关系，我变了，如果i初始化为index，那么判断条件是差值不超过3且不越界，主要是这个地方。
 *   因为我判断前导零，就直接用i!=index比较习惯了。
 * */
int main(){
	Solution s;
	vector<string> ans=s.restoreIpAddresses("25525511135");
	cout<<"\n";
	for(auto& a:ans)
		cout<<a<<"\n";
    return 0;
}
