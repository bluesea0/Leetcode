#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年10月29日下午1:29:50
//class Solution {
//public:
//    vector<int> nums;
//    int target;
//    vector<int> ans;
//    vector<int> searchRange(vector<int>& nums, int target) {
//        //这道题充分显示了我对二分法没有熟练掌握。。。。
//        this->nums=nums;
//        this->target=target;
//        ans.assign(2);
//        ans[0]=nums.size()+1;
//        ans[1]=-1;
//        search(0,nums.size()-1);//那这个传进去的是哪一个呢？
//        return ans;
//        //怎么更新呢？
//        // int lo=0,hi=0;
//        // while(lo<hi){
//        //     int mid=lo+(hi-lo)/2;
//        //     //是不是得用递归？好难写啊！
//        //     //如果是在mid右边，是在mid左边，是跨mid的。。这都分别怎么计算呢？
//        //     //感觉用迭代的方式是写不出来的，只能用递归吧。
//    }
//    int search(int lo,int hi){
//            while(lo<hi){
//                int mid=lo+(hi-lo)/2;
//                if(nums[mid]>=target){
//                    ans[0]=min(ans[0],search(lo,mid));
//                }//这里我也只处理了left，那right什么时候处理呢？真的太难了！
//            }
//        }
//    }
//};
/*
 * 1。写不下去的垃圾代码，啊，一年前我竟然一下子就AC了，但是不是用的递归，而是二分之后再往左右判断
 *   那个时候居然觉得简单，我比那个时候还弱了吗，没有先到这个写法。
 *2.对应剑指offer53-I，我觉得我还是先不看这个了，太难了，等到我看到那个算法系统教程的时候再回来吧。。好难
 * */

//11-4
/*
 * 1.二分就是想搞死我！！！哼!
 * 2.我需要总结一下二分，写个博客，总结题解，因为之后复习还会需要的！
 * */

//11-5
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0,right=nums.size();
        vector<int> ans{-1,-1};
        while(left<right){//找左边的位置
            int mid=left+(right-left)/2;
            if(target<=nums[mid])//这里的小细节还是要注意。
                right=mid;
            else left=mid+1;
        }
        if(left==nums.size()||nums[left]!=target) return ans;
        ans[0]=left;
        left=0,right=nums.size();
        while(left<right){
            int mid=left+(right-left)/2;
            if(target>=nums[mid])
                left=mid+1;
            else right=mid;
        }
        ans[1]=left-1;
        return ans;
    }
};
/*
 * 1.Yes！我也终于AC了，太开心了吧！grand可厉害了，直接用寻找target+1的方式，这个下次复习我要推导一下。
 * */


//6-12
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //通过二分法查找左边界和右边界
        //找到的是>=target的第一个位置
        int n=nums.size();
        if(n==0)return 0;
        int left=bs(nums,target,0,n-1);
        int right=bs(nums,target+1,0,n-1);
        return right-left;
    }
    int bs(vector<int>& nums,int target,int left,int right){//寻找左边界
        while(left<=right){
            int mid=left+((right-left)>>1);
            if(target<nums[mid])right=mid-1;
            else if(target==nums[mid])right=mid-1;
            else left=mid+1;
        }
        return left;
    }
};
/*
 * 1.二分通过利用找target+1来使得代码缩短，我习惯写二分法是right就指向结尾，判断是left<=right，然后
 *   其中比较的时候一定要把所有的分支写出来，分别判断，然后有冗余的合并，不然一下子写出来合并的二分太
 *   烧脑了！难啊！
 * */

//10-23
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())return {-1,-1};
        int n=nums.size();
        int left=search(nums,target,0,n-1);//负责找到>=target的最左的位置
        int right=search(nums,target+1,0,n-1);
        if(left==right)return {-1,-1};
        else return {left,right-1};
    }
    int search(vector<int>& nums,int target,int left,int right){
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>=target)right=mid-1;
            else if(nums[mid]<target)left=mid+1;
        }
        return left;
    }
};
/*
 * 1.6-12写的题解是针对剑指offer上的吧。这里针对查找，将代码抽为一个公共函数的技巧，分别在数组中查找target
 *   这样返回>=的第一个位置，查找target+1也返回>=target+1的位置，那么就是正好>target的起始位置。
 *   绝了绝了。
 * 2.针对返回，如果没有出现target，那么left和right的值肯定是一样的，如果只出现了一次，那么肯定是
 *  right==left+1这样的，所以判断结果只用是否相等就可以了。
 * */
int main(){

    return 0;
}
