#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年6月12日下午11:35:46
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vis;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vis.resize(nums.size(),0);
        vector<int> path;
        sub(nums,0,path);
        return ans;
    }
    void sub(vector<int>& nums,int index,vector<int>& path){
        ans.push_back(path);
        for(int i=index;i<nums.size();i++){
            if(i>index&&nums[i]==nums[i-1]&&vis[i-1]==0)continue;
            path.push_back(nums[i]);
            vis[i]=1;
            sub(nums,i+1,path);
            vis[i]=0;
            path.pop_back();
        }
    }
};
/*
 * 1.子集问题真的如鱼得水，算是蛮简单的？
 * 2.关键是如何去构造出来，子集直接进来dfs就push进去。
 * 3.但是我还以为这个没有办法用位运算来控制呢，没想到是可以的，要获取到当前位以及前一位。
 * */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //位控制
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int m=nums.size();
        int n=pow(2,m);
        for(int i=0;i<n;i++){
            int t=i;
            vector<int> temp;
            bool flag=true;//需要通过这个来辅助判断是否是重复的，重复则不放入
            for(int j=0;j<m;j++){
                //关键的问题是如何每次获取最高位？
                if(t&(1<<(m-j-1))){
                    if(j>0&&nums[j]==nums[j-1]&&(t&(1<<(m-j)))==0){//位运算&优先级低。在判断时一定要注意括号
                        flag=false;break;//以前已经有过了，就不必再遍历了
                    }
                    temp.push_back(nums[j]);
                }
            }
            if(flag)ans.push_back(temp);
        }
        return ans;
    }
};
int main(){

    return 0;
}
