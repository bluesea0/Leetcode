#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-13
/*
1.对应剑指offer中的44题，这个评论区给出的答案比较好。
https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/solution/mian-shi-ti-44-shu-zi-xu-lie-zhong-mou-yi-wei-de-6/

*/
class Solution {
public:
    int findNthDigit(int n) {
        long int start=1,len=1;//溢出的时候需要把它们全都改为long int。
        long int ct=9;//注意ct不是一个累积量，而是这个len下有多少位！
        while(n>ct){
            n-=ct;
            start*=10;
            len++;
            ct=9*start*len;
        }
        string num=to_string(start+(n-1)/len);//卧槽，这个下标要把我搞死啊!
        //领略到了n-1的威力啊！绝了绝了。
        return num[(n-1)%len]-'0';//这个该怎么写呢？我忽然迷惑了。
    }
};
//10-17
/*
1.关键的点是：ct如何更新、最后得出来应该如何转换为第n位的数字。
*/
class Solution {
public:
    int findNthDigit(int n) {
        //int nums=10,digit=1,start=0;
        long long nums=10,digit=1,start=0;
        while(n>=nums){
            n-=nums;
            //start=10*digit;//这里计算错了啊，应该是*10来的
            //start*=10;
            start=(start==0?10:start*10);
            digit++;
            nums=9*start*digit;
            //nums=9*start;//这个地方也理解错了，不是数的数量，而是数位的数量啊！！！
            //天哪！我是怎么回事啊，如果面试这样的话你不就？？？无语子。什么思路啊。
        }
        //int s=start+n/digit;
        long long s=start+n/digit;
        return to_string(s)[n%digit]-'0';
    }
};//1000000000溢出了，所以改为long long吧。
/*
 * 1.Yes!我也AC了，我好开心，这个看了有50分钟才自己想出来。
 * 2.nums记录的是数位的字符总数，而不是当前区间内有多少个数，还要乘上digit才行，digit用于后面的计算所属
 *   位置的；start是每轮*10，因为题解中给的是从1开始计数，然后后来计算的时候要n-1，但是我从0开始就多
 *   减掉一个，而且while循环判断时有=号，所以存在不同，我就不用在结果就算是-1了。
 *   但是start的更新要注意，因为我初始化为了0，所以内部要判断，不能简单地=*10了，会死循环了。
 * */
int main(){
    Solution2 s;
    cout<<s.findNthDigit(1000);
    return 0;
}
