#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年3月3日下午6:45:06
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
        // }//这个遍历方法是错误的，两者路径长度不一定等长的啊
        // for(int i=min(p1.size(),q1.size())-1;i>=0;i--){//这个也不对，得把它翻转过来才行
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
 * 1.按照记录父节点的方式，但是我这个很慢啊。
 * */

//3-4
/*
 * 1.https://www.cnblogs.com/grandyang/p/4641968.html，递归讲的很清楚，有点难度。
 * 2.官方给的记录父节点的方法，而且通过对p先跑一下标记访问过的节点，在对q跑一边，遇到第一个被访问过的
 *   点就是对应的ans。
 * */

//3-5
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||root==p||root==q)return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);//能运行到这里说明root不为p或q
        TreeNode* right=lowestCommonAncestor(root->right,p,q);//所以查看p或q是否在左右子树中
        if(left&&right)return root;//既在左又在右，那么LCA就是当前节点
        return left?left:right;//这个地方很复杂啊
        //这里返回的意义是什么呢？非空则表示在左或者右子树
    }
};

//5-21
//评论区写的这个我能看懂一点，递归的好难理解啊。
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
            else if(lNode==null) {//两个都在右子树
                return rNode;
            }
            else { //两个都在左子树里面
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
 * 1.一下子把递归写出来了，太棒了吧！！！！我理解了！
 * */
int main(){

    return 0;
}
