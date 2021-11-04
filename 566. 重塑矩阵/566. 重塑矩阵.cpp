#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��17������1:50:34
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m=nums.size(),n=nums[0].size();
        if(r*c>m*n)return nums;
        vector<vector<int>> res(r,vector<int>(c,0));
        int k=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                res[i][j]=nums[k/n][k%n];//�ؼ��������±�ļ����
                k++;
            }
        }
        return res;
    }
};
/*
 * 1.���ǱȽ�easy����Ŀ��
 * 2.  for (int x = 0; x < m * n; ++x) {
            ans[x / c][x % c] = nums[x / n][x % n];
        }
	�ٷ�����ж����ܵ�����Ҳ���������Ĺ�ϵ�������ӡ�
 * */
int main(){

    return 0;
}
