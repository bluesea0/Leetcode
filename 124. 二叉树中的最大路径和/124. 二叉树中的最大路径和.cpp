#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年10月28日下午4:48:25
class Solution {
public:
    int ans=0;
    int maxPathSum(TreeNode* root) {
        //思路：递归地计算以每个节点作为根节点的子二叉树的和，选择其中的最大值返回
        if(!root)return 0;
        ans=root->val;
        path(root);
        return ans;
    }
    int path(TreeNode* root){
        if(!root->left&&!root->right){
            ans=max(ans,root->val);
            return root->val;
        }
        int left=0,right=0;
        if(root->left)left=path(root->left);
            //不对，我的思路不对了，如果我不返回整棵子数的和，那么函数返回就不一致了。
        if(root->right)right=path(root->right);
//        int s=max(max(left+root->val,right+root->val),left+right+root->val);
//        ans=max(s,ans);
        //这三个分别进行判断：加上左子数，加上右子树，以及（左右子数都为负，无法贡献时）
        //前两项并且返回s的意思是，只能取左路径或右路径或者都不取。
        int s=max(max(left+root->val,right+root->val),root->val);
        ans=max(max(s,left+right+root->val),ans);//从整棵子树中选择
        //[5,4,8,11,null,13,4,7,2,null,null,null,1]
        //48 ,而本代码输出55，上面这个样例是不对的了。。。因为它不应该算左右的和，因为
        //不能迂回地走，我的计算方法，会将整棵树都计算，而不是一条路径了。。。
        return s;
    }
};
/*
 * 1.https://www.cnblogs.com/grandyang/p/4280120.html，人家这代码简洁啊，你还需要学习啊。
 *   不过我觉得我已经很不错了，能够AC，说明我还是有思路的！以上能够看出来是后序遍历啊！
 * 2.上面链接中又有，如果要返回这个最大的路径，怎么办？我觉得这真的是一个面试的时候很好的问题啊！
 *   并不一定你能写出来，但是你一定要有思路，思路值钱。
 *   我想了想还是觉得这个钱不好拿，明天复习的时候看看链接中的解答。
 * */

//10-29
//又复习了一下，还是觉得要返回路径的这个钱我拿不了，也尝试看了评论区中的代码，天书啊，算了。

//11-18
/*
 * 1.复习能够想到思路，递归地去计算，递归返回条件是叶结点，判断子树的时候共需要判断四种的max值
 *   根节点，根节点+左节点，根节点+右节点，根节点+左节点+右节点
 * */

//12-25
class Solution2 {
public:
    int ans=INT_MIN;//天哪，原来[-3]针对这样的要是0，绝了绝了。
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* r){
        if(!r)return 0;
        if(!r->left&&!r->right){
            ans=max(ans,r->val);//针对[1]这样只有一个节点的二叉树
             return r->val;
        }
        int left=dfs(r->left);
        int right=dfs(r->right);
        int now=max(max(left,right)+r->val,r->val);//我的天，我知道了，它是不能拐弯的！
        ans=max(ans,max(now,left+right+r->val));
        return now;//这个返回的时候肯定是要包括根节点的。我都加了啊！，这里理解错了，关键点不在根节点
    }//[5,4,8,11,null,13,4,7,2,null,null,null,1],我输出55，预期是48.
    //我好像想起来了，断的两条路肯定是不能拼起来的啊！这可怎么控制啊
    //应该是在返回的时候控制
};
/*
 * 1.本来是想胡尔马约的过去不想写代码的，但是看到上次写都快两个月之前了，然后就写了。
 *   果然遇到了更多的问题，就是关键的点是按照这个规则，不能有拐弯的
 * 2.时间空间O(N)，。对每个节点访问不超过 2次。空间是在最坏情况下，空间复杂度主要取决于递归调用层数，
 *   最大层数等于二叉树的高度，最坏情况下，二叉树的高度等于二叉树中的节点个数。
 * */

//2021-6-5
class Solution {
public:
    int ans=INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root){//以root为根节点，并且包含root，只包含左或右或只root的最大值
        if(!root)return 0;
        int left=dfs(root->left);
        int right=dfs(root->right);
        int m=max(left,right)+root->val;
        int t=max(max(m,left+right+root->val),root->val);
        ans=max(ans,t);
        return max(m,root->val);
    }
};
/*
 * 1.一遍AC嘻嘻嘻，我太棒啦。
 * 2.我认为我比之前有进步了，这里的dfs就直接将判断左右子数是否为空来作为递归结束的标准，这样写
 *   比判断左右子数是否为空再决定是否递归，更简洁！
 * */

//9-19
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root){//以root为根节点，并且包含root，只包含左或右或只root的最大值
        if(!root)return 0;
        int left=max(dfs(root->left),0);//如果是负数则忽略掉
        int right=max(dfs(root->right),0);
        int maxGain=max(max(left,right)+root->val,root->val);
        int m=max(maxGain,left+right+root->val);//这里多一个所包含的整个子树
        ans=max(ans,m);
        return maxGain;//关键是返回的时候只能是根or根+左or+根+右
    }
};
int main(){

    return 0;
}
