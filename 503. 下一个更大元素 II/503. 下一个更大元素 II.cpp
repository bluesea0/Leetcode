#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��3��9������1:38:50
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //����ջ
        //1 2 1 1 2 1
        //����forѭ��
        if(nums.empty())return {};
        vector<int> stk,ans(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            while(!stk.empty()&&nums[stk.back()]<nums[i]){
                ans[stk.back()]=nums[i];
                stk.pop_back();
            }
            //if(nums.empty()||nums[i]<nums[stk.back()])
            stk.push_back(i);//���ڵĻ�����Ҫ��
        }
        for(int i=0;i<nums.size();i++){
            while(!stk.empty()&&nums[stk.back()]<nums[i]){
                ans[stk.back()]=nums[i];
                stk.pop_back();
            }
        }
        return ans;
    }
};
/*
 * 1.һ����AC�ˣ���̫���ˣ����쵥��ջ��֪ʶ��
 * 2.ԭ������ѭ�����鰡���ٷ�д�ĺ�ţ����%�����٣��Ͳ���д����forѭ���ˣ���Ҫѧϰ�����
 * */
int main(){

    return 0;
}
