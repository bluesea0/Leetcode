#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年10月27日下午10:16:02
//首先来一个递归的解法：
class Solution {
public:
   vector<int> ans;
   vector<int> inorderTraversal(TreeNode* root) {
       inorder(root);
       return ans;
   }
   void inorder(TreeNode* root){
       if(!root)return;
       inorder(root->left);
       ans.push_back(root->val);
       inorder(root->right);
   }
};
//那么如何用迭代来实现中序遍历呢。。。
/*
 * 1.先让root入？然后root出，出来之后入right，然后如果left为空，就打印自己，否则就入栈，然后再让left
 *   入栈？但是这样遇到只有左子节点的时候就会死循环。。。我也不知道怎么办了。
 * */

//9-19
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* cur=root;
        vector<int> ans;
        while(!stk.empty()||cur){
            while(cur){
                stk.push(cur);
                cur=cur->left;
            }
            cur=stk.top();
            ans.push_back(cur->val);
            stk.pop();
            cur=cur->right;
        }
        return ans;
    }
};
/*
 * 1.利用栈，先让左节一直入栈，然后弹出首个，取遍历右节点。
 * */
int main(){

    return 0;
}
