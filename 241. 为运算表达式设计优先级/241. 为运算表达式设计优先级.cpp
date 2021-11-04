#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月13日上午1:11:04
//class Solution {
//public:
//    vector<int> diffWaysToCompute(string input) {
//        vector<int> ans;//原来不用去重
//        for(int i=0;i<input.size();i++){
//            if(!(input[i]>='0'&&input[i]<='9')){//如果是符号的话，分治处理
//                int left=compute(input,0,i-1);//还是利用下标来传吧
//                int right=compute(input,i+1,input.size()-1);//开始和结束的下标
//                ans.push_back(con(input[i],left,right));
//            }
//        }
//        //怎么用set来初始化vector呢？
//        return ans;
//    }
//    int compute(string &s,int begin,int end){
//        if(begin==end) return s[begin]-'0';//返回计算结果
//        for(int i=begin;i<=end;i++){
//            if(!(input[i]>='0'&&input[i]<='9')){
//                int left=compute(s,begin,i-1);
//                int right=compute(s,i+1,end);
//                //写不下去了，因为这里到底是返回一个什么？应该不是单个的值，而是向量吧。
//            }
//        }
//    }
//    int com(char c,int left,int right){
//        int res=0;
//        if(c=='-')
//            res=left-right;
//        else if(c=='+')
//            res=left+right;
//        else res=left*right;
//        return res;
//    }
//};


int main(){

    return 0;
}
