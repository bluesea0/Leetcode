#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-16 剑指offer第15题
class Solution {
public:
    //循环判断时间复杂度为O(logn)
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n){
            if(n%2==1)
                ans++;//可以换为ans+=(n&1)//表示的是末位是否是1.
            n/=2;//n&=(n-1)
        }
        return ans;
    }
};
/*
1.以上就AC了啊，难道还有什么问题吗？或者是n=n>>1.
2.总的来说没什么难度，不值当复习。不对刚刚说的话太自大了，看了一下解法，确实有知识点。
3.n&=n-1，这个就是从二进制的视角来看的了，就专门处理二进制的问题。
*/
//10-19
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n){//这样更快了。
            ans++;
            n&=n-1;
        }
        return ans;
    }
};
int main(){
    Solution s;
    cout<<s.hammingWeight(11);
    return 0;
}
