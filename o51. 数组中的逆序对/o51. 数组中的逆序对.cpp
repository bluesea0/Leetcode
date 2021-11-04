#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��6��12������12:17:59
class Solution {
public:
    int ans;
    int reversePairs(vector<int>& nums) {
        //���ù鲢����
        ans=0;
        if(nums.empty()||nums.size()==1)return ans;
        mergeSort(nums,0,nums.size()-1);
        return ans;
    }
    void mergeSort(vector<int>& nums,int left,int right){
        if(left<right){
            int mid=left+((right-left)>>1);
            mergeSort(nums,left,mid);
            mergeSort(nums,mid+1,right);
            merge(nums,left,mid,right);
        }
    }
    void merge(vector<int>& nums,int left,int mid,int right){
        int i=left,j=mid+1;
        vector<int> temp;
        while(i<=mid&&j<=right){
            if(nums[i]>=nums[j]){
//                ans+=(j-mid);
//                if(nums[i]==nums[j])ans--;//�ҿ��ˣ��Ҿ���д��û���Ⱑ
            	ans+=(j-mid-1);//����i���������Ĺ���
                temp.push_back(nums[j++]);
            }else temp.push_back(nums[i++]);
        }
        while(i<=mid){
        	temp.push_back(nums[i++]);
        	ans+=(j-mid-1);//����i���������Ĺ���
        }
        while(j<=right)temp.push_back(nums[j++]);
//        for(int i=0;i<(int)temp.size();i++){
//            nums[left+i]=temp[i];
//        }
//        cout<<ans<<" ans ";
//        for(auto& t:temp)
//        	cout<<t<<" ";
//        cout<<"\n";
        copy(temp.begin(),temp.end(),nums.begin()+left);//ֱ��copy����
    }
};
/*
 * 1.������ǵ�ǰi���>j�Ļ�����ô���ƶ�j������ӣ����Ǻ�������һ�����⣬�ƶ����jҲ��Ȼ�п���С��i��ô��ʱ
 *   ����ٴμ���ͻ��ظ��ģ�ȷʵ�������ҵ������ƶ������ǲ���ȷ�ġ�
 * 2.���i<=j��ôj��һֱ�����ƶ�����ôi�������ƶ��Ƚ��Ƿ�>j������ڣ�˵������j֮ǰ����������ֱ����ӣ�
 *   ���ԣ��һ����۲���������ĺø��Ӱ���
 * 3.��ȷ˼·�����ƶ�i��ʱ����Ҫ���������������Ĺ��ף���ô����j-mid-1����Ȼ������j����ÿ���ƶ�i��ʱ��
 *   �ͼ��������ԵĹ��ף���Ȼ���ƶ�j��ʱ��Ҳ���Լ��������ԵĹ��ף�inv_count+=(mid-i+1);
 * */

//7-15
/*
 * 1.����1�����ٴθ�ϰ����������ͬ�������⣬�����ڸ�������Ե�ansʱ����Ļ���ans+=(j-mid)��
 *  �����������7 8 ��4 5���ͻ�����ظ���������⣬jָ��4�ƶ�ʱ������һ��4��jָ��5�ƶ�ʱ�ּ�����һ��4�Ĺ���
 *  ���յĽ����ans=3�������ļ���������׵ġ�
 * 2.�ؼ��ĵ��ǣ�j���<i����ôjҪ����˳��Ĳ����ˣ��ͼ�����������ԵĹ��ף���Ȼi��λ��>j����ôi��i֮���λ��
 *   ����>j������ȫ��ͳ�ơ��������ַ�������Ļ���������� 4 5 6 ��1 2 3�����ģ�iû�б����꣬��ȥwhile֮��
 *   ��Ҫ�ٱ���i���룬��ʱҲ���ö���ļ��㡣��Ϊ֮ǰ�ƶ�j��ʱ���Ѿ���ȫ������ˣ����Ը������н����
 * 3.����д�ˣ��ǳ�˿����
 * */
class Solution {
public:
    int ans;
    int reversePairs(vector<int>& nums) {
        //����дһ�£���Ϊֻд��һ�Σ���̫��Ϥ��
        //�ܶԹ鲢�����е�־�
        if(nums.size()<=1)return 0;
        ans=0;
        mergeSort(nums,0,nums.size()-1);
        return ans;
    }
    void mergeSort(vector<int>& nums,int left,int right){
        if(left<right){
            int mid=left+((right-left)>>1);
            mergeSort(nums,left,mid);
            mergeSort(nums,mid+1,right);
            merge(nums,left,mid,right);
        }
    }
    void merge(vector<int>& nums,int left,int mid,int right){
        int i=left,j=mid+1;
        vector<int> temp;
        while(i<=mid&&j<=right){
            if(nums[i]<=nums[j])
                temp.push_back(nums[i++]);
            else{
                ans+=(mid-i+1);
                temp.push_back(nums[j++]);
            }
        }
        while(i<=mid)temp.push_back(nums[i++]);
        while(j<=right)temp.push_back(nums[j++]);
        for(int i=left;i<=right;i++)
            nums[i]=temp[i-left];
    }
};
int main(){
	Solution s;
	vector<int> nums={1,3,2,3,1};
	s.reversePairs(nums);
    return 0;
}
