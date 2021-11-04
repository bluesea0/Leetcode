#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月5日下午3:06:09
//class Solution {
//public:
//    int equalSubstring(string s, string t, int maxCost) {
//        //转换为求最长连续子序列问题
//        vector<int> cost(s.size(),0);
//        for(int i=0;i<s.size();i++){
//            cost[i]=abs(s[i]-t[i]);
//        }
//        int left=0,right=0,cur=0,ans=0;
//        while(right<cost.size()){
//            cur+=cost[right];
//            while(cur>=maxCost){//移动左指针，这样单纯地循环是不对的，因为并不=k，有可能有更大的
//            //区间满足>k，但是并不=k
//                if(cur==maxCost)//不对，这么写仍是不对，对于样例2来说也就是<=k
//                    ans=max(ans,right-left+1);
//                cur-=cost[left];
//                left++;
//                if(cur<maxCost)
//                    ans=max(ans,right-left+1);
//            }//天哪，忽然意识到我写这个循环会陷入死循环啊，针对示例3，我人傻了
//            //第一个0就会一直出不去
//            //所以关键的问题就是怎么移动left指针？
//            right++;
//        }
//        return ans;
//    }
//};
/*
 * 1.上面一直在纠结怎么在移动left的时候更新，但是实际上根本就没有那个啥啊，烦死我了。
 * 2.更新right的时候也可以自然更新！
 * */
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        //转换为求最长连续子序列问题
        vector<int> cost(s.size(),0);
        for(int i=0;i<s.size();i++){
            cost[i]=abs(s[i]-t[i]);
        }
        int left=0,right=0,cur=0,ans=0;
        while(right<cost.size()){
            cur+=cost[right];
            while(cur>maxCost){
                cur-=cost[left];
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};
int main(){

    return 0;
}
