#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年10月29日下午1:38:47
class Solution {
public:
    vector<int> ans;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    int kthLargest(TreeNode* root, int k) {
        //思路：中序遍历就可以了。
        inorder(root);
        return ans[ans.size()-k];
    }
};
/*
 * 1.之前的解法是这样的，不管怎么要需要遍历整棵BST，就感觉不太好，看了另一种解法，学到了。
 * */
class Solution1 {
public:
    int k,n=0;
    int kthLargest(TreeNode* root, int k) {
        //思路：在中序遍历过程中，记录当前访问的是第几个节点，到k时就返回，就不需要遍历整棵二叉了
        this->k=k;
        return kth(root);
    }
    int kth(TreeNode* root){//我错了，这样返回的是第k小的节点。
        //那就右根左。
        if(!root)return -1;
        int m=kth(root->right);
        if(m!=-1) return m;//这里m每次返回都要判断，否则还是会继续进行递归，最终只会返回-1.
        n++;
        if(n==k) return root->val;
        m=kth(root->left);
        if(m!=-1) return m;
        return -1;//这里也是不知道返回什么，所以返回-1吧。
    }
};
/*
 * 2.上面可以看出来，我写的十分垃圾。
 * 3.下面精简一下，用类数据成员来维护ans
 * */
class Solution2 {
public:
    int k,ans;//这样就精简了许多。
    int kthLargest(TreeNode* root, int k) {
        //思路：在中序遍历过程中，记录当前访问的是第几个节点，到k时就返回，就不需要遍历整棵二叉了
        this->k=k;
        kth(root);
        return ans;
    }
    void kth(TreeNode* root){
        if(!root)return;
        kth(root->right);
        if(k==0)return;//卧槽这里好难判断啊，你是先判断k是否=0还是先--k呢？
        if(--k==0){
            ans=root->val;
            return;
        };
        kth(root->left);
    }
};//时间复杂度，O(n)，当它退化为链表时，空间也是，因为有大小为O(n)的栈
//复习这个的同时看一下230，这道题能不能也用迭代？明天复习请写一下。

//3-23
/*
 * 1.今天复习还是只能想到中序遍历之后再取的结果。
 * 2.注意到，对BST中序遍历得到的结果是递增的，对BST先右子树、根、左子树的结果是递减的！这样的话就能求第k大的
 *   数字，而不用遍历整棵树。但如何遍历标记k，在遍历的时候做判断返回还挺复杂的。
 * */

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        vector<TreeNode*> stk;//初始时为空，不降根节点放入
        int ans;
        while(!stk.empty()||root){//root不加!等价于root!=NULL
            while(root){//r表示当前处理的节点
                stk.push_back(root);
                root=root->right;
            }
            root=stk.back();
            stk.pop_back();
            if(--k==0){
                ans=root->val;
                break;
            }
            root=root->left;
        }
        return ans;
    }
};
/*
 * 3.从230题过来，修改了一下入栈的顺序就实现了迭代版本，先入右节点，再根，再左节点，即右根左。
 * */

//6-12
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* cur=root;
        while(cur||!st.empty()){
            while(cur){
                st.push(cur);
                cur=cur->right;//天哪，原来是k大的节点，不是第k小的节点，又难了一点
            }
            cur=st.top();
            st.pop();
            if(--k==0){
                return cur->val;
            }
            cur=cur->left;
        }
        return 0;
    }
};
/*
 * 1.一开始看题理解错了，以为是第k小，那么就是正常中序遍历，而这里是第k大，那么就让右子节点先入栈。
 * 2.今天只想到了迭代版本，递归版本我不会写。
 * 3.递归时，要判断k是否等于0，k是类成员变量，=时则一直向上return；
 * */
int main(){

    return 0;
}
