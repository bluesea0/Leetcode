#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��10��13������7:31:42
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++)
                dp[i]+=(dp[j-1]*dp[i-j]);
        }
        return dp.back();
    }
};
/*
 * 1.�������������������⡣����Ҫ�˷��ģ���ϰ���
 * */
int main(){

    return 0;
}
