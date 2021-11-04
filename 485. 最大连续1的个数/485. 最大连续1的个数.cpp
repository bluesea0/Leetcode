#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��4������4:52:03
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0,cur=0;
        for(auto n:nums){
            if(n){
                cur++;
                ans=max(ans,cur);
            }else cur=0;
        }
        return ans;
    }
};
/*
 * 1.��ʵ����Ƿǳ��򵥵İɣ��ҿ��ٷ���������������0��ʱ��ż���max���Ҿ��ñ��Һÿ�����������ÿ�ζ�Ҫmax
 * 2.����������ȴ����˵��˫ָ�룿�ǵø���ô�鷳�𣿷ǵ���ô��������дһ�°ɡ�
 * */
class Solution2 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left=0,right=0,ans=0;
        while(right<nums.size()){
            if(nums[right++])continue;
            else{
                //�ƶ���ָ��
                ans=max(right-left-1,ans);
                left=right;
            }
        }
        return max(ans,right-left);
    }
};
/*
 * 3.˫ָ��ⷨ��ʵ����̫���ˡ�
 * */
int main(){

    return 0;
}
