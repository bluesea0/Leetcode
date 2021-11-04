#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��10��27������9:33:34
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
 * 1.�����ǵݹ�Ľⷨ����Ȼvery���ˡ�AC�ˡ�
 *   ʱ�䣺O(n)������ n �Ƕ������Ľڵ�����ÿһ���ڵ�ǡ�ñ�����һ�Ρ�
 *   O(n)��Ϊ�ݹ������ջ�Ŀ�����ƽ�������ΪO(logn)����������������״��Ϊ O(n)��
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
 * 2.������Ҳ�ܼ򵥰�����������ջ���������ӽڵ��룬�������ӽ���롣
 * 3.���Ӷ�ͬ�ϡ�
 * 4.������Ҫ�ر������Ŀ��ʱ��ȥ����һ�¹ٷ���⣬Ȼ���֡�������Ȼ���и�Morris ������
 * */
int main(){

    return 0;
}
