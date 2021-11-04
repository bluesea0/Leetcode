#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年10月28日下午5:29:24
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //最直接的思路：使用map记录数字出现的次数，之后遍历map将>n/2的数字返回
        //摩尔投票法？是用来解决这个问题的吗？
        //摩尔投票法是什么来着？我忘了，只记得代码了。。。
        int ans,ct=0;
        for(auto n:nums){
            if(ct==0){
                ans=n;
                ct++;
            }else if(n==ans)ct++;
            else ct--;
        }
        return ans;
    }
};
/*
 * 1.https://leetcode-cn.com/problems/majority-element/solution/duo-shu-yuan-su-by-leetcode-solution/
 *   这里说了，正确性较难整明，那我就知道它的算法的过程就好了。
 * */
int main(){

    return 0;
}
