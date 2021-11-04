#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��7��12������9:09:43
class Solution {
public:
    int longestValidParentheses(string s) {
        /*
        1.dp����.dp[i]��ʾ���±�i��β�����Ч�ַ��ĳ���
        ( 0
        ) ( dp[i]=dp[i-2]+2;
        ) )
        */
        int m=s.size(),ans=0;
        vector<int> dp(m,0);
        for(int i=1;i<m;i++){
            if(s[i]=='(')continue;
            if(s[i-1]=='('){
                dp[i]=2;
                if(i-2>=0)dp[i]+=dp[i-2];
            }else{
                if(dp[i-1]==0)continue;
                if(i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='('){
                    dp[i]=dp[i-1]+2;
                    if(i-dp[i-1]-2>=0)
                        dp[i]+=dp[i-dp[i-1]-2];
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
/*
 * 1.ֱ�ӿ��ǲ����ģ��������֮���֪��Ҫ��dp������dp���߼���ͦ���ӣ���ֻϣ�����ܼ�סһ�㡣
 * 2.Ҳ������ջ���������Ϊһ�����������ƥ��Ķ���ջ��
 * 3.����ջ�Ľⷨ��̫��ֱ���ˣ��Ҳ��С�
 * 4.�ڿ�һ�¿ռ�O��1���Ľⷨ����������лл���Ҿ�ֱ��dp�ͺ��ˡ�
 * */

//10-20
//class Solution {
//public:
//    int longestValidParentheses(string s) {
//        stack<char> stk;
//        int res=0;
//        for(int i=0;i<s.size();i++){
//            if(s[i]=='(')
//                stk.push(s[i]);
//            else{
//                if(!stk.empty()&&stk.top()=='('){
//                    res+=2;
//                    stk.pop();
//                }
//            }
//        }
//        return res;
//    }
//};
/*
"()(()"���ǲ������ģ�����ֻ����2�����ӣ�������4��
�����ȥ�ж��Ƿ������أ������ˡ�
��dp��dpҲ��ȫ���ᡣ
*/
/*
 * 1.��������Ǵ���ģ���Ϊ�����������ģ��������⡣dp�ⷨҲ��ȫ�벻������ջ�ĽⷨҲţ��
 *   ���ö���ռ�ķ���Ҳţ��
 * */

//10-21
//class Solution {
//public:
//    int longestValidParentheses(string s) {
//        stack<int> stk;
//        //stk.push(-1);
//        int res=0,cur=0;
//        for(int i=0;i<s.size();i++){
//            if(s[i]=='(')
//                stk.push(i);
//            else{
//                //stk.pop();
//                if(stk.empty())
//                    cur=0;
//                else{
//                    stk.pop();
//                    // if(stk.empty())
//                    //     cur+=2;
//                    // else cur+=i-stk.top();//"()(())"Ӧ����6�����Ը�Ϊ+=
//                    //��������������"(()()"�оͻ��ظ�����õ�6
//
//                    //cur+=2;���ֻ�ǵ���+2��������"()(()"�޷�Ӧ��(�ָ��Ĳ������������
//                }
//                res=max(res,cur);
//            }
//        }
//        return res;
//    }
//};
/*
 * 1.��Ϊ�Ҿ��������-1��Ϊջ�ף������ҳ����ǵ����ݣ������ȵ�ջ�ٺ�ջ��Ԫ�رȽϣ�Ҳ�����ҳ��õģ�����
 *   �볢���ܲ����ñ�ķ������⣬��������ûд�ɹ�������ȥ����grand�Ľⷨ�ɡ�grand�ⷨ��ţ��
 * 2.grand�����)�ָ��Ĳ��Ϸ��ģ���ͨ������start�����ƣ�()(()������(����������ջ�������ơ�
 * 3.�ҳ�����dp������д��
 * */
class Solution {
public:
    int longestValidParentheses(string s) {
        //dp[i]��ʾ��iΪ��β����Ϸ����Ӵ��ĳ��ȡ�
        //s[i]==(��dp[i]=0��ʾ�Ϸ���ֻ����)��β��
        //s[i]==)��ʱ���s[i-1]==(,dp[i]=dp[i-2]+2;
                 //s[i-1]==),s[i-dp[i-1]-1]==(,dp[i]=dp[i-1]+2+dp[i-dp[i-1]-2]
        vector<int> dp(s.size(),0);
        int res=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')continue;
            if(i>0&&s[i-1]=='(')
                dp[i]=i>=2?(dp[i-2]+2):2;
            else if(i>0&&s[i-1]==')'){
                if(i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='('){
                    dp[i]=dp[i-1]+2;//���ﻹҪȥ�жϣ�
                    if(i-dp[i-1]-2>=0)
                        dp[i]+=dp[i-dp[i-1]-2];
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};
/*
 * 1.���ģ������dp��д��������֮ǰд�ļ�ֱһ��һ����������
 * 2.�ٽ�������?:�жϷ������������벻�٣����ҿ��Դ�i==1��ʼ������i==0��λ�ã������(����Ϳ���ʹ0�������
 *   )����ô�ں�����ж���Ҳ�����õ��������������0��ʼ������������Ҫ�ж�i>0�������
 * 3.дһ�²���Ҫ����ռ�ģ��Ƚϼ򵥰ɡ�
 * */
class Solution {
public:
    int longestValidParentheses(string s) {
        int left=0,right=0,maxans=0,n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                left++;
            else right++;
            if(left==right)maxans=max(2*left,maxans);
            else if(right>left){
                left=0;
                right=0;
            }
        }
        left=0,right=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(')
                left++;
            else right++;
            if(left==right){
                maxans=max(2*left,maxans);
            }else if(left>right){
                left=0;
                right=0;
            }
        }
        return maxans;
    }
};
/*
 * 1.�Ƚϼ򵥣����α�����
 * */

//10-22
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int ans=0,start=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')stk.push(i);
            else{//������)
                if(stk.empty())start=i+1;
                else{
                    stk.pop();
                    if(stk.empty())
                        ans=max(i-start+1,ans);
                    else ans=max(ans,i-stk.top());
                }
            }
        }
        return ans;
    }
};
/*
 * 1.grand�Ľⷨ��ͨ��start������������Ч��λ�õĳ��ȡ��ȹٽ�������ˣ�ѧϰ��
 * */
int main(){

    return 0;
}
