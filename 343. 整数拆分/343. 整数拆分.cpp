#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年5月22日下午12:16:05
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n+1,0);
        dp[1]=1,dp[2]=1;
        for(int i=3;i<=n;i++){
            for(int j=1;j<i;j++){
               // dp[i]=max(j*dp[i-j],dp[i]);思路错了，这样就默认i-j部分继续拆分了
                //实际上可以不继续拆分，就拆分为2段。
            	dp[i]=max(max(j*dp[i-j],j*(i-j)),dp[i]);
            }
            cout<<i<<" "<<dp[i]<<endl;
        }
        return dp[n];
    }
};
//AC了，自己想错了，正确思路：
/*
 * 1.我一开始只的写法是将它至少拆分为了3段，没有考虑拆为两段的情况，
 * 当n≥2 时，可以拆分成至少两个正整数的和。
 * 令k是拆分出的第一个正整数，则剩下的部分是 n-k，n-k可以不继续拆分，或者继续拆分成至少两个正整数的和。
   后面两种选择对应了两项。
   2.下面的方法是针对数学的：>=5的要拆分为最多的3，余数为1说明有
 * */
//官方写的：
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        int quotient = n / 3;
        int remainder = n % 3;
        if (remainder == 0) {
            return (int)pow(3, quotient);
        } else if (remainder == 1) {//余数为1说明有一个4的分解。如10
            return (int)pow(3, quotient - 1) * 4;
        } else {//余数为2说明有一个2的分解。如11
            return (int)pow(3, quotient) * 2;
        }
    }
};
int main(){
	Solution s;
	s.cuttingRope(10);
    return 0;
}
