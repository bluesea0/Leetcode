#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��24������2:27:00
//class Solution {
//public:
//    int findNumberOfLIS(vector<int>& nums) {
//        //�⽫����������ж��ҵ������������ĳ��ȣ�Ȼ������һ��ȷ���ж��ٸ���
//        //�ȼ�¼max����ȥdp�������ҵ�����=max���ж��ٸ���
//        //���ԣ����������ģ��ҾͲ������ˡ�
//    }
//};
/*
 * 1.���ͦ�ѵģ��ٷ���⻹�������߶����Ľⷨ����̫���ˣ�grand�Ľⷨ�Ƚ�������
 *   ��len��¼���ȣ�cnt��¼ֱ����ǰ�ĸ�������Ļ�ͦ�ѵġ�
 *   https://www.cnblogs.com/grandyang/p/7603903.html
 * */
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        //cnt��¼����ǰ�ĸ�����len��ʾ����
        int m=nums.size(),res=0,mx=0;
        vector<int> cnt(m,1),len(m,1);
        for(int i=0;i<m;i++){
            for(int j=0;j<i;j++){
                if(nums[i]<=nums[j])continue;//�޷��γɵ���������
                if(len[i]==len[j]+1)//˵���ֳ����µ�ͬ���ȵĵ���������
                    cnt[i]+=cnt[j];
                else if(len[i]<len[j]+1){
                    len[i]=len[j]+1;
                    cnt[i]=cnt[j];//���ҲҪ�Ŵ���
                }
            }
            if(mx<len[i]){//������ô���£��Ҳ�̫�ǵ��ˡ�����
                mx=len[i];
                res=cnt[i];
            }else if(mx==len[i])res+=cnt[i];
        }
        return res;
    }
};//[1,2,3,1,2,3,1,2,3]����������ˣ���Ӧ����10�������������Ҫ����<��
//��iָ��ڶ���3��jָ��ڶ���1��ʱ��len[i]=3,len[j]=1����ʱ��Ӧ�ø���i�������ᵼ��len����ر�С
//���������ķǳ�����˼��
int main(){

    return 0;
}
