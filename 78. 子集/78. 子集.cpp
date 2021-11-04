#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��6��12������11:12:45
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        sub(nums,path,0);
        return ans;
    }
    void sub(vector<int>&nums,vector<int>& path,int index){
        ans.push_back(path);
        for(int i=index;i<nums.size();i++){
            path.push_back(nums[i]);
            sub(nums,path,i+1);
            path.pop_back();
        }
    }
};
/*
 * 1.���к��Ӽ����������ԵĲ�ͬ�������ǵݹ����ʱȫ�����Ǵ���index+1���Ӽ���i+1��
 *   ����ȫ����Ҫ�жϳ��ȣ��Ӽ�һ����ֱ��push���С�
 * */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //λ����
        vector<vector<int>> ans;
        int m=nums.size();
        int n=pow(2,m);
        for(int i=0;i<n;i++){
            int t=i;
            vector<int> temp;
            for(int j=0;j<m;j++){
                //�ؼ������������ÿ�λ�ȡ���λ��
                if(t&(1<<(m-j-1)))temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
/*
 * 1.λ�����Ҳ̫���˰ɣ�0msAC�ˡ�
 * */
int main(){

    return 0;
}
