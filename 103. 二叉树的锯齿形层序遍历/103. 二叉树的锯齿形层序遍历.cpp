#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��22������1:47:04
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //������reverse�������£�
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int flag=0;
        while(!q.empty()){
            int len=q.size();
            vector<int> t;
            TreeNode* f;
            while(len--){
                f=q.front();q.pop();
                t.push_back(f->val);
                if(f->left)q.push(f->left);
                if(f->right)q.push(f->right);
            }
            if(flag)
                reverse(t.begin(),t.end());
            ans.push_back(t);
            flag^=1;
        }
        return ans;
    }
};//ʱ��:O(n)  �ռ�:O(n)
int main(){

    return 0;
}
