#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��10��20������8:53:39
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==nullptr)return {};
        vector<int> ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int len=q.size();
            int mx=INT_MIN;
            for(int i=0;i<len;i++){
                TreeNode* temp=q.front();
                q.pop();
                mx=max(mx,temp->val);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            ret.push_back(mx);
        }
        return ret;
    }
};
/*
 * 1.�൱���ˡ�
 * */
int main(){

    return 0;
}
