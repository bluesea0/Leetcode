#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月5日下午2:47:54
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //思路：双指针，j是快指针，i是慢指针，i指向下一个可以插入的位置
        if(nums.empty())return 0;
        int i=0;
        for(int j=0;j+1<nums.size();j++){
            if(nums[j]!=nums[j+1]){//那最后的位置怎么判断啊
                i++;
                nums[i]=nums[j+1];
            }
        }
        return i+1;
    }
};
/*
 * 1.AC了，从27题题解种来的思路，不一定是swap，因为后面的数组不要了，所以就不用管后面的部分，直接赋值就可。
 *   public int removeDuplicates(int[] nums) {
    if (nums.length == 0) return 0;
    int i = 0;
    for (int j = 1; j < nums.length; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}
//天哪，官方写的比我牛逼哦。直接让j从1开始。
 * */
int main(){

    return 0;
}
