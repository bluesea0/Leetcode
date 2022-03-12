#include <bits/stdc++.h>
using namespace std;
//@date: 2022-02-27  20:08
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s; //样例"AB" 1

        vector<string> ans(min(numRows, int(s.size())));
        bool down = false;
        int n = 0;
        for (char c : s)
        {
            ans[n] += c;
            if (n == 0 || n == numRows - 1)
                down = !down;
            n += down ? 1 : -1;
        }
        string res = "";
        for (auto str : ans)
            res += str;
        return res;
    }
};
/*
1.真的蛮难的，我自己都想不出来，规律是总结不出来的，第一种也没想到把它看成是矩阵。
*/
int main()
{

    return 0;
}
