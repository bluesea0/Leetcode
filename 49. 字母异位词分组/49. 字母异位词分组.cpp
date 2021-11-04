#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月16日下午2:19:07
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;
        for(auto s:strs){
            string cs=s;
            sort(cs.begin(),cs.end());
            um[cs].emplace_back(s);
        }
        vector<vector<string>> ans;
        for(auto u:um){
            ans.emplace_back(u.second);
        }
        return ans;
    }
};//AC了，之前看过解题思路。
//复杂度:O(nklogk),n是字串个数,k是最长串的长度。O(nk).空间分析错了。
//当然也可以使用对字母计数，因为它的输入全都是小写字母
/*
 * 1.https://www.cnblogs.com/grandyang/p/4385822.html 的第二种解法很有意思啊，计数，让它能形成
 *   单独的key。明天写一下。
 * */

//12-17
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;
        for(auto s:strs){
            vector<int> v(26,0);
            string t="";
            for(auto c:s)v[c-'a']++;
            for(int i=0;i<26;i++){
                if(v[i]==0)continue;
                t+=string(1,i+'a')+to_string(v[i]);//天哪这里是i+'a'啊！！！
                //string(5+"a")天哪，这样子什么都没有。。。
                //cout<<5+"a";也什么都没有，int+string没结果？别爱我。。。
            }
            um[t].emplace_back(s);
        }
        vector<vector<string>> ans;
        for(auto u:um)
            ans.emplace_back(u.second);
        return ans;
    }
};//AC了，但是这样有点慢的
int main(){

    return 0;
}
