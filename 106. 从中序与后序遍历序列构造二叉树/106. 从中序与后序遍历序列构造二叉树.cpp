#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年10月30日下午7:38:42
class Solution {//AC了，
public:
    unordered_map<int,int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        return build(inorder,postorder,postorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int post,int left,int right){
        if(post<0||left>right) return NULL;
        int p=mp[postorder[post]];
        TreeNode* root=new TreeNode(postorder[post]);
        root->left=build(inorder,postorder,post-right+p-1,left,p-1);//这里要注意是减去右节点的数量啊。
        root->right=build(inorder,postorder,post-1,p+1,right);
        return root;
    }
};
/*
 * 1.这个也有迭代版本，那明天复习看！
 * */
int main(){

    return 0;
}
