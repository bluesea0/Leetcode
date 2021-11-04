#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月16日下午4:08:15
class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        generate("",n,n);
        return ans;
    }
    void generate(string s,int left,int right){
        if(left>right||left<0||right<0)return;//不能生成有效的括号组和，剪枝操作
        if(left==0&&right==0)ans.push_back(s);
        else{
            generate(s+"(",left-1,right);
            generate(s+")",left,right-1);
        }
    }
};
/*
 * 1.回溯方法，没想到这么快就写出来了！我真棒啊!
 * */
int main(){

    return 0;
}
