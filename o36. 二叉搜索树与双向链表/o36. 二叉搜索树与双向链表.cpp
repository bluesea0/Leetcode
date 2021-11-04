#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-12
class Solution {
private:
    void tree(Node* root,Node* &pre,Node* &head){//�����root���ܴ����ã�����Ϊʲô�أ�
        //���ƺ������ˣ�ָ�봫����ʵҲ��ֵ���ݣ�������root�ڵ㣬
        //ԭ��ĿӦ���ǲ����޸�ԭroot�ģ�����ͨ��������Ҫֵֻ����ָ�븴��һ�¾Ϳ����ˡ�
        //���������Ļ������������Ƶ����������ʧ�𣬿�����ֻ��ָ���ֵ��
        if(!root) return;
        //�и�����
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
 * 1.�о������Ѷȣ�һ�������µġ���ֻ�뵽���ܷ���vector���洢��������Ľ���������ٱ����������ָ��
 * 2.����grand�Ľⷨ���е����汾�ģ�����ջ��ʵ�֣��������Ѷȵġ�
 * */
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
       //дһ�������汾�ģ�
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
            pre=cur;//�������pre����ôָ��������Ҫpre��
            cur=cur->right;
        }
        head->left=pre;
        pre->right=head;
        return head;
    }
};
/*
 * 1.��Ҫ���Ƕ��������и������ˡ�
 * */

//5-22
//д��һ�µݹ�汾���������������⣬��Ҫ��ϰ�ġ�
class Solution {
public:
    Node* head=NULL,*pre=NULL;
    Node* treeToDoublyList(Node* root) {
        //�ݹ�汾��
        if(!root)return root;
        inorder(root);
        head->left=pre;
        pre->right=head;
        return head;
    }
    void inorder(Node* root){
        if(!root)return;
        inorder(root->left);
        if(!head){//�������������ߵĵ�ʱ��ʹ�õ�
            head=root;//ʹheadָ������ߵĵ�
        }
        if(pre){
            root->left=pre;//��Ȼԭ������������ָ����ָ���ˣ�����Ϊ�˼�����������ķֱ�
            //��������������ָ���ˡ���Ȼ����û�б仯��
            pre->right=root;//��������ôд�ģ��ܸо�������������̫һ������
        }
        pre=root;
        inorder(root->right);
    }
};
//��д��һ������ģ��ิϰ�ɡ�����
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        //����ջ�������������
        if(!root)return root;
        Node* head=NULL,*pre=NULL;
        stack<Node*> stk;
        Node* cur=root;
        while(!stk.empty()||cur){
            while(cur){
                stk.push(cur);
                cur=cur->left;
            }
            cur=stk.top();//����ֱ��ʹ��֮ǰ��cur���У��������¶���OMG����Ȼ�ֲ���������
            //����Ĳ����£��ͳ����ˡ�
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
/*1.�ؼ��ĵ�ʱҪ��¼head�ڵ㣬��һֱ��������ڵ�ģ�Ȼ���¼��������е�pre�ڵ㣬���ڸı�ָ��
 * */
int main(){

    return 0;
}
