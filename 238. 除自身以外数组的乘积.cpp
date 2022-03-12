#include <bits/stdc++.h>
using namespace std;
//@date: 2021-11-08  23:00
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> left(n + 1, 1);  //left[i]表示nums[i]中前i个数的乘积
        vector<int> right(n + 1, 1); //right[i]表示nums[i]中后n-i个数的乘积
        for (int i = 0; i < n; i++)
            left[i + 1] = left[i] * nums[i];
        for (int i = n - 1; i >= 0; i--)
            right[i] = right[i + 1] * nums[i];
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            res[i] = left[i] * right[i + 1];
        }
        return res;
    }
};
/*
1.用前缀乘积和后缀乘积写出来了，太棒了！空间复杂度是O(n)，
  我的天哪，居然还有O(1)的解法，难以置信。我睡前看看。
*/

//11-11
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 1; i < n; i++)
            res[i] = res[i - 1] * nums[i - 1];
        //1 2 3 4
        //1 1 2 6
        //    8 6
        int r = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            // res[i]=res[i]*nums[i+1];
            res[i] *= r;
            r *= nums[i];
        }
        return res;
    }
};
/*
1.需要有一个辅助的R来计算。
*/
int main()
{

    return 0;
}
