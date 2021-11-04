#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年5月23日下午2:54:41
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        helper(nums,0);
        return ans;
    }
    void helper(vector<int> nums,int start){//注意这里是传值
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
 * 1.上述结果可以AC，关键的点是helper函数只能传值，不能传引用，所以总结下来就是sort+判断+传值+不swap，可以达到
 *   去重的效果。其实不用排序是不是也行？
 *   尝试写一下使用set来标记，和o38的解法类似：
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
 * 1.上述结果AC了，第二种方法就是在函数内部用set来去重+传引用。
 * */

//6-10
/*
 * 1.今天有做一次总结，其实还挺乱的，这个最好的解法是dfs，就通过vis数组俩标记是否访问过。
 *          if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
                continue;
            }
	 这是官解给的解答，如果相等，且之前的没有被访问过那么就忽略。
   2.第二种是swap，那么有两种方法，一种是通过set判断，效率低；一种是通过判断和之前的是否相同来避免固定
     相同的数，但是不能swap回来，关于这一点我还是没搞明白。所以就用第一种方法就行。
 * */
int main(){

    return 0;
}
