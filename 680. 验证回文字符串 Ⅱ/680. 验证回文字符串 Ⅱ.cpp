#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月6日下午3:09:23
class Solution {
public:
    bool validPalindrome(string s) {
        //大意了啊，没仔细看题，因为它是easy的，所以就过于自信了啊。
        //在不相等的时候分别去判断减去i和j
        return palin(s,0,s.size()-1,1);
    }
    bool palin(string & s,int fr,int to,int flag){
        while(fr<to){
            if(s[fr]==s[to]){fr++;to--;}
            else if(flag){
                return (palin(s,fr+1,to,0) || palin(s,fr,to-1,0));
            }else return false;
        }
        return true;
    }
};
/*
 * 1.AC了。时间是O(n)，空间？调用了函数O(1)吧。
 *
 *public boolean validPalindrome(String s) {
    for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
        if (s.charAt(i) != s.charAt(j)) {
            return isPalindrome(s, i, j - 1) || isPalindrome(s, i + 1, j);
        }
    }
    return true;
}

private boolean isPalindrome(String s, int i, int j) {
    while (i < j) {
        if (s.charAt(i++) != s.charAt(j--)) {
            return false;
        }
    }
    return true;
}//这个实现比我简洁多了！下次复习！
 * */

//12-22
/*
 * 1.今天复习，害，人家的代码怎么就能写的这么优美呢！优雅代码！
 * */
int main(){

    return 0;
}
