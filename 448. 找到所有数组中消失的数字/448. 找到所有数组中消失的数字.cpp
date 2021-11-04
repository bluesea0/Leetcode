#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��13������8:33:42
//class Solution {
//public:
//    vector<int> findDisappearedNumbers(vector<int>& nums) {
//        //�����ֻ�뵽���ö���ռ�ģ���ϣ��
//        //��ͣ����У�λ���㣿����Ҳ��ȷ����Щ�ǳ������Σ���Щ����һ�Σ�
//        //��Щû���֣���̫���˰ɡ����ö���ռ䣿
//    }
//};
/*
 * 1.�о���ͦ�ѵģ�û�������ô�����������˵��Ҫԭ���޸ġ�
 * */

//2-14
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=(nums[i]-1)%n;
            nums[x]+=n;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]<=n)
                ans.push_back(i+1);//������Ҫ+1���Ǵ�1��ʼ������
        }
        return ans;
    }
};
/*
 * 1.AC�ˣ���ΪԪ��ֵ��С�����ƣ����Կ���ͨ��ԭ���޸Ĳ����ж�Ԫ��ֵ��С�����㣬ѧ���ˡ�
 * 2.inplace�޸ģ�����ռ�ö���ռ�Ļ����Ϳ���������ת��
 * */

//3-20
class Solution2 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //����������ת�ķ���
        //��������������˵�������+n�Ļ������ܻ������������
        for(int i=0;i<nums.size();i++){
            int n=abs(nums[i]);
            nums[n-1]=-abs(nums[n-1]);//֮���������abs������Ϊ���ܻ��������
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
            if(nums[i]>0)
                ans.push_back(i+1);
        return ans;
    }
};

//5-20
/*
 * 1.����ţ�ܣ�ֱ�Ӷ��������ݣ�������ԭ�������Ǹ���ֱ��ȡabs�����ţ�����ֻҪ���ֹ��ľ��Ǹ���
 * */

//2021-6-8
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            while(nums[i]!=nums[nums[i]-1])//���ѭ�����������ζ�Ž�nums[i]�ŵ��÷ŵ�λ��
            //Ҳ����nums[i]-1��λ�á����Ұ���
                swap(nums[i],nums[nums[i]-1]);
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
            if(nums[i]-1!=i)
                ans.push_back(i+1);
        return ans;
    }
};
/*
 * 1.���swapҲ���ҵģ����ԡ�
 * */
int main(){

    return 0;
}
