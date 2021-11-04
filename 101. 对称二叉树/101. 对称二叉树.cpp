#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��6��12������2:16:28
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;//corner caseע��Ŷ
        return sysme(root->left,root->right);
    }
    bool sysme(TreeNode*left,TreeNode* right){
        if(!left&&!right)return true;//���߶�Ϊ��
        if(!left||!right) return false;//������һ��Ϊ��
        if(left->val!=right->val)return false;
        return sysme(left->left,right->right)&&sysme(left->right,right->left);
    }
};
/*
 * 1.�ݹ�汾�ܿ��д�����ˣ���ô�����أ�
 * */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        queue<TreeNode*> q;
        if(root->left)q.push(root->left);
        if(root->right)q.push(root->right);
        if(q.size()&1)return false;
        while(!q.empty()){
            TreeNode* t1=q.front();q.pop();
            TreeNode* t2=q.front();q.pop();
            //����ط����жϺ��鷳������ô���ܼ�һ���أ�
            if(t1->val!=t2->val)return false;
            if(t1->left&&t2->right){
                q.push(t1->left);
                q.push(t2->right);
            }else if(!t1->left&&!t2->right){}
            else return false;//����ֻ��һ��Ϊ��
            if(t1->right&&t2->left){
                q.push(t1->right);
                q.push(t2->left);
            }else if(!t1->right&&!t2->left){}
            else return false;
        }
        return true;
    }
};
/*
 * 1.�����汾Ҳ�ܿ�д�����ˣ������е㳤�ˡ�
 * */
//�����ǹٷ����
class Solution {
public:
    bool check(TreeNode *u, TreeNode *v) {
        queue <TreeNode*> q;
        q.push(u); q.push(v);
        while (!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if (!u && !v) continue;//ͨ��������ж�ԭ�����ﻹ����push��ȥ�գ�
            if ((!u || !v) || (u->val != v->val)) return false;

            q.push(u->left);
            q.push(v->right);

            q.push(u->right);
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);//�۰�Ŷ��������ɺ�ţŶ
        //�����ҾͲ����ˣ��Ǻ���push�����еĲ�������������push�������Σ�
    }
};
int main(){

    return 0;
}
