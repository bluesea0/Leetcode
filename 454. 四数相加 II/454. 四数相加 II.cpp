#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��10��17������1:19:53
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> mp;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B.size();j++)
                mp[A[i]+B[j]]++;
        }
        int ans=0;
        for(int i=0;i<C.size();i++){
            for(int j=0;j<D.size();j++)
                if(mp.count(-(C[i]+D[j])))
                    ans+=mp[-(C[i]+D[j])];//��Ϊ�����������Ŀ
        }
        return ans;
    }
};
/*
 * 1.һ��ʼû��ͨΪʲôҪAB���齨���ͣ���Ϊ�п��ܳ��ּ��������Ƿ�����Ŀ������֮�ͣ����Կ��Խ�����ϣ��
 * */
int main(){

    return 0;
}
