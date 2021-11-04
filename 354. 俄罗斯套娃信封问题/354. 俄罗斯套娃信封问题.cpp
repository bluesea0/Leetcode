#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年3月4日下午9:50:42
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int m=envelopes.size();
        vector<int> dp(m,1);
        cout<<m;
        sort(envelopes.begin(),envelopes.end(),[](const auto& a,const auto& b){
        	return a[0]<b[0];//天哪，真的是我的这个sort函数写的不对啊，不能有=号的？
        	//终于发现了bug所在！原来cmp函数不能有=号的啊！
        });
        int ans=1;
        for(int i=1;i<m;i++){
            for(int j=0;j<i;j++){
                if(envelopes[i][0]>envelopes[j][0]&&envelopes[i][1]>envelopes[j][1])
                    dp[i]=max(dp[i],dp[j]+1);
            }
            if(dp[i]>ans)ans=dp[i];
        }
        return ans;//我是真的看不出来我哪里写错了，明天再复习一下子。
    }
};
/*
 * 1.上面修改了cmp函数之后的返回将<=变为<，学到了一个知识点啊。
 * 2.时间是O(n^2)，题解中的排序是将0维升序，1维降序。这样只需求一维的最长递增子序列了。
 * 3.而且求最长递增子序列也可以用二分的方法来写，f[j]表示最长递增子序列长度为j时的最小值
 * */
class Solution2 {//按照官解的写法
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int m=envelopes.size();
        vector<int> dp(m,1);
        sort(envelopes.begin(),envelopes.end(),
        [](const vector<int>& a,const vector<int>& b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);});
        int ans=1;
        for(int i=1;i<m;i++){
            for(int j=0;j<i;j++){
                if(envelopes[j][1]<envelopes[i][1])
                    dp[i]=max(dp[i],dp[j]+1);
            }
            if(dp[i]>ans)ans=dp[i];
        }
        return ans;//我是真的看不出来我哪里写错了，明天再复习一下子。
    }
};

//利用贪心+二分的解法，这个也太快了吧！！！
class Solution3 {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> d;
        sort(envelopes.begin(),envelopes.end(),
        [](const vector<int>& a,const vector<int>& b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
        });
        d.push_back(envelopes[0][1]);
        for(int i=1;i<envelopes.size();i++){
            if(envelopes[i][1]>d.back())d.push_back(envelopes[i][1]);
            else{
                int j=lower_bound(d.begin(),d.end(),envelopes[i][1])-d.begin();
                d[j]=envelopes[i][1];
            }
        }
        return d.size();
    }
};
/*
 * 1.上面只用dp的话运行时长是1000+ms，但是这个就40ms，绝了绝了啊！！！
 * */
int main(){
	Solution s;
	vector<vector<int>> a={{15,8},{2,20},{2,14},{4,17},{8,19},{8,9},{5,7},{11,19},{8,11},{13,11},{2,13},{11,19},{8,11},{13,11},{2,13},{11,19},{16,1},{18,13},{14,17},{18,19}};
	cout<<s.maxEnvelopes(a);
    return 0;
}
