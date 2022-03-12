#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
//2021年1月28日下午6:53:16
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int m = nums.size();
        vector<int> sums(m, 0);
        for (int i = 0; i < m; i++)
        { //这个我求错了啦！
            //怎么求累加来着？
            sums[i] += nums[i];
            if (i > 0)
                sums[i] += sums[i - 1];
        }
        for (int i = 0; i < m; i++)
        {
            if (i == 0)
            {
                if (sums[m - 1] - sums[i] == 0)
                    return i;
            }
            else if (i == m - 1)
            {
                if (sums[i - 1] == 0)
                    return i;
            }
            else
            {
                if (sums[i - 1] == sums[m - 1] - sums[i])
                    return i;
            }
        }
        return -1;
    }
};
/*
 * 1.AC了，O(n)
 * 2.原来这个是前缀和的解法，我都没反应过来！呜呜呜啊。
 *   看了官方题解才知道，其实根本不用一个额外的前缀和数组来保存啊，先求出来所有的和，然后以一个sum统计
 *   前缀和，遍历到第i个元素时，判断sum==total-sum-nums[i]即可，真是绝了！
 * */

//2-4
/*
 * 1.再复习我还是只能想出来我的那种方法。记录左边的元素和，那么右边的就可以计算出来，就是total-sum-nums[i]
 * */

//11-19
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        for (int i = 0; i < n; i++)
            sums[i + 1] = sums[i] + nums[i];
        for (int i = 1; i <= n; i++)
        {
            if (sums[i - 1] == sums[n] - sums[i])
                return i - 1;
        }
        return -1;
    }
};
/*
1.Yes!相当简单，AC了，无难度。sums[i]表示前i个元素的和，只要判断好sums如何表示就能写出很
  简洁的代码。再回看之前写的代码，实在是太丑了。。。
2.我太鸡贼了，这道题和1991题一样，应该是1991的周赛转过来的？我就把1991也提交了，这样就做一道
  能显示通过两道，你骗谁呢？只是为了数字的虚荣吧，怪不得你周赛只能做出来一道题。
*/
int main()
{

    return 0;
}
