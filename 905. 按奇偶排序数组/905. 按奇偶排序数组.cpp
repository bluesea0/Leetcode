#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��25������3:15:37
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        //˼·����λָ�룬һ�α����������б�������
        int i=0,j=A.size()-1;
        while(i<j){
            while(A[i]%2==0&&i<j)i++;
            while(A[j]%2==1&&i<j)j--;
            swap(A[i],A[j]);
        }
        return A;
    }
};
//AC�ˣ�ûʲô���⡣
int main(){

    return 0;
}
