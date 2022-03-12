#include <bits/stdc++.h>
using namespace std;
//@date: 2021-11-18  00:07

class Solution
{
public:
    int ans;
    int findTilt(TreeNode *root)
    {
        ans = 0;
        helper(root);
        return ans;
    }
    int helper(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        ans += abs(left - right);
        return left + right + root->val;
    }
};
/*
1.相当简单没得说。。。直接递归解决。
*/
int main()
{

    return 0;
}
