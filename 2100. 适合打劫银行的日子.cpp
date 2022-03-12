#include <bits/stdc++.h>
using namespace std;
//@date: 2022-03-06  22:16
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        stack<int> stk;
        int n=security.size();
        vector<int> ans,left(n,0),right(n,0);
        //考虑一些特殊情况
        if(time==0){//应该构造一个[0,n-1]的数组？
            for(int i=0;i<n;i++)
                left[i]=i;
            return left;
        }
        // if(time==1){// 这里写的是有问题的，样例 [1,2,3,4] 1
        //     for(int i=1;i<n-1;i++)
        //         left[i]=1;
        //     return left;
        // }
        if((n+1)/2<=time) return ans;
        for(int i=0;i<n;i++){
            if(!stk.empty()&&security[stk.top()]<security[i]){//非严格递减栈
                while(!stk.empty())stk.pop();
            }
            if(stk.size()>=time&&stk.top()==i-1){//这样判断是不对的，天哪如何确保连续？
                //我认为如果要确保连续，那必须清空而不是一个个比较然后弹出，不必留下。
                left[i]=1;
            }
            stk.push(i);
        }
        while(!stk.empty())stk.pop();
        for(int i=n-1;i>=0;i--){
            if(!stk.empty()&&security[stk.top()]<security[i]){//
                while(!stk.empty())stk.pop();
            }
            if(stk.size()>=time&&stk.top()==i+1)
                right[i]=1;
            stk.push(i);
        }
        for(int i=0;i<n;i++){
            if(left[i]&&right[i])
                ans.push_back(i);
        }
        return ans;
    }
};
/*
1.终于提交了，错了3次，我的肝疼。我去，我是用单调栈做的，但是一看题解是用dp，我裂开了。
  明天看看用dp怎么解吧。。。。
*/

//3-12周六
class Solution2 {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        vector<int> left(n,0),right(n,0),ans;
        for(int i=1;i<n;i++){
            if(security[i]<=security[i-1])
                left[i]=left[i-1]+1;
            if(security[n-i-1]<=security[n-i])
                right[n-i-1]=right[n-i]+1;
        }
        for (auto a:left)
            cout << a << " ";
        for (auto a:right)
            cout << a << " ";
        for (int i = 0; i < n; i++)
            {
                if (left[i] >= time && right[i] >= time)
                    ans.push_back(i);
            }
        return ans;
    }
};
/*
1.大傻子，数组更新错了天哪，所以提交有问题，绝绝子了属于是。
*/
int main()
{
    Solution2 s;
    vector<int> a = {5, 3, 3, 3, 5, 6, 2};
    s.goodDaysToRobBank(a, 2);
    return 0;
}
