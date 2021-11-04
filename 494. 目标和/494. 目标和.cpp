#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<numeric>
using namespace std;
//2021��2��18������10:31:08
//class Solution {
//public:
//    int findTargetSumWays(vector<int>& nums, int S) {
//        //����01�������⣬״̬����������ѡ[0,i]������ܷ񹹳ɺ�S
//        //��Ҳ��֪���������ף�����������
//        //��ʵ�����뵽����dfs���������Ǵ�0-1�������ģ�����dfs�϶�����Ҫдһ����
//
//        //dp����ĺ��壺dp[i][j]=��ʾǰi��������ɺ�Ϊj�ķ�����������ͨ�˰�ͨ��
//        //�����ڵ�ѡ����ѡ��ѡ������Ҫѡ���������Ǹ�Ҫ��ѡ��
//        int m=nums.size();
//        if(S<0)S=-S;
//        vector<vector<int>> dp(m,S+1);
//        //base case��ʲô��
//        //S�Ǹ�������ת��Ϊ����
//        //��������ʱ���һֱ����ֵ���ţ��Ϳ϶��������и���
//    }
//};

//2-18
//class Solution {
//public:
//    int findTargetSumWays(vector<int>& nums, int S) {
//        //��ʼ����ĺͲ�����1000����ô��Ӧ�ĸ�ֵҲ����С��-1000�����Բ��������±�+1000
//        //������һ��2000�����飬��1000��Ϊԭ��
//        int m=nums.size(),n=abs(S);
//        vector<vector<int>> dp(m,vector<int>(2001,0));//���ԣ���������̣�Ҳ�п���
//        //���ֺͻᳬ��S�����Ի��ǵù̶���1000
//        dp[0][n-nums[i]]=1;
//        dp[0][n+nums[i]]=1;
//        for(int i=1;i<m;i++){//������Ʒ
//            for(int j=n;j<n*2+1;j++){//��������,���ƶ����±�Ϊ0��ʼ��
//                dp[i][j]=dp[i-1][j-nums[i]]+dp[i-1][j+nums[i]];
//            }
//        }
//        return dp[m-1][1000+S];
//    }
//};
/*
 * 1.��������˼·�һ���ûд��ȥ���ٷ����д�Ĳ��ã���һ�����д�úã���������˼·����һ�¡�
 * 2.�����AC�ˣ����治���װ���̫���ˡ�
 * */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n=accumulate(nums.begin(),nums.end(),0);
        if(abs(S)>n)return 0;
        int m=nums.size();
        //���S�Ǹ�ֵ�Ļ�����ô����˭�أ�
        vector<vector<int>> dp(m,vector<int>(2*n+1,0));
        dp[0][n+nums[0]]=1;//���൱�����еĺͣ��±꣩������ƽ����nλ�Ա�֤�±��ǷǸ�ֵ
        dp[0][n-nums[0]]+=1;//�������Ǹ��ӣ����nums[0]=0�Ļ�����ô����Ҫ���ϵģ�
        for(int i=1;i<m;i++){//i��ʾ������Ʒ
            for(int j=0;j<2*n+1;j++){//j��ʾ���Ǻͣ�Ҳ���Ǳ�������
                if(j-nums[i]>=0&&j-nums[i]<=2*n)
                    dp[i][j]+=dp[i-1][j-nums[i]];
                if(j+nums[i]>=0&&j+nums[i]<=2*n)
                    dp[i][j]+=dp[i-1][j+nums[i]];
            }
        }
//        for(int i=0;i<m;i++){
//        	for(int j=0;j<2*n+1;j++){
//        		cout<<dp[i][j]<<" ";
//        	}
//        	cout<<endl;
//        }
        return dp[m-1][n+S];
    }
};
//�����ǽ��пռ��Ż���
class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n=accumulate(nums.begin(),nums.end(),0);
        if(abs(S)>n)return 0;
        int m=nums.size();
        //���S�Ǹ�ֵ�Ļ�����ô����˭�أ�
        vector<int> dp(2*n+1,0);
        dp[n+nums[0]]=1;//���൱�����еĺͣ��±꣩������ƽ����nλ�Ա�֤�±��ǷǸ�ֵ
        dp[n-nums[0]]+=1;//�������Ǹ��ӣ����nums[0]=0�Ļ�����ô����Ҫ���ϵģ�
        for(int i=1;i<m;i++){//i��ʾ������Ʒ
            vector<int> temp(2*n+1,0);//����Ҫ��ʼ��һ��ȫ�µģ�
            for(int j=0;j<2*n+1;j++){//j��ʾ���Ǻͣ�Ҳ���Ǳ�������
                if(j-nums[i]>=0&&j-nums[i]<=2*n)
                    temp[j]+=dp[j-nums[i]];
                if(j+nums[i]>=0&&j+nums[i]<=2*n)
                    temp[j]+=dp[j+nums[i]];
            }
            dp=temp;
        }
        return dp[n+S];
    }
};
/*
 * 1.�Ż�֮��Ŀӣ�tempҪ��ʼ��Ϊȫ0�ģ������Ǹ�ֵΪdp��
 * */
//dfs��
class Solution�� {
public:
    int ans=0;
    int findTargetSumWays(vector<int>& nums, int S) {
        //дһ��dfs+�������飬grand���˼������飬�������Ǹ��ṹ�ø��ӣ����Ȳ�����
        //���ذ汾��dfs��AC�ˣ�����������
        dfs(nums,S,0,0);
        return ans;
    }
    void dfs(vector<int>& nums,int S,int index,int sums){
        if(index==nums.size()){
            if(sums==S)
                ans++;
            return;
        }
        dfs(nums,S,index+1,sums-nums[index]);
        dfs(nums,S,index+1,sums+nums[index]);
    }
};
int main(){
	Solution s;
	vector<int> nums={0,0,0,0,0,0,0,0,1};
	cout<<s.findTargetSumWays(nums, 1);
    return 0;
}
