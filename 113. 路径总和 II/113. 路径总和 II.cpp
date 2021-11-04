#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-20
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//class Solution {
//public:
//    vector<vector<int>> pathSum(TreeNode* root, int sum) {
//        //��������������ˣ���Ϊlong�ͷ������Ͳ���������
//        //������Ͳ�֪������ô�����ˡ�����
//        vector<vector<int>> ans;
//        if(!root)return ;
//        vector<int> p;
//        p.push_back(root->val);
//        path(ans,p,root,root->val,sum);
//        return ans;
//    }
//    void path(vector<vector<int>>& ans,vector<int> p,TreeNode* node,int ct,int sum){
//        if(!node->left&&!node->right){
//            if(ct==sum)
//                ans.push_back(p);
//            return;
//        }
//
//        //ԭ��������push��֮��Ҫ�˳��İ�
//        //���˹ٷ����֮��о�������봫�������ã��ǾͶ���Ϊ��Ա�������������������!
//        if(node->left)path(ans,p.push_back(node->left->val),node->left,ct+node->left->val,sum);
//        if(node->right)path(ans,p.push_back(node->right->val),node->right,ct+node->right->val,sum);
//    }
//};
class Solution {
public:
     vector<vector<int>> ans;
     vector<int> p;
     vector<vector<int>> pathSum(TreeNode* root, int sum) {
        path(root,sum);
        return ans;
    }
    void path(TreeNode* node,int ct){
        if(!node) return;
        p.push_back(node->val);
        ct-=node->val;//������ѵİ���������Ҫ��-ȥ�����ѵģ�
        if(!node->left&&!node->right){
            if(ct==0)
                ans.push_back(p);
            p.pop_back();return;//���Ѱ�������Ŀ����ˡ�
        }
        if(node->left)path(node->left,ct);
        if(node->right)path(node->right,ct);
        p.pop_back();
    }
};
/*
1.���봫�������ã��ǾͶ���Ϊ��Ա�������������������!
2.ʱ�临�Ӷȷ���������˼����Ȼ��O(n^2)�������¶������˻�Ϊ����N �����Ľڵ������������£�
  �����ϰ벿��Ϊ��״���°벿��Ϊ��ȫ�����������ҴӸ��ڵ㵽ÿһ��Ҷ�ӽڵ��·����������ĿҪ��
3.���츴ϰ��һ��BFS����������ͦ���ӵġ�
*/

//10-27��ѧϰBFS
/*
 * 1.https://leetcode-cn.com/problems/path-sum-ii/solution/lu-jing-zong-he-ii-by-leetcode-solution/
 *   �ٷ���BFS�Ľ�����ţ�ƣ������112��BFS�����ƣ�����112����Ҫ��¼·������ô�������¼·����������
 *   ����ʹ���˹�ϣ����¼���ڵ㣬��������������ģ���ô����Ҫ��¼ÿ���ڵ��·������������ţƤ���ˡ�
 * */

//11-19
class Solution2 {
public:
    unordered_map<TreeNode*,TreeNode*> um;
    int target;
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)return ans;
        target=sum;
        queue<TreeNode*> q({root});
        um[root]=root;
        while(!q.empty()){
            TreeNode* top=q.front();q.pop();
            if(!top->left&&!top->right){helper(top);continue;}
            if(top->left){
                q.push(top->left);
                um[top->left]=top;
            }
            if(top->right){
                q.push(top->right);
                um[top->right]=top;
            }
        }
        return ans;
    }
    void helper(TreeNode* t){
        int ct=0;
        vector<int> path;
        while(um[t]!=t){
            path.push_back(t->val);
            ct+=t->val;
            t=um[t];
        }
        path.push_back(t->val);
        reverse(path.begin(),path.end());
        if(ct+t->val==target)
            ans.push_back(path);
    }
};
/*
 * 1.ԭ������ô�ö�û��ϰ����Ⱑ����ʵ���DFS�����м��������ģ�����Ϊ˼·����������ʵ�����м��ɵ�
 * ��ʲôʱ��push/pop���´θ�ϰ��ʱ��Ҫдһ�¡�
 * 2.Yes��BFS�汾AC�ˣ�ʹ�ù�ϣ����¼���ڵ㡣
 * */

//5-23
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(!root) return ans;
        vector<int> p;
        helper(root,p,target);
        return ans;
    }
    void helper(TreeNode* root,vector<int>&path,int target){
        if(!root)return;//DFS��д�ҵĹؼ�����Ҫ���ж����������Ϊ�ݹ鷵���������������ں����ڲ��ж��ܷ�ݹ�
        //���ã�������������������Լ����ǵ���������ܶࡣ
        if(!root->left&&!root->right&&target==root->val){
            path.push_back(root->val);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        helper(root->left,path,target-root->val);
        helper(root->right,path,target-root->val);
        path.pop_back();
    }
};//һ����AC�ˣ�ûʲô���⡣
int main(){

    return 0;
}
