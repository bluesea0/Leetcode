#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��10��29������1:38:47
class Solution {
public:
    vector<int> ans;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    int kthLargest(TreeNode* root, int k) {
        //˼·����������Ϳ����ˡ�
        inorder(root);
        return ans[ans.size()-k];
    }
};
/*
 * 1.֮ǰ�Ľⷨ�������ģ�������ôҪ��Ҫ��������BST���͸о���̫�ã�������һ�ֽⷨ��ѧ���ˡ�
 * */
class Solution1 {
public:
    int k,n=0;
    int kthLargest(TreeNode* root, int k) {
        //˼·����������������У���¼��ǰ���ʵ��ǵڼ����ڵ㣬��kʱ�ͷ��أ��Ͳ���Ҫ�������ö�����
        this->k=k;
        return kth(root);
    }
    int kth(TreeNode* root){//�Ҵ��ˣ��������ص��ǵ�kС�Ľڵ㡣
        //�Ǿ��Ҹ���
        if(!root)return -1;
        int m=kth(root->right);
        if(m!=-1) return m;//����mÿ�η��ض�Ҫ�жϣ������ǻ�������еݹ飬����ֻ�᷵��-1.
        n++;
        if(n==k) return root->val;
        m=kth(root->left);
        if(m!=-1) return m;
        return -1;//����Ҳ�ǲ�֪������ʲô�����Է���-1�ɡ�
    }
};
/*
 * 2.������Կ���������д��ʮ��������
 * 3.���澫��һ�£��������ݳ�Ա��ά��ans
 * */
class Solution2 {
public:
    int k,ans;//�����;�������ࡣ
    int kthLargest(TreeNode* root, int k) {
        //˼·����������������У���¼��ǰ���ʵ��ǵڼ����ڵ㣬��kʱ�ͷ��أ��Ͳ���Ҫ�������ö�����
        this->k=k;
        kth(root);
        return ans;
    }
    void kth(TreeNode* root){
        if(!root)return;
        kth(root->right);
        if(k==0)return;//�Բ���������жϰ����������ж�k�Ƿ�=0������--k�أ�
        if(--k==0){
            ans=root->val;
            return;
        };
        kth(root->left);
    }
};//ʱ�临�Ӷȣ�O(n)�������˻�Ϊ����ʱ���ռ�Ҳ�ǣ���Ϊ�д�СΪO(n)��ջ
//��ϰ�����ͬʱ��һ��230��������ܲ���Ҳ�õ��������츴ϰ��дһ�¡�

//3-23
/*
 * 1.���츴ϰ����ֻ���뵽�������֮����ȡ�Ľ����
 * 2.ע�⵽����BST��������õ��Ľ���ǵ����ģ���BST���������������������Ľ���ǵݼ��ģ������Ļ��������k���
 *   ���֣������ñ���������������α������k���ڱ�����ʱ�����жϷ��ػ�ͦ���ӵġ�
 * */

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        vector<TreeNode*> stk;//��ʼʱΪ�գ��������ڵ����
        int ans;
        while(!stk.empty()||root){//root����!�ȼ���root!=NULL
            while(root){//r��ʾ��ǰ����Ľڵ�
                stk.push_back(root);
                root=root->right;
            }
            root=stk.back();
            stk.pop_back();
            if(--k==0){
                ans=root->val;
                break;
            }
            root=root->left;
        }
        return ans;
    }
};
/*
 * 3.��230��������޸���һ����ջ��˳���ʵ���˵����汾�������ҽڵ㣬�ٸ�������ڵ㣬���Ҹ���
 * */

//6-12
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* cur=root;
        while(cur||!st.empty()){
            while(cur){
                st.push(cur);
                cur=cur->right;//���ģ�ԭ����k��Ľڵ㣬���ǵ�kС�Ľڵ㣬������һ��
            }
            cur=st.top();
            st.pop();
            if(--k==0){
                return cur->val;
            }
            cur=cur->left;
        }
        return 0;
    }
};
/*
 * 1.һ��ʼ���������ˣ���Ϊ�ǵ�kС����ô������������������������ǵ�k����ô�������ӽڵ�����ջ��
 * 2.����ֻ�뵽�˵����汾���ݹ�汾�Ҳ���д��
 * 3.�ݹ�ʱ��Ҫ�ж�k�Ƿ����0��k�����Ա������=ʱ��һֱ����return��
 * */
int main(){

    return 0;
}
