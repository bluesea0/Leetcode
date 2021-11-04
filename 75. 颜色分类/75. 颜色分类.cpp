#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月16日下午4:10:48
//class Solution {
//public:
//    void sortColors(vector<int>& nums) {
//        //看到这道题，我的感觉就是，不好意思不能。
//        //双指针？行不通，还不能用库函数，常数空间一趟扫描？那更是天方夜谭吧。。。太难了。
//    }
//};

//12-17
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //p0和p1分别标记0和1下一个要放的位置位置。
        int p0=0,p1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                swap(nums[i],nums[p1]);
                p1++;
            }else if(nums[i]==0){
                swap(nums[p0],nums[i]);//这个应该放到判断的前面？
                if(p0<p1)//如果不交换的话，后来的p0可能就会占掉1
                    swap(nums[i],nums[p1]);//啊我这么写有大问题啊，[1,0]这样的，就会被交换两次，因为p0一直指向的是第0位，我哭了。
                    //天哪，不是swap p0和p1啊。。
                    //因为swap p0和i的话, p0可能指向的就是1，就有可能将1换到后面i的位置，所以
                    //将i和p1的位置又换了，将i位置上的1换到p1的位置
                    //那有没有一种可能p1本身指向的也是1？这样被换到后面，可不就坏了？
                    //应该不会？我也不确定这样的样例
                p0++;
                p1++;
            }
        }
    }
};//根据官方题解写的，还是挺难的。明天写一下另一种双指针解法

//12-18
//太牛了，这种方法我真的没想出来，主要是一个指针指向插入0的位置，一个指向插入2的位置，而且还有一个
//指针遍历，其实我觉得都是三指针了，还说双指针。。

//2021-7-14
/*
 * 1.官方题解过于难理解，还是grand的解法比较好。
 * 2.根据grand的解法来写一下。
 * */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=nums.size()-1,cur=0;
        while(cur<=j){
            // if(nums[i]==2||nums[j]==0)swap(nums[i],nums[j]);
            // if(nums[i]==0)i++;
            // if(nums[j]==2)j--;
            //这个解法不行，如果i和j都指向了1，那么就会出错。。。死循环了。
            if(nums[cur]==0){
                swap(nums[cur],nums[i]);
                i++;
                cur++;
            }else if(nums[cur]==2){
                swap(nums[cur],nums[j]);
                j--;//这里cur不++，因为有可能j被移到前面来，不一定是0，或者是1，或者是2.
            }else cur++;
        }
    }
};
int main(){

    return 0;
}
