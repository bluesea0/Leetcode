#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-16
/*
1.主要的思路是，判断最右边的1是否在最高位？
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;//需要加上这个判断，输入当中会有负例，
        //题目中说的是“给定一个整数”，
        return (n&(n-1))==0;
    }
};
//10-22复习，挺绝的这个。
int main(){
    Solution s;
    cout<<s.isPowerOfTwo(8);
    return 0;
}
