#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
//10-23
class Solution
{
public:
    //前缀和+哈希
    int subarraySum(vector<int> &nums, int k)
    {
        //if(k==0) return 0; 如果nums={0},k=0，那就=1？如果nums={0,0}，k=0,ret=3？这种怎么来
        // 判断啊，我觉得有点难度。不知道怎么考虑。
        vector<int> sum(nums.size(), 0);
        unordered_map<int, int> mp;
        sum[0] = nums[0];
        for (int i = 1; i < sum.size(); i++)
        { //我有点不明白 这个前缀和的区间开闭 我写的没错 右闭区
            sum[i] = sum[i - 1] + nums[i];
        }
        int ret = 0;
        mp[0] = 1; //表示的是当前数正好为k时，计数+1
        //-1 -2 -1
        for (int i = 0; i < sum.size(); i++)
        {
            //            cout<<"mp"<<mp[sum[i]]<<endl;
            //            if(sum[i]==k)ret+=mp[sum[i]];
            //            else if(k&&sum[i]-k>0 && mp.count(sum[i]-k))ret+=mp[sum[i]-k];
            if (mp.count(sum[i] - k) != 0)
                ret += mp[sum[i] - k];
            mp[sum[i]]++; //这个应该放到后面，不应该包括自己啊。
            //针对{1,2,3},0这个样本，你分析吧。所以不能放前面的原因就是这个啊。
        }
        return ret;
    }
};
/*
1.针对[1],0样本我加了k==0的限制，但是对[-1,-1,1]，0这个样本就通不过了，你说气不气人。
  我投降我是真不懂了。
2.正对sum[i]==k的情况，比如说[2,2],2这个case分析一下。
  mp[2]=1;ct=1;
  [0,0],0样例：ct=1,mp[0]=2;ct=3,mp[0]=3。
3.果然我不是很明白为什么一开始要加上mp[0,1]
  https://www.cnblogs.com/grandyang/p/6810361.html，评论区中就有讲解。
   [2,2,2,2,2] k=4 ; [1,3,2,2,4] k=4
   从起始数开始求的连续和为K 那么 这种corner case 你就需要 放上map.put(0,1)
4.AC了，但真是一波三折啊。
*/
class Solution1
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int sum = 0, ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (auto n : nums)
        {
            sum += n;
            if (mp.count(sum - k) != 0)
                ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
}; //AC了，yes，下次复习要口述一下。

//10-27
/*
 * 1.这几次复习想口述，但是真的想不出来思路是什么，然后去看了题解，题解价值20万啊。
 * 2.首先，第一种思路是枚举，计算以当前i为结尾的连续子数组中有多少个和满足=k，然后就j就倒着从i开始遍历
 *   需要注意的是，是倒着，不能正着，因为正着真的你代码应该就是O(n^3)了，每次都要从j求到i。如果倒着求
 *   就可以[j,i]到[j-1,i]直接加上nums[j]即可了。这种枚举的思路也很厉害啊！思路清晰！
 * 3.考虑以i结尾的和为k的连续子数组个数，那么就统计有多少个前缀和为pre[i]-k的pre[j]即可，其中j<=i的。
 *   哈希表mp记录pre[i]出现的次数。绝！理清了思路。
 * */

//10-30
/*
 * 思路：
连续子数组的题目一般都是使用滑动窗口？不对是前缀和，排好序以及没有负数的才用滑动窗口吧，
计算前缀和，对前缀和遍历，查看前缀和-k是否存在在之前的前缀和中，如果有那么就说明从之前的那一段
到目前的位置的和是=k的。复杂度都是O(n)
我目前有的疑问是，这个已经是最优的解法了，不是说要一层一层地来吗？这已经在最优解那一层了，
O(n2)的解法：那就以每个节点i作为结束，计算它之前的每个结点的和，试了一下是超时的。PASS
 * */

//11-12
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        for (int i = 0; i < n; i++)
            sums[i + 1] = sums[i] + nums[i];
        unordered_map<int, int> mp;
        mp[0] = 1;
        //0 1 2 3
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (mp.count(sums[i] - k))
                res += mp[sums[i] - k];
            mp[sums[i]]++;
        }
        return res;
    }
};
/*
1.今天才发现，做熟了前缀和题目之后，感觉这也太简单了吧。以前只不过是没做过这种题型而已！！
2.还可以进行一个空间的优化，因为每次都只遍历到了sums[i]，所以是可以的，明天写一下空间优化。
*/
//11-13
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        //0 1 2 3
        int res = 0, sums = 0;
        for (int i = 0; i < n; i++)
        {
            sums += nums[i];
            if (mp.count(sums - k))
                res += mp[sums - k];
            mp[sums]++;
        }
        return res;
    }
};
/*
1.相当easy，空间复杂度为常数。
*/
int main()
{
    Solution1 s;
    vector<int> nums = {1, 1, 1};
    cout << s.subarraySum(nums, 2);
    return 0;
}
