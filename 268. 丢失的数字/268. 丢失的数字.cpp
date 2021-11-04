#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��6��8������1:12:51
//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        int n=nums.size();
//        for(int i=0;i<n;i++){
//        	int index=nums[i];
//            while(nums[i]<n&&nums[index]!=i){//�����Ǵ�ģ����Ǻ�i�Ƚϰ�����ô��i�Ƚ������أ�
//                swap(nums[i],nums[index]);
//            }
//        }
//        for(auto& n:nums)
//        	cout<<n<<" ";
//        for(int i=0;i<n;i++){
//            if(nums[i]!=i)
//                return i;
//        }
//        return n;
//    }
//};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]<n&&nums[nums[i]]!=nums[i]){//����Ƚ�ʱ���������Ⱑ������
                swap(nums[i],nums[nums[i]]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i)
                return i;
        }
        return n;
    }
};
/*
 * 1.���˹ٷ���⣬�о�ţ���ˣ�ԭ��������λ���㰡����ʵҲ��һ�ֹ�ϣ��˼���ڡ�ţ�ơ�
 * */
int main(){
	Solution s;
	vector<int> nums={9,6,4,2,3,5,7,0,1};
	cout<<s.missingNumber(nums);
    return 0;
}
