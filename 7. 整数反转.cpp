#include <bits/stdc++.h>
using namespace std;
//@date: 2021-11-07  18:24
class Solution
{
public:
    int reverse(int x)
    {
        //a%b，取模的正负是取决于a的，只要a为负值，那么结果就为负，与b的正负无关
        int res = 0;
        while (x != 0)
        {
            if (res < INT_MIN / 10 || res > INT_MAX / 10)
                return 0; //发生溢出
            int d = x % 10;
            x /= 10;
            res = res * 10 + d;
        }
        return res;
    }
};
/*
1.官解的推导简直牛逼死了，我学习了！
*/
int main()
{

    return 0;
}
