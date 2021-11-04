#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年6月8日上午1:12:51
//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        int n=nums.size();
//        for(int i=0;i<n;i++){
//        	int index=nums[i];
//            while(nums[i]<n&&nums[index]!=i){//这里是错的，不是和i比较啊，怎么和i比较上了呢？
//                swap(nums[i],nums[index]);
//            }
//        }
//        for(auto& n:nums)
//        	cout<<n<<" ";
//        for(int i=0;i<n;i++){
//            if(nums[i]!=i)
//                return i;
//        }
//        return n;
//    }
//};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]<n&&nums[nums[i]]!=nums[i]){//这里比较时遇到了问题啊。。。
                swap(nums[i],nums[nums[i]]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i)
                return i;
        }
        return n;
    }
};
/*
 * 1.看了官方题解，感觉牛死了，原来可以用位运算啊，其实也有一种哈希的思想在。牛逼。
 * */
int main(){
	Solution s;
	vector<int> nums={9,6,4,2,3,5,7,0,1};
	cout<<s.missingNumber(nums);
    return 0;
}
