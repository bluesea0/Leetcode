#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��16������4:08:15
class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        generate("",n,n);
        return ans;
    }
    void generate(string s,int left,int right){
        if(left>right||left<0||right<0)return;//����������Ч��������ͣ���֦����
        if(left==0&&right==0)ans.push_back(s);
        else{
            generate(s+"(",left-1,right);
            generate(s+")",left,right-1);
        }
    }
};
/*
 * 1.���ݷ�����û�뵽��ô���д�����ˣ��������!
 * */
int main(){

    return 0;
}
