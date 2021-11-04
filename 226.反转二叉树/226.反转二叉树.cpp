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
            TreeNode* top=q.front();q.pop();//�������ӽڵ����ʱ���佻����
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
    TreeNode* invertTree(TreeNode* root) {//�Ƚϼ����ⲻ��
        if(!root) return root;
        TreeNode* left=invertTree(root->left);//һ��Ҫ������ʱ������������ý���������ȥ�������Ӷ��������
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
