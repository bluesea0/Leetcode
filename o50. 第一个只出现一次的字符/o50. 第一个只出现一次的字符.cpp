#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//10-15
/*
1.我去，easy的题目都这么难？我第一想法是要用hash计数，但是怎么计算呢？
*/
class Solution {
public:
//    char firstUniqChar(string s) {//这种写法是错的啊，人家说的是s中的。。。不是按照字母表的。。
//        vector<int> chars(26);
//        for(auto ss:s){
//            chars[ss-'a']+=1;
//        }
//        for(int i=0;i<chars.size();i++){//这里长度该怎么控制呢？
//            if(chars[i]==1)
//                return i+'a';
//        }
//        return ' ';
//    }
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(auto ss:s)
            mp[ss]+=1;
        for(auto ss:s){
            if(mp[ss]==1)
                return ss;
        }
        return ' ';
    }
};
/*
2.上面的AC了，居然还花了一会工夫。。。
明天复习的时候再看讲解吧。
*/
//10-19
/*
1.看的时候还是懵了一下，可能我是只想通过一次遍历解决，但是这个似乎解决不了。
  看了一下绝缘子的解法，也是这么写的，看来这个简单的题就不必再花功夫了。
*/
int main(){
    Solution s;
    cout<<s.firstUniqChar("leetcode");
    return 0;
}
