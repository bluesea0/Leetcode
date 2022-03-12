#include <bits/stdc++.h>
using namespace std;
//@date: 2021-11-11  00:54
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        //什么没有负数关于连续子数组和用滑动窗口，我还是只能想到暴力解法！
        //暴力和前缀和都是一样的复杂度啊，用hash也不能和560一样的吧？因为你并不确定是n啊
        //还有可能是n的倍数呢。
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        for (int i = 0; i < n; i++)
            sums[i + 1] = sums[i] + nums[i];
        unordered_map<int, int> mp;
        for (int i = 0; i <= n; i++)
        {
            if (mp.count(sums[i] % k))
            {
                if (i - mp[sums[i] % k] >= 2)
                    return true;
            }
            else
                mp[sums[i] % k] = i;
        }
        return false;
    }
};
/*
1.当然是看题解写出来的。。。
两数相减的整除k，转化为每个数对k的余数相同。
*/
int main()
{

    return 0;
}
