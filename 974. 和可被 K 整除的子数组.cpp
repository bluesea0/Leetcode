#include <bits/stdc++.h>
using namespace std;
//@date: 2021-11-24  18:35
class Solution
{
public:
    int subarraysDivByK(vector<int> &A, int k)
    {
        //求元素之和，求子数组的题，一看这个就是前缀和+哈希
        //哈希记录%数，(a-b)%k==0即整除，那么转换为a%k==b%k，从之前的一道题里学过来的。
        int n = A.size();
        vector<int> sums(n + 1, 0);
        for (int i = 0; i < n; i++)
            sums[i + 1] = sums[i] + A[i];
        unordered_map<int, int> mp;
        int res = 0;
        for (int i = 0; i <= n; i++)
        {
            int t = (sums[i] % k + k) % k;
            if (mp.count(t))
                res += mp[t];
            mp[t]++;
        }
        return res;
    }
};
/*
1.样本[-1,2,9]，k=2所以取了绝对值，但是取绝对值之后
[2,-2,2,-4],k=6就出现了问题，应该是2，修改绝对之后，就变为了6，错了。
所以我不知道这个负数怎么处理。
2.看了题解，明白了，负数取余在c++中为负数，需要+模数才能和原来一样。
比如2-(-1)%3==0，即2的同余数是-1，所以-1%3=-1，需要+3才能和2表示一样是同余数。
不能取abs，在取模的情况下，只有+模数才可以。
*/
int main()
{
    int a = -1;
    cout << a % 5; //-1
    return 0;
}
