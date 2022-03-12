#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
//2021年2月5日下午4:12:05
class Solution
{
public:
    int longestOnes(vector<int> &A, int K)
    {
        //转换为窗口中最多只能有k个0
        int left = 0, right = 0, ct = 0, max1 = 0, ans = 0;
        while (right < A.size())
        { //草，我都懵了，到底该怎么更新？有没有一个确定点的模板啊？
            if (A[right])
                ct++; //我乱了，这就是没掌握好模板的代价吗？
            max1 = max(ct, max1);
            if (right - left + 1 - max1 > K)
            {
                if (A[left])
                    ct--;
                left++;
            }
            ans = max(ans, right - left + 1); //这次我也学聪明了，就把答案更新放在外面。
            right++;
        }
        return ans;
    }
};
/*
 * 1.和424题非常像，都是在检查left之后，也就是每次更新right时更新ans，如果想在更新left时更新那么，
 *   就会有很多问题导致答案不不正确。
 * 2.https://www.cnblogs.com/grandyang/p/6376115.html，这个写的很牛逼，我上面写的其实也对
 *   class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, zero = 0, left = 0, k = 1;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) ++zero;//直接记录0的个数
            while (zero > k) {
                if (nums[left++] == 0) --zero;//缩小窗口的时候判断是否是0
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
因为这道题其实和字符还是不一样，这里只有0、1两个。
 * */

//11-23
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        //[left,right]中最多包含k个0，这里的k个不需要连续。
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        for (int i = 0; i < n; i++)
            sums[i + 1] = sums[i] + (1 - nums[i]);
        //遍历right，通过二分找到左边界
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int l = helper(sums, 0, i, sums[i] - k);
            ans = max(ans, i - l);
        }
        return ans;
    }
    int helper(vector<int> &nums, int left, int right, int k)
    {
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};
/*
1.将0反转为1，前缀和记录为出现的0的个数的累加数组，遍历找到区间中0的个数不超过k的最左下标
  学到了学到了，好聪明啊。
2.明天再写一下滑窗的解法，复习的时候根本没有想到用滑窗怎么写。
*/

//11-24滑窗解法
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int left = 0, right = 0, cnt = 0, res = 0;
        while (right < n)
        {
            if (nums[right++] == 0)
                cnt++;
            while (cnt > k)
            {
                if (nums[left] == 0)
                    cnt--;
                left++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};
/*
1.看grand的解法是这么写的，记录0的个数，缩小left的条件是0的计数值>k时，绝了绝了。
*/
int main()
{

    return 0;
}
