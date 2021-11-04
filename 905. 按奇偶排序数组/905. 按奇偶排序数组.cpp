#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月25日下午3:15:37
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        //思路：首位指针，一次遍历，过程中遍历交换
        int i=0,j=A.size()-1;
        while(i<j){
            while(A[i]%2==0&&i<j)i++;
            while(A[j]%2==1&&i<j)j--;
            swap(A[i],A[j]);
        }
        return A;
    }
};
//AC了，没什么问题。
int main(){

    return 0;
}
