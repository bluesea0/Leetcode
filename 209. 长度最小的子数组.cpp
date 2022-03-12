#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//10-14
class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int ans = nums.size() + 1, start = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum < s)
                continue;
            while (sum - nums[start] >= s)
            {
                sum -= nums[start];
                start++;
            }
            ans = min(ans, i - start + 1);
        }
        return ans == nums.size() + 1 ? 0 : ans;
    }
};
/*
1.卧槽！！！我竟然一下子AC了！！！开心啊！！哈哈哈哈哈！然后没忍住去了鹅组看，那个死去的
研究生的问题，我也觉得矫情，就是矫情，为啥鹅组人要批评踩啊。。。
2.官方的答案：
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        int start = 0, end = 0;
        int sum = 0;
        while (end < n) {
            sum += nums[end];
            while (sum >= s) {//可以这样来判断，学到了。
                ans = min(ans, end - start + 1);
                sum -= nums[start];//明天可以再来写一下。
                start++;
            }
            end++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
3.还有二分解法明天要看一下。
*/
//10-21
/*
1.复习了一下二分解法，真的好厉害啊。太厉害了，我懂了，前缀和然后找到bound，再减去就相当于
  会>=s。
2.看了grand的解法，如果有负数的话，二分法会失效，这个明白，但是滑动窗口也会失效？
  明白了，就这个样本3,{2,-3,1,4}，因为有负数，所以在求和的过程中可能会出现0，但是在加上4的时候，
  就>3，但是计算的是从0开始的长度。所以要怎么解呢？暴力解？前缀和只有在都是正数的
*/

//2-10
/*
 * 1.来复习一下前缀和+二分的解法，顺便学习一下C++的标准库，比如二分，如果是在OJ，那么就不用自己手写了。
 * 2.前缀和有个技巧，sums[i]表示前i个数的和，i=0时为0，表示不是和。
 * */

//11-8
/*
1.每次看到题都只能想到滑窗的解法，但是实际上它还有前缀和的解法。
*/
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; i++)
            sums[i] = sums[i - 1] + nums[i - 1]; //sums[i]表示nums中前i个数的和
        for (int i = 0; i <= n; i++)
        {
            int t = sums[i] + target;
            //在sums数组中找到第一个>=t的下标，最靠近左边的位置
            int left = i, right = n;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (sums[mid] >= t)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            if (left != n + 1)
                ans = min(ans, left - i);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
/*
1.OhYes，我太棒啦！！通过前缀和，以及遍历前缀和数组，然后二分，达到了O(nlogn)的级别，很棒!
*/
int main()
{
    Solution s;
    vector<int> nums = {2, -3, 1, 4};
    cout << s.minSubArrayLen(3, nums);
    return 0;
}
