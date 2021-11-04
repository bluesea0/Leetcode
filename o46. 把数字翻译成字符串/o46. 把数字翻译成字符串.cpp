#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-17
/*
1.其实我觉得这个很简单，但是还是写一下，主要是为了熟悉C++语法。
*/
class Solution {
public:
    int ans=0;
    int translateNum(int num) {
        //if(num==0)return 1;
        tr(0,to_string(num));
        return ans;
    }
    void tr(int index,string m){
        if(index==m.size()){
            ans++;return;
        }
        for(int i=0;i<2&&index+i<m.size();i++){
            //string ts=m.substr(index,i+1);//substr的第二个参数是长度，不是下标啊！
            string ts=m.substr(index,i+1);
            int temp=stoi(ts);
            cout<<temp<<endl;
            if(temp>=0 and temp<=25 and to_string(temp).size()==ts.size())
                tr(index+i+1,m);
        }
    }
};
/*
1.为什么？为什么这里12258输出的是个0？绝了！我要手动跑一边才行，虽然我写的很辣鸡，虽然在网上
  都没有搜到和我有相同写法的，但是我还是要继续看。。。等到晚上回去再跑一下。。。气死我了。
*/
//10-21
/*
1.主要是对之前错误的代码进行了修改，还没有看官方的解法。明天复习再看。
*/
//10-22
/*
1.有点理解了官方的题解的dp算法，时间复杂度也理解了，然后那个大佬的另一个解法还没看。
*/

//5-26
class Solution {
public:
    int translateNum(int num) {
        //这个方法我首先还是想到了回溯法来确定，实际上可以用dp来做
        //if(num<10)return num;//输入有0，没有考虑到。出错了。
        //我去，你上边这是什么判断方法？？？那输入样例有9，就输出9了？？
        //if(num==0)return 0;//卧槽你没看人家给的条件啊？？？0翻译成a好吗？？？怎么就返回0了？
        if(num==0)return 1;
        vector<int> nums;
        while(num){
            nums.push_back(num%10);
            //cout<<num%10<<endl;
            //num>>=1;//我的天哪，我还自作聪明用了右移一位做除法，但是它实际上是/2啊，不是/10
            //应该是/10啊大哥，我的天实在是无语了。。。
            num/=10;
        }
        reverse(nums.begin(),nums.end());
        vector<int> dp(nums.size()+1,0);
        dp[0]=1,dp[1]=1;
        for(int i=2;i<=nums.size();i++){
            dp[i]=dp[i-1];//天哪这个转移方程可怎么写啊，怎么计算呢？
            if(nums[i-2]&&(nums[i-2]*10+nums[i-1]<=25))//还有 506这样的用例啊！！
                dp[i]+=dp[i-2];
        }
        return dp.back();
    }
};
/*
 * 1.我终于AC了，但是有许多血的教训：
 * 　1.首先状态转移方程分不清要不要+1，最重要的还是要理清含义dp[i]表示前i为能组合的个数，那么不能重复+1
 *     不然结果就很大了。dp[i]=dp[i-1]+dp[i-2]，如果dp[i-2]<=25的话。
 *   2.判断时要记得前导0，506这样的例子，中间的0不能分开。
 *   3.在循环获取每位的时候，不是右移一位啊，右移>>是对二进制的位操作，右移表示的是/2，我循环获取每个
 *     个位每次循环要/10，记住>>是/2，左移<<是*2，获取个位是/10.
 *   4.按照循环获取数的个位时，获取的是倒序的，需要reverse一下。
 *   5.注意要关注边界用例，要特殊处理，处理的情况要根据题意。所以来总结一下流程：
 *
 * 2.写完代码之后一定要先处理边界用例，边界用例具体返回结果根据题意来返回，不要想当然地返回。
 * */
int main(){
    Solution s;
    cout<<s.translateNum(0);

//    string s="abcd";
//    cout<<s.substr(0,2);//ab
    return 0;
}
