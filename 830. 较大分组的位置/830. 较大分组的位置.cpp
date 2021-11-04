#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月5日上午10:56:10
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        for(int i=0;i<s.size();i++){
            int j=i;
            while(i+1<s.size()&&s[i]==s[i+1])i++;
            if(i-j>=2)ans.push_back({j,i});
        }
        return ans;
    }
};
/*
 * 1.一次AC，还是比较开心的。O(n)，官方给的答案也一般般。
 * */
int main(){

    return 0;
}
