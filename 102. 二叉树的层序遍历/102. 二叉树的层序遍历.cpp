#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月17日下午3:59:36
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> t;
            int len=q.size();
            while(len--){
                TreeNode* f=q.front();q.pop();
                t.push_back(f->val);//注意这里push的是值哦。
                if(f->left)q.push(f->left);
                if(f->right)q.push(f->right);
            }
            ans.push_back(t);
        }
        return ans;
    }
};//没什么难度。

//5-22
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //层次遍历
        if(!root)return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> temp;
            while(size--){
                TreeNode* t=q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left)q.push(t->left);//又马虎写错了，这里是t不是root哦。
                if(t->right)q.push(t->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
//简单，无难度。
int main(){

    return 0;
}
