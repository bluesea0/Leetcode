#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-20
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//class Solution {
//public:
//    vector<vector<int>> pathSum(TreeNode* root, int sum) {
//        //返回这个还不行了，因为long和返回类型不符。。。
//        //那我这就不知道是怎么回事了。。。
//        vector<vector<int>> ans;
//        if(!root)return ;
//        vector<int> p;
//        p.push_back(root->val);
//        path(ans,p,root,root->val,sum);
//        return ans;
//    }
//    void path(vector<vector<int>>& ans,vector<int> p,TreeNode* node,int ct,int sum){
//        if(!node->left&&!node->right){
//            if(ct==sum)
//                ans.push_back(p);
//            return;
//        }
//
//        //原来是这里push了之后要退出的啊
//        //看了官方解答之后感觉如果不想传函数引用，那就定义为成员变量，这样方便代码简洁!
//        if(node->left)path(ans,p.push_back(node->left->val),node->left,ct+node->left->val,sum);
//        if(node->right)path(ans,p.push_back(node->right->val),node->right,ct+node->right->val,sum);
//    }
//};
class Solution {
public:
     vector<vector<int>> ans;
     vector<int> p;
     vector<vector<int>> pathSum(TreeNode* root, int sum) {
        path(root,sum);
        return ans;
    }
    void path(TreeNode* node,int ct){
        if(!node) return;
        p.push_back(node->val);
        ct-=node->val;//真的蛮难的啊！这里需要先-去，蛮难的！
        if(!node->left&&!node->right){
            if(ct==0)
                ans.push_back(p);
            p.pop_back();return;//好难啊！我真的哭泣了。
        }
        if(node->left)path(node->left,ct);
        if(node->right)path(node->right,ct);
        p.pop_back();
    }
};
/*
1.不想传函数引用，那就定义为成员变量，这样方便代码简洁!
2.时间复杂度分析很有意思，居然是O(n^2)。最坏情况下二叉树退化为链表。N 是树的节点数。在最坏情况下，
  树的上半部分为链状，下半部分为完全二叉树，并且从根节点到每一个叶子节点的路径都符合题目要求。
3.明天复习搞一下BFS，看起来还挺复杂的。
*/

//10-27，学习BFS
/*
 * 1.https://leetcode-cn.com/problems/path-sum-ii/solution/lu-jing-zong-he-ii-by-leetcode-solution/
 *   官方的BFS的解答真的牛逼，这个和112的BFS很类似，但是112不需要记录路径，那么在这里记录路径就是问题
 *   这里使用了哈希来记录父节点，否则如果是其他的，那么就需要记录每个节点的路径，这种是最牛皮的了。
 * */

//11-19
class Solution2 {
public:
    unordered_map<TreeNode*,TreeNode*> um;
    int target;
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)return ans;
        target=sum;
        queue<TreeNode*> q({root});
        um[root]=root;
        while(!q.empty()){
            TreeNode* top=q.front();q.pop();
            if(!top->left&&!top->right){helper(top);continue;}
            if(top->left){
                q.push(top->left);
                um[top->left]=top;
            }
            if(top->right){
                q.push(top->right);
                um[top->right]=top;
            }
        }
        return ans;
    }
    void helper(TreeNode* t){
        int ct=0;
        vector<int> path;
        while(um[t]!=t){
            path.push_back(t->val);
            ct+=t->val;
            t=um[t];
        }
        path.push_back(t->val);
        reverse(path.begin(),path.end());
        if(ct+t->val==target)
            ans.push_back(path);
    }
};
/*
 * 1.原来我这么久都没复习这道题啊，其实这个DFS还是有技术含量的，别以为思路清晰，但其实还是有技巧的
 * 　什么时候push/pop。下次复习的时候要写一下。
 * 2.Yes！BFS版本AC了！使用哈希来记录父节点。
 * */

//5-23
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(!root) return ans;
        vector<int> p;
        helper(root,p,target);
        return ans;
    }
    void helper(TreeNode* root,vector<int>&path,int target){
        if(!root)return;//DFS不写乱的关键点是要将判断条件最好作为递归返回条件，而不是在函数内部判断能否递归
        //调用，那样产生的冗余代码以及考虑的情况都会多很多。
        if(!root->left&&!root->right&&target==root->val){
            path.push_back(root->val);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        helper(root->left,path,target-root->val);
        helper(root->right,path,target-root->val);
        path.pop_back();
    }
};//一下子AC了，没什么问题。
int main(){

    return 0;
}
