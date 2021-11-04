#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年6月10日下午2:14:03
class Solution {
public:
    string longestPalindrome(string s) {
        //要分奇偶吗？
        //那么对一个数来判断i-1和i+1的位置是否相同？
        //dp[i]表示以它为中心最多扩展出的回文子串长度
        //但如果这样的想法的话，其实用不到dp的啊。
        //因为每次中心都不一样，所以分开判断就好了。
        int n=s.size(),start=0,len=1;//最短的是自身，所以len初始化为1
        for(int i=1;i<n-1;i++){
            int t=check1(s,i);
            if(t>len){
                len=t;
                start=i-len/2;
            }
        }
        for(int i=0;i<n-1;i++){
            int t=check2(s,i);
            if(t>len){
                len=t;
                start=i-len/2+1;
            }
        }
        return s.substr(start,len);
    }
    int check1(string& s,int index){
        int i=1,n=s.size();
        while(index+i<n&&index-i>=0){
            if(s[index+i]==s[index-i])i++;
            else break;
        }
        return 2*(i-1)+1;
    }
    int check2(string& s,int index){
        int i=0,n=s.size();
        while(index-i>=0&&index+i+1<n){
            if(s[index-i]==s[index+i+1])i++;
            else break;
        }
        return 2*i;
    }
};
/*
 * 1.AC了，但是写的比较繁琐。枚举回文中心，使用中心扩展法。官解地回文扩展法写的很简洁，只写了一个子
 *   函数，奇数时传参，expandAroundCenter(s, i, i);偶数时传参expandAroundCenter(s, i, i+1);
 *   学习了。返回的也是左右边界{}。
 * 2.使用dp的解法：dp[i,j]表示i~j是否是回文串，需要从小到大进行更新。枚举字串长度，枚举起点，更新所有
 *   其实还挺麻烦的哈。空间复杂度更高了。
 * */
int main(){

    return 0;
}
