#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��3��3������6:45:06
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> father;
    vector<TreeNode*> p1,q1;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root);
        father[root]=root;
        getPath(p,p1);
        getPath(q,q1);
        TreeNode* ans;
        reverse(p1.begin(),p1.end());
        reverse(q1.begin(),q1.end());
        for(int i=0;i<p1.size()&&i<q1.size();i++){
            if(p1[i]==q1[i])ans=p1[i];
            else break;

        }
        // }//������������Ǵ���ģ�����·�����Ȳ�һ���ȳ��İ�
        // for(int i=min(p1.size(),q1.size())-1;i>=0;i--){//���Ҳ���ԣ��ð�����ת��������
        //     if(p1[i]==q1[i]){
        //         ans=p1[i];break;
        //     }
        // }
        return ans;
    }
    void getPath(TreeNode* p,vector<TreeNode*>& p1){
        p1.push_back(p);
        while(father[p]!=p){
            p1.push_back(father[p]);
            p=father[p];
        }
    }
    void helper(TreeNode* r){
        if(r->left){
            father[r->left]=r;
            helper(r->left);
        }
        if(r->right){
            father[r->right]=r;
            helper(r->right);
        }
    }
};
/*
 * 1.���ռ�¼���ڵ�ķ�ʽ�������������������
 * */

//3-4
/*
 * 1.https://www.cnblogs.com/grandyang/p/4641968.html���ݹ齲�ĺ�������е��Ѷȡ�
 * 2.�ٷ����ļ�¼���ڵ�ķ���������ͨ����p����һ�±�Ƿ��ʹ��Ľڵ㣬�ڶ�q��һ�ߣ�������һ�������ʹ���
 *   ����Ƕ�Ӧ��ans��
 * */

//3-5
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||root==p||root==q)return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);//�����е�����˵��root��Ϊp��q
        TreeNode* right=lowestCommonAncestor(root->right,p,q);//���Բ鿴p��q�Ƿ�������������
        if(left&&right)return root;//�����������ң���ôLCA���ǵ�ǰ�ڵ�
        return left?left:right;//����ط��ܸ��Ӱ�
        //���ﷵ�ص�������ʲô�أ��ǿ����ʾ�������������
    }
};

//5-21
//������д��������ܿ���һ�㣬�ݹ�ĺ�����Ⱑ��
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root==p||root==q) {
            return root;
        }
        if (root!=null){
            TreeNode lNode=lowestCommonAncestor(root.left,p,q);
            TreeNode rNode=lowestCommonAncestor(root.right,p,q);
            if (lNode!=null&&rNode!=null)
                return root;
            else if(lNode==null) {//��������������
                return rNode;
            }
            else { //������������������
                return lNode;
            }
        }
        return null;
    }
}

//9-19
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)return root;
        if(root==p||root==q)return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,q,p);
        if(left&&right)return root;
        if(left)return left;
        else return right;
    }
};
/*
 * 1.һ���Ӱѵݹ�д�����ˣ�̫���˰ɣ�������������ˣ�
 * */
int main(){

    return 0;
}
