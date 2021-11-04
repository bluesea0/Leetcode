#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��3��27������10:20:55
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
        if(sum>target)return;//�����ʵ�����ж��˰ɣ�
        if(path.size()>=k)return;//��Ȼ֮ǰ�ĺ�û��=target������size�Ѿ����ˣ�
        for(int i=start;i<candidates.size();i++){
            if(sum+candidates[i]>target)break;//�����������ж�sum��target�ظ���
            path.push_back(candidates[i]);
            sum+=candidates[i];
            helper(path,i+1,sum,target,k);
            path.pop_back();
            sum-=candidates[i];
        }
    }
};
/*
 * 1.̫ţ�ˣ���һ����AC�ˣ��ٶȷǳ��Ŀ죬ֱ�Ӿ��ǻ���+��֦��
 * */
int main(){

    return 0;
}
