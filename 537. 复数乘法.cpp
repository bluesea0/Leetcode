#include <bits/stdc++.h>
using namespace std;
//@date: 2022-02-25  22:17
class Solution
{
public:
    string complexNumberMultiply(string num1, string num2)
    {
        int m = num1.size(), n = num2.size();
        int n1 = num1.find("+");
        int n2 = num2.find("+");
        int a = stoi(num1.substr(0, n1));
        int b = stoi(num1.substr(n1 + 1, m - n1 - 2)); //如果有负号能直接转换吗？-5能直接转换？
        int c = stoi(num2.substr(0, n2));
        int d = stoi(num2.substr(n2 + 1, n - n2 - 2));

        int p = a * c - b * d;
        int q = a * d + b * c;
        string s = to_string(p) + "+" + to_string(q) + "i";
        return s;
    }
};
/*
1.好久没写代码，只是处理字符串而已。明天看看题解。
*/
int main()
{

    return 0;
}
