#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��3������10:13:16
//class Solution {
//public:
//    void rotate(vector<int>& nums, int k) {
//        //(i+k)%n�����ƶ��������λ��
//        //�������[1,2,3,4]��k=2�����ģ��ͻ�ֻ�ƶ�ż��λ��������λ��ô���أ��Ҳ������ҹ���
//        int i=0,ct=0;
//        while(ct<nums.size()){
//            int j=(i+k)%n;
//
//        }
//    }
//};
/*
 * 1.���ò�˵�������ĺ��Ѻ��Ѱ���
 * */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //���÷�ת��дһ��
        int n=nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k%n);//��ʵ���ﲻ��-1����Ϊ����ָ�����ת�ĺ�һ��λ��
        reverse(nums.begin()+k%n,nums.end());
    }
};
//����дһ�»�״�滻�Ľⷨ
class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        int idx=0,temp=nums[0],start=0,n=nums.size();
        if(k==0||k%n==0) return;//����ֱ�ӼӸ��ж�������Щ���ƶ��ķ��ص���grandҲ����ôд��
        for(int i=0;i<n;i++){
            int nid=(idx+k)%n;//��Ҫ���õ�λ��
            swap(temp,nums[nid]);
            idx=nid;
            if(idx==start){//���������ȵĻ����������[1] 0�ͻ����idx=1��������ͻ���ʲ����ڵ��±�
                start++;
                idx++;
                temp=nums[idx];
            }
        }
    }
};//�����Ŀ�Һ��Ѷ�λ���ĸ���𣬾��Ȳ�����������ˡ�


//6-19
/*
 * 1.���츴ϰֻ�뵽ֱ��ͨ��%�ҵ��±꣬���ǲ���֪����ôѭ�������Ҹ���Ҳû���뵽�п��ܻ�ֻ�ƶ�ż��λ�����
 *   k��ż���Ļ���̫����ʵ���ǡ�
 * 2.��һ��˼·�ǣ�ʹ��һ���µ����飬�ŵ������ת��λ�á�������������ö���ռ�Ļ�����ô����Ҫһ��������
 *   ����ǰһ������
 * */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k%n==0)return;
        int start=0,pre=nums[0],idx=0;
        for(int i=0;i<n;i++){
            idx=(idx+k)%n;
            int t=nums[idx];
            nums[idx]=pre;
            pre=t;//����pre�Ľ�����������ǡ�
            if(idx==start){//���Ʋ�ֻ��һ��Ȧ��ѭ����������Ȧ�����¿�ʼһ��Ȧ
                start++;
                idx++;
                pre=nums[idx];
            }
        }
    }
};
int main(){

    return 0;
}
