#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年6月12日下午11:12:45
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        sub(nums,path,0);
        return ans;
    }
    void sub(vector<int>&nums,vector<int>& path,int index){
        ans.push_back(path);
        for(int i=index;i<nums.size();i++){
            path.push_back(nums[i]);
            sub(nums,path,i+1);
            path.pop_back();
        }
    }
};
/*
 * 1.排列和子集有两处明显的不同，首先是递归调用时全排列是传入index+1，子集是i+1。
 *   并且全排列要判断长度，子集一进来直接push就行。
 * */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //位控制
        vector<vector<int>> ans;
        int m=nums.size();
        int n=pow(2,m);
        for(int i=0;i<n;i++){
            int t=i;
            vector<int> temp;
            for(int j=0;j<m;j++){
                //关键的问题是如何每次获取最高位？
                if(t&(1<<(m-j-1)))temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
/*
 * 1.位运算的也太快了吧，0msAC了。
 * */
int main(){

    return 0;
}
