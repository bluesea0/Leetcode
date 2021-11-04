#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��3��26������10:25:47
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> candidates,visit;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //����visit���飬����Ƿ���ʹ��������������ͬ��
        //1a��1b��ֻ����1a��ʹ�õ������1b�ſ��Ա�ʹ��
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
            //������ж�������ע����i��i-1������i��start���������[1,1,1,3,3,5]�ͻ��������[3,5]
            //��Ϊ�ڱ�����2��3��ʱ�򣬵�һ��3��������visit���Ϊ��0���Ӷ����ִ���
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
//        //Ϊʲô���û����أ�
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
 * 1.���ģ������ǲ��еģ���������������������⣬һ�������Ĵ����ڡ��ͱ���������������
 *   candidates = [10,1,2,7,6,1,5], target = 8�������Ľ��Ϊ 1 1 2 5 6 7 10��Ŀ��ֵΪ8��
 *   ��ô���������ҵ�1 2 5 ���������������޷��ҵ�1 7����������Ϊ����������������ͬʱ�ڴ����ڣ�
 * 2.�����ܽᣬ�ҳ����к�Ϊtarget����;��ǻ��ݽⷨ��
 * */
int main(){

    return 0;
}
