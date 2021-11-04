#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��10��30������7:38:42
class Solution {//AC�ˣ�
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
        root->left=build(inorder,postorder,post-right+p-1,left,p-1);//����Ҫע���Ǽ�ȥ�ҽڵ����������
        root->right=build(inorder,postorder,post-1,p+1,right);
        return root;
    }
};
/*
 * 1.���Ҳ�е����汾�������츴ϰ����
 * */
int main(){

    return 0;
}
