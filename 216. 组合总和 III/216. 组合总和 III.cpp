#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年3月27日上午10:20:55
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> candidates;
    vector<vector<int>> combinationSum3(int k, int n) {
        candidates.resize(9,0);
        for(int i=0;i<candidates.size();i++)
            candidates[i]=i+1;
        vector<int> path;
        helper(path,0,0,n,k);
        return ans;
    }
    void helper(vector<int>& path,int start,int sum,int target,int k){
        if(sum==target){
            if(path.size()==k)ans.push_back(path);
            return;
        }
        if(sum>target)return;//这个其实不用判断了吧，
        if(path.size()>=k)return;//既然之前的和没有=target，并且size已经够了，
        for(int i=start;i<candidates.size();i++){
            if(sum+candidates[i]>target)break;//这里和上面的判断sum和target重复了
            path.push_back(candidates[i]);
            sum+=candidates[i];
            helper(path,i+1,sum,target,k);
            path.pop_back();
            sum-=candidates[i];
        }
    }
};
/*
 * 1.太牛了，我一下子AC了，速度非常的快，直接就是回溯+剪枝。
 * */
int main(){

    return 0;
}
