#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��5��22������8:33:25
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        //����ͨ��swap����Ż�ԭλ�����ԭλ�Ѿ����ˣ�˵�����ظ���
        //������ͨ���Ӹ������жϣ������Ӧλ���Ѿ��为����ô���Ǹ����ظ�
        for(int i=0;i<nums.size();i++){
            // if(nums[abs(nums[i])]<0)ans.push_back(abs(nums[i]));//���Բ��ԣ������ͷ���������
            // //���0�أ�-0��0�����Ի���ȡswap�ȽϿ��ס�

            // else nums[abs(nums[i])]=-nums[abs(nums[i])];
            while(nums[nums[i]]!=nums[i])
                swap(nums[i],nums[nums[i]]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i)
                return nums[i];
        }
        return 0;
    }
};
/*
 * 1.̫��������������ʱ�򣬱�������ȡ��ֵ�����Ƿ�����0���������Ȼ����swap׼�����ص�ʱ�򣬷��ֺ�������ֻ��Ҫ
 *   ����һ���Ϳ��ԡ���������������������ô�鷳�ġ�
 * 2.
 * */
int main(){

    return 0;
}
