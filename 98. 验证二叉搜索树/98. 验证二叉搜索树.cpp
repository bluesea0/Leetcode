#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��10��11������10:19:14
class Solution {
public:
    bool helper(TreeNode* root,long long left_lower,long long right_lower){
        if(root==nullptr)return true;
        if(root->val<=left_lower||root->val>=right_lower){
            return false;//��ǰroot��ֵӦ������left��right֮���
        }
        return helper(root->left,left_lower,root->val)&&helper(root->right,root->val,right_lower);
    }
    bool isValidBST(TreeNode* root) {
        //���õݹ�ķ�ʽ���
        //���ÿ��������root����֤���������ӽڵ�ֵ<��ǰ���������ӽڵ�ֵ>��ǰ
        //�ݹ��ж�
        return helper(root,LONG_MIN,LONG_MAX);//����Ҫ��long���жϣ���Ϊ�п��ܽڵ��д�������С��
        //�Ǹ�ֵ��
    }
};
/*
 * 1.����Է���ʱ�򿴵ģ�һ��ʼû���뵽����ⷨ�����ȥ�ж������������нڵ�ֵ��С�ڵ�ǰ�أ�
 *   �Լ�����������жϣ����Ǵ�������ġ�����ĵݹ���������档
 * 2.�����õ����ķ�ʽ�����һ�¡�
 * */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* cur=root;
        long long pre=LONG_MIN;
        while(!stk.empty()||cur!=nullptr){
            while(cur){
                stk.push(cur);
                cur=cur->left;
            }
            cur=stk.top();
            stk.pop();
            if(cur->val<=pre)return false;//��Ҫ�Ǻ�֮ǰ�Ƚϣ����<=�Ļ�����ô��false��
            pre=cur->val;
            cur=cur->right;
        }
        return true;
    }
};
int main(){

    return 0;
}
