#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月11日下午4:32:48
class Solution {
public:
    int mySqrt(int x) {
        //利用e值近似
        if(x==0)return 0;
        int a=exp(0.5*log(x));
        return (long long)(a+1)*(a+1)<=x?a+1:a;
    }
};
class Solution2 {
public:
    int mySqrt(int x) {
        //二分法
        if(x==0) return 0;
        int l=0,r=x;
        while(l<=r){//这里应该有=的
            int mid=l+(r-l)/2;
            if((long long)mid*mid<=x)
                l=mid+1;
            else r=mid-1;
        }
        return l-1;
    }
};
/*
 * 1.第一个解法是袖珍计算器算法，看官解给的。O(1)
 * 2.第二种是二分法，这里的l和r以及循环的条件和return结果都是需要注意的。我写的没什么问题，太棒了，已经学会
 *   二分的融会贯通了！
 * */

//2021-6-7
class Solution {
public:
    int mySqrt(int x) {
        //二分法
        if(x==0) return 0;
        int l=1,r=x;
        while(l<=r){//这里应该有=的
            int mid=l+(r-l)/2;
            if((long long)mid*mid<=x)
                l=mid+1;
            else r=mid-1;
        }
        return l-1;
    }
};
/*
 * 1.今天又复习了一下，发现我写二分还是习惯用<=，【】闭区间，更简洁！
 * */
int main(){

    return 0;
}
