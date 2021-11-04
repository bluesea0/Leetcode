#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月6日下午2:47:43
class Solution {
public:
    string reverseVowels(string s) {
        //思路：双指针分别遍历，交换
        //复杂度:O(n)，O(1)
        int i=0,j=s.size()-1;
        unordered_set st={'a','e','i','o','u','A','E','I','O','U'};//只有小写吗？包括大写吗？
        while(i<j){
            while(i<j&&st.count(s[i])==0)i++;
            while(i<j&&st.count(s[j])==0)j--;
            swap(s[i],s[j]);
            i++;j--;
        }
        return s;
    }
};
/*
 * 1.没什么技术含量。
 * */
int main(){

    return 0;
}
