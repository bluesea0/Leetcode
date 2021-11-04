#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年5月23日下午2:48:23
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
            helper(nums,start+1);//关键这里是处理start+1后的位置
            swap(nums[i],nums[start]);
        }
    }
};//主要思路就是dfs，将当前位置和任一之后的位置交换元素，然后去处理之后的位置，处理完了之后交换回来
//继续处理下一个。


int main(){

    return 0;
}
