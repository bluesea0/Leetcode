#include <bits/stdc++.h>
using namespace std;
//@date: 2021-11-20  16:41
// class Solution {
// public:
//     int shortestSubarray(vector<int>& nums, int k) {
//         //难道不是很简单吗？前缀和+二分？
//         //我忽然反应过来不行，因为A[i]它有负数！不能保证前缀和是递增序列。。。
//         //怪不得是道hard题哈。
// 思考的时候在想，是否用pair排序？
//比如针对样例：A = [2,-1,2]，前缀和：[0,2,1,3]
//那么遍历前缀和，针对0如何找到3，那么就需要遍历后面所有的？这太难了，如何找到？
//所以就不知道怎么办了。
//     }
// };
class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        //不得不说，官解这个解法真的太牛了，评论区也很牛，我理解了。
        int n = nums.size(), res = INT_MAX;
        deque<int> dq;                    //存储下标
        vector<long long> sums(n + 1, 0); //溢出了。
        //signed integer overflow: -2147400000 + -100000 cannot be represented in type 'int'
        for (int i = 0; i < n; i++)
            sums[i + 1] = sums[i] + nums[i];
        for (int i = 0; i <= n; i++)
        {                                                     //遍历前缀和数组
            while (!dq.empty() && sums[dq.back()] >= sums[i]) //保持严格单调递增
                dq.pop_back();
            dq.push_back(i);
            //有一段子数组和满足至少为K
            while (dq.size() > 1 && sums[dq.back()] - sums[dq.front()] >= k)
            {
                res = min(res, dq.back() - dq.front());
                dq.pop_front();
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
/*
1.牛死啦，根据官解写出来了。
 虽然说是滑动窗口的题目，但是不是，其实是单调队列的题目吧，不能按照滑窗的模板来，因为有
 弹出尾元素的步骤，不是滑窗，但是弹出首元素是滑窗的思想，移动left，所以总的来说，本题的
 解题方法是前缀和+单调队列+滑动窗口的思想，厉害！hard题不愧是hard题！学到了，好开心！
*/
int main()
{

    return 0;
}
