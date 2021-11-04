#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��17������2:22:23
//class Solution {
//public:
//    bool canPartition(vector<int>& nums) {
//        sort(nums.begin(),nums.end());
//        int left=0,right=nums.size()-1;
//        int sums=accumulate(nums.begin(),nums.end(),0);
//        while(left<right){
//            //���ĺ�Ȼ�о��������У���Ϊ���
//            //[1,5,5,11]�����ǰ��ֿ��ģ�Ӧ���û�������
//            //[1,5,5,9]��������ǻ����϶������ˣ��ƺ�Ӧ����˫ָ�룬�����ҵĽⷨ�Ǵ�İ�
//            //�����Ŀ����ô�ܺͱ�������ǣ�������أ�
//        }
//    }
//};
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //״̬�ǣ�Ԫ�غ�Ŀ��ֵ��0/1����
        //dp[i][j]��ʾǰi��Ԫ���ܷ���ϳɺ�Ϊj���Ӽ�
        if(nums.size()<2)return false;//���ֻ��һ��Ԫ�ػ���û��Ԫ�أ���ô���ֳܷ������Ӽ�
        //������һ���Ӽ�Ϊ�տ�����
        int sums=accumulate(nums.begin(),nums.end(),0);
        if(sums&1)return false;//����������ÿ϶�����
        //�������е����ֵ��������ֵ>sums/2
        int target=sums/2;
        int maxn=nums[0],m=nums.size();
        for(int i=1;i<nums.size();i++)
            maxn=max(maxn,nums[i]);
        if(maxn>target)return false;//��Ϊֻ���������������Բ��ָܷ�Ϊ������
        vector<vector<int>> dp(m,vector<int>(target+1,0));//����Ҫtarget+1�ɣ�
        dp[0][nums[0]]=1;//��ֻ��ѡ��0��Ԫ��ʱ�����γɺ�Ϊnums[0]�ı���
        for(int i=0;i<m;i++)
            dp[i][0]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<=target;j++){
                if(nums[i]<=j){//���Է��µ�ǰԪ�أ���ô�ͷŻ��߲���
                    //�Һ�Ȼ�ֶ����dp����״̬�ĺ���ģ���ˣ���̫����ô���㰡
                    dp[i][j]=dp[i-1][j-nums[i]]||dp[i-1][j];//�Ż��߲���
                }else{//������µ�ǰ��nums[i]���ǿ϶��ᳬj������������
                    dp[i][j]=dp[i-1][j];//ֻ�ܲ���
                }
            }
        }
        return dp[m-1][target];
    }
};
/*
 * 1.AC�ˣ���������ͦ�ѵİ���������дһ��״̬ѹ���ģ���ʡ�ռ��
 * */
class Solution2 {
public:
    bool canPartition(vector<int>& nums) {
        //״̬�ǣ�Ԫ�غ�Ŀ��ֵ��0/1����
        //dp[i][j]��ʾǰi��Ԫ���ܷ���ϳɺ�Ϊj���Ӽ�
        if(nums.size()<2)return false;//���ֻ��һ��Ԫ�ػ���û��Ԫ�أ���ô���ֳܷ������Ӽ�
        //������һ���Ӽ�Ϊ�տ�����
        int sums=accumulate(nums.begin(),nums.end(),0);
        if(sums&1)return false;//����������ÿ϶�����
        //�������е����ֵ��������ֵ>sums/2
        int target=sums/2;
        int maxn=nums[0],m=nums.size();
        for(int i=1;i<nums.size();i++)
            maxn=max(maxn,nums[i]);
        if(maxn>target)return false;//��Ϊֻ���������������Բ��ָܷ�Ϊ������
        vector<int> dp(target+1,0);//����Ҫtarget+1�ɣ�
        dp[0]=1;
        dp[nums[0]]=1;//��ֻ��ѡ��0��Ԫ��ʱ�����γɺ�Ϊnums[0]�ı���
        for(int i=1;i<m;i++){
            for(int j=target;j>=1;j--){
                if(nums[i]<=j){//���Է��µ�ǰԪ�أ���ô�ͷŻ��߲���
                    //�Һ�Ȼ�ֶ����dp����״̬�ĺ���ģ���ˣ���̫����ô���㰡
                    dp[j]=dp[j-nums[i]]||dp[j];//�Ż��߲���
                }
                // else{//������µ�ǰ��nums[i]���ǿ϶��ᳬj������������
                //     dp[j]=dp[j];//�����ֻһ��״̬�Ļ���������Ͳ������˰�
                // }
            }
        }
        return dp[target];
    }
};//�ǳ��øģ�ҲAC�ˡ�

//6-11
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        /*
        ת��Ϊ01�������⣬
        dp[i][j]��ʾǰi�����еĺ��ܷ�==j����������
        dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i]] nums[i]<=j
        base case:
        dp[0][0]=1
        dp[i][0]=0
        */
        if(nums.size()==1)return false;
        int sums=accumulate(nums.begin(),nums.end(),0);
        if(sums%2)return false;
        int maxn=*max_element(nums.begin(),nums.end());//�������Ԫ�ر�target���ǿ϶���ɲ��ˡ�
        if(maxn>sums/2)return false;
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(sums/2+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sums/2;j++){
                //if(nums[i-1]>j)continue;
                if(nums[i-1]>j) dp[i][j]=dp[i-1][j];//ֻ���ǲ��š�
                else dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][sums/2];
    }
};
/*
 * 1.״̬���³��������⣬����Ʒ��������ʱ��ֱ��continue��Ȼ���У��ðɣ�����ȷʵ�ǣ�������Ҫ���µġ�
 * 2��״̬��ʼ��Ҳ�͹ٽⲻһ��������Ϊ��dp[0][j]��ʾֻȡǰ0������Ҳ���ǲ�ȡ����ɿ϶�ֻ��dp[0][0]=1
 *   ������Ϊfalse�������dp[i][0]��ȡǰi������Ϊ0������ΪΪfalse����Ϊ���������������Բ��У����϶�Ҫ
 *   ���졣���������Ҳ��AC�����Ծ��������ɣ��Ҳ�̫���ٽ⣬����Ϊ�ܲ�ȡ��
 * 3.���Խ��пռ��Ż���
 * */
int main(){

    return 0;
}
