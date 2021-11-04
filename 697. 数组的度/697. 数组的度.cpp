#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��20������12:35:30
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int ct=0;
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++){
            um[nums[i]]++;
            if(um[nums[i]]>ct){
                ct=um[nums[i]];//�Բۣ���������������ˣ�����
            }//[1,3,2,2,3,1]�����е����ȶ���һ���ģ�����Ҫѡ������С�ģ���ô����Ҫ���������
            //��һ��������Ȼ�����жϡ�
        }
        vector<int> res;
        for(auto& [k,v]:um){
            if(v==ct)res.push_back(k);
        }
        int ans=nums.size();
        for(auto& r:res){
            int left=0,right=nums.size()-1;//������ʵֻ������˫ָ�룬����ÿ�α�����������O(n)�ĸ��ӶȰ�
            while(nums[left]!=r)left++;
            while(nums[right]!=r)right--;
            ans=min(right-left+1,ans);
        }
        return ans;
    }
};
/*
 * 1.�������ҵ�д��������ͨͨ������O(n)�������ҵ�д��������Ч
 * 2.�ٷ������ʹ����unordered_map<int, vector<int>> mp;�Ľṹ�������ȷʵûע�����value�е�����ӳ��
 *   Ϊ������0��ʾ������1��2��ʾ��ʼ��ֹ�±꣬�о���ͦ���ġ��������������ҿ���ÿ�쿴����
 * 3.�����������кܶ໬���Ľⷨ������ѧ���ˣ�����Ҫдһ�¡�
 * */
int main(){

    return 0;
}
