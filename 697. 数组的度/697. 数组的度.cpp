#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月20日下午12:35:30
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int ct=0;
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++){
            um[nums[i]]++;
            if(um[nums[i]]>ct){
                ct=um[nums[i]];//卧槽，我理解提意理解错了！！！
            }//[1,3,2,2,3,1]，所有的数度都是一样的，但是要选择跨度最小的，那么就需要求出来所有
            //度一样的数，然后再判断。
        }
        vector<int> res;
        for(auto& [k,v]:um){
            if(v==ct)res.push_back(k);
        }
        int ans=nums.size();
        for(auto& r:res){
            int left=0,right=nums.size()-1;//这里其实只能算是双指针，而且每次遍历基本上是O(n)的复杂度吧
            while(nums[left]!=r)left++;
            while(nums[right]!=r)right--;
            ans=min(right-left+1,ans);
        }
        return ans;
    }
};
/*
 * 1.上面是我的写法，普普通通，都是O(n)，不过我的写法并不高效
 * 2.官方题解中使用了unordered_map<int, vector<int>> mp;的结构，这个我确实没注意过，value中的向量映射
 *   为三个，0表示次数，1、2表示起始终止下标，感觉还挺绝的。不过滑窗的题我可真每天看懂。
 * 3.不过评论区有很多滑窗的解法，我是学到了！明天要写一下。
 * */
int main(){

    return 0;
}
