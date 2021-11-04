#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月6日下午1:54:33
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //其实没什么算法问题，但是怎么写呢？
        vector<vector<int>> ans;
        if(numRows==0) return ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> t(i+1,0);
            t[0]=1;
            for(int i=1;i+1<t.size();i++){
                t[i]=ans.back()[i-1]+ans.back()[i];
            }
            t[i]=1;
            ans.push_back(t);
        }
        return ans;
    }
};
/*
 * 1.AC了。复杂度：O(n^2)，空间为常数1，不需要考虑返回值的空间占用。
 * class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);//直接这样还可以！
        for (int i = 0; i < numRows; ++i) {
            ret[i].resize(i + 1);
            ret[i][0] = ret[i][i] = 1;
            for (int j = 1; j < i; ++j) {//i=0//i=1时都不会进入这个循环
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
        }
        return ret;
    }
};
官方写的才优秀。
 * */

//12-22
/*
 * 1.这次复习我还是会考虑到numRows=1的特殊情况，如果让我写的话，肯定不会写上面这么简洁的，我还是
 *   得复习。
 * */
int main(){

    return 0;
}
