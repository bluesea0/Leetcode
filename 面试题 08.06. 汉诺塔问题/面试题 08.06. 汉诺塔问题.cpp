#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年9月21日下午11:28:46
class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        //分解为小问题，将A的n-1个借C先移到B上，再将A的最后一个移到C上，
        //第三步是将B的n-1个借A移到C上。
        //牛啊！大彻大悟！
        int n=A.size();
        hano(n,A,B,C);
    }
    void hano(int n,vector<int>& A, vector<int>& B, vector<int>& C){
        if(n==1){
            C.push_back(A.back());
            A.pop_back();
            return;
        }
        hano(n-1,A,C,B);
        C.push_back(A.back());
        A.pop_back();
        hano(n-1,B,A,C);
    }
};
int main(){

    return 0;
}
