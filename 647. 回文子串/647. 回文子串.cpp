#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年8月29日上午10:06:21
class Solution {
public:
    int countSubstrings(string s) {
        //中心扩展法，遍历每一个中心点，中心点包括为一个或两个对称
        int ans=0;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<2;j++){//表示扩展的大小，中心为单个或中心为两个
                int l=i,r=i+j;
                while(l>=0&&r<s.size()&&s[l]==s[r]){
                    ans++;
                    l--;
                    r++;
                }
            }
        }
        return ans;
    }
};
int main(){

    return 0;
}
