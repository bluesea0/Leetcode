#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��5��20������11:00:59
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            while(nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
            // if(i+1!=nums[i])//����������ͳ�ƣ�֮��ͳһͳ�ƾͿ�����
            //     ans.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(i+1!=nums[i])
                ans.push_back(nums[i]);
        }
        return ans;
    }
};
/*
 * 1.����41��ڶ��ֽⷨ����ˡ��������鴴����ϣ��
 * */
//class Solution {
//public:
//    vector<int> findDuplicates(vector<int>& nums) {
//        //���Խ���Ӧλ�ñ�Ϊ��ֵ
//        vector<int> ans;
//        for(int i=0;i<nums.size();i++){
//            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
//        }
//        for(int i=0;i<nums.size();i++)
//            if(nums[i]>0)
//                ans.push_back(i+1);
//        return ans;
//    }
//};
/*
 * 2.����Ϊʧ�ܵĳ��ԣ���Ϊ�г������εģ���������ȡ����Ϊ����������û�г��ֹ���Ҳ�Ǹ�����������ôͳ�ơ�
 *   Ӧ����forѭ����ͳ�ơ�
 * */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //���Խ���Ӧλ�ñ�Ϊ��ֵ
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]<0)
                ans.push_back(abs(nums[i]));
            else nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        }
        return ans;
    }
};//��ʵҲû�п���٣�swap����68ms�������52ms���������ǿ���һ�㡣

//2021-6-8
/*
 * 1.���츴ϰ���ֵ������ǣ���ֻ���뵽��swap������������ɸ����Ĳ����밡��
 *
 * */
int main(){

    return 0;
}
