#include <bits/stdc++.h>
using namespace std;
//@date: 2022-03-04  10:02
class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i + 1 < n; i++)
        {
            int mn = nums[i], mx = nums[i];
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > mx)
                    mx = nums[j];
                else if (nums[j] < mn)
                    mn = nums[j];
                sum += (mx - mn);
            }
        }
        return sum;
    }
};
/*
1.注意到返回的结果是long long。所以sum定义时需要时long long。
2.O(n)单调栈的解法可真牛哇。
*/
int main()
{

    return 0;
}
