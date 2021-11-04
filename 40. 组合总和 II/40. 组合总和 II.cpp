#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年3月26日下午10:25:47
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> candidates,visit;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //建立visit数组，标记是否访问过，如果两个数相同，
        //1a，1b，只有在1a被使用的情况下1b才可以被使用
        sort(candidates.begin(),candidates.end());
        visit.resize(candidates.size(),0);
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
            if(i!=start&&candidates[i]==candidates[i-1]&&visit[i-1]==0)continue;
            //这里的判断条件，注意是i和i-1，不是i和start，针对样本[1,1,1,3,3,5]就会出现两个[3,5]
            //因为在遍历第2个3的时候，第一个3被弹出，visit标记为了0，从而出现错误。
            path.push_back(candidates[i]);
            sum+=candidates[i];
            visit[i]=1;
            helper(path,i+1,sum,target);
            path.pop_back();
            sum-=candidates[i];
            visit[i]=0;
        }
    }
};

//6-19
//class Solution {
//public:
//    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//        vector<vector<int>> ans;
//        sort(candidates.begin(),candidates.end());
//        //为什么不用滑窗呢？
//        int left=0,right=0,n=candidates.size(),cur=0;
//        for(;right<n;right++){
//            if(right>0&&candidates[right]==candidates[right-1])continue;
//            cur+=candidates[right];
//            while(cur>=target){
//                if(target==cur){
//                    vector<int> temp;
//                    for(int j=left;j<=right;j++){
//                        temp.push_back(candidates[j]);
//                    }
//                    ans.push_back(temp);
//                }
//                cur-=candidates[left++];
//            }
//        }
//        return ans;
//    }
//};
/*
 * 1.天哪，滑窗是不行的，滑窗解决的是连续的问题，一个连续的窗口内。就比如所给的样例：
 *   candidates = [10,1,2,7,6,1,5], target = 8。排序后的结果为 1 1 2 5 6 7 10，目标值为8，
 *   那么滑窗可以找到1 2 5 这个结果，但是它无法找到1 7这个结果，因为它们两个数不可能同时在窗口内！
 * 2.所以总结，找出所有和为target的组和就是回溯解法。
 * */
int main(){

    return 0;
}
