#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月4日下午2:03:55
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//        //思路：先遍历一下计算0的个数，因为要尽量少操作，所以要确定每个元素最终的位置
//        //咦，但是好想知道总的0的个数，也计算不出来最终的位置啊。
//        //双指针怎么解决？首尾指针肯定是不行的啊，指向的位置也不能直接swap
//        //easy的题目我做不出来，我真难受
//    }
//};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //一个指针指向0的位置，一个指针指向待交换非0的位置
        int i=0,j=0;
        while(i<nums.size()&&j<nums.size()){
            while(j<nums.size()&&nums[j]!=0)j++;
            while(i<nums.size()&&nums[i]==0)i++;
            if(i>=nums.size()||j>=nums.size())break;
            if(i>j)
                swap(nums[i],nums[j]);
            else i++;
        }
    }
};
/*
 * 1.一下子就AC了，太令人开心了吧。
 * 复杂度O(n)最坏情况下要遍历整个数组
	样例：全0、全非0、110（0已在后面，无需移动）
	2.看了下题解和grand，真让人伤心，人家都是这么写的，left指针指向已处理好的序列尾部，right指向待处理头部
	绝了。
	class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                swap(nums[i], nums[j++]);
            }
        }
    }
};
 * */

//9-27复习
/*
 * 1.left指向已处理好的元素的末尾，指向的是非0的元素，right一旦指向非0的，那么就和left交换
 *  这样既可以保证，非0值会被交换到首部了。
 * */
int main(){

    return 0;
}
