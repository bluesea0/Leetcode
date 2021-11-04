#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月12日下午2:01:37
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //二分查找，查找比target刚好大的字母，如果没找到就返回最小的
        int left=0,right=letters.size();
        while(left<right){
            int mid=left+(right-left)/2;
            if(letters[mid]<=target)
                left=mid+1;
            else right=mid;
        }
        return right==letters.size()?letters[0]:letters[right];
    }
};
/*
 * 1.天啦，一下子就AC了，时间O(logn)，比较基本的二分，而且right初始化为size长度会更简便。
 *   退出循环时是left==right的，那么之后处理right就可以了，也不用+1/-1等操作。
 * 2.
 * */
int main(){

    return 0;
}
