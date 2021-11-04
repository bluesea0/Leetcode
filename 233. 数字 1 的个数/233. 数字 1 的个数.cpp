#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-13
class Solution {
public:
    int countDigitOne(int n) {
        if(n<=0) return 0;//��Ҫ��������жϣ����ܻ��и�ֵ���֡�
        long digit=1;
        int high=n/10,low=0,res=0;//��ʼ�����ﲻ֪����ôд��
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
1.��Ӧ��ָoffer43�⡣�����������������á�
*/
//10-17
/*
1.���츴ϰ��������д���е������ˣ��ؼ���cur��high�ĸ�ֵ����ʼ�������⡣
class Solution:
    def countDigitOne(self, n: int) -> int:
        digit, res = 1, 0
        high, cur, low = n // 10, n % 10, 0//һ��ʼ��ʼ���ˡ�
        while high != 0 or cur != 0:
            if cur == 0: res += high * digit
            elif cur == 1: res += high * digit + low + 1
            else: res += (high + 1) * digit
            low += cur * digit//low��ô������һֱ��ͦ�յ�
            cur = high % 10//���ں����cur���еģ��Ͳ�����n��ȡcur��
            high //= 10
            digit *= 10
        return res
//���������������Ĵ��룬ѧϰ�ˣ��´θ�ϰԶ�������дһ�¡�
*/

//5-25
class Solution {
public:
    int countDigitOne(int n) {
        long long high=n/10,cur=n%10,low=0,ans=0,digit=1;//ʹ��int���������ʾ���ˡ�
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
