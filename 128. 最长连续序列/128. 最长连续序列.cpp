#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年10月23日下午12:54:29
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto& n:nums)
            mp[n]=1;
        int ans=0;
        for(auto& n: nums){
            if(mp.count(n-1)==0){//表示以n为起点查找
                int t=1;
                while(mp.count(n+t))t++;
                ans=max(ans,t);
            }
        }
        return ans;
    }
};
/*
 * 1.当然这道题是我自己没想出来的，只是看了官解说用哈希，并且只对没有小于等于它的数才遍历，所以是O(n)复杂度
 *
 * */
int main(){

    return 0;
}
