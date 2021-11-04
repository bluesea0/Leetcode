#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��10��10������11:20:29
//class Solution {
//public:
//    int findLength(vector<int>& nums1, vector<int>& nums2) {
//        int m=nums1.size(),n=nums2.size();
//        int maxL=0;
//        for(int i=0;i<m;i++){
//            int k=i;
//            bool flag=false;
//            for(int j=0;j<n;j++){
//                if(k<m&&nums1[k]==nums2[j]){
//                    k++;
//                    flag=true;
//                }
//                else if(flag)break;
//            }
//            maxL=max(maxL,k-i);
//        }
//        return maxL;
//    }
//};
/*
[0,0,0,0,0,0,1,0,0,0]
[0,0,0,0,0,0,0,1,0,0]
���6������9
�Ҳ�֪����Ϊʲô���Ҳ��ᡣ
����Ĳ�֪����ô�޸ģ������
1.���˹ٷ���dp��Ⳣ��дһ�¡�
*/
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //dp[i][j]��ʾnums1[i,:]��nums2[j,:]��֮���������鳤��
        //��ô����״̬��ʽΪdp[i][j]=dp[i+1][j+1]+1 ���nums1[i]==nums2[j]
        //������0.���ս���洢��dp[0][0]�С����ԣ���һ������һ���Ǵ�0��ʼ�ġ�
        //��Ϊ������Ҫ�õ������״̬�����Ե������
        int m=nums1.size(),n=nums2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int ans=0;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(nums1[i]==nums2[j])dp[i][j]=dp[i+1][j+1]+1;
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
/*
 * 1.Ҳ��΢�����˵����⣬��Ϊdp[0][0]�ǽ����������Ͷ�dp����Ĵ洢��������ƫ�
 *   �ǰ���i��j���ڵģ�����Ϊ���������顣����дһ�»������ڵ�д����
 * */

//10-11
class Solution {
public:
    int helper(vector<int>& nums1, vector<int>& nums2,int ind1,int ind2){
        int m=nums1.size(),n=nums2.size();
        int k=0,ret=0;
        for(int i=0;i+ind1<m&&i+ind2<n;i++){
            if(nums1[i+ind1]==nums2[i+ind2])
                k++;
            else k=0;
            ret=max(ret,k);
        }
        return ret;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //�������ڵĽⷨ
        //����A
        int m=nums1.size(),n=nums2.size();
        int temp=0,ans=0;
        for(int i=0;i<m;i++){
            temp=helper(nums1,nums2,i,0);
            ans=max(ans,temp);
        }
        for(int i=0;i<n;i++){
            temp=helper(nums1,nums2,0,i);
             ans=max(ans,temp);
        }
        return ans;
    }
};
/*
 * 1.д��ʱ���Ȼ������Щ���⡣
 * */
int main(){

    return 0;
}
