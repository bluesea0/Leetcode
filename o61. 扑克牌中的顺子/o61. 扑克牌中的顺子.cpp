#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��6��18������2:52:06
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        //�����������ʵ�е��Ի󣬿��������дһ��
        unordered_set<int> us;
        int maxn=INT_MIN,minn=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)continue;
            if(us.count(nums[i]))return false;
            us.insert(nums[i]);
            minn=min(minn,nums[i]);
            maxn=max(maxn,nums[i]);
        }
        return maxn-minn<5;
    }
};
/*
 * 1.���򣺳�0�ⲻ�����ظ��ģ�������setȥ�أ����ֵ��Сֵ��ֵ����>=5��
 *
 * */
int main(){

    return 0;
}
