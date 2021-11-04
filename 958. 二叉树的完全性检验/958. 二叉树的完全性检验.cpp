#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��10��26������1:22:23
//class Solution {
//public:
//    bool flag;
//    bool isCompleteTree(TreeNode* root) {
//        if(root==nullptr)return true;
//        flag=true;
//        helper(root);
//        return flag;
//    }
//    int helper(TreeNode* root){
//        if(root==nullptr)return 0;
//        int left=helper(root->left);
//        int right=helper(root->right);
//        if(left<right){
//            flag=false;return 0;
//        }
//        if(flag==false)return 0;
//        return left+right+1;
//    }
//};
//[1,2,3,5,null,7]
//���ģ���������������������ʵ���жϲ������ˡ�
//������д��ֻ��ȷ���˾ֲ�����û�п��ǵ����塣���������������ֱ��ǣ����Ǻ�����֮��Ͳ����ˡ�
//����������ôд�ģ���������������������ǲ���ȷ�ġ�
class Solution {
public:
    int k,index;
    bool isCompleteTree(TreeNode* root) {
        k=0,index=1;
        if(root==nullptr)return true;
        if(dfs(root,1)==false) return false;
        return k==index;
    }
    bool dfs(TreeNode* root,int id){
        if(root==nullptr)return true;
        k++;
        index=max(id,index);
        if(id>100)return false;
        return dfs(root->left,2*id)&&dfs(root->right,2*id+1);
    }
};
/*
 * 1.�ٽ���ֻ����bfs�Ľⷨ��ԭ���ж��Ƿ�����ȫ�ģ���Ҫ��bfs������������������dfs�Ľⷨ��
 *   ���ϣ���Ҫ���ǽڵ��������±�֮��Ĺ�ϵ��������bfs�ⷨ��
 * */

//10-26
/*
 * 1.BFS�ķ���һ��ʼû��д��������������������ͨ������һ��flagȥ��ʶ�Ƿ������˿սڵ㡣
 * */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root==nullptr)return true;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=false;
        while(!q.empty()){
            auto top=q.front();q.pop();
            //if(top==nullptr&&!q.empty())return false;
            if(top==nullptr){
                flag=true;continue;
            }
            if(flag)return false;//����Ѿ��������սڵ��ˣ�����֮����Ȼ�������˷ǿյĽڵ㣬��ô�ͱ�ʾ��������ġ�
            q.push(top->left);
            q.push(top->right);
        }
        return true;
    }
};
int main(){

    return 0;
}
