#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��19������11:21:08
//class Solution {
//public:
//    vector<int> visit;
//    bool canPartitionKSubsets(vector<int>& nums, int k) {
//        int sums=accumulate(nums.begin(),nums.end(),0);
//        if(sums%k)return false;//����ƽ��
//        //������ֵ���������k�Ļ�����ô�϶���������
//        int maxn=nums[0];
//        for(int i=1;i<nums.size();i++)
//            maxn=max(maxn,nums[i]);
//        int target=sums/k;
//        if(maxn>target)return false;
//        //�û��ݵķ���һ��һ������
//        //��ôд���밡���Һ�����Ĳ�̫�ᰡ���ҿ����ˡ�
//        //����˵���ڵ�һ��Ԫ��4����ô�����γ�������������Ԫ����ͣ�
//        //�ǵ���һ��visit���鰡
//        visit.resize(nums.size(),0);
//        return dfs(nums,target,k);//ÿ�ε��ö��ṹ���Ӽ�
//    }
//    bool dfs(vector<int>& nums,int target,int k){
//        if(k===0){//�Ѿ�������k���Ӽ�����Ҫ�ж��Ƿ����е�Ԫ�ض�������������
//            for(int i=0;i<visit.size();i++)
//                if(visit[i]==0)return false;
//            return true;
//        }
//        //���ģ��Ҳ�֪������ôд��ȥ�ˣ���������һ������Ϊ�����ģ�������ô�������أ�
//        for(int i=0;i<nums.size();i++){//����grand�Ľⷨ�����ˣ���start�����һ��������ǰ�ĺ�
//������ʱ������������һ��curSUM��һֱ��������startȥ����֮�����еĿ����ԡ�
//            if()
//        }
//    }
//};
/*
 * 1.�����ǳ��Բ�����������ģ�û��д����������grand�ĳ�ʼд����https://www.cnblogs.com/grandyang/p/7733098.html
 *   ԭ����Ҫ��һ��start�ģ����������ǰ�ĺ�������target����ô�ʹ�ͷ��ʼ����start��grand�Ĵ���д�ĺܺ�
 *   �����ֶ����л�һ�µݹ�����
 *class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        vector<bool> visited(nums.size(), false);
        return helper(nums, k, sum / k, 0, 0, visited);
    }
    bool helper(vector<int>& nums, int k, int target, int start, int curSum, vector<bool>& visited) {
        if (k == 1) return true;
        if (curSum == target) return helper(nums, k - 1, target, 0, 0, visited);
        for (int i = start; i < nums.size(); ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            //����ĵ���start��Ϊ��i+1�����ҵ�ǰ�ĵ㱻true�ˣ��´ξͻ��Զ�������ǰ��ֵ��
            if (helper(nums, k, target, i + 1, curSum + nums[i], visited)) return true;
            visited[i] = false;
        }
        return false;
    }
};//�Ҿ������д�Ļ��Ǻܺõģ�����������һ�¡�
 * */
class Solution {
public:
    vector<int> visit;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sums=accumulate(nums.begin(),nums.end(),0);
        if(sums%k)return false;//����ƽ��
        //������ֵ���������k�Ļ�����ô�϶���������
        // int maxn=nums[0];//����֮��Ļ��Ͳ�������ˣ���ֱ�������һ����
        // for(int i=1;i<nums.size();i++)
        //     maxn=max(maxn,nums[i]);
        sort(nums.begin(),nums.end());
        int target=sums/k;
        if(nums.back()>target)return false;
        //�û��ݵķ���һ��һ������
        //��ôд���밡���Һ�����Ĳ�̫�ᰡ���ҿ����ˡ�
        //����˵���ڵ�һ��Ԫ��4����ô�����γ�������������Ԫ����ͣ�
        //�ǵ���һ��visit���鰡
        while(nums.back()==target){
            nums.pop_back();
            k--;//���Ҳ�ǽ��ͳ�������ʱ���һ���Ż���
        }
        visit.resize(nums.size(),0);
        return dfs(nums,target,k,0,0);//ÿ�ε��ö��ṹ���Ӽ�
    }
    bool dfs(vector<int>& nums,int target,int k,int start,int cur){
        // if(k===0){//�Ѿ�������k���Ӽ�����Ҫ�ж��Ƿ����е�Ԫ�ض�������������
        //     for(int i=0;i<visit.size();i++)
        //         if(visit[i]==0)return false;//������ʵû�в�����û�����ʵ��ģ���Ϊ������ֵ
        //         //�����Ѿ�ȷ����
        //     return true;
        // }
        if(k==1) return true;//������Ŀ�ĸ����������Ϳ���ȷ���������ǰ��1�Ļ����Ϳ϶��н�
        //���ģ��Ҳ�֪������ôд��ȥ�ˣ���������һ������Ϊ�����ģ�������ô�������أ�
        //�ҿ����еĴ����ж��������Ƿŵ������
        if(cur==target) return dfs(nums,target,k-1,0,0);//ȥ�ж���һ��
        if(cur>target) return false;
        for(int i=start;i<nums.size();i++){
            if(visit[i])continue;//����Ѿ������ʹ���
            //if(cur+nums[i]>target)break;//�����ֵ��Խ��Խ��
            visit[i]=1;
            if(dfs(nums,target,k,i+1,cur+nums[i])) return true;
            //bool flag=false;
            //if(cur+nums[i]==target)flag=;//��Ҫ��ʼ������һ���Ӽ�������curֵӦ��Ϊ0�ˣ�ͬʱkֵ-1
            //else flag=dfs(nums,target,k,i+1,cur+nums[i]);
            visit[i]=0;

            //if(flag)return true;
        }
        return false;
    }
};
//��ʱ�ˣ�������ȥ��ͨ����������149/149�����������һ��������
/*
 * 1.AC�ˣ������װ������Ӷ��ǽ׳˼���ģ�ʵ����̫�ѡ�
 *   ���ֻ��ݷ��ľ������ڣ�forѭ����ѡ���ʱ�����ݲ�Ҫ�����ƺ��жϣ�Ҫ�����ŵ�������ͷ�жϣ�
 * 2.��̬�滮�Ľⷨ����������ѧϰ��
 * */
int main(){

    return 0;
}
