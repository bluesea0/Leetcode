#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月19日下午2:30:13
class Solution {
public:
    int bulbSwitch(int n) {
        //这个题目分析出来就是求n内的完全平方数的个数，具体代码我就不写了？
        //算了，来都来了，就让它AC吧。
        //也就是本位的因数的个数，如果个数是奇数的话，那么就是亮的，如果是偶数的话那么就是灭的
        //1是完全平放数，只有完全平放数才会有两个相同的因数
        if(n==0)return 0;
        int res=0,k=1;
        while(k*k<=n){
            k++;
            res++;
        }
        return res;
    }
};
int main(){

    return 0;
}
