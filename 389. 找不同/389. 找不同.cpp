#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月18日上午2:27:30
class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.size()==0)return t[0];//return的是char啦，大哥你要注意
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int k=0;
        while(k<s.size()){
            if(s[k]!=t[k])break;
            k++;
        }
        return t[k];
    }
};
//当然我只想到了这个，是回去等通知的解法，看了官方给的三种，真的恍然大悟。
//计数、位运算、ASCII值求和。

//12-18
class Solution1 {
public:
    char findTheDifference(string s, string t) {
        //使用ASCII值
        int sum=0;
        for(auto c:s)
            sum+=c;
        for(auto c:t)
            sum-=c;
        return -sum;//注意这里是负值哦，因为是t多了一个字母
    }
};
class Solution2 {
public:
    char findTheDifference(string s, string t) {
        //位运算
        int ans=0;//直接用int就行
        for(auto c:s)
            ans^=c;
        for(auto c:t)
            ans^=c;
        return ans;
    }
};
int main(){

    return 0;
}
