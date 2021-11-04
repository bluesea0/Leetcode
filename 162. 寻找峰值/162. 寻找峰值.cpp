#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��10��27������10:16:55
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //O(n)����Ļ�����ô��ȥ���������е�ÿ����
        //�����ж���βԪ��
        int n=nums.size();
        if(n==1)return 0;//����Ӧ��return�±�
        //�ж���β
        if(nums[0]>nums[1])return 0;
        if(nums[n-1]>nums[n-2])return n-1;
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1])return i;//����Ҳ����ans=i;break;����ͳһ��
            //���淵�ء�
        }
        return 0;
    }
};
/*
 * 1.O(n)����ĸ��Ӷ��ǱȽϼ򵥵ģ�����Ҫ����O(logn)�����
 * */

//10-28
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //ʹ�ö��ֵķ�����
        int left=0,right=nums.size()-1;
        while(left<right){//���ʱ�˳�
            int mid=left+(right-left)/2;
            if(nums[mid+1]>nums[mid])left=mid+1;
            // else if(nums[mid-1]>nums[mid])right=mid-1;
            // else if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1])return mid;
            else right=mid;
        }//������д�������[2,1]�����ĳ���Ϊ2�ľͲ����ã���Ϊmid-1û�а����ǻ���ʴ�����±��
        //grand��ֻ������mid��mid+1����������ԾͲ������Խ�磬��Ϊmid=0��ʱ��ȷʵ�ǻ����Խ�磬
        //��Ϊmid�ǱȽ�ƫ����left�ģ����ǿ��ƫ��right������Ȼ���ǻ���mid+1�±�Խ�������
        return left;
    }
};
/*
 * 1.�Լ�д�Ļ��������⣬���±귵�ص�ʱ��grand����ţ��
 * */
int main(){

    return 0;
}
