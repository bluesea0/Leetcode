#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��14������10:40:46
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int m=A[0];
        vector<bool> ans(A.size());
        ans[0]=(m==0?true:false);
        for(int i=1;i<A.size();i++){
            m=(m*2+A[i])%5;
            if(m==0)ans[i]=true;
        }
        return ans;
    }
};
/*
 * 1.һ��ʼ����Ϊ����ǹ���λ����ģ����ǿ���A����ķ�Χ��30000���ȣ��ǿ϶����ܼ������ÿ�εĽ���ˣ���Ȼ
 *   2��3��η�����ʲô���ݽṹҲ���治�˰������Ծ�ע�⵽��Ϊʲôѡ��/5�أ��������������0��5��10��15��20
 *   �ı�ʾ��û��ʲô���ɣ�Ȼ���ҷ�����������ˣ�ûʲô���ɣ����Բ�����
 * 2.�ٷ��������ֻ����������Ϳ����ˣ����Ҳ��ᡣ
 * */
int main(){

    return 0;
}
