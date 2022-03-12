#include <bits/stdc++.h>
using namespace std;
//@date: 2022-03-03  22:15
class Solution
{
public:
    int addDigits(int num)
    {
        while (num >= 10)
        {
            num = func(num);
        }
        return num;
    }
    int func(int num)
    {
        int sum = 0;
        while (num)
        {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
};
/*
1.看到题目要求说，可以不使用循环或者递归？那我不行，我只会写循环的。

*/
int main()
{

    return 0;
}
