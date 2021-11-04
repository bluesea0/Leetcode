#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��4������2:03:55
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//        //˼·���ȱ���һ�¼���0�ĸ�������ΪҪ�����ٲ���������Ҫȷ��ÿ��Ԫ�����յ�λ��
//        //�ף����Ǻ���֪���ܵ�0�ĸ�����Ҳ���㲻�������յ�λ�ð���
//        //˫ָ����ô�������βָ��϶��ǲ��еİ���ָ���λ��Ҳ����ֱ��swap
//        //easy����Ŀ��������������������
//    }
//};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //һ��ָ��ָ��0��λ�ã�һ��ָ��ָ���������0��λ��
        int i=0,j=0;
        while(i<nums.size()&&j<nums.size()){
            while(j<nums.size()&&nums[j]!=0)j++;
            while(i<nums.size()&&nums[i]==0)i++;
            if(i>=nums.size()||j>=nums.size())break;
            if(i>j)
                swap(nums[i],nums[j]);
            else i++;
        }
    }
};
/*
 * 1.һ���Ӿ�AC�ˣ�̫���˿����˰ɡ�
 * ���Ӷ�O(n)������Ҫ������������
	������ȫ0��ȫ��0��110��0���ں��棬�����ƶ���
	2.����������grand�����������ģ��˼Ҷ�����ôд�ģ�leftָ��ָ���Ѵ���õ�����β����rightָ�������ͷ��
	���ˡ�
	class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                swap(nums[i], nums[j++]);
            }
        }
    }
};
 * */

//9-27��ϰ
/*
 * 1.leftָ���Ѵ���õ�Ԫ�ص�ĩβ��ָ����Ƿ�0��Ԫ�أ�rightһ��ָ���0�ģ���ô�ͺ�left����
 *  �����ȿ��Ա�֤����0ֵ�ᱻ�������ײ��ˡ�
 * */
int main(){

    return 0;
}
