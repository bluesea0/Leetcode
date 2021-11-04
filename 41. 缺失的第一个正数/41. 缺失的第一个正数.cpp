#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年3月20日下午3:08:49
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int& num:nums)
            if(num<=0)num=n+1;
        for(int i=0;i<n;i++){
            if(abs(nums[i])<=n){
                nums[abs(nums[i])-1]=-abs(nums[abs(nums[i])-1]);//将每个数对应的下标的数转换为负数
            }
        }
        for(int i=0;i<n;i++)
            if(nums[i]>0)
                return i+1;
        return n+1;
    }
};
/*
 * 1.上面的AC了，利用哈希的思想，题目当中提到：使用常数级别额外空间，那么就要想到哈希的思想！
 * */

//5-20
/*
 * 1.我认为还是第二种解法比较好。置换到原来的位置上。两种解法的知识点是原地哈希，利用数组下标和元素建立哈希表。
 * 2.
 * */
class Solution {//但是实际上这个解法好费时，应该是因为有swap。
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            while(nums[i]>0&&nums[i]<nums.size()&&nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);//可以直接这么写吗？
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1)
                return i+1;
        }
        return nums.size()+1;
    }
};

//6-8
/*
 * 1.想用swap猛一看，不在数组长度范围内的数，似乎没办法交换了？但是实际上还是换汤不换药，那就只交换
 *   在范围内的，剩余的再次遍历就ok了。
 * 2.类似的题目都有变负数的解法。
 * */
int main(){
	Solution s;
	vector<int> nums={3,4,1,1};
	cout<<s.firstMissingPositive(nums);
    return 0;
}
