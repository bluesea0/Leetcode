#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月19日下午3:20:05
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //思路：先转置，后对每行reverse
        for(int i=0;i<matrix.size();i++)
            for(int j=i+1;j<matrix[0].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        for(int i=0;i<matrix.size();i++)
            reverse(matrix[i].begin(),matrix[i].end());//天哪，我还从来没有在cpp中用过反转函数
    }
};//时间复杂度:O(n^2)

//7-12
//原地根据下标反转
/*
 * 1.主要有两个难点，一是原地反转的坐标旋转公式，一是需要枚举的范围。
 * 2.相比之下觉得第二个点更难。
 * 首先根据公式matrix[j][n-i-1]=matrix[i][j]，推导出四个位置变换的公式
 * matrix[][]=matrix[j][n-i-1]代入第一式得到最终放的位置是matrix[n-i-1][n-j-1]
 * matrix[][]=matrix[n-i-1][n-j-1]代入第一式matrix[n-j-1][i]
 * matrix[][]=matrix[n-j-1][i]代入第一式matrix[i][j]
 * 所以再倒序赋值，使用temp存储最开始的matrix[i][j]
 * 最终的公式：
 *   matrix[j][n-i-1]=matrix[i][j]
 *   matrix[n-i-1][n-j-1]=matrix[j][n-i-1]
 *   matrix[n-j-1][i]=matrix[n-i-1][n-j-1]
 *   matrix[i][j]=matrix[n-j-1][i]
 * */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-i-1;j++){//我不理解这里为什么要用这个，难道说是只反转差不多1/4的位置就行？
                int temp=matrix[i][j];//因为每次操作4个数？
                matrix[i][j]=matrix[n-j-1][i];
                matrix[n-j-1][i]=matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1]=matrix[j][n-i-1];
                matrix[j][n-i-1]=temp;
            }
        }
    }
};
/*
 * 1.公式我能会推导，但是这个枚举的位置实在是太难了，我不理解，如果遇到，只能是碰钉子了。
 *   肯定是临时想不起来，关键的点就是只遍历右上角的1/4就行，j从i开始，j是列数限制。
 * */
int main(){

    return 0;
}
