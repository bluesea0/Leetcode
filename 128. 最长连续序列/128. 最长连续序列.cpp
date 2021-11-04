#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��10��23������12:54:29
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto& n:nums)
            mp[n]=1;
        int ans=0;
        for(auto& n: nums){
            if(mp.count(n-1)==0){//��ʾ��nΪ������
                int t=1;
                while(mp.count(n+t))t++;
                ans=max(ans,t);
            }
        }
        return ans;
    }
};
/*
 * 1.��Ȼ����������Լ�û������ģ�ֻ�ǿ��˹ٽ�˵�ù�ϣ������ֻ��û��С�ڵ����������ű�����������O(n)���Ӷ�
 *
 * */
int main(){

    return 0;
}
