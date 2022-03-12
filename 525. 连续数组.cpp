#include <bits/stdc++.h>
using namespace std;
//@date: 2021-11-13  01:29
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int count = 0, n = nums.size();
        mp[0] = -1;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i])
                count++;
            else
                count--;
            if (mp.count(count))
                res = max(res, i - mp[count]);
            else
                mp[count] = i;
        }
        return res;
    }
};
/*
1.前缀和，一下子AC了哎，相当开心了。
  时间和空间都是O(n)。
*/
int main()
{

    return 0;
}
