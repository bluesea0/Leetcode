#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月2日下午10:20:53
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //思路：将num1全都放到一个集合里，然后遍历2，那也不行啊，原来的也delete不了了。这是求并集。
        unordered_set<int> st,ans;
        vector<int> ret;
        for(auto n:nums1)
            st.insert(n);
        for(auto n:nums2){
            if(st.count(n)!=0)
                ans.insert(n);
        }
        for(auto a:ans)
            ret.push_back(a);
        return ret;
    }
};
/*
 * 1.AC了，这是一道easy的题目，时间空间都是：O(m+n)
 * 2.官方还给了先排序，然后双指针：就这？的一道题。
 * */
class Solution1 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int length1 = nums1.size(), length2 = nums2.size();
        int index1 = 0, index2 = 0;
        vector<int> intersection;
        while (index1 < length1 && index2 < length2) {
            int num1 = nums1[index1], num2 = nums2[index2];
            if (num1 == num2) {
                // 保证加入元素的唯一性
                if (!intersection.size() || num1 != intersection.back()) {//这里最后一个元素可以通过back()函数访问
                    intersection.push_back(num1);
                }
                index1++;
                index2++;
            } else if (num1 < num2) {
                index1++;
            } else {
                index2++;
            }
        }
        return intersection;
    }
};
//
//作者：LeetCode-Solution
//链接：https://leetcode-cn.com/problems/intersection-of-two-arrays/solution/liang-ge-shu-zu-de-jiao-ji-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
int main(){

    return 0;
}
