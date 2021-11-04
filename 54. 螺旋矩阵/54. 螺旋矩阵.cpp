#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年5月22日下午3:42:52
//class Solution {
//public:
//    vector<int> spiralOrder(vector<vector<int>>& matrix) {
//        if(matrix.empty()) return {};
//        int top=0,left=0,right=matrix[0].size()-1,bottom=matrix.size()-1;
//        vector<int> ans;
//        while(top<=bottom&&left<=right){
//            for(int i=left;i<=right;i++)
//                ans.push_back(matrix[top][i]);
//            top++;
//            for(int i=top;i<=bottom;i++)
//                ans.push_back(matrix[i][right]);
//            right--;
//            for(int i=right;i>=left;i--)
//                ans.push_back(matrix[bottom][i]);
//            bottom--;
//            for(int i=bottom;i>=top;i--)
//                ans.push_back(matrix[i][left]);
//            left++;
//        }
//        return ans;
//    }
//};
/*
 * 1.但是针对这个就出现了问题[[1,2,3,4],[5,6,7,8],[9,10,11,12]]，打印了[1,2,3,4,8,12,11,10,9,5,6,7,6]
 *   最后多打印了一个6，是因为第三个for循环，left和right的地方，重复打印了，已经在第一个for循环哪里打印过了
 *   所以怎么解决呢？多个判断？但又要在哪里判断呢？
 * 2.我忽然懂了，最好的判断条件是什么呢？就是根据节点的总数来？但是我这个不行，我是for循环来的。
 * */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        int top=0,left=0,right=matrix[0].size()-1,bottom=matrix.size()-1;
        vector<int> ans;
        while(top<=bottom&&left<=right){
            for(int i=left;i<=right;i++)
                ans.push_back(matrix[top][i]);
            top++;
            for(int i=top;i<=bottom;i++)
                ans.push_back(matrix[i][right]);
            right--;
            for(int i=right;i>=left&&top<=bottom;i--)//加上&后面的判断可以避免
            //3行4列的重复打印[1,2]位置的数
                ans.push_back(matrix[bottom][i]);
            bottom--;
            for(int i=bottom;i>=top&&left<=right;i--)//加这个我以为是4行3列的那种，
            //遍历到最后的时候top==bottom，但是left<right的，left和right已经负责打印过了，
            //从它那个方向过来已经打印过了，所以不能重复打印的。
                ans.push_back(matrix[i][left]);
            left++;
        }
        return ans;
    }
};
/*
 * 1.上面是参照评论区中给出的代码，然后我看很多题解都是下面这样的解法。
 * */
//从评论区复制的
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        if (matrix.empty()) return {};
        vector<int> res;
        int l = 0;                      //左边界
        int r = matrix[0].size() - 1;   //右边界
        int t = 0;                      //上边界
        int b = matrix.size() - 1;      //下边界
        while (true)//这里使用无限循环
        {
            //left -> right
            for (int i = l; i <= r; i++) res.push_back(matrix[t][i]);
            if (++t > b) break;//其实一旦有一个队互相错过了，那么就表示已经打印完了。
            //top -> bottom
            for (int i = t; i <= b; i++) res.push_back(matrix[i][r]);
            if (--r < l) break;
            //right -> left
            for (int i = r; i >= l; i--) res.push_back(matrix[b][i]);
            if (--b < t) break;
            //bottom -> top
            for (int i = b; i >= t; i--) res.push_back(matrix[i][l]);
            if (++l > r) break;
        }
        return res;
    }
};
int main(){

    return 0;
}
