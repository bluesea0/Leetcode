#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��6��10������12:50:21
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty())return;
        next_permutation(nums.begin(),nums.end());//ʹ�ÿ⺯������
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //�����Ҫ�۲���ɵģ������������ˣ��������Լ��ܽ᣿��Ǹ�Ҳ��ᡣ
        //�����ǴӺ���ǰ�ҽ����λ�ã���ǰ�����ҵ���������λ��Ȼ�󽻻����͵õ�����һ������
        //��֪���ڸ����һ������ȷ���ģ����ǵڶ����Ǵ�j��ʼ�ң����Ǵ�0��ʼ�ң�
        //�Ҿ����������еĹ����ˡ�

        //�Ӻ���ǰ�ҽ����λ��i���ٴӺ���ǰ�ҵ�һ��j>i��λ�ã�������֮��i��֮���ǵ���ģ�ֱ�ӷ�ת
        int n=nums.size(),i=n-2;
        while(i>=0){
            if(nums[i]>=nums[i+1])i--;//������Ҫ�Ƿ��ϸ���
            //��5 1 1������һ������1 1 5��ֱ��������reverse��
            else break;
        }
        if(i<0){
            reverse(nums.begin(),nums.end());return;
        }
        int j;
        for(j=n-1;j>i;j--){
            if(nums[j]>nums[i])break;
        }
        swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
    }
};
/*
 * 1.�����ܽ᣺�ٴӺ���ǰ�ҵ�����ĵ�һ������i���ڴӺ���ǰ�ҵ���һ������i������j������
 *   �۸���֮ǰ������˳��i+1�����ǽ���j������һ��С��i��������ô��Ȼ���ֽ�������reverse���ɡ�
 * 2.����ԭ��
 *   ������Ҫ��һ����ߵġ���С������һ���ұߵġ��ϴ��������������ܹ��õ�ǰ���б�󣬴Ӷ��õ���һ�����С�
 *   ����С�����������ң������ϴ�����������С��
 *   ��������ɺ󣬡��ϴ������ұߵ�����Ҫ���������������С�
 *   ���������ڱ�֤�����д���ԭ�����е�����£�ʹ���ķ��Ⱦ�����С��
 * */
int main(){

    return 0;
}
