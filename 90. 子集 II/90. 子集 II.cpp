#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��6��12������11:35:46
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vis;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vis.resize(nums.size(),0);
        vector<int> path;
        sub(nums,0,path);
        return ans;
    }
    void sub(vector<int>& nums,int index,vector<int>& path){
        ans.push_back(path);
        for(int i=index;i<nums.size();i++){
            if(i>index&&nums[i]==nums[i-1]&&vis[i-1]==0)continue;
            path.push_back(nums[i]);
            vis[i]=1;
            sub(nums,i+1,path);
            vis[i]=0;
            path.pop_back();
        }
    }
};
/*
 * 1.�Ӽ�������������ˮ���������򵥵ģ�
 * 2.�ؼ������ȥ����������Ӽ�ֱ�ӽ���dfs��push��ȥ��
 * 3.�����һ���Ϊ���û�а취��λ�����������أ�û�뵽�ǿ��Եģ�Ҫ��ȡ����ǰλ�Լ�ǰһλ��
 * */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //λ����
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int m=nums.size();
        int n=pow(2,m);
        for(int i=0;i<n;i++){
            int t=i;
            vector<int> temp;
            bool flag=true;//��Ҫͨ������������ж��Ƿ����ظ��ģ��ظ��򲻷���
            for(int j=0;j<m;j++){
                //�ؼ������������ÿ�λ�ȡ���λ��
                if(t&(1<<(m-j-1))){
                    if(j>0&&nums[j]==nums[j-1]&&(t&(1<<(m-j)))==0){//λ����&���ȼ��͡����ж�ʱһ��Ҫע������
                        flag=false;break;//��ǰ�Ѿ��й��ˣ��Ͳ����ٱ�����
                    }
                    temp.push_back(nums[j]);
                }
            }
            if(flag)ans.push_back(temp);
        }
        return ans;
    }
};
int main(){

    return 0;
}
