#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年6月10日上午11:48:18
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";//需要判断一方是否为0

        int n1=num1.size(),n2=num2.size();

        vector<int> res(n1+n2,0);//保存结果
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                int t=(num1[i]-'0')*(num2[j]-'0');
                res[i+j+1]+=(t%10);//这里加之后可能存在进位，需要处理
                res[i+j]+=(res[i+j+1]/10);
                res[i+j+1]%=10;

                res[i+j]+=(t/10);//前一位应该没那么快出现进位，下一次循环会再处理
            }
        }
        int start=0;
        if(res[0]==0)start++;
        string s;
        for(int i=start;i<n1+n2;i++){
            s.push_back(res[i]+'0');
        }
        return s;
    }
};
int main(){

    return 0;
}
