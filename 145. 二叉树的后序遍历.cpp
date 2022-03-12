#include <bits/stdc++.h>
using namespace std;

//2020年10月27日下午10:36:25
//递归版本我就不写了，没必要。。。直接看迭代和morris。
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//class Solution {
//public:
//   vector<int> postorderTraversal(TreeNode* root) {
//       vector<int> ans
//       stack<TreeNode*> st;
//       TreeNode* node=root;
//       while(node||!st.empty()){
//           while(node->left){
//               st.push(node->left);
//               node=node->left;
//           }
//           while(node->right){//这样push也不对的啊。
//               st.push(node->right);
//               node=node->right;
//           }//就像给的这个样例，就遍历不到3了。。。我真的母鸡怎么搞了。
//       }
//   }
//};//我写的垃圾代码，写不下去了，没思路。
//昨天晚上看了思路，然后今天仍旧写不出来，好难啊！
//必须要掌握思想才行，只记得代码不行。不值钱。

//整体思路是前序遍历：根左右，那么每次根出栈，进入后序的栈，然后左节点入右节点入，那么出的时候就可以
//形成根右左了。
//第一种解法：
class Solution
{
public:
  vector<int> postorderTraversal(TreeNode *root)
  {
    vector<int> ans;
    if (!root)
      return ans;
    stack<TreeNode *> pre, post;
    pre.push(root);
    while (!pre.empty())
    {
      TreeNode *top = pre.top();
      pre.pop(); //这里根先入先出
      post.push(top);
      if (top->left)
        pre.push(top->left); //左先入，那么后出
      if (top->right)
        pre.push(top->right); //右后入，那么先出。
    }
    while (!post.empty())
    {
      ans.push_back(post.top()->val);
      post.pop();
    }
    return ans;
  }
};
//下面第二种解法也AC了，看了grand的讲解才醍醐灌顶啊。
class Solution2
{
public:
  vector<int> postorderTraversal(TreeNode *root)
  {
    vector<int> ans;
    if (!root)
      return ans;
    TreeNode *head = root; //指向的是访问的前一个节点
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
      TreeNode *top = st.top();
      if (top->left != NULL && top->left != head && top->right != head)
      {
        st.push(top->left);
      }
      else if (top->right != NULL && top->right != head)
      { //左为空或者左已被访问过。
        st.push(top->right);
      }
      else
      { //如果左右子节点均为空，或者都已被访问过，那么就将当前ans
        ans.push_back(top->val);
        st.pop();
        head = top;
      }
    }
    return ans;
  }
};
/*
 * 1.还是grand讲的透彻啊
 * https://www.cnblogs.com/grandyang/p/4251757.html
 * */

//10-17
/*
 * 1.今天再复习我已经想不起来迭代版本是怎么写的了。。。真的想不起来了。
 * 2.看了代码，我甚至连需要用栈来存储节点这个都给忘记了。
 * 3.思想表述：还是只记这两种解法就ok。
 * */

//2021-11-4
/*
1.原来的我看grand的解法并不高明。可以通过类似于前序遍历的方式来写，我尝试一下。
*/
class Solution
{
public:
  vector<int> postorderTraversal(TreeNode *root)
  {
    vector<int> ans;
    if (!root)
      return ans;
    TreeNode *head = root, *pre = nullptr;
    stack<TreeNode *> stk;
    while (!stk.empty() || head)
    {
      while (head)
      {
        stk.push(head);
        head = head->left;
      }
      TreeNode *top = stk.top(); //可以通过前序遍历->后序遍历
      if ((!top->left && !top->right) || top->right == pre || (top->left == pre && !top->right))
      {
        //分三种情况，一种是遍历到了叶子节点，二是右节点遍历完了
        //三是遍历完了左节点，并且右子树为空
        ans.push_back(top->val);
        stk.pop();
        pre = top;
      }
      else
        head = top->right;
    }
    return ans;
  }
};
/*
1.我觉得还是我写的比较好理解。
*/
int main()
{

  return 0;
}
