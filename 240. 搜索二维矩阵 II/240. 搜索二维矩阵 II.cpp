#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年5月22日上午8:18:48
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	if(matrix.empty())return false;//剑指offer04题，范围包含了0所以需要这里的判断。
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
 * 1.注意matrix的限制条件，是否为空。
 * */
int main(){

    return 0;
}
