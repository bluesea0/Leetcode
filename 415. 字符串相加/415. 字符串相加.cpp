#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��9��19������1:27:34
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
        if(pre){ans+="1";};//1+9=10;û������Ļ�����Ϊ0
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
/*
 * 1.д�ĺ��鷳���ٷ����д�ĺܺá�
 * */
int main(){

    return 0;
}
