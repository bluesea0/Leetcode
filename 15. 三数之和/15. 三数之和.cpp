#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年11月27日下午12:05:57
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //思路：这个不是要求的下标，那么就直接sort然后双指针
        vector<vector<int>> ans;
        if(nums.size()==0) return ans;
        sort(nums.begin(),nums.end());
        //这里要对nums.size()进行修改
        for(int i=0;i<int(nums.size())-2;i++){//mad！我知道了，因为它是无符号整数，所以不能和负号比较!
            if(i!=0&&nums[i]==nums[i-1])continue;//去重
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if(nums[j]+nums[k]==-nums[i]){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    //去重
                    while(j<k&&nums[j]==nums[j+1])j++;
                    while(j<k&&nums[k]==nums[k-1])k--;
                    j++;k--;
                }
                else if(nums[j]+nums[k]<-nums[i])
                    j++;
                else if(nums[j]+nums[k]>-nums[i])
                    k--;
            }
        }
        return ans;//为什么会堆缓存溢出呢？针对样本[0]
    }
};
/*
 * 1.工作又没了，边界情况没判断，nums数组可能为空，并且vector是push_back，不是append。。。
 * 2.mad草，提交了三次都没通过，要死了真的。最好真的for循环条件判断的地方不要有-号出现
 * 3.[-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0]。mad终于解决了上个问题，这个样例没通过，我写的算法
 *   有问题。我吐了。这题真的搞得我太心累了。
 *   这个问题是，我不能上来就去重，那样就将结果[[-2,1,1],[0,0,0]]忽略掉了。害！
 * 4.经过上面的修改，终于AC了，我也想哭了。
 * */
int main(){
	Solution s;
	vector<int> a{-1,0,1,2,-1,-4};
	auto c=s.threeSum(a);
	cout<<c.size();
//	int a=1,b=-1,c=0;
//	if(a+b==-c)cout<<"hh";//不是-0的问题。
    return 0;
}
