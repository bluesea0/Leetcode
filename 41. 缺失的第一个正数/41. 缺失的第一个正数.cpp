#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��3��20������3:08:49
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int& num:nums)
            if(num<=0)num=n+1;
        for(int i=0;i<n;i++){
            if(abs(nums[i])<=n){
                nums[abs(nums[i])-1]=-abs(nums[abs(nums[i])-1]);//��ÿ������Ӧ���±����ת��Ϊ����
            }
        }
        for(int i=0;i<n;i++)
            if(nums[i]>0)
                return i+1;
        return n+1;
    }
};
/*
 * 1.�����AC�ˣ����ù�ϣ��˼�룬��Ŀ�����ᵽ��ʹ�ó����������ռ䣬��ô��Ҫ�뵽��ϣ��˼�룡
 * */

//5-20
/*
 * 1.����Ϊ���ǵڶ��ֽⷨ�ȽϺá��û���ԭ����λ���ϡ����ֽⷨ��֪ʶ����ԭ�ع�ϣ�����������±��Ԫ�ؽ�����ϣ��
 * 2.
 * */
class Solution {//����ʵ��������ⷨ�÷�ʱ��Ӧ������Ϊ��swap��
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            while(nums[i]>0&&nums[i]<nums.size()&&nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);//����ֱ����ôд��
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1)
                return i+1;
        }
        return nums.size()+1;
    }
};

//6-8
/*
 * 1.����swap��һ�����������鳤�ȷ�Χ�ڵ������ƺ�û�취�����ˣ�����ʵ���ϻ��ǻ�������ҩ���Ǿ�ֻ����
 *   �ڷ�Χ�ڵģ�ʣ����ٴα�����ok�ˡ�
 * 2.���Ƶ���Ŀ���б为���Ľⷨ��
 * */
int main(){
	Solution s;
	vector<int> nums={3,4,1,1};
	cout<<s.firstMissingPositive(nums);
    return 0;
}
