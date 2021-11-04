#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年3月3日下午4:12:05
class Solution {
public:
    //它其实包括三种情况，p是最近，q是最近，当前root是最近（p、q在左右子树中）
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //如果是分散在两个当中
        if((p->val<root->val&&q->val>root->val)||(q->val<root->val&&p->val>root->val))
            return root;
        if(root->val==p->val||root->val==q->val)return root;
        if(p->val<root->val&&q->val<root->val)//都在左子树中
            return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);//不然肯定在右子树中
    }
};
/*
 * 1.算是比较简单的，需要利用到BST的性质，中序遍历顺序的性质。时间是O(n)，空间都是O(H)。
 * 2.官方给的是迭代的版本，思路是找出分别到p和q的路径，分叉的点就是ans，空间降为O(1)。
 * 3.看到评论区给出来的三行递归：
 * class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root.val < p.val && root.val < q.val) return lowestCommonAncestor(root.right, p, q);
        if(root.val > p.val && root.val > q.val) return lowestCommonAncestor(root.left, p, q);
        return root;
    }
} //我悟了，我写的上两个判断情况都是返回root，那就可以直接不判断。绝绝子啊。
 * */

//6-18
/*
 * 1.直接过来还是感觉有点懵。写一下。
 * 2.还行，根据BST的性值来
 * */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //需要借助BST的性质
        if(!root)return root;
        if(root==p||root==q||(p->val<root->val&&q->val>root->val)||(
            q->val<root->val&&p->val>root->val//因为p和q不一定有顺序，所以
        ))return root;
        if(p->val<root->val&&q->val<root->val)
            return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);
    }
};
int main(){

    return 0;
}
