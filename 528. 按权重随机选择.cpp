#include <bits/stdc++.h>
using namespace std;
//@date: 2021-11-18  20:16
class Solution
{
public:
    vector<int> sums;
    Solution(vector<int> &w)
    {
        // int n=w.size();
        // sums.resize(n,0);
        //我本来想这么写，但是就很那啥，写的很冗余
        sums = w; //grand是直接赋值，太牛了吧。。。
        for (int i = 1; i < w.size(); i++)
            sums[i] = sums[i - 1] + w[i];
    }

    int pickIndex()
    {
        int x = rand() % sums.back() + 1;
        int left = 0, right = sums.size() - 1; //在nums数组中找到第一个>=它的元素的下标
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (sums[mid] >= x)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
/*
1.AC了，相当开心。但是还是看了题解，我自己是想不出来的，所以需要复习。
  将随机选择改为区间的问题，区间范围对应到真实的选择，并且因为都是正数，可以使用二分来查找。
  我发现前缀和好喜欢和二分结合在一起，其实是有迹可循的，因为前缀和是个排序的数组！
  排序数组中查找当然用二分！绝了绝了。
2.在[1,sums]中生成一个数，区间大小表示对应被选中的频率。随机生成一个，然后看它映射的区间
  很牛。
*/
int main()
{

    return 0;
}
