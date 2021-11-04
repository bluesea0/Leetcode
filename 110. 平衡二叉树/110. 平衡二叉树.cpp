#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年3月23日下午5:34:37
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        //需要一个递归函数计算返回子树的高度
        //这个循环的嵌套让我有点懵了
        return balance(root)>=0;
    }
    int balance(TreeNode* root){
        if(!root)return 0;
        int left=balance(root->left);
        int right=balance(root->right);
        if(left==-1||right==-1||abs(left-right)>1)
            return -1;
        return max(left,right)+1;
    }
};
/*
 * 1.这道题完全不是easy级别的我认为，一开始我完全搞不清思路，因为不确定函数要返回什么，肯定要有一个函数返回
 *   子树的高度，但是这里又最后要返回布尔值，我就不懂了。看了解析之后有自顶向下的，会重复计算。
 *   其实我的思路是自底向上地计算子树的高度。
 * */

//6-12
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        //corner case：空树是平衡二叉树吗？

        return balance(root)==-1?false:true;
    }
    int balance(TreeNode* root){
        if(!root)return 0;
        int left=balance(root->left);
        int right=balance(root->right);
        if(left==-1||right==-1||abs(right-left)>1)return -1;//左右子数其中有一个不平衡
        return max(left,right)+1;
    }
};
/*
 * 1.和之前写的一样，问题不大。
 * */
int main(){

    return 0;
}
