#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��8��29������2:59:11
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // if(!root1&&!root2)return nullptr;
        // TreeNode* node=new TreeNode(0);
        // if(root1){
        //     node->val+=root1->val;
        // }
        // if(root2){
        //     node->val+=root2->val;
        // }
        // //�����ˣ��ж��Ƿ�Ϊ�պ��鷳��
        // node->left=mergeTrees(root1->left,root2->left);
        // node->right=mergeTrees(root1->right,root2->right);
        // return node;
        if(!root1&&!root2)return nullptr;
        TreeNode* node=new TreeNode(0);
        if(root1&&root2){
            node->val=root1->val+root2->val;
            node->left=mergeTrees(root1->left,root2->left);
            node->right=mergeTrees(root1->right,root2->right);
        }else if(root1){
            node->val=root1->val;
            node->left=mergeTrees(root1->left,nullptr);
            node->right=mergeTrees(root1->right,nullptr);
        }
        else if(root2){
            node->val=root2->val;
            node->left=mergeTrees(nullptr, root2->left);
            node->right=mergeTrees(nullptr,root2->right);
        }
        return node;
        //���������жϺ���ܸ��ӣ�����ô�ж��أ�

    }
};
/*
 * 1.AC�ˣ����߼���ĺ��Ѱ���
 * 2.�ٷ���������У��ȴ������µĽڵ㣬���õ����Ҹı���ԭ���������еĽڵ㣬д�ıȽϼ�࣬�����һ���
 *   �����Ŀǰ�Լ����뷨�ɡ�
 * */
int main(){

    return 0;
}
