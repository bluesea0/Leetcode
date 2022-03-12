#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
//2021年9月29日上午1:10:36
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxP = nums[0], minP = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int mx = maxP, mn = minP;
            maxP = max(mx * nums[i], max(mn * nums[i], nums[i]));
            minP = min(mn * nums[i], min(mx * nums[i], nums[i]));
            res = max(res, maxP);
        }
        return res;
    }
};
/*
 * 1.一开始很疑惑觉得只需要取max(mx*nums[i],mn*nums[i])两者，但是想到它是选取子数组，所以就包括
 *   只从当前i开始作为一个新的子数组这样的结果。
 * */

//11-7
/*
1.之前的还是没有考虑到dp，一看标签是dp这才明白，具体思想该怎么做，上述的代码过了两天就不理解了。
  还是功力不够啊。上述解法只是经过空间优化后的dp解法。
*/
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        //fmax表示以i结尾的子数组的最大值，包含下标i元素
        //fmin表示以i结尾的子数组的最小值，包含下标i元素
        //关键点是子数组，一定是一定是包含当前元素的，最差就是当前元素直接作为子数组的开始了。
        if (nums.empty())
            return 0;
        vector<int> fmax(nums), fmin(nums); //直接以nums作为初始化，牛啊，这样就不用单独赋值0位了
        for (int i = 1; i < nums.size(); i++)
        {
            fmax[i] = max(fmax[i - 1] * nums[i], max(fmin[i - 1] * nums[i], nums[i]));
            fmin[i] = min(fmin[i - 1] * nums[i], min(fmax[i - 1] * nums[i], nums[i]));
        }
        return *max_element(fmax.begin(), fmax.end());
    }
};
int main()
{
    Solution s;

    return 0;
}
