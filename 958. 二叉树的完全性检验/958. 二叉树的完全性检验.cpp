#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年10月26日上午1:22:23
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
//天哪，还有这样的样例，那属实是判断不出来了。
//我这样写，只是确认了局部，但没有考虑到整体。左子树和右子树分别都是，但是合起来之后就不是了。
//本来是想这么写的，但是针对上面的样例结果是不正确的。
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
 * 1.官解中只给了bfs的解法，原来判断是否是完全的，需要用bfs啊，评论区中其他有dfs的解法。
 *   如上，需要考虑节点总数和下标之间的关系。下面是bfs解法。
 * */

//10-26
/*
 * 1.BFS的方法一开始没有写出来，不过看到评论区通过设置一个flag去标识是否遇到了空节点。
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
            if(flag)return false;//如果已经遍历到空节点了，但是之后仍然遍历到了非空的节点，那么就表示是有问题的。
            q.push(top->left);
            q.push(top->right);
        }
        return true;
    }
};
int main(){

    return 0;
}
