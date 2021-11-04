#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��10��29������2:19:18
//�ý�ָoffer54��Ĵ����޸ģ�ͨ����
class Solution {
public:
    int k,ans;
    int kthSmallest(TreeNode* root, int k) {
        this->k=k;
        kth(root);
        return ans;
    }
    void kth(TreeNode* root){
        if(!root)return;
        kth(root->left);
        if(k==0)return;//�Բ���������жϰ����������ж�k�Ƿ�=0������--k�أ�
        if(--k==0){
            ans=root->val;
            return;
        };
        kth(root->right);
    }
};
/*
 * 1.https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/solution/er-cha-sou-suo-shu-zhong-di-kxiao-de-yuan-su-by-le/
 *  �ٷ�д�ĵ����İ汾�治��ѧ���ˡ�ʱ�临�Ӷ�Ҳѧ���ˡ���ʱ�临�Ӷ�������е����ʡ�
 * */
//����дһ�µ����汾��


//3-23
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode *t��
        while(!st.empty()){
            t=st.top();
            while(t->left){
                st.push(t->left);
                t=t->left;
            }//�������Ѿ�Ϊ����
            k--;st.pop();
            t=t->right;
            //�����Ѿ����ˣ��Ҳ����ˡ�
        }
    }
};
/*
 * 1.������o54д��һ�µݹ�汾�ģ��պ�«��ư��
 * */
//class Solution {
//public:
//    int kthSmallest(TreeNode* root, int k) {
//        vector<TreeNode*> stk;
//        int ans;
//        stk.push_back(root);
//        TreeNode* r=stk.back();
//        while(!stk.empty()){
//            while(r->left){//����������������ƵĻ�����һֱ����������
//            //��ôдwhile���ǲ��ԣ�������ж�left�ͻ�һֱ��ͣ�ط�������
//                stk.push_back(r->left);
//                r=r->left;
//            }
//            r=stk.back();
//            stk.pop();
//            if(--k==0){
//                ans=r->val;
//                break;
//            }
//            if(r->right){
//                r=r->right;
//                stk.push_back(r);
//            }
//            //if(r->right)stk.push_back(r->right);//����������
//        }
//        return ans;
//    }
//};
/*
 * 2.�����ǵ����汾���и���������д�Ĳ��ԣ������⣬������Ҫ��ϰһ�£���סģ����ôд�ġ�
 * */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> stk;//��ʼʱΪ�գ��������ڵ㲻����
        int ans;
        while(!stk.empty()||root){//root����!�ȼ���root!=NULL
            while(root){//r��ʾ��ǰ����Ľڵ�
                stk.push_back(root);
                root=root->left;
            }
            root=stk.back();
            stk.pop_back();
            if(--k==0){
                ans=root->val;
                break;
            }
            root=root->right;//����ֱ��=�������ж��Ƿ�Ϊ�գ�����ǿյĻ����Ͳ���ȥ�ٴ���������ʼ�����ˡ�
        }//�����Ҫ���µ�����԰�Ķ����������У�3.25��֮��
        return ans;
    }
};

//6-12
lass Solution {
public:
    int k,ans;
    int kthSmallest(TreeNode* root, int k) {
        this->k=k;
        kth(root);
        return ans;
    }
    void kth(TreeNode* root){
        if(!root)return;
        kth(root->left);
        if(this->k==0)return;
        if(--k==0){
            this->ans=root->val;
            return;
        }
        kth(root->right);
    }
};
/*
 * 1.����o54��֮������ģ�ѧϰ�˵����汾���д��
 * */
int main(){

    return 0;
}
