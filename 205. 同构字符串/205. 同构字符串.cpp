#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月27日下午4:45:54
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //直接思想是用哈希
        unordered_map<char,char> mp;
        unordered_set<char> st;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])==0&&st.count(t[i])==0){//映射为相同的数
                mp[s[i]]=t[i];//卧槽这个逻辑还真挺复杂的啊
                st.insert(t[i]);
            }
            //有问题了，对样例ab aa，就会产生a和b都映射为a的情况。。这可咋整啊
            //也就是会产生多个不同的字母映射为同一个字母的情况
            else if(mp.count(s[i])!=0&&mp[s[i]]==t[i])continue;
            else if(mp.count(s[i])!=0&&mp[s[i]]!=t[i]||st.count(t[i])!=0) return false;
        }
        return true;
    }
};
//居然AC了，其实我也不太确定的，真的有点难度。
/*
 * 1.需要字母之间存在双射的关系，官方给的解是维护两张哈希表，太有道理了啊！
 *
 * */
int main(){

    return 0;
}
