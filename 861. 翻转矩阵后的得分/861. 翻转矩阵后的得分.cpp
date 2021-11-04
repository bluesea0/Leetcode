#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月7日上午11:05:52
//class Solution {
//public:
//    int matrixScore(vector<vector<int>>& A) {
//        //思路：状态+操作，这里的操作是针对某位反转行或者列
//        //状态呢？是遍历每个位置还是说只针对高位？
//        //如果是遍历的话，遍历几次？停止条件又是什么？因为题目说是任意次移动。
//        //太难了太难了。状态数组又是几维的？太难了。
//    }
//};
//看了题解之后，直呼牛牛牛！

//12-21
//再看还是不会，但是这次看了题解之后，彻底明白了。

//12-22
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m=A.size(),n=A[0].size();
        int res=m*1<<(n-1);//第0列所有元素都是1
        for(int j=1;j<n;j++){
            //从第1列开始计算其中1的个数，如果少于0的个数，那么就反转
            int n1=0;
            for(int i=0;i<m;i++){
                if(A[i][0]==1)
                    n1+=A[i][j];
                else n1+=(1-A[i][j]);
            }
            int k=max(n1,m-n1);
            res+=k*(1<<(n-j-1));
        }
        return res;
    }
};//AC了。
int main(){

    return 0;
}
