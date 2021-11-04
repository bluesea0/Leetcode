#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��5������4:22:38
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //˼·��˫ָ�룬�����������ѭ�����Ƶ�һ������
        //˫ָ������ڲ����������
        //int ans=1e7;//
        int ans=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());//����ô���������ˣ�
        for(int i=0;i+2<nums.size();i++){
            int t=target-nums[i];
            int j=i+1,k=nums.size()-1;
            while(j<k){
                //�������t�Ǹ���������ô�Ұ�߾ͻ������������ô��ʼ���أ�
                if(abs(nums[j]+nums[k]-t)<abs(ans-target))ans=nums[j]+nums[k]+nums[i];
                //����������µĵط���ô��ô���أ�����
                if(nums[j]+nums[k]<t){
                    j++;
                }else if(nums[j]+nums[k]>t){
                    k--;
                }else return target;
            }
        }
        return ans;
    }
};//[0,0,0] 1���������ȷʵ���Ҵ��˿���������Ϊ����ʵ�����ܽ��У��������t�Ͱ��������ȥ�ˣ�
//�ҵ���ѽ���������ˣ���ʵ��Ӧ�÷Ž�ȥ��ֵ������ô�Ѳ�ֵ�Ž�ȥ�ˣ�
//[0,1,2] 3����ȵ�ʱ��Ӧ��return 0����Ӧ��return���Ŀ��
//[1,1,1,1] 0 �������������Ϊ�Ұ�ans��ʼ��Ϊ��INT_MAX�����ٷ������1e7
//[1,1,1,0] 100
/*
 * 1.�ύ��6�β�ͨ�������䶶�����ؼҵ���Ϣ�ɡ�
 * 2.��Ҫע���������ʵͦ��ģ�����ʱans�洢�Ĳ��ǲ�ֵ�����������ֵ��ans�жϵ�ʱ��-����target������t
 *   ���ʱ���ص���target������t��ans��ʼ������Ϊ˵����nums.length>=3���Կ���ֱ����ô��ʼ����
 *   ��ʵ����Ϊ�˷�����õ�tû�뵽�������ô�����ᡣ�����Ժ���������������˵temp���������Ҹ�������
 *   ������˼�ˣ����ҿ϶����᷵��temp��
 * */
int main(){

    return 0;
}
