#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年8月29日下午2:59:11
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // if(!root1&&!root2)return nullptr;
        // TreeNode* node=new TreeNode(0);
        // if(root1){
        //     node->val+=root1->val;
        // }
        // if(root2){
        //     node->val+=root2->val;
        // }
        // //我懵了，判断是否为空好麻烦。
        // node->left=mergeTrees(root1->left,root2->left);
        // node->right=mergeTrees(root1->right,root2->right);
        // return node;
        if(!root1&&!root2)return nullptr;
        TreeNode* node=new TreeNode(0);
        if(root1&&root2){
            node->val=root1->val+root2->val;
            node->left=mergeTrees(root1->left,root2->left);
            node->right=mergeTrees(root1->right,root2->right);
        }else if(root1){
            node->val=root1->val;
            node->left=mergeTrees(root1->left,nullptr);
            node->right=mergeTrees(root1->right,nullptr);
        }
        else if(root2){
            node->val=root2->val;
            node->left=mergeTrees(nullptr, root2->left);
            node->right=mergeTrees(nullptr,root2->right);
        }
        return node;
        //左右子树判断好像很复杂，该怎么判断呢？

    }
};
/*
 * 1.AC了，捋逻辑真的好难啊！
 * 2.官方给的题解中，既创建了新的节点，又用到并且改变了原来二叉树中的节点，写的比较简洁，但是我还是
 *   坚持我目前自己的想法吧。
 * */
int main(){

    return 0;
}
