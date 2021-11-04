#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年10月27日下午9:33:34
class Solution {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        pre(root);
        return ans;
    }
    void pre(TreeNode* root){
        if(!root) return;
        ans.push_back(root->val);
        pre(root->left);
        pre(root->right);
    }
};
/*
 * 1.首先是递归的解法，当然very简单了。AC了。
 *   时间：O(n)，其中 n 是二叉树的节点数。每一个节点恰好被遍历一次。
 *   O(n)，为递归过程中栈的开销，平均情况下为O(logn)，最坏情况下树呈现链状，为 O(n)。
 * */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* t=st.top();st.pop();
            ans.push_back(t->val);
            if(t->right)st.push(t->right);
            if(t->left)st.push(t->left);
        }
        return ans;
    }
};
/*
 * 2.迭代的也很简单啊。就是利用栈，先让右子节点入，再让左子结点入。
 * 3.复杂度同上。
 * 4.当我想要关闭这个题目的时候，去看了一下官方题解，然后发现。。。居然还有个Morris 遍历？
 * */
int main(){

    return 0;
}
