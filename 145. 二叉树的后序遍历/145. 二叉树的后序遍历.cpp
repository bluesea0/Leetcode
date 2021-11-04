#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��10��27������10:36:25
//�ݹ�汾�ҾͲ�д�ˣ�û��Ҫ������ֱ�ӿ�������morris��

//class Solution {
//public:
//   vector<int> postorderTraversal(TreeNode* root) {
//       vector<int> ans
//       stack<TreeNode*> st;
//       TreeNode* node=root;
//       while(node||!st.empty()){
//           while(node->left){
//               st.push(node->left);
//               node=node->left;
//           }
//           while(node->right){//����pushҲ���Եİ���
//               st.push(node->right);
//               node=node->right;
//           }//�����������������ͱ�������3�ˡ����������ĸ����ô���ˡ�
//       }
//   }
//};//��д���������룬д����ȥ�ˣ�û˼·��
//�������Ͽ���˼·��Ȼ������Ծ�д�����������Ѱ���
//����Ҫ����˼����У�ֻ�ǵô��벻�С���ֵǮ��

//����˼·��ǰ������������ң���ôÿ�θ���ջ����������ջ��Ȼ����ڵ����ҽڵ��룬��ô����ʱ��Ϳ���
//�γɸ������ˡ�
//��һ�ֽⷨ��
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> pre,post;
        pre.push(root);
        while(!pre.empty()){
            TreeNode* top=pre.top();pre.pop();//����������ȳ�
            post.push(top);
            if(top->left)pre.push(top->left);//�����룬��ô���
            if(top->right)pre.push(top->right);//�Һ��룬��ô�ȳ���
        }
        while(!post.empty()){
            ans.push_back(post.top()->val);
            post.pop();
        }
        return ans;
    }
};
//����ڶ��ֽⷨҲAC�ˣ�����grand�Ľ���������ඥ����
class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        TreeNode* head=root;//ָ����Ƿ��ʵ�ǰһ���ڵ�
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* top=st.top();
            if(top->left!=NULL && top->left !=head && top->right!=head){
                st.push(top->left);
            }else if(top->right!=NULL && top->right != head){//��Ϊ�ջ������ѱ����ʹ���
                st.push(top->right);
            }else{//��������ӽڵ��Ϊ�գ����߶��ѱ����ʹ�����ô�ͽ���ǰans
                ans.push_back(top->val);
                st.pop();
                head=top;
            }
        }
        return ans;
    }
};
/*
 * 1.����grand����͸����
 * https://www.cnblogs.com/grandyang/p/4251757.html
 * */

//11-17
/*
 * 1.�����ٸ�ϰ���Ѿ��벻���������汾����ôд���ˡ���������벻�����ˡ�
 * 2.���˴��룬����������Ҫ��ջ���洢�ڵ�������������ˡ�
 * 3.˼�����������ֻ�������ֽⷨ��ok��
 * */
int main(){

    return 0;
}
