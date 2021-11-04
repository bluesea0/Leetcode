#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年3月26日下午9:54:42
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> candidates;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> path;
        this->candidates=candidates;
        helper(path,0,0,target);
        return ans;
    }
    void helper(vector<int>& path,int start,int sum,int target){
        if(sum==target){
            ans.push_back(path);return;
        }
        if(sum>target)return;
        for(int i=start;i<candidates.size();i++){
            if(sum+candidates[i]>target)break;
            path.push_back(candidates[i]);
            sum+=candidates[i];
            helper(path,i,sum,target);
            path.pop_back();
            sum-=candidates[i];
        }
    }
};
/*
 * 1.学完77题的模式，在这里也就很熟悉了。for循环中push一下。是一个回溯的解法。
 * */

//6-19
//class Solution {
//public:
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        //我不太懂这个为什么不用滑动窗口处理？这不就是滑窗的题目吗？
//        //我忽然看到它说可以无限次被选取。
//        //那就必须用回溯的办法了。
//    }
//};

//2021-9-1
/*
 * 1.还是得认真审题，才能不搞错思路。
 * 2.我来试写一下吧，好久没有写过回溯的题目了。这个要看看我自己的记忆怎么样。
 * */
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> path;
        dfs(candidates,0,0,target,path);
        return ans;
    }
    void dfs(vector<int>& candidates,int index,int res,int target,vector<int>& path){
        if(res>=target){
            if(res==target)
                ans.push_back(path);
            return ;
        }
        for(int i=index;i<candidates.size();i++){
            path.push_back(candidates[i]);
            dfs(candidates,i,res+candidates[i],target,path);
            path.pop_back();
        }
    }
};
/*
 * 1.相对来说还是比较顺利的，熟悉了一下怎么写，等到笔试的时候相对来说也不会那么慌了。
 * */
int main(){

    return 0;
}
