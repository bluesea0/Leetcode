#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
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
class Solution {
public:
    int lastRemaining(int n, int m) {
        //约瑟夫环问题，
        int idx=0;
        for(int i=2;i<=n;i++){
            idx=(idx+m)%i;
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
int main(){

    return 0;
}
