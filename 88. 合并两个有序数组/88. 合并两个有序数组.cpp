#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月6日下午3:34:53
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //一个比较重要的问题就是如果是从前往后比较的话，那免不了会产生元素移动
        //那么就从后往前比较了。
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0&&j>=0){
            if(nums1[i]>=nums2[j]){
                nums1[k]=nums1[i];
                i--;
            }else{
                nums1[k]=nums2[j];
                j--;
            }
            k--;
        }
        //最后将剩余的放进去？
        //说明还没放完
        while(i>=0)nums1[k--]=nums1[i--];
        while(j>=0)nums1[k--]=nums2[j--];
    }
};
/*
 * 1.AC了。复杂度是O(m+n),O(1)。
 * */
int main(){

    return 0;
}
