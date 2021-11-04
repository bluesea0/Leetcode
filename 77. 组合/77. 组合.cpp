#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年3月26日下午1:44:35
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int> res;
        helper(res,1,n,k);
        return ans;
    }
    void helper(vector<int>& res,int start,int end,int k){
        //我不知道这个push和pop的顺序该是怎样的。
        //该如何控制？在参数中res是否包含了start？是在循环中push和pop还是应该怎么控制？
        //具体来说问题是，push和pop应该在什么时机？
        if(res.size()==k){
            ans.push_back(res);return;
        }
        for(int i=start;i<=end;i++){
            res.push_back(i);
            helper(res,i+1,end,k);
            res.pop_back();
        }
    }
};
/*
 * 1.挺难的，还是看了讲解之后才写出来的，这个算是回溯算法。我要总结一下组和问题，是个比较大的问题。
 * */
int main(){

    return 0;
}
