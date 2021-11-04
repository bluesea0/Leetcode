#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��10��30������8:59:57
//class Solution {
//public:
//    unordered_map<int,int> mp;
//    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
//        //��������漰��Ϊʲô��δ���ǰ��ͺ�����
//        //ǰ�������ĵ�һ���ͺ�����������һ���϶����ܸ��ڵ㡣
//        for(int i=0;i<post.size();i++){
//            mp[post[i]]=i;
//        }
//        TreeNode* t=new TreeNode(pre[0]);//�����֮ǰ����һ��������Ǹ���һ�����ڵ���
//        build(t,pre,post,1,pre.size()-1,0,post.size()-2);
//        return t;
//    }
//    void build(TreeNode*& root,vector<int>& pre, vector<int>& post��int index,int left,int right){
//        if(index>pre.size()||left>right) return;
//        int p=mp[pre[index]];//д����ȥ�˰�������Ҫ����������һ�����ڵ㣿Ȼ���أ�
//        //����Ҫ�������еĲ���rootָ��leftָ��ǰ����ôrightָ��˭�أ�
//        //�ؼ�������
//        root->left=������
//    }
//};//̫���ˡ�
/*
 * 1.����https://www.cnblogs.com/grandyang/p/10909191.html�Ľ��⣬���ˣ�ԭ�������������Ҳ��ջ�Ľⷨ
 *   ����ѧϰ.
 * */
class Solution {
public:
    unordered_map<int,int> mp;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        for(int i=0;i<post.size();i++){
            mp[post[i]]=i;
        }
        return build(pre,post,0,pre.size()-1,0,post.size()-1);
    }
    TreeNode* build(vector<int>& pre, vector<int>& post,int preL,int preR,int postL,int postR){
        if(preL>preR||postL>postR) return NULL;
        TreeNode* t=new TreeNode(pre[preL]);
        if(preL==preR) return t;//�Բۣ��˼�ֱ���жϷ����ˣ�
        int p=mp[pre[preL+1]],len=p-postL+1;//�����������ֻ��1��ô�죿�ǲ��ͷ���Խ���ˣ�
        t->left=build(pre,post,preL+1,preL+len,postL,p);
        t->right=build(pre,post,preL+len+1,preR,p+1,postR);
        //�������ǲ�֪�����������ĳ�����ô���ư�������������
        //զ����ô���أ����뿴�˼���ôд�ģ�Ϊʲô�Ҿ�д��������
        return t;
    }
};
//AC�ˣ���Ȼ���ǲ������������ж�ֱ�ӷ��أ�̫ţ�ˣ�
//���Ӷȣ��ٷ�������O(n^2)?�ҾͲ�̫�����ˣ�Ϊʲô�أ�Ϊɶ����n�أ��Ѿ��������������ˡ�
//105��106����O(n)�İ���ÿ���ڵ㹹��һ�ο���

//12-25
/*
 * 1.��������ͺܷ��գ���ȷʵ��ûʲô˼·���ӱܣ�����������⡣
ֻ֪��ǰ����  �����ң�  �����  ������ ��ô����ȥ�أ�
�����ܵĸ��ڵ���ȷ���������ӽڵ㶼�ǻ���һ��İ�����ôҪ������һ��ȥ�����أ�
   2.https://www.cnblogs.com/grandyang/p/10909191.html ���ķǳ���
	preorder -> [1] [2,4,5] [3,6,7]
	postorder -> [4,5,2] [6,7,3] [root]
	��һ�������У�ǰ��ĸ��ڵ�һ���ǳ����ں�����������һ���������������������ж���ѭ��������ɣ�
	̫�����ˡ��´θ�ϰһ��Ҫд���룡
 * */


int main(){

    return 0;
}
