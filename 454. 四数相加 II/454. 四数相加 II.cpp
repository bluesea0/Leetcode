#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年10月17日上午1:19:53
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
                    ans+=mp[-(C[i]+D[j])];//因为计算的是总数目
        }
        return ans;
    }
};
/*
 * 1.一开始没想通为什么要AB数组建立和，因为有可能出现减法？但是发现题目是四数之和，所以可以建立哈希表。
 * */
int main(){

    return 0;
}
