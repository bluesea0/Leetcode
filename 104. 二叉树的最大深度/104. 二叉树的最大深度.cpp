#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年10月29日下午2:47:01
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};//AC了。明天学习BFS。

//2021-6-12
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            int len=q.size();
            while(len--){
                TreeNode* t=q.front();
                q.pop();
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            ans++;
        }
        return ans;
    }
};
/*
 * 1.corner case没考虑啊，指针为空怎么办？你都不想这个，offer没了啊。再见吧。
 *  而且好多马虎的地方写错了，我是不是没带脑子？代码提交之前一定要把样例手动运行了，能通过，②考虑corner
 *  case，日你妈退钱！
 * */
int main(){

    return 0;
}
