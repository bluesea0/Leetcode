#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��2������7:22:13
//class Solution {
//public:
//    void recoverTree(TreeNode* root) {
//        //��Ȼ֪�������������������ôȷ����Ҫ�����������ڵ���±��أ��Ҳ�̫����
//        //�ҷ�����
//        if(!root)return;
//        stack<TreeNode*> st;
//        st.push(root);//���ﲻ�����˼���ǰ��İ���
//        TreeNode* left=NULL,right=NULL;//��Ӧ�ñ���ڵ㣬Ӧ�ñ���ֵ
//        // int left=0,right=0;//Ӧ�ñ���ڵ㣬�����Ǳ���ֵ������
//        TreeNode* pre=root;
//        while(!st.empty()){//�������
//            TreeNode* top=st.top();
//            while(top->left){//�����д�������Ⱑ
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
//        }//���ҵ��죬���治��д����ô�����أ���ô������ָ���ء�
//        //��������ڵģ�����ǲ����ڵģ��ⶼ�Ǻܴ�����Ⱑ���ҷ����ˡ�
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
        while(!st.empty()||cur){//�������
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
 * 1.AC�ˣ���Ȼ������������ջʽ��������������ҳ���һ��morris����ɡ�
 *
 * */
class Solution1 {//�����morris�Ĺ��̣��Ҳ����ף�Ϊʲô����break��
public://��Ȼ�䣬����ʯ�������ˣ���Ϊ���Ѿ����������ṹ������Ҫ������ȥȻ���ٰ�cur.right��Ϊ�յģ�
    void recoverTree(TreeNode* root) {
        if(!root)return;
        TreeNode* cur=root,*pred=NULL;
        TreeNode* left=NULL,*right=NULL;
        while(cur){
            if(cur->left==NULL){//�����һ��ǲ�֪����ô��¼ǰһ���ڵ㰡
                if(pred&&pred->val>cur->val){
                    right=cur;
                    if(!left)left=pred;
                   // else break;//Ϊʲôע�͵����֮��Ϳ����ˣ�
                }
                pred=cur;
                cur=cur->right;
            }else{//Ѱ�������������ұߵĽڵ�
                TreeNode*pre=cur->left;
                while(pre->right&&pre->right!=cur)
                    pre=pre->right;
                if(!pre->right){//����������
                    pre->right=cur;
                    cur=cur->left;//�Ҿ�������д�Ļ�������3·��ڣ������Ͳ�֪������·�ж��أ�
                }else{//�������ѱ�����
                    pre->right=NULL;//�Ҳ�̫���װ�����������������ǰ�����������أ�
                    if(pred&&pred->val>cur->val){//������ʵֱ����pre��ok�ˣ�
                        right=cur;
                        if(!left)left=pred;//������Ҫ��pred����Ϊpre��һ���ֲ�����
                        //else break;
                    }
                    pred=cur;
                    cur=cur->right;
                }
            }
        }//����������ⶼ����������Ϊ�ջ��߱�����������֮���жϵģ���������Ϊʲô�أ�
        swap(left->val,right->val);
    }
};

//5-21
/*
 * 1.����Ĺؼ������������Ӧ���ǵ����ģ�������������������ڵ㣬��ʱ��Ϊ���������һ���ǲ����ڵģ�
 *   ��ô��ʱ�ͻ��������ط�����nums[i]>nums[i+1]���������������������ǽ������ڵģ���ôֻ��һ��
 *   ��ʱ��Ҫ�ҳ���������һ����xָ��ϴ��ֵ���ڶ�����yָ���С��ֵ���ǳ�������
 * */
int main(){

    return 0;
}
