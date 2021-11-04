#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-12
class Solution {
private:
    void tree(Node* root,Node* &pre,Node* &head){//这里的root不能传引用！这是为什么呢？
        //我似乎明白了，指针传递其实也是值传递，复制了root节点，
        //原题目应该是不想修改原root的，所以通不过，需要只值传递指针复制一下就可以了。
        //但是这样的话函数参数复制的这个不会消失吗，拷贝的只是指针的值。
        if(!root) return;
        //中根遍历
        tree(root->left,pre,head);
        if(!head){
            head=root;
        }else{
            root->left=pre;
            pre->right=root;
        }
        pre=root;
        tree(root->right,pre,head);
    }
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        Node *pre=NULL,*head=NULL;
        tree(root,pre,head);
        head->left=pre;
        pre->right=head;
        return head;
    }
};

//5-18
/*
 * 1.感觉好有难度，一看到是懵的。我只想到了能否用vector来存储中序遍历的结果，这样再遍历结果设置指向？
 * 2.看了grand的解法还有迭代版本的，借助栈来实现，还是有难度的。
 * */
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
       //写一个迭代版本的：
        if(!root)return root;
        Node* head=NULL,*pre=NULL;
        vector<Node*> stk;
        Node*cur=root;
        while(cur||!stk.empty()){
            while(cur){
                stk.push_back(cur);
                cur=cur->left;
            }
            cur=stk.back();
            stk.pop_back();
            if(!head){
                head=cur;
            }else{
                pre->right=cur;
                cur->left=pre;
            }
            pre=cur;//天啦这个pre可怎么指啊。还需要pre吗？
            cur=cur->right;
        }
        head->left=pre;
        pre->right=head;
        return head;
    }
};
/*
 * 1.主要还是二叉树的中根遍历了。
 * */

//5-22
//写了一下递归版本，还是遇到了问题，需要复习的。
class Solution {
public:
    Node* head=NULL,*pre=NULL;
    Node* treeToDoublyList(Node* root) {
        //递归版本：
        if(!root)return root;
        inorder(root);
        head->left=pre;
        pre->right=head;
        return head;
    }
    void inorder(Node* root){
        if(!root)return;
        inorder(root->left);
        if(!head){//这个遍历到最左边的点时会使用到
            head=root;//使head指向最左边的点
        }
        if(pre){
            root->left=pre;//虽然原来的左右子数指针有指向了，但是为了兼顾左右子树的分别
            //所以这里两个都指向了。虽然方向没有变化。
            pre->right=root;//这里是怎么写的？总感觉对左右子数不太一样啊。
        }
        pre=root;
        inorder(root->right);
    }
};
//又写了一遍迭代的，多复习吧。。。
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        //利用栈来中序迭代遍历
        if(!root)return root;
        Node* head=NULL,*pre=NULL;
        stack<Node*> stk;
        Node* cur=root;
        while(!stk.empty()||cur){
            while(cur){
                stk.push(cur);
                cur=cur->left;
            }
            cur=stk.top();//这里直接使用之前的cur就行，不用重新定义OMG，不然局部变量更新
            //外面的不更新，就出错了。
            stk.pop();
            if(!head)head=cur;
            else{
                pre->right=cur;
                cur->left=pre;
            }
            pre=cur;
            cur=cur->right;
        }
        head->left=pre;
        pre->right=head;
        return head;
    }
};
/*1.关键的点时要记录head节点，是一直遍历到左节点的，然后记录中序遍历中的pre节点，用于改变指向。
 * */
int main(){

    return 0;
}
