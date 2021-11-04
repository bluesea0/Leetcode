#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年9月19日上午1:27:34
class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size()<num2.size())swap(num1,num2);
        int m=num1.size(),n=num2.size();
        int pre=0;
        string ans;
        int i,j;
        for(i=m-1,j=n-1;i>=0&&j>=0;i--,j--){
            int t=(num1[i]-'0')+(num2[j]-'0')+pre;
            pre=t/10;
            t%=10;
            ans+=(t+'0');
        }
        while(i>=0){
            int t=(num1[i]-'0')+pre;
            pre=t/10;
            t%=10;
            ans+=(t+'0');
            i--;
        }
        if(pre){ans+="1";};//1+9=10;没有这个的话会结果为0
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
/*
 * 1.写的好麻烦。官方题解写的很好。
 * */
int main(){

    return 0;
}
