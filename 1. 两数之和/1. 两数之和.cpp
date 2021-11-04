#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��27������11:52:42
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        unordered_map<int,int> um;
//        for(size_t i=0;i<nums.size();i++)
//            um[nums[i]]=i;
//        sort(nums.begin(),nums.end());
//        size_t i=0,j=nums.size()-1;
//        while(i<j){
//            if(nums[i]+nums[j]==target) return {um[nums[i]],um[nums[j]]};
//            else if(nums[i]+nums[j]<target)i++;
//            else if(nums[i]+nums[j]>target)j--;
//        }
//        return {-1,-1};//��ʾ������
//    }
//};
/*
[3,2,4]
6
1.�Բۣ������˰�����Ϊ����������֮��id�Ǹı�ģ�����
  ��������ǽ�������map�У�����������ظ���Ԫ����ô�죿
  ��ʵ���ظ�������ν����ô���൱��ѡ������һ���ˡ�
2.�ִ��ˣ�û���ǵ�[3,3] 6��Ӧ����0��1��������д���ͻ����1��1 ���ˣ�����û�ˡ�
3.�Ҵ����ˣ�̫���ˣ�Ϊʲô��д�Ĳ����أ��������أ�
4.���˹ٷ���⣬�����Լ�����˼·�����˰���
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++){
            if(um.count(target-nums[i])){
                return {um[target-nums[i]],i};
            }
            um[nums[i]]=i;//����ŵ������������ǲ�����
        }
        return {-1,-1};
    }
};
/*
 * 5.����������ǰ��չٷ����д�����ģ�ʵ�������ꡣ
 *   ʱ��ռ䶼��O(n)��
 * */

int main(){

    return 0;
}
