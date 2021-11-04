#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月14日上午10:40:46
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int m=A[0];
        vector<bool> ans(A.size());
        ans[0]=(m==0?true:false);
        for(int i=1;i<A.size();i++){
            m=(m*2+A[i])%5;
            if(m==0)ans[i]=true;
        }
        return ans;
    }
};
/*
 * 1.一开始我以为这个是关于位运算的，但是看了A数组的范围，30000长度，那肯定不能计算出来每次的结果了，不然
 *   2的3万次方，用什么数据结构也保存不了啊，所以就注意到它为什么选择/5呢，就想二进制数中0、5、10、15、20
 *   的表示有没有什么规律，然后我发现是我想多了，没什么规律，所以不会了
 * 2.官方题解整明只用余数计算就可以了，那我不会。
 * */
int main(){

    return 0;
}
