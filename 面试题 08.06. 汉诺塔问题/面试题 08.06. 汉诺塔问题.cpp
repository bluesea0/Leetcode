#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��9��21������11:28:46
class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        //�ֽ�ΪС���⣬��A��n-1����C���Ƶ�B�ϣ��ٽ�A�����һ���Ƶ�C�ϣ�
        //�������ǽ�B��n-1����A�Ƶ�C�ϡ�
        //ţ�����󳹴���
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
