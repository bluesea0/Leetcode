#include <bits/stdc++.h>
using namespace std;
//@date: 2022-02-26  16:24
class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int ans = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > nums[i])
                    ans = max(ans, nums[j] - nums[i]);
            }
        }
        return ans;
    }
};
/*
1.三个月没刷题，之前提交是11.25号，我的妈，正好3个月！正好3个月没刷题！天哪，一个季度哎。
2.我只想到了暴力解法，看到数据的范围是2 <= n <= 1000，所以只想到了O(n^2)的解法。
  原来是和买股票一样的，我都忘了，可以是一次遍历的。
*/
class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int ans = -1, premin = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] <= premin)
                premin = nums[i];
            else
                ans = max(ans, nums[i] - premin);
        }
        return ans;
    }
}; //按照题解的前缀数组的解法。
int main()
{

    return 0;
}
