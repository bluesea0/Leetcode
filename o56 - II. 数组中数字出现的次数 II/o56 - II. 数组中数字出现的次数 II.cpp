#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<cmath>
using namespace std;
//2021��3��23������12:47:18
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //����˳����Ǹ�ʲô�ǲ�ͬ�ģ��ӵ͵��ߺʹӸߵ���
        vector<int> bits(32,0);
        for(auto n:nums){
            for(int i=0;n!=0;i++){
                if(n&1)bits[i]++;
                n=n>>1;
            }
        }
        int ans=0;
        for(int i=0;i<bits.size();i++)
            if(bits[i]%3)ans+=pow(2,i);
        return ans;
    }
};
/*
 * 1.�����������Ľⷨ�������ˣ����һ�����ֳ���3�Σ����Ķ�����ÿһλҲ���ֵ�3�Ρ�
 *   ��������еĳ������ε����ֵĶ����Ʊ�ʾ��ÿһλ���ֱ����������ôÿһλ���ܱ�3������
 *   ���ǰ����������е����ֵĶ����Ʊ�ʾ��ÿһλ����������
 *   ���ĳһλ�ܱ�3��������ô��һλ��ֻ����һ�ε��Ǹ�������һ�϶�Ϊ0��
 *   ���ĳһλ���ܱ�3��������ôֻ����һ�ε��Ǹ����ֵĸ�λ��һ��Ϊ1.
 * */

//6-16
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> count(32,0);
        for(int i=0;i<nums.size();i++){
            int t=nums[i],j=0;
            while(t){
                if(t&1)count[j]+=1;
                t>>=1;
                j++;//�����������j��Ҫ++��
            }
        }//ͳ�������е�����
        int b=1,ans=0;
        for(int i=0;i<count.size();i++){
            if(count[i]%3)
                ans+=b;
            //i=31ʱ��Ҳ������һ��Ҫ�˳�ѭ���ˣ�����b���ǻ�����һλ���ܹ����ƶ���32�Σ�
            //���Ի�������
            if(i!=31)
                b<<=1;//runtime error: left shift of negative value -2147483648 (solution.cpp)
        }
        return ans;
    }
};
/*
 * 1.˼·�еģ�����д��ʱ��û����ô˳����
 * 2.������ͨ��λ�Ļ����� | ����д�ģ���Ҫ�Ӹ�λ��ʼ������
 * */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> count(32,0);
        for(int i=0;i<nums.size();i++){
            int t=nums[i],j=0;
            while(t){
                if(t&1)count[j]+=1;
                t>>=1;
                j++;//�����������j��Ҫ++��
            }
        }//ͳ�������е�����
        int ans=0;
        // for(int i=0;i<count.size();i++){
        //     if(count[i]%3)
        //         ans=(ans|1);
        //     ans<<=1;
        // }
        //���Ҫʹ�û��������Ļ�����Ҫ�Ӹ�λ��ʼ����
        for(int i=31;i>=0;i--){
            ans<<=1;//����λ����Ȼ�ͻ����һ��
            if(count[i]%3)
                ans=(ans|1);
        }
        return ans;
    }
};
int main(){
	Solution s;
	vector<int> nums={3,4,3,3};
	cout<<s.singleNumber(nums);
    return 0;
}
