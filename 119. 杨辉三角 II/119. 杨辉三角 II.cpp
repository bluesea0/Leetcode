#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月13日下午8:59:38
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //O(k)的空间复杂度？但是每一行不都得由前一行计算而来吗？那就不可能直接计算第k行
        //的啊，只直接申请一个长度为k的数组？我觉得不行吧？
        //我知道了，只申请一个长度为k的，但是在计算前面的时候后面不用就好了！
        //时间复杂度肯定是不会减小的，就是原地更新了
        vector<int> nums(rowIndex+1,1);
        for(int k=2;k<=rowIndex;k++){
            for(int j=k-1;j>=1;j--){
                nums[j]=nums[j]+nums[j-1];
            }
        }
        return nums;
    }
};
/*
 * 1.AC了，比较开心，正序更新出现覆盖的现像，那就倒序更新。
 * 2.这个我受启发的点就是：因为不能有额外的空间，那就原地更新！看了题解发现其实是滚动数组的思想，
 *   非常开心！！
 * */
int main(){

    return 0;
}
