#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��17������3:59:36
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
                t.push_back(f->val);//ע������push����ֵŶ��
                if(f->left)q.push(f->left);
                if(f->right)q.push(f->right);
            }
            ans.push_back(t);
        }
        return ans;
    }
};//ûʲô�Ѷȡ�

//5-22
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //��α���
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
                if(t->left)q.push(t->left);//����д���ˣ�������t����rootŶ��
                if(t->right)q.push(t->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
//�򵥣����Ѷȡ�
int main(){

    return 0;
}
