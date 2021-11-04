#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��10��27������10:16:02
//������һ���ݹ�Ľⷨ��
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
//��ô����õ�����ʵ����������ء�����
/*
 * 1.����root�룿Ȼ��root��������֮����right��Ȼ�����leftΪ�գ��ʹ�ӡ�Լ����������ջ��Ȼ������left
 *   ��ջ��������������ֻ�����ӽڵ��ʱ��ͻ���ѭ����������Ҳ��֪����ô���ˡ�
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
 * 1.����ջ���������һֱ��ջ��Ȼ�󵯳��׸���ȡ�����ҽڵ㡣
 * */
int main(){

    return 0;
}
