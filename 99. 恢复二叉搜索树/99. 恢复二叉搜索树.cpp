#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月2日下午7:22:13
//class Solution {
//public:
//    void recoverTree(TreeNode* root) {
//        //虽然知道是中序遍历，但是怎么确定需要交换的两个节点的下标呢？我不太懂。
//        //我放弃。
//        if(!root)return;
//        stack<TreeNode*> st;
//        st.push(root);//这里不必让人家提前入的啊。
//        TreeNode* left=NULL,right=NULL;//不应该保存节点，应该保存值
//        // int left=0,right=0;//应该保存节点，而不是保存值。。。
//        TreeNode* pre=root;
//        while(!st.empty()){//中序遍历
//            TreeNode* top=st.top();
//            while(top->left){//这里就写的有问题啊
//                st.push(top->left);
//                top=top->left;
//            }
//            top=st.top();st.pop();
//            if(top->val<pre-val){
//                if(!left)left=pre;
//                else right=top;
//            }
//            pre=top;
//            top=top->right;
//        }//啊我的天，我真不会写，怎么考虑呢？怎么让它们指向呢。
//        //如果是相邻的，如果是不相邻的，这都是很大的问题啊，我放弃了。
//    }
//};
//11-3
class Solution {
public:
    void recoverTree(TreeNode* root) {
        if(!root)return;
        stack<TreeNode*> st;
        TreeNode* left=NULL,*right=NULL;
        TreeNode* pre=NULL,*cur=root;
        while(!st.empty()||cur){//中序遍历
            while(cur){
                st.push(cur);
                cur=cur->left;
            }
            cur=st.top();st.pop();
            if(pre&&(cur->val<pre->val)){
                right=cur;
                if(!left)left=pre;
                else break;
            }
            pre=cur;
            cur=cur->right;
        }
        swap(left->val,right->val);
    }
};
/*
 * 1.AC了！虽然很慢！上面是栈式中序遍历，下面我尝试一下morris中序吧。
 *
 * */
class Solution1 {//这个是morris的过程，我不明白，为什么不能break？
public://忽然间，电光火石就明白了！因为你已经更改了树结构啊！需要遍历回去然后再把cur.right置为空的！
    void recoverTree(TreeNode* root) {
        if(!root)return;
        TreeNode* cur=root,*pred=NULL;
        TreeNode* left=NULL,*right=NULL;
        while(cur){
            if(cur->left==NULL){//害，我还是不知道怎么记录前一个节点啊
                if(pred&&pred->val>cur->val){
                    right=cur;
                    if(!left)left=pred;
                   // else break;//为什么注释掉这个之后就可以了？
                }
                pred=cur;
                cur=cur->right;
            }else{//寻找左子树中最右边的节点
                TreeNode*pre=cur->left;
                while(pre->right&&pre->right!=cur)
                    pre=pre->right;
                if(!pre->right){//遍历左子树
                    pre->right=cur;
                    cur=cur->left;//我觉得这样写的话，就有3路岔口，根本就不知道在哪路判断呢？
                }else{//左子树已遍历完
                    pre->right=NULL;//我不太明白啊，遍历完左子树，前驱到底在哪呢？
                    if(pred&&pred->val>cur->val){//这里其实直接用pre就ok了？
                        right=cur;
                        if(!left)left=pred;//这里需要是pred，因为pre是一个局部变量
                        //else break;
                    }
                    pred=cur;
                    cur=cur->right;
                }
            }
        }//看的两个题解都是在左子树为空或者遍历完左子树之后判断的，但是这是为什么呢？
        swap(left->val,right->val);
    }
};

//5-21
/*
 * 1.问题的关键点是中序遍历应该是递增的，但是如果交换了两个节点，这时分为两种情况，一种是不相邻的，
 *   那么此时就会有两个地方产生nums[i]>nums[i+1]的情况，而不是增序，如果是交换相邻的，那么只有一处
 *   此时需要找出两处，第一处用x指向较大的值，第二处用y指向较小的值。非常厉害。
 * */
int main(){

    return 0;
}
