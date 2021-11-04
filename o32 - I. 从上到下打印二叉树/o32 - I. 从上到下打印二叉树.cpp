#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��5��22������4:43:45
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        //��α���
        if(!root)return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* t=q.front();
            q.pop();
            ans.push_back(t->val);
            if(t->left)q.push(t->left);//����д���ˣ�������t����rootŶ��
            if(t->right)q.push(t->right);
        }
        return ans;
    }
};
int main(){

    return 0;
}
