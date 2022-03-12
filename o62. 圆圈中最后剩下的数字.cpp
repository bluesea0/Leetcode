#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
//2021年3月8日下午5:31:39
//class Solution {
//public:
//    int lastRemaining(int n, int m) {
//        //卧槽，真的好有意思啊这道题，但是我不会，它是简单级别，但是我应该只会模仿？
//        //我会申请n那么大的vector，然后一直循环n-1次，再判断其中哪个是0
//        //啊有点难度
//    }
//};
class Solution
{
public:
    int lastRemaining(int n, int m)
    {
        //约瑟夫环问题，
        int idx = 0;
        for (int i = 2; i <= n; i++)
        {
            idx = (idx + m) % i;
        }
        return idx;
    }
};
/*
 * 1.AC了，还是从题解中学习的，每次去除就相当于把每个数都往前移动了m位，最后只剩长度为一的index就是0，那么
 *   每次都往后移动m次并且每次总数组长度都在变化。
 * */

//6-18
/*
 * 1.反正我还不是很理解这个问题，就每次index往后移动m次，并且模上当前数组长度。
 * */

//11-7
class Solution
{
public:
    int lastRemaining(int n, int m)
    {
        if (n == 1)
            return 0;
        int d = lastRemaining(n - 1, m);
        return (d + m) % n;
    }
};
/*
1.真的蛮难理解的，如果只剩下最后一个那么肯定是0，0表示的是下标，f(n,m)表示长度为n的序列，
  每m个移除最后留下的数的下标。因为针对有n个元素，删除了第m%n个后，起始下标变为m%n，而
  从n-1个中选取时，每次都是下标从0开始计数的，所以应该+m%n进行下标的一个平移，对其操作吧。
*/
int main()
{

    return 0;
}
