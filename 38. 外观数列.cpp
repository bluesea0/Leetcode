#include <bits/stdc++.h>
using namespace std;
//@date: 2022-03-01  22:13
class Solution
{
public:
    string countAndSay(int n)
    { // 通过递归来实现
        if (n == 1)
            return "1";
        string ans = "1";
        while (n != 1)
        {
            string r;
            int ct = 1, i = 0;
            for (i = 0; i + 1 < ans.size(); i++)
            {
                if (ans[i] == ans[i + 1])
                    ct++;
                else
                {
                    r += to_string(ct);
                    r += ans[i];
                    ct = 1;
                }
            }
            r += to_string(ct);
            r += ans[i];
            ans = r;
            n--;
        }
        return ans;
    }
};
/*
1.不算怎么难，主要是就是遍历处理。
*/
int main()
{

    return 0;
}
