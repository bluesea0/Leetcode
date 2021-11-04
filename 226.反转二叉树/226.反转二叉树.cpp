#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-8
struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        TreeNode* t=root->left;
        root->left=invertTree(root->right);
//        if(cur.left)
       root->right=invertTree(t);
        return root;
    }
};

//10-9

class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode* top=q.front();q.pop();//在左右子节点入队时将其交换。
            TreeNode* t=top->left;
            top->left=top->right;
            top->right=t;
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
        return root;
}};


//5-21
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {//比较简单问题不大，
        if(!root) return root;
        TreeNode* left=invertTree(root->left);//一定要建立临时变量，否则会用交换过的再去交换，从而不变出错
        TreeNode* right=invertTree(root->right);
        root->left=right;
        root->right=left;
        return root;
    }
};
int main()
{

    return 0;
}
