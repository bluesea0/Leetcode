#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月3日上午1:05:50
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;//啊天哪，是从根节点到叶子节点，我哭了。
        return mind(root);
    }
    int mind(TreeNode* root){
        if(!root->left&&!root->right) return 1;
        int left=INT_MAX,right=INT_MAX;
        if(root->left&&root->right){
            left=mind(root->left);
            right=mind(root->right);
        }else if(!root->left)
            right=mind(root->right);
        else if(!root->right)
            left=mind(root->left);
        return min(left,right)+1;
    }
};//我写的垃圾代码啊，AC了。。只超过了5%。。。
//二叉树的遍历都是O(n)，二叉树搜索才是O(logn)
//官方写的递归好好看啊，我要学习，下次复习要写的！
//那么迭代如何完成呢？BFS怎么写。
class Solution1 {
public:
    int minDepth(TreeNode* root) {
        //BFS的话思路是什么呢？对每个点豆要是一个pair来记录所在深度？
        //如果遇到一个叶结点了，就直接return了？
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,1));//que.emplace(root, 1);原来是可以直接push的啊，不需要()<>
        while(!q.empty()){
            TreeNode* f=q.front().first;
            int L=q.front().second;q.pop();
            if(!f->left&&!f->right)return L;//如果遇到了叶结点
            if(f->left)q.push(make_pair(f->left,L+1));
            if(f->right)q.push(make_pair(f->right,L+1));
        }
        return 0;//只是象征性的return了。
    }
};//这是我的BFS解法，速度更慢。官方和我的解法是一样的！赛高!
/*
 * 递归解法：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/solution/li-jie-zhe-dao-ti-de-jie-shu-tiao-jian-by-user7208/
 * 评论区中这个牛啊。
 * class Solution {
    public int minDepth(TreeNode root) {
        if(root == null) return 0;
        int m1 = minDepth(root.left);
        int m2 = minDepth(root.right);
        //1.如果左孩子和右孩子有为空的情况，直接返回m1+m2+1
        //2.如果都不为空，返回较小深度+1
        return root.left == null || root.right == null ? m1 + m2 + 1 : Math.min(m1,m2) + 1;
    }
}
人家简化了一下，学到了。
 * */
int main(){

    return 0;
}
