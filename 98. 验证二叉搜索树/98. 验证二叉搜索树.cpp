#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年10月11日下午10:19:14
class Solution {
public:
    bool helper(TreeNode* root,long long left_lower,long long right_lower){
        if(root==nullptr)return true;
        if(root->val<=left_lower||root->val>=right_lower){
            return false;//当前root的值应该是在left和right之间的
        }
        return helper(root->left,left_lower,root->val)&&helper(root->right,root->val,right_lower);
    }
    bool isValidBST(TreeNode* root) {
        //先用递归的方式解决
        //针对每个子树的root，保证其所有左子节点值<当前，所有右子节点值>当前
        //递归判断
        return helper(root,LONG_MIN,LONG_MAX);//这里要用long来判断，因为有可能节点中存在着最小的
        //那个值！
    }
};
/*
 * 1.中午吃饭的时候看的，一开始没有想到这个解法，如何去判断左子树中所有节点值都小于当前呢？
 *   以及右子树如何判断？都是存在问题的。上面的递归给定很神奇。
 * 2.下面用迭代的方式来求解一下。
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
            if(cur->val<=pre)return false;//主要是和之前比较，如果<=的话，那么就false。
            pre=cur->val;
            cur=cur->right;
        }
        return true;
    }
};
int main(){

    return 0;
}
