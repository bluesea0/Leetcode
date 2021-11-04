#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月28日下午6:53:16
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int m=nums.size();
        vector<int> sums(m,0);
        for(int i=0;i<m;i++){//这个我求错了啦！
            //怎么求累加来着？
            sums[i]+=nums[i];
            if(i>0)sums[i]+=sums[i-1];
        }
        for(int i=0;i<m;i++){
            if(i==0){
                if(sums[m-1]-sums[i]==0)return i;
            }else if(i==m-1){
                if(sums[i-1]==0) return i;
            }else {
                if(sums[i-1]==sums[m-1]-sums[i]) return i;
            }
        }
        return -1;
    }
};
/*
 * 1.AC了，O(n)
 * 2.原来这个是前缀和的解法，我都没反应过来！呜呜呜啊。
 *   看了官方题解才知道，其实根本不用一个额外的前缀和数组来保存啊，先求出来所有的和，然后以一个sum统计
 *   前缀和，遍历到第i个元素时，判断sum==total-sum-nums[i]即可，真是绝了！
 * */

//2-4
/*
 * 1.再复习我还是只能想出来我的那种方法。记录左边的元素和，那么右边的就可以计算出来，就是total-sum-nums[i]
 * */
int main(){

    return 0;
}
