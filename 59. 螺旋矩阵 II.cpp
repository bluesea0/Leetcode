#include <bits/stdc++.h>
using namespace std;
//@date: 2021-11-07  18:10
class Solution
{
public:
    //按照模拟的方法来写。
    vector<vector<int>> generateMatrix(int n)
    {
        //即右、下、左、上
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> res(n, vector<int>(n, 0));
        int total = n * n, count = 0;
        int x = 0, y = 0, d = 0;
        while (count < total)
        {
            count++;
            res[x][y] = count;
            int nx = x + dir[d][0], ny = y + dir[d][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || res[nx][ny] != 0)
            {                    //这里怎么不覆盖呢？
                                 //直接判断不为0，说明已经被初始化了。学习了！
                d = (d + 1) % 4; //更改方向
                nx = x + dir[d][0];
                ny = y + dir[d][1];
            }
            x = nx;
            y = ny;
        }
        return res;
    }
};
int main()
{

    return 0;
}
