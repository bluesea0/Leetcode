#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��24������1:33:31
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res=1,ans=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                res=res+1;
                ans=max(ans,res);
            }else res=1;
        }
        return ans;
    }
};
/*
 * 1.̰�ĵķ���������ʵ��һ��ʼ���˼·��dp����
 * 2.
 * */
int main(){

    return 0;
}
