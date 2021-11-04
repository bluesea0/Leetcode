#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月19日上午11:21:08
//class Solution {
//public:
//    vector<int> visit;
//    bool canPartitionKSubsets(vector<int>& nums, int k) {
//        int sums=accumulate(nums.begin(),nums.end(),0);
//        if(sums%k)return false;//不能平分
//        //求最大的值，如果大于k的话，那么肯定不能评分
//        int maxn=nums[0];
//        for(int i=1;i<nums.size();i++)
//            maxn=max(maxn,nums[i]);
//        int target=sums/k;
//        if(maxn>target)return false;
//        //用回溯的方法一个一个的试
//        //怎么写代码啊？我好像真的不太会啊，我哭泣了。
//        //比如说对于第一个元素4，那么就依次尝试让它和其他元素组和？
//        //那得有一个visit数组啊
//        visit.resize(nums.size(),0);
//        return dfs(nums,target,k);//每次调用都会构造子集
//    }
//    bool dfs(vector<int>& nums,int target,int k){
//        if(k===0){//已经构造了k个子集，需要判定是否所有的元素都被包括进来了
//            for(int i=0;i<visit.size();i++)
//                if(visit[i]==0)return false;
//            return true;
//        }
//        //天哪，我不知道该怎么写下去了，我是想有一个数作为根本的，但是怎么传进来呢？
//        for(int i=0;i<nums.size();i++){//看了grand的解法明白了，用start来标记一定包括当前的和
//在运行时，参数可以有一个curSUM，一直标记着这个start去访问之后所有的可能性。
//            if()
//        }
//    }
//};
/*
 * 1.上面是尝试不对数组排序的，没有写出来，看了grand的初始写法，https://www.cnblogs.com/grandyang/p/7733098.html
 *   原来是要有一个start的，并且如果当前的和满足了target，那么就从头开始计算start，grand的代码写的很好
 *   可以手动运行画一下递归树。
 *class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        vector<bool> visited(nums.size(), false);
        return helper(nums, k, sum / k, 0, 0, visited);
    }
    bool helper(vector<int>& nums, int k, int target, int start, int curSum, vector<bool>& visited) {
        if (k == 1) return true;
        if (curSum == target) return helper(nums, k - 1, target, 0, 0, visited);
        for (int i = start; i < nums.size(); ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            //下面的调用start变为了i+1，并且当前的点被true了，下次就会自动包含当前的值了
            if (helper(nums, k, target, i + 1, curSum + nums[i], visited)) return true;
            visited[i] = false;
        }
        return false;
    }
};//我觉得这个写的还是很好的，所以贴过来一下。
 * */
class Solution {
public:
    vector<int> visit;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sums=accumulate(nums.begin(),nums.end(),0);
        if(sums%k)return false;//不能平分
        //求最大的值，如果大于k的话，那么肯定不能评分
        // int maxn=nums[0];//排序之后的话就不用这个了，而直接是最后一个了
        // for(int i=1;i<nums.size();i++)
        //     maxn=max(maxn,nums[i]);
        sort(nums.begin(),nums.end());
        int target=sums/k;
        if(nums.back()>target)return false;
        //用回溯的方法一个一个的试
        //怎么写代码啊？我好像真的不太会啊，我哭泣了。
        //比如说对于第一个元素4，那么就依次尝试让它和其他元素组和？
        //那得有一个visit数组啊
        while(nums.back()==target){
            nums.pop_back();
            k--;//这个也是降低程序运行时间的一个优化点
        }
        visit.resize(nums.size(),0);
        return dfs(nums,target,k,0,0);//每次调用都会构造子集
    }
    bool dfs(vector<int>& nums,int target,int k,int start,int cur){
        // if(k===0){//已经构造了k个子集，需要判定是否所有的元素都被包括进来了
        //     for(int i=0;i<visit.size();i++)
        //         if(visit[i]==0)return false;//这里其实没有不可能没被访问到的，因为都是正值
        //         //而且已经确定了
        //     return true;
        // }
        if(k==1) return true;//由于题目的各种条件，就可以确定过如果当前是1的话，就肯定有解
        //天哪，我不知道该怎么写下去了，我是想有一个数作为根本的，但是怎么传进来呢？
        //我看所有的代码判断条件都是放到这里的
        if(cur==target) return dfs(nums,target,k-1,0,0);//去判断下一个
        if(cur>target) return false;
        for(int i=start;i<nums.size();i++){
            if(visit[i])continue;//如果已经被访问过了
            //if(cur+nums[i]>target)break;//后面的值会越来越大
            visit[i]=1;
            if(dfs(nums,target,k,i+1,cur+nums[i])) return true;
            //bool flag=false;
            //if(cur+nums[i]==target)flag=;//需要开始构造下一个子集，所以cur值应该为0了，同时k值-1
            //else flag=dfs(nums,target,k,i+1,cur+nums[i]);
            visit[i]=0;

            //if(flag)return true;
        }
        return false;
    }
};
//超时了，但是我去看通过的用例是149/149，可能是最后一个用例？
/*
 * 1.AC了，不容易啊。复杂度是阶乘级别的，实在是太难。
 *   发现回溯法的精髓所在，for循环做选择的时候内容不要有限制和判断，要将它放到函数开头判断！
 * 2.动态规划的解法，我明天再学习！
 * */
int main(){

    return 0;
}
