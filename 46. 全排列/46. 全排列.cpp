#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��5��23������2:48:23
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums,0);
        return ans;
    }
    void helper(vector<int>& nums,int start){
        if(start==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++){
            swap(nums[i],nums[start]);
            helper(nums,start+1);//�ؼ������Ǵ���start+1���λ��
            swap(nums[i],nums[start]);
        }
    }
};//��Ҫ˼·����dfs������ǰλ�ú���һ֮���λ�ý���Ԫ�أ�Ȼ��ȥ����֮���λ�ã���������֮�󽻻�����
//����������һ����


int main(){

    return 0;
}
