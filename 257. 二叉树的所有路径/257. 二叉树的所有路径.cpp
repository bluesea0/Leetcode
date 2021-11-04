#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年5月21日下午5:44:54
class Solution {
public:
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        path(root,"");
        return ans;//函数需要返回值！
    }
    void path(TreeNode* r,string s){
        if(!r)return;
        if(!r->left&&!r->right){
            s+=to_string(r->val);
            ans.push_back(s);
            return;
        }
        path(r->left,s+to_string(r->val)+"->");
        path(r->right,s+to_string(r->val)+"->");
    }
};
/*
 * 1.AC了，问题不大，但是太恐怖了，我好马虎，提交时完全可以看出来的，就是手误，眼睛不在代码吧。
 *  我在代码中标记出来错误。
 * */
int main(){

    return 0;
}
