#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年10月1日下午8:25:02
class Solution {
public:
    int ans;
    int sumNumbers(TreeNode* root) {
        ans=0;
        if(root==nullptr)return 0;
        sumn(root,root->val);
        return ans;
    }
    void sumn(TreeNode* root,int val){
        //if(root==nullptr)return;
        if(root->left==nullptr&&root->right==nullptr){
            ans+=val;
            return;
        }
        if(root->left)sumn(root->left,val*10+root->left->val);
        if(root->right)sumn(root->right,val*10+root->right->val);
    }
};
/*
 * 1.还是比较简单的，一下子AC了。
 * 2.时间复杂度和空间复杂度都是O(n)。每个节点遍历一次，空间最坏是链式的二叉树。
 * */
int main(){

    return 0;
}
