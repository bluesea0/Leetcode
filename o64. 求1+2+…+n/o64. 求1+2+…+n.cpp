#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年6月18日上午10:04:10
class Solution {
public:
    int sumNums(int n) {
        //不好意思，不讲武德
        return n*(1+n)/2;
    }
};
/*
 * 1.之前是这么写的，我是没有理解题意，不让使用for循环，那么就对对应递归；
 *   不能使用if判断那么就用&&短路作用。
 * */
class Solution {
public:
    int sumNums(int n) {
        //return n&&(n+sumNums(n-1));
        n&&(n+=sumNums(n-1));//用&&代替if判断，当n=0时，短路。
        return n;
    }
};
int main(){

    return 0;
}
