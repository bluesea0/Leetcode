#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��5��23������2:54:41
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        helper(nums,0);
        return ans;
    }
    void helper(vector<int> nums,int start){//ע�������Ǵ�ֵ
        if(start==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++){
            if(start!=i&&nums[i]==nums[start])continue;
            swap(nums[i],nums[start]);
            helper(nums,start+1);
            //swap(nums[i],nums[start]);
        }
    }
};
/*
 * 1.�����������AC���ؼ��ĵ���helper����ֻ�ܴ�ֵ�����ܴ����ã������ܽ���������sort+�ж�+��ֵ+��swap�����Դﵽ
 *   ȥ�ص�Ч������ʵ���������ǲ���Ҳ�У�
 *   ����дһ��ʹ��set����ǣ���o38�Ľⷨ���ƣ�
 * */
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        helper(nums,0);
        return ans;
    }
    void helper(vector<int>& nums,int start){
        if(start==nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> us;
        for(int i=start;i<nums.size();i++){
            if(us.count(nums[i]))continue;
            us.insert(nums[i]);
            swap(nums[i],nums[start]);
            helper(nums,start+1);
            swap(nums[i],nums[start]);
        }
    }
};
/*
 * 1.�������AC�ˣ��ڶ��ַ��������ں����ڲ���set��ȥ��+�����á�
 * */

//6-10
/*
 * 1.��������һ���ܽᣬ��ʵ��ͦ�ҵģ������õĽⷨ��dfs����ͨ��vis����������Ƿ���ʹ���
 *          if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
                continue;
            }
	 ���ǹٽ���Ľ�������ȣ���֮ǰ��û�б����ʹ���ô�ͺ��ԡ�
   2.�ڶ�����swap����ô�����ַ�����һ����ͨ��set�жϣ�Ч�ʵͣ�һ����ͨ���жϺ�֮ǰ���Ƿ���ͬ������̶�
     ��ͬ���������ǲ���swap������������һ���һ���û�����ס����Ծ��õ�һ�ַ������С�
 * */
int main(){

    return 0;
}
