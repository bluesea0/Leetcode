#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年6月12日下午2:16:28
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;//corner case注意哦
        return sysme(root->left,root->right);
    }
    bool sysme(TreeNode*left,TreeNode* right){
        if(!left&&!right)return true;//两者都为空
        if(!left||!right) return false;//其中有一个为空
        if(left->val!=right->val)return false;
        return sysme(left->left,right->right)&&sysme(left->right,right->left);
    }
};
/*
 * 1.递归版本很快就写出来了，那么迭代呢？
 * */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        queue<TreeNode*> q;
        if(root->left)q.push(root->left);
        if(root->right)q.push(root->right);
        if(q.size()&1)return false;
        while(!q.empty()){
            TreeNode* t1=q.front();q.pop();
            TreeNode* t2=q.front();q.pop();
            //这个地方的判断好麻烦啊，怎么才能简单一点呢？
            if(t1->val!=t2->val)return false;
            if(t1->left&&t2->right){
                q.push(t1->left);
                q.push(t2->right);
            }else if(!t1->left&&!t2->right){}
            else return false;//其中只有一个为空
            if(t1->right&&t2->left){
                q.push(t1->right);
                q.push(t2->left);
            }else if(!t1->right&&!t2->left){}
            else return false;
        }
        return true;
    }
};
/*
 * 1.迭代版本也很快写出来了，不过有点长了。
 * */
//下面是官方题解
class Solution {
public:
    bool check(TreeNode *u, TreeNode *v) {
        queue <TreeNode*> q;
        q.push(u); q.push(v);
        while (!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if (!u && !v) continue;//通过这里的判断原来这里还可以push进去空？
            if ((!u || !v) || (u->val != v->val)) return false;

            q.push(u->left);
            q.push(v->right);

            q.push(u->right);
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);//哇啊哦，这个技巧好牛哦
        //但是我就不懂了，那后来push进队列的不就是两个了吗？push进了两次？
    }
};
int main(){

    return 0;
}
