#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��5��22������8:18:48
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	if(matrix.empty())return false;//��ָoffer04�⣬��Χ������0������Ҫ������жϡ�
        int m=matrix.size(),n=matrix[0].size();
        int i=0,j=n-1;
        while(i<m&&j>=0){
            if(target>matrix[i][j])
                i++;
            else if(target<matrix[i][j])
                j--;
            else return true;
        }
        return false;
    }
};
/*
 * 1.ע��matrix�������������Ƿ�Ϊ�ա�
 * */
int main(){

    return 0;
}
