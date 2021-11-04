#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年7月12日下午9:09:43
class Solution {
public:
    int longestValidParentheses(string s) {
        /*
        1.dp方法.dp[i]表示以下标i结尾的最长有效字符的长度
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
 * 1.直接看是不会解的，看了题解之后才知道要用dp，而且dp的逻辑还挺复杂，我只希望你能记住一点。
 * 2.也可以用栈来解决，因为一般的这种括号匹配的都用栈。
 * 3.看了栈的解法，太反直觉了，我不行。
 * 4.在看一下空间O（1）的解法。看不懂，谢谢，我就直接dp就好了。
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
"()(()"，是不连续的，所以只能是2这样子，不能是4。
那如何去判断是否连续呢？不会了。
用dp？dp也完全不会。
*/
/*
 * 1.上面题解是错误的，因为不能求连续的，这是问题。dp解法也完全想不出来，栈的解法也牛，
 *   不用额外空间的方法也牛。
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
//                    // else cur+=i-stk.top();//"()(())"应该是6，所以改为+=
//                    //但是上述做法在"(()()"中就会重复计算得到6
//
//                    //cur+=2;如果只是单纯+2，那这样"()(()"无法应对(分隔的不连续的情况。
//                }
//                res=max(res,cur);
//            }
//        }
//        return res;
//    }
//};
/*
 * 1.因为我觉得先添加-1作为栈底，不是我常考虑的内容，而且先弹栈再和栈顶元素比较，也不是我常用的，所以
 *   想尝试能不能用别的方法来解，但是上述没写成功，还是去看看grand的解法吧。grand解法真牛！
 * 2.grand中针对)分隔的不合法的，会通过更新start来控制，()(()这样的(多的情况，用栈顶来控制。
 * 3.我尝试用dp方法来写。
 * */
class Solution {
public:
    int longestValidParentheses(string s) {
        //dp[i]表示以i为结尾的最长合法的子串的长度。
        //s[i]==(，dp[i]=0表示合法的只能以)结尾，
        //s[i]==)此时如果s[i-1]==(,dp[i]=dp[i-2]+2;
                 //s[i-1]==),s[i-dp[i-1]-1]==(,dp[i]=dp[i-1]+2+dp[i-dp[i-1]-2]
        vector<int> dp(s.size(),0);
        int res=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')continue;
            if(i>0&&s[i-1]=='(')
                dp[i]=i>=2?(dp[i-2]+2):2;
            else if(i>0&&s[i-1]==')'){
                if(i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='('){
                    dp[i]=dp[i-1]+2;//这里还要去判断？
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
 * 1.天哪，我这个dp的写法，和我之前写的简直一摸一样。。。。
 * 2.官解中善用?:判断符，看起来整齐不少，而且可以从i==1开始遍历，i==0的位置，如果是(本身就可以使0，如果是
 *   )，那么在后面的判断中也可以用到，而且你这里从0开始遍历，都还需要判断i>0的情况。
 * 3.写一下不需要额外空间的，比较简单吧。
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
 * 1.比较简单，两次遍历。
 * */

//10-22
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int ans=0,start=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')stk.push(i);
            else{//右括号)
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
 * 1.grand的解法，通过start来控制连续有效的位置的长度。比官解好理解多了！学习！
 * */
int main(){

    return 0;
}
