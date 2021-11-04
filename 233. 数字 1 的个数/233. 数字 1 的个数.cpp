#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-13
class Solution {
public:
    int countDigitOne(int n) {
        if(n<=0) return 0;//需要加上这个判断，可能会有负值出现。
        long digit=1;
        int high=n/10,low=0,res=0;//初始化这里不知道怎么写。
        while(high || n){
            int cur=n%10;
            if(cur==0)
                res+=high*digit;
            else if(cur==1)
                res+=(high*digit+low+1);
            else
                res+=(high+1)*digit;
            high/=10;
            low+=(n%10)*digit;
            digit*=10;
            n/=10;
        }
        return res;
    }
};
/*
1.对应剑指offer43题。这个评论区里给的题解好。
*/
//10-17
/*
1.今天复习发现了我写的有点冗余了，关键是cur和high的赋值，初始化的问题。
class Solution:
    def countDigitOne(self, n: int) -> int:
        digit, res = 1, 0
        high, cur, low = n // 10, n % 10, 0//一开始初始化了。
        while high != 0 or cur != 0:
            if cur == 0: res += high * digit
            elif cur == 1: res += high * digit + low + 1
            else: res += (high + 1) * digit
            low += cur * digit//low怎么更新我一直都挺恼的
            cur = high % 10//是在后面对cur进行的，就不用在n上取cur了
            high //= 10
            digit *= 10
        return res
//这是优秀评论区的代码，学习了，下次复习远距离地重写一下。
*/

//5-25
class Solution {
public:
    int countDigitOne(int n) {
        long long high=n/10,cur=n%10,low=0,ans=0,digit=1;//使用int会溢出，表示不了。
        while(high||cur){
            if(cur==0){
                ans+=high*digit;
            }else if(cur==1){
                ans+=high*digit+low+1;
            }else ans+=(high+1)*digit;

            low+=cur*digit;
            cur=high%10;
            high/=10;
            digit*=10;
        }
        return ans;
    }
};
int main(){
    Solution s;
    cout<<s.countDigitOne(1410065408);
    return 0;
}
