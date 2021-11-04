#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月1日下午1:32:43
//class Solution {
//public:
//    int rob(TreeNode* root) {
//        //思路：对于一颗子树来说，有两种结果，包含根节点和不包含根节点但是有子节点。
//        //但目前的问题是我不知道怎么实现
//        //应该是要递归着写？递归的过程就返回两种结果？我不会，投降。
//    }
//};
//当然是没有写出来了啊。

//12-3
class Solution {
public:
    unordered_map<TreeNode*,int> f,g;
    int rob(TreeNode* root) {
        //思路：对于一颗子树来说，有两种结果，包含根节点和不包含根节点但是有子节点。
        //但目前的问题是我不知道怎么实现
        //应该是要递归着写？递归的过程就返回两种结果？我不会，投降。
        if(!root) return 0;
        dfs(root);
        return max(f[root],g[root]);
    }
    void dfs(TreeNode* root){
        if(!root) return;
        //我还是不会写，这里如何进行遍历呢？这里的g还是没有的啊，怎么求啊。
        //后根遍历？我跪了。
        //看了题解，果真是后根遍历，我没有想错！
        dfs(root->left);
        dfs(root->right);
        f[root]=root->val+g[root->left]+g[root->right];
        //因为是map，如果没有这个关键字的话，那么直接这样求的就是0？
        g[root]=max(f[root->left],g[root->left])+max(f[root->right],g[root->right]);
        //这里如果root->left或者root->right是否为空的话，None，经过map其实就是0，不必担心。
    }
};
//上面这种解法复杂度都为O(n)，那么下面经过空间优化的，可以发现求root只和左右子节点有关系。
struct Status{//这个是需要在类外定义的。
    int select;
    int notSelect;
};
class Solution {
public:
    unordered_map<TreeNode*,int> f,g;
    int rob(TreeNode* root) {
        if(!root) return 0;
        Status s=dfs(root);
        return max(s.select,s.notSelect);
    }
    Status dfs(TreeNode* root){
        if(!root) return{0,0};
        Status l=dfs(root->left);
        Status r=dfs(root->right);
        Status ret;
        ret.select=root->val+l.notSelect+r.notSelect;
        ret.notSelect=max(l.select,l.notSelect)+max(r.select,r.notSelect);
        return ret;
    }
};
//这样子速度也更加快了。空间复杂度仍是O(n)，是使用的栈空间！

//12-22
/*
 * 1.天哪这次复习也稍微很为难了，还以为是max(root->val,left,right,left+right)呢，完全没有考虑当前
 *   根节点被选中的话，可以左右子节点不选中，而它的递归子树被计算啊！不愧是中等题目啊！下次复习要写
 *   代码。
 * 2.看了grand的解法https://www.cnblogs.com/grandyang/p/5275096.html，原来不必要像是只能建立struct
 *   也可以用vector<int> res(2,0)这样来返回，学到了。
 * */
int main(){

    return 0;
}
