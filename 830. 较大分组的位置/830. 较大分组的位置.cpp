#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��5������10:56:10
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
 * 1.һ��AC�����ǱȽϿ��ĵġ�O(n)���ٷ����Ĵ�Ҳһ��㡣
 * */
int main(){

    return 0;
}
