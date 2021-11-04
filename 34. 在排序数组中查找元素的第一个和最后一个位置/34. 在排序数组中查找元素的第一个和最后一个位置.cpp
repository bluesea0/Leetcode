#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��10��29������1:29:50
//class Solution {
//public:
//    vector<int> nums;
//    int target;
//    vector<int> ans;
//    vector<int> searchRange(vector<int>& nums, int target) {
//        //���������ʾ���ҶԶ��ַ�û���������ա�������
//        this->nums=nums;
//        this->target=target;
//        ans.assign(2);
//        ans[0]=nums.size()+1;
//        ans[1]=-1;
//        search(0,nums.size()-1);//���������ȥ������һ���أ�
//        return ans;
//        //��ô�����أ�
//        // int lo=0,hi=0;
//        // while(lo<hi){
//        //     int mid=lo+(hi-lo)/2;
//        //     //�ǲ��ǵ��õݹ飿����д����
//        //     //�������mid�ұߣ�����mid��ߣ��ǿ�mid�ġ����ⶼ�ֱ���ô�����أ�
//        //     //�о��õ����ķ�ʽ��д�������ģ�ֻ���õݹ�ɡ�
//    }
//    int search(int lo,int hi){
//            while(lo<hi){
//                int mid=lo+(hi-lo)/2;
//                if(nums[mid]>=target){
//                    ans[0]=min(ans[0],search(lo,mid));
//                }//������Ҳֻ������left����rightʲôʱ�����أ����̫���ˣ�
//            }
//        }
//    }
//};
/*
 * 1��д����ȥ���������룬����һ��ǰ�Ҿ�Ȼһ���Ӿ�AC�ˣ����ǲ����õĵݹ飬���Ƕ���֮�����������ж�
 *   �Ǹ�ʱ���Ȼ���ü򵥣��ұ��Ǹ�ʱ��������û���ȵ����д����
 *2.��Ӧ��ָoffer53-I���Ҿ����һ����Ȳ�������ˣ�̫���ˣ��ȵ��ҿ����Ǹ��㷨ϵͳ�̵̳�ʱ���ٻ����ɡ�������
 * */

//11-4
/*
 * 1.���־���������ң�������!
 * 2.����Ҫ�ܽ�һ�¶��֣�д�����ͣ��ܽ���⣬��Ϊ֮��ϰ������Ҫ�ģ�
 * */

//11-5
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0,right=nums.size();
        vector<int> ans{-1,-1};
        while(left<right){//����ߵ�λ��
            int mid=left+(right-left)/2;
            if(target<=nums[mid])//�����Сϸ�ڻ���Ҫע�⡣
                right=mid;
            else left=mid+1;
        }
        if(left==nums.size()||nums[left]!=target) return ans;
        ans[0]=left;
        left=0,right=nums.size();
        while(left<right){
            int mid=left+(right-left)/2;
            if(target>=nums[mid])
                left=mid+1;
            else right=mid;
        }
        ans[1]=left-1;
        return ans;
    }
};
/*
 * 1.Yes����Ҳ����AC�ˣ�̫�����˰ɣ�grand�������ˣ�ֱ����Ѱ��target+1�ķ�ʽ������´θ�ϰ��Ҫ�Ƶ�һ�¡�
 * */


//6-12
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //ͨ�����ַ�������߽���ұ߽�
        //�ҵ�����>=target�ĵ�һ��λ��
        int n=nums.size();
        if(n==0)return 0;
        int left=bs(nums,target,0,n-1);
        int right=bs(nums,target+1,0,n-1);
        return right-left;
    }
    int bs(vector<int>& nums,int target,int left,int right){//Ѱ����߽�
        while(left<=right){
            int mid=left+((right-left)>>1);
            if(target<nums[mid])right=mid-1;
            else if(target==nums[mid])right=mid-1;
            else left=mid+1;
        }
        return left;
    }
};
/*
 * 1.����ͨ��������target+1��ʹ�ô������̣���ϰ��д���ַ���right��ָ���β���ж���left<=right��Ȼ��
 *   ���бȽϵ�ʱ��һ��Ҫ�����еķ�֧д�������ֱ��жϣ�Ȼ��������ĺϲ�����Ȼһ����д�����ϲ��Ķ���̫
 *   �����ˣ��Ѱ���
 * */

//10-23
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())return {-1,-1};
        int n=nums.size();
        int left=search(nums,target,0,n-1);//�����ҵ�>=target�������λ��
        int right=search(nums,target+1,0,n-1);
        if(left==right)return {-1,-1};
        else return {left,right-1};
    }
    int search(vector<int>& nums,int target,int left,int right){
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>=target)right=mid-1;
            else if(nums[mid]<target)left=mid+1;
        }
        return left;
    }
};
/*
 * 1.6-12д���������Խ�ָoffer�ϵİɡ�������Բ��ң��������Ϊһ�����������ļ��ɣ��ֱ��������в���target
 *   ��������>=�ĵ�һ��λ�ã�����target+1Ҳ����>=target+1��λ�ã���ô��������>target����ʼλ�á�
 *   ���˾��ˡ�
 * 2.��Է��أ����û�г���target����ôleft��right��ֵ�϶���һ���ģ����ֻ������һ�Σ���ô�϶���
 *  right==left+1�����ģ������жϽ��ֻ���Ƿ���ȾͿ����ˡ�
 * */
int main(){

    return 0;
}
