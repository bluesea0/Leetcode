#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��27������4:19:56
/*
 * 1.�ҿ���������ʱ��͸о��ϲ�������Ҫ��Ȼ��ô�����ң��벻���������������ĸо����ˣ���ֵ����
 *   ����Ҫ�����������鳤�ȵ���ż�Ե����⣬�ͳ����鷳�ɣ������һ����������λ�����ǲ�����top-kth��������
 *   ������������ô���ǾͲ�֪���ˡ�
 * 2.�ٷ������ַ����Ƚ����������е�k/2-1λ�õ�Ԫ�ش�С��Ȼ������С�ĵĲ��֣�֮�����k�����ˡ�
 *   ����k��ʾ��k�������
 * */
//class Solution {
//public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        int i=0,j=0,m=nums1.size(),n=nums2.size();
//        int k=(m+n-1)/2;//����ƶ��Ĵ���
//        while(k&&i<m&&j<n){
//            if(nums1[i]<=nums2[j])i++;
//            else j++;
//            k--;
//        }
//        while(i<m&&k){
//            i++;//���������1��δ�ƶ���
//            k--;
//        }
//        while(j<n&&k){
//            j++;
//            k--;
//        }
//        //��������ô������ʵ����Ҫ�ܸ��ӵ��ж�
//        if((m+n)%2==0){//�����ż��
//            if(i>=m)return (nums2[j]+nums2[j+1])*1.0/2;
//            else if(j>=n) return (nums1[i]+nums1[i+1])*1.0/2;
//            else return (nums1[i]+nums2[j])*1.0/2;
//        }else{//���ģ�����������������ô�����أ�
//            //���ģ���֪����ô�����ˣ��ҹ��ˡ�
//            if(j>=n)return nums1[i]*1.0;
//            else if(i>=m) return nums2[j]*1.0;
//            else return min(nums1[i],nums2[j])*1.0;
//        }
//    }
//};


//3-24
/*
 * 1.֮ǰ����д��O(m+n)�Ľⷨ����Ȼ��Ϊʵ���Ǻø��ӣ��һ���ûд�����������д���Ǵ�ģ�������
 *   [1,2] [-1,3]�������Ļ���iָ��1��jָ��3��Ȼ���ֻ�ܴ�����������ֱ���ȡ���������԰���������
 * */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int k1=findm(nums1,nums2,0,0,(m+n+1)/2);
        int k2=findm(nums1,nums2,0,0,(m+n+2)/2);
        cout<<k1<<" "<<k2<<endl;
        return (k1+k2)*1.0/2;
    }
    int findm(vector<int>& nums1, vector<int>& nums2,int i,int j,int k){
        if(i>=nums1.size())return nums2[j+k-1];
        if(j>=nums2.size())return nums1[i+k-1];
        if(k==1)return min(nums1[i],nums2[j]);//�����ʲô������
        int idx1=min((int)nums1.size(),i+k/2)-1;//��������ʹ�õĲ����ǣ������һ������k/2��ô��ֱ�ӱȽ����һ��
        //֮ǰgrand�Ľⷨ�ǲ���Ļ���ֱ�Ӻ��Ե���һ�������е�ǰk/2�������Ҿ�����д�ı�Ť��
        //��ô������Ͳ���ֱ��k-k/2�ˣ���Ӧ�ü�ȥ��������Ŀ��
        int idx2=min((int)nums2.size(),j+k/2)-1;
        if(nums1[idx1]<nums2[idx2])//˵��idx1֮ǰ�Ķ����Ժ��Ե�
        	return findm(nums1,nums2,idx1+1,j,k-(idx1-i+1));
            //return findm(nums1,nums2,i+k/2,j,k-k/2);//��Ϊ��������
        else return findm(nums1,nums2,i,idx2+1,k-(idx2-j+1));
        	//return findm(nums1,nums2,i,j+k/2,k-k/2);
    }
};
/*
 * 1.����AC�ˣ��治������grand�ⷨ���ñ�Ť������д������ģ���������Χʱ��ֱ��k��ȥ�����е�����
 * */

//7-12
/*
 * 1.������֮ǰ����û�������⣬��һ����һ��Ҫ�࿴������⣬���ղ�ͬ��˼·�����͸����
 * 2.ת��Ϊ������������ѡ���kС��Ԫ�أ����ö��ֵķ������Ƚ�A[k/2-1]��B[k/2-1]ֱ����ȥ��С�Ĳ��֣�
 *   ��С��ֵ����С�����ֻ��k-2ֵ����ô���ǵ�k-1С�ģ������ǵ�kС�ġ�
 * */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if((m+n)%2)
            return findM(nums1,nums2,0,0,(m+n)/2+1);
        else return (findM(nums1,nums2,0,0,(m+n)/2)+findM(nums1,nums2,0,0,(m+n)/2+1))*1.0/2;
    }
    int findM(vector<int>& nums1, vector<int>& nums2,int idx1,int idx2,int k){
        if(idx1>=nums1.size())return nums2[idx2+k-1];//return nums2[k-1];//���س����ˣ�Ӧ��+idx����
        if(idx2>=nums2.size())return nums1[idx1+k-1];//nums1[k-1];
        if(k==1)return min(nums1[idx1],nums2[idx2]);

        int m=nums1.size(),n=nums2.size();
        int i1=min(idx1+k/2-1,m-1);
        int i2=min(idx2+k/2-1,n-1);
        if(nums1[i1]<=nums2[i2]){
            return findM(nums1,nums2,i1+1,idx2,k-(i1-idx1+1));
        }else return findM(nums1,nums2,idx1,i2+1,k-(i2-idx2+1));
    }
};

//10-1��ϰ
/*
 * 1.��һ��ʮ�ּ��Ĵ���ע����ǣ�Ҫ�ҵ��ǵ�k�������������ܳ���Ϊ������ʱ��Ҫ+1
 *   ż��ʱ�ǵ�(m+n)/2��������+1�������ֵ��
 * */
int main(){
	Solution s;
	vector<int> nums1={1};
	vector<int> nums2={2,3,4,5,6};
	cout<<s.findMedianSortedArrays(nums1, nums2);
    return 0;
}
