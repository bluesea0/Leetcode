#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年8月28日下午8:02:44
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //单调栈，递减，非严格
        stack<int> stk;//存储index
        vector<int> ans(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            while(!stk.empty()&&temperatures[i]>temperatures[stk.top()]){
                ans[stk.top()]=i-stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};
/*
 * 1.我太牛了吧，一下子增长自信。添加到单调栈专题中。
 * */
int main(){

    return 0;
}
