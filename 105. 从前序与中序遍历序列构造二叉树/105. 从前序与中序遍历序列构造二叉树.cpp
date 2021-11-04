#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��10��30������7:16:23
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //˼·��ǰ������е�ÿһ���㶼��Ϊ���ڵ㣬������������ҵ���Ӧ��λ�ã�
        //�ݹ鹹����������
        TreeNode* root=build(preorder,inorder,0,0,inorder.size()-1);
        return root;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int pre,int left,int right){
    	if(pre<0 || pre>=preorder.size()||left>right) return NULL;//�������ж���Ҫ�����[1,2][1,2]����
        //������ʵpre�������0�İ�������
    	if(left==right){
            TreeNode* t=new TreeNode(inorder[left]);
            return t;
    }
        int p=left;
       while(inorder[p]!=preorder[pre])p++;
       TreeNode* root=new TreeNode(preorder[pre]);
       root->left=build(preorder,inorder,pre+1,left,p-1);
       root->right=build(preorder,inorder,pre+p-left+1,p+1,right);//������������������
       return root;
    }
};
/*
 * 1.����д��ʱ�������˺ܶ�С���⡣�������ԵĻ��϶������²��õ�ӡ�󡣡�����������AC�ˡ���
 * 2.�ڶ��׶Σ�ʹ�ù�ϣ��洢inorder�ڵ�Ͷ�Ӧ���±ꡣ
 * */
class Solution1 {//ʱ�临�Ӷ�O(n)���ռ�Ҳ�ǣ��洢��ϣ���������ֱ����Ļ���ʱ�临�Ӷ�Ӧ��Ҳ�����ˡ�
public:
    unordered_map<int,int> mp;//ʹ�ù�ϣ���洢֮���44ms��24ms��ţ����
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=build(preorder,inorder,0,0,inorder.size()-1);
        return root;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int pre,int left,int right){
    	if(left>right) return NULL;//����ֻ��Ҫһ���жϼ��ɡ�����˳�������ֵǮ����
//        if(left==right){//����ʵ������ж����е����İ���
//            TreeNode* t=new TreeNode(inorder[left]);
//            return t;
//    }
        int p=mp[preorder[pre]];
       TreeNode* root=new TreeNode(preorder[pre]);
       root->left=build(preorder,inorder,pre+1,left,p-1);//���left==right�Ļ������������᷵�ؿյġ�
       root->right=build(preorder,inorder,pre+p-left+1,p+1,right);
       return root;
    }
};
/*
 * 3.��Ȼ�����е����Ľⷨ�����������һ������츴ϰ�ɣ�����û�����ˡ�
 * 4.����һ��Ҫ��5���ӿ�һ�½�����Ƶ��Ϊʲô��������ô�����糱��������
 * */

//12-25
/*
 * 1.�ؼ��ĵ�������������������Խ�����ϣ��ӳ���±꣬ʡȥ������ʱ�䣻
 * �ڽ���pre����preorder�еļ�����£��۷���������left<right����null���ɡ�
 * 2.�����о���θ�ϰ��ͦ���ջ�ġ�
 * */

//5-22
class Solution {
public:
    unordered_map<int,int> um;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int m=preorder.size();
        for(int i=0;i<inorder.size();i++){
            um[inorder[i]]=i;//�����������ظ�Ԫ��
        }
        return build(preorder,inorder,0,m-1,0,m-1);
    }
    TreeNode* build(vector<int>& preorder,vector<int>& inorder,int pre1,int pre2,int in1,int in2){
        if(pre1>pre2) return NULL;
        TreeNode* root=new TreeNode(preorder[pre1]);
        int index=um[preorder[pre1]];
        int left_num=index-in1;
        int right_num=in2-index;
        root->left=build(preorder,inorder,pre1+1,pre2-right_num,in1,index-1);
        root->right=build(preorder,inorder,pre1+left_num+1,pre2,index+1,in2);
        return root;
    }
};
/*
 * 1.��д��һ�£�����ûʲô���⡣
 * 2.�����Ļ���˵һ��˼·��ǰ��������Ӹ��ڵ�root��ʼ��ֻҪ�����ӽڵ㣬��һֱ�������·��ߣ�ֱ�������½ǡ�
 * ������������Ǵ������½����ϣ�ʾ���е�4-5-8-9-3������������ڵ������ӽڵ㣬���ת��ʾ���е�8-10����
 ��ˣ������е�if������ǰ������һֱ���������������������inorder[inorderIndex]����ʾ�������½ǣ�
 ��ʱ����Ҫ�����߲�������������Ҳ����while����顣
����ÿ̫������̫���ˡ�
 * */


int main(){

    return 0;
}
