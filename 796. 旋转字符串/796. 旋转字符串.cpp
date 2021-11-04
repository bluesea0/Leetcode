#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月4日下午3:12:12
class Solution {
public:
    bool rotateString(string A, string B) {
        //首先判断长度，有可能长度不相同。
        if(A.size()!=B.size())return false;
        A=A+A;
        return A.find(B)==string::npos?false:true;
    }
};
/*
 * 1.我发现了，如果是旋转的，就有可能是添加原来的，还在哪个地方遇到过相同的手段。
 * */
int main(){

    return 0;
}
