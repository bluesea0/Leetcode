#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��16������4:10:48
//class Solution {
//public:
//    void sortColors(vector<int>& nums) {
//        //��������⣬�ҵĸо����ǣ�������˼���ܡ�
//        //˫ָ�룿�в�ͨ���������ÿ⺯���������ռ�һ��ɨ�裿�Ǹ����췽ҹ̷�ɡ�����̫���ˡ�
//    }
//};

//12-17
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //p0��p1�ֱ���0��1��һ��Ҫ�ŵ�λ��λ�á�
        int p0=0,p1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                swap(nums[i],nums[p1]);
                p1++;
            }else if(nums[i]==0){
                swap(nums[p0],nums[i]);//���Ӧ�÷ŵ��жϵ�ǰ�棿
                if(p0<p1)//����������Ļ���������p0���ܾͻ�ռ��1
                    swap(nums[i],nums[p1]);//������ôд�д����Ⱑ��[1,0]�����ģ��ͻᱻ�������Σ���Ϊp0һֱָ����ǵ�0λ���ҿ��ˡ�
                    //���ģ�����swap p0��p1������
                    //��Ϊswap p0��i�Ļ�, p0����ָ��ľ���1�����п��ܽ�1��������i��λ�ã�����
                    //��i��p1��λ���ֻ��ˣ���iλ���ϵ�1����p1��λ��
                    //����û��һ�ֿ���p1����ָ���Ҳ��1���������������棬�ɲ��ͻ��ˣ�
                    //Ӧ�ò��᣿��Ҳ��ȷ������������
                p0++;
                p1++;
            }
        }
    }
};//���ݹٷ����д�ģ�����ͦ�ѵġ�����дһ����һ��˫ָ��ⷨ

//12-18
//̫ţ�ˣ����ַ��������û���������Ҫ��һ��ָ��ָ�����0��λ�ã�һ��ָ�����2��λ�ã����һ���һ��
//ָ���������ʵ�Ҿ��ö�����ָ���ˣ���˵˫ָ�롣��

//2021-7-14
/*
 * 1.�ٷ�����������⣬����grand�Ľⷨ�ȽϺá�
 * 2.����grand�Ľⷨ��дһ�¡�
 * */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=nums.size()-1,cur=0;
        while(cur<=j){
            // if(nums[i]==2||nums[j]==0)swap(nums[i],nums[j]);
            // if(nums[i]==0)i++;
            // if(nums[j]==2)j--;
            //����ⷨ���У����i��j��ָ����1����ô�ͻ����������ѭ���ˡ�
            if(nums[cur]==0){
                swap(nums[cur],nums[i]);
                i++;
                cur++;
            }else if(nums[cur]==2){
                swap(nums[cur],nums[j]);
                j--;//����cur��++����Ϊ�п���j���Ƶ�ǰ��������һ����0��������1��������2.
            }else cur++;
        }
    }
};
int main(){

    return 0;
}
