#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��10��28������10:46:26
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
            //if(s[i]==' ')continue;//" 3/2 "������ֱ����ô�жϰ������ģ�
            //�����ô���Ļ������������Ŀո񣬲����жϾͻ�ֱ�����3�ˡ������ʹ��ˡ�
            if((!isdigit(s[i])&&s[i]!=' ')||i==n-1){//���ǿ��ƿո��˰������˾���
                if(pre=='+')stk.push(num);
                else if(pre=='-')stk.push(-num);
                else if(pre=='*'){
                    stk.top()=stk.top()*num;
                }else if(pre=='/'){
                    stk.top()=stk.top()/num;
                }
                pre=s[i];//��¼֮ǰ���������
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
 * 1.д��ʱ����������һЩ����ģ�����˵�����жϵ���pre�����������*��ʱ�����֮ǰ��+�ţ���ôֻ�����
 *   ��push��ȥ�����֮ǰ��*�ţ��Ż���в�����������˼��
 * */
int main(){

    return 0;
}
