#include <bits/stdc++.h>
using namespace std;
//@date: 2021-11-21  10:28
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int n = nums.size(), ans = 0;
        vector<int> sums(n + 1, 0);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            sums[i + 1] = sums[i] + nums[i];
        for (int i = 0; i <= n; i++)
        {
            if (mp.count(sums[i] - goal))
                ans += mp[sums[i] - goal];
            mp[sums[i]]++;
        }
        return ans;
    }
};
/*
1.在评论区看到和560题类似，但是560可以有负数，所以不能用滑动窗口，这个可以用？但是我没想到
  怎么用，之后再看看。
*/

//11-23
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        //滑动窗口的解法
        int left = 0, right = 0, n = nums.size();
        int sums = 0, ans = 0;
        while (right < n)
        {
            sums += nums[right];
            while (left < right && sums > goal)
                sums -= nums[left++]; //需要控制范围
            if (sums == goal)
            {
                ans++;
                // while(left<right&&nums[left]==0){
                //     left++;
                //     ans++;
                // }这里不能移动left，比如针对样本[0,0,0] goal=0
                for (int j = left; j < right; j++)
                {
                    if (nums[j] == 0)
                        ans++;
                    else
                        break; //得break掉啊，需要是连续的0
                }
            }
            right++; //把这个忘记了，sums就溢出了。。。
        }
        return ans;
    }
};
/*
1.太难了，相当不容易，比正常的滑窗多了的步骤是，判断left是否有连续的0，再添加解的个数。
*/
int main()
{

    return 0;
}
