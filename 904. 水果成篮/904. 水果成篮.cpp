#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月10日下午4:47:55
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int,int> um;
        int left=0,right=0,ans=0;
        while(right<tree.size()){
            um[tree[right++]]++;
            while(um.size()>2){
                um[tree[left]]--;
                if(um[tree[left]]==0)um.erase(tree[left]);
                left++;
            }
            ans=max(ans,right-left);
        }
        return ans;
    }
};
/*
 * 1.挺简单的，用哈希表来记录个数。
 * */
int main(){

    return 0;
}
