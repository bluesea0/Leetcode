#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月24日下午2:27:00
//class Solution {
//public:
//    int findNumberOfLIS(vector<int>& nums) {
//        //这将所有最长子序列都找到？那先求出最长的长度？然后再来一遍确认有多少个？
//        //先记录max，再去dp数组中找到所有=max的有多少个？
//        //不对，不是这样的，我就不明白了。
//    }
//};
/*
 * 1.真的挺难的，官方题解还给出了线段树的解法？那太难了，grand的解法比较清晰。
 *   有len记录长度，cnt记录直到当前的个数，真的还挺难的。
 *   https://www.cnblogs.com/grandyang/p/7603903.html
 * */
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        //cnt记录到当前的个数，len表示长度
        int m=nums.size(),res=0,mx=0;
        vector<int> cnt(m,1),len(m,1);
        for(int i=0;i<m;i++){
            for(int j=0;j<i;j++){
                if(nums[i]<=nums[j])continue;//无法形成递增子序列
                if(len[i]==len[j]+1)//说明又出现新的同长度的递增序列了
                    cnt[i]+=cnt[j];
                else if(len[i]<len[j]+1){
                    len[i]=len[j]+1;
                    cnt[i]=cnt[j];//这个也要遗传的
                }
            }
            if(mx<len[i]){//这里怎么更新？我不太记得了。。。
                mx=len[i];
                res=cnt[i];
            }else if(mx==len[i])res+=cnt[i];
        }
        return res;
    }
};//[1,2,3,1,2,3,1,2,3]这个样例绝了，答案应该是10，我那里更新需要控制<，
//在i指向第二个3，j指向第二个1的时候，len[i]=3,len[j]=1，这时不应该更新i，那样会导致len错误地变小
//这个样例真的非常有意思。
int main(){

    return 0;
}
