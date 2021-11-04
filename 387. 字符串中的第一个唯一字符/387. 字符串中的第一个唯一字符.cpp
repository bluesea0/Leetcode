#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月23日下午3:36:02
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> occ(26,0);
        for(auto c:s)
            occ[c-'a']++;
        for(int i=0;i<s.size();i++){
            if(occ[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};//感觉这个没有什么特别的。面试肯定也不会有这样的题目吧。

int main(){

    return 0;
}
