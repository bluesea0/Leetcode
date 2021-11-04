#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月5日下午4:22:38
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //思路：双指针，先排序，最外层循环控制第一个数，
        //双指针控制内层的两个数，
        //int ans=1e7;//
        int ans=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());//我怎么忘了排序了？
        for(int i=0;i+2<nums.size();i++){
            int t=target-nums[i];
            int j=i+1,k=nums.size()-1;
            while(j<k){
                //如果下面t是个负数，那么右半边就会溢出，那我怎么初始化呢？
                if(abs(nums[j]+nums[k]-t)<abs(ans-target))ans=nums[j]+nums[k]+nums[i];
                //天哪这个更新的地方怎么这么难呢！！！
                if(nums[j]+nums[k]<t){
                    j++;
                }else if(nums[j]+nums[k]>t){
                    k--;
                }else return target;
            }
        }
        return ans;
    }
};//[0,0,0] 1，这个样本确实是我错了看起来，因为它其实并不能进行，但我这个t就把它给算进去了？
//我地妈呀，我理解错了，其实不应该放进去差值，我怎么把差值放进去了？
//[0,1,2] 3，相等的时候不应该return 0啊，应该return这个目标
//[1,1,1,1] 0 出现了溢出，因为我把ans初始化为了INT_MAX，看官方题解是1e7
//[1,1,1,0] 100
/*
 * 1.提交了6次才通过，气冷抖啊，回家等消息吧。
 * 2.需要注意的问题其实挺多的，更新时ans存储的不是差值，而是数组的值，ans判断的时候-的是target，不是t
 *   相等时返回的是target，不是t，ans初始化，因为说明了nums.length>=3所以可以直接那么初始化，
 *   其实我是为了方便才用的t没想到造成了这么多的误会。所以以后还是起别的名，比如说temp，这样让我更加明白
 *   它的意思了，那我肯定不会返回temp的
 * */
int main(){

    return 0;
}
