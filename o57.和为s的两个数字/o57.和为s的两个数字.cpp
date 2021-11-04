#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��31������3:21:34
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.empty())return {};//��ʵ���Ҳ����Ҫ�С�
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]==target)return {nums[i],nums[j]};
            else if(nums[i]+nums[j]<target)i++;
            else j--;
        }
        return {};
    }
};
/*
 * 1.�ܼ򵥵�һ���⣬ûʲô�Ѷȡ�
 * 2.�����������и������п���nums[i]+nums[j]���֮���������е����Ƚϼ��˵�������ǣ�
 *   INT_MAX+ĳֵ���ͻ������ͬʱ�������Ϊtarget-nums[j]Ҳ���ܻ��������Ϊ���ܴ��ڸ�ֵ
 *   ĳ��ֵ-INT_MIN����ô�ͻ����������������ø�Ϊlong long��ǿ��ת��һ��
 * */
int main(){

    return 0;
}
