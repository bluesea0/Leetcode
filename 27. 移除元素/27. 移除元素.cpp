#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月5日下午2:09:05
//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        int i=0,j=nums.size()-1;
//        while(i<j){//退出循环是i==j
//            while(i<=j&&nums[j]==val)j--;
//            while(i<j&&nums[i]!=val)i++;
//            swap(nums[i],nums[j]);
//        }
//        return i==0?0:i+1;
//    }
//};//天哪，对[1,2,2] [2,2,2]这样的样例可怎么办啊，怎么判断这这种样例呢？

//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        //if(nums.size()==1) nums[0]==val?0:1;
//        int j=nums.size(),i=0;
//        for(i=0;i<j;i++){
//            if(nums[i]==val){
//                while(i<j-1&&nums[j-1]==val)j--;
//                swap(nums[i],nums[j-1]);
//            }
//        }//草，又遇到问题了[2,2] 3这样的完全没有需要去除的数据，我这个写法就遇到了问题啊
//        return i;//改为j-1，i返回又出现了问题，我已经完全放弃了。
//    }
//};
/*
 * 1.草，提交了，千算万算，没算到会有单个元素输入[2] 3，草，给我气懵了。
 * 2.写了两种方法感觉都通不过，烦死了啦。
 * 3.天哪，看了解答，这绝对不是简单级别的题目吧，好难啊。可以使用覆盖，也可以整个减少size的大小，
 *   这是我没有想到的，我一直想用i来控制，但其实它是控制不了的。
 * */

//1-6
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=nums.size()-1;
        while(i<=j){//需要有=，不然就少判断了一个元素
            if(nums[i]==val){
                nums[i]=nums[j];
                j--;
            }else i++;
        }
        return j+1;
    }
};//只记得这一种方法，AC了。O(n) O(1)
/*
 * 1.当要移除的元素很少时，上述交换的方法比较有用。但是如果极端点来说，如果整个数组都是要移除的元素，那么
 *   上述方法就会比较低效，对每个元素都要进行赋值操作。
 * 2.所以使用快慢指针，i指向处理好的末尾，j指向下一个!=val也就是待处理的位置。下次要写一下这个
 * */
int main(){

    return 0;
}
