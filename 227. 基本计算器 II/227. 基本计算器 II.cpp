#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年10月28日下午10:46:26
class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        char pre='+';
        int num=0,n=s.size();
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                num=num*10+(s[i]-'0');
            }
            //if(s[i]==' ')continue;//" 3/2 "，不能直接这么判断啊，天哪，
            //如果这么做的话，遍历到最后的空格，不加判断就会直接输出3了。。。就错了。
            if((!isdigit(s[i])&&s[i]!=' ')||i==n-1){//忘记控制空格了啊，绝了绝了
                if(pre=='+')stk.push(num);
                else if(pre=='-')stk.push(-num);
                else if(pre=='*'){
                    stk.top()=stk.top()*num;
                }else if(pre=='/'){
                    stk.top()=stk.top()/num;
                }
                pre=s[i];//记录之前的运算符号
                num=0;
            }
        }
        int sum=0;
        while(!stk.empty()){
            sum+=stk.top();
            stk.pop();
        }
        return sum;
    }
};
/*
 * 1.写的时候还是遇到了一些问题的，比如说符号判断的是pre，比如遍历到*号时，如果之前是+号，那么只会把数
 *   先push进去，如果之前是*号，才会进行操作！很有意思！
 * */
int main(){

    return 0;
}
