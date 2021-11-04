#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��2������10:20:53
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //˼·����num1ȫ���ŵ�һ�������Ȼ�����2����Ҳ���а���ԭ����Ҳdelete�����ˡ������󲢼���
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
 * 1.AC�ˣ�����һ��easy����Ŀ��ʱ��ռ䶼�ǣ�O(m+n)
 * 2.�ٷ�������������Ȼ��˫ָ�룺���⣿��һ���⡣
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
                // ��֤����Ԫ�ص�Ψһ��
                if (!intersection.size() || num1 != intersection.back()) {//�������һ��Ԫ�ؿ���ͨ��back()��������
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
//���ߣ�LeetCode-Solution
//���ӣ�https://leetcode-cn.com/problems/intersection-of-two-arrays/solution/liang-ge-shu-zu-de-jiao-ji-by-leetcode-solution/
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
int main(){

    return 0;
}
