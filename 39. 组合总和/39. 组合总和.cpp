#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��3��26������9:54:42
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
 * 1.ѧ��77���ģʽ��������Ҳ�ͺ���Ϥ�ˡ�forѭ����pushһ�¡���һ�����ݵĽⷨ��
 * */

//6-19
//class Solution {
//public:
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        //�Ҳ�̫�����Ϊʲô���û������ڴ����ⲻ���ǻ�������Ŀ��
//        //�Һ�Ȼ������˵�������޴α�ѡȡ��
//        //�Ǿͱ����û��ݵİ취�ˡ�
//    }
//};

//2021-9-1
/*
 * 1.���ǵ��������⣬���ܲ����˼·��
 * 2.������дһ�°ɣ��þ�û��д�����ݵ���Ŀ�ˡ����Ҫ�������Լ��ļ�����ô����
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
 * 1.�����˵���ǱȽ�˳���ģ���Ϥ��һ����ôд���ȵ����Ե�ʱ�������˵Ҳ������ô���ˡ�
 * */
int main(){

    return 0;
}
