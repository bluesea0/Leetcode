#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月13日下午8:33:42
//class Solution {
//public:
//    vector<int> findDisappearedNumbers(vector<int>& nums) {
//        //这个我只想到了用额外空间的，哈希？
//        //求和？不行，位运算？但是也不确定哪些是出现两次，哪些出现一次，
//        //哪些没出现，这太难了吧。不用额外空间？
//    }
//};
/*
 * 1.感觉还挺难的，没想出来怎么做，看题解是说需要原地修改。
 * */

//2-14
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=(nums[i]-1)%n;
            nums[x]+=n;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]<=n)
                ans.push_back(i+1);//这里需要+1，是从1开始计数的
        }
        return ans;
    }
};
/*
 * 1.AC了，因为元素值大小有限制，所以可以通过原地修改并且判断元素值大小来计算，学到了。
 * 2.inplace修改，不能占用额外空间的话，就可以正负反转！
 * */

//3-20
class Solution2 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //采用正负反转的方法
        //看到评论区有人说，如果是+n的话，可能会存在溢出的情况
        for(int i=0;i<nums.size();i++){
            int n=abs(nums[i]);
            nums[n-1]=-abs(nums[n-1]);//之所以这里加abs，是因为可能会出现两次
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
            if(nums[i]>0)
                ans.push_back(i+1);
        return ans;
    }
};

//5-20
/*
 * 1.这里牛蛙，直接对数组数据，不管它原来是正是负，直接取abs整负号，这样只要出现过的就是负。
 * */

//2021-6-8
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            while(nums[i]!=nums[nums[i]-1])//这个循环检测条件意味着将nums[i]放到该放的位置
            //也就是nums[i]-1的位置。好乱啊。
                swap(nums[i],nums[nums[i]-1]);
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
            if(nums[i]-1!=i)
                ans.push_back(i+1);
        return ans;
    }
};
/*
 * 1.这个swap也够乱的，着迷。
 * */
int main(){

    return 0;
}
