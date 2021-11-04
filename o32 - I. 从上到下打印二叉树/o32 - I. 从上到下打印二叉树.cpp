#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年5月22日下午4:43:45
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        //层次遍历
        if(!root)return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* t=q.front();
            q.pop();
            ans.push_back(t->val);
            if(t->left)q.push(t->left);//又马虎写错了，这里是t不是root哦。
            if(t->right)q.push(t->right);
        }
        return ans;
    }
};
int main(){

    return 0;
}
