#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年10月29日下午2:19:18
//用剑指offer54题的代码修改，通过了
class Solution {
public:
    int k,ans;
    int kthSmallest(TreeNode* root, int k) {
        this->k=k;
        kth(root);
        return ans;
    }
    void kth(TreeNode* root){
        if(!root)return;
        kth(root->left);
        if(k==0)return;//卧槽这里好难判断啊，你是先判断k是否=0还是先--k呢？
        if(--k==0){
            ans=root->val;
            return;
        };
        kth(root->right);
    }
};
/*
 * 1.https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/solution/er-cha-sou-suo-shu-zhong-di-kxiao-de-yuan-su-by-le/
 *  官方写的迭代的版本真不错，学到了。时间复杂度也学到了。对时间复杂度这个还有点疑问。
 * */
//下面写一下迭代版本：


//3-23
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode *t：
        while(!st.empty()){
            t=st.top();
            while(t->left){
                st.push(t->left);
                t=t->left;
            }//左子树已经为空了
            k--;st.pop();
            t=t->right;
            //啊我已经忘了，我不会了。
        }
    }
};
/*
 * 1.又照着o54写了一下递归版本的，照葫芦画瓢。
 * */
//class Solution {
//public:
//    int kthSmallest(TreeNode* root, int k) {
//        vector<TreeNode*> stk;
//        int ans;
//        stk.push_back(root);
//        TreeNode* r=stk.back();
//        while(!stk.empty()){
//            while(r->left){//但是这里如果不控制的话，会一直访问左子树
//            //这么写while就是不对，如果用判断left就会一直不停地访问左了
//                stk.push_back(r->left);
//                r=r->left;
//            }
//            r=stk.back();
//            stk.pop();
//            if(--k==0){
//                ans=r->val;
//                break;
//            }
//            if(r->right){
//                r=r->right;
//                stk.push_back(r);
//            }
//            //if(r->right)stk.push_back(r->right);//这里有问题
//        }
//        return ans;
//    }
//};
/*
 * 2.上面是迭代版本的中根遍历，我写的不对，有问题，还是需要复习一下，记住模板怎么写的。
 * */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> stk;//初始时为空！！！根节点不放入
        int ans;
        while(!stk.empty()||root){//root不加!等价于root!=NULL
            while(root){//r表示当前处理的节点
                stk.push_back(root);
                root=root->left;
            }
            root=stk.back();
            stk.pop_back();
            if(--k==0){
                ans=root->val;
                break;
            }
            root=root->right;//这里直接=，不用判断是否为空，如果是空的话，就不会去再从左子树开始遍历了。
        }//这个需要更新到博客园的二叉树遍历中，3.25号之后。
        return ans;
    }
};

//6-12
lass Solution {
public:
    int k,ans;
    int kthSmallest(TreeNode* root, int k) {
        this->k=k;
        kth(root);
        return ans;
    }
    void kth(TreeNode* root){
        if(!root)return;
        kth(root->left);
        if(this->k==0)return;
        if(--k==0){
            this->ans=root->val;
            return;
        }
        kth(root->right);
    }
};
/*
 * 1.做了o54题之后过来的，学习了迭代版本如何写。
 * */
int main(){

    return 0;
}
