#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��3��3������4:12:05
class Solution {
public:
    //����ʵ�������������p�������q���������ǰroot�������p��q�����������У�
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //����Ƿ�ɢ����������
        if((p->val<root->val&&q->val>root->val)||(q->val<root->val&&p->val>root->val))
            return root;
        if(root->val==p->val||root->val==q->val)return root;
        if(p->val<root->val&&q->val<root->val)//������������
            return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);//��Ȼ�϶�����������
    }
};
/*
 * 1.���ǱȽϼ򵥵ģ���Ҫ���õ�BST�����ʣ��������˳������ʡ�ʱ����O(n)���ռ䶼��O(H)��
 * 2.�ٷ������ǵ����İ汾��˼·���ҳ��ֱ�p��q��·�����ֲ�ĵ����ans���ռ併ΪO(1)��
 * 3.���������������������еݹ飺
 * class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root.val < p.val && root.val < q.val) return lowestCommonAncestor(root.right, p, q);
        if(root.val > p.val && root.val > q.val) return lowestCommonAncestor(root.left, p, q);
        return root;
    }
} //�����ˣ���д���������ж�������Ƿ���root���ǾͿ���ֱ�Ӳ��жϡ������Ӱ���
 * */

//6-18
/*
 * 1.ֱ�ӹ������Ǹо��е��¡�дһ�¡�
 * 2.���У�����BST����ֵ��
 * */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //��Ҫ����BST������
        if(!root)return root;
        if(root==p||root==q||(p->val<root->val&&q->val>root->val)||(
            q->val<root->val&&p->val>root->val//��Ϊp��q��һ����˳������
        ))return root;
        if(p->val<root->val&&q->val<root->val)
            return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);
    }
};
int main(){

    return 0;
}
