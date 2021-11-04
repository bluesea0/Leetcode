#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��10��28������4:48:25
class Solution {
public:
    int ans=0;
    int maxPathSum(TreeNode* root) {
        //˼·���ݹ�ؼ�����ÿ���ڵ���Ϊ���ڵ���Ӷ������ĺͣ�ѡ�����е����ֵ����
        if(!root)return 0;
        ans=root->val;
        path(root);
        return ans;
    }
    int path(TreeNode* root){
        if(!root->left&&!root->right){
            ans=max(ans,root->val);
            return root->val;
        }
        int left=0,right=0;
        if(root->left)left=path(root->left);
            //���ԣ��ҵ�˼·�����ˣ�����Ҳ��������������ĺͣ���ô�������ؾͲ�һ���ˡ�
        if(root->right)right=path(root->right);
//        int s=max(max(left+root->val,right+root->val),left+right+root->val);
//        ans=max(s,ans);
        //�������ֱ�����жϣ��������������������������Լ�������������Ϊ�����޷�����ʱ��
        //ǰ����ҷ���s����˼�ǣ�ֻ��ȡ��·������·�����߶���ȡ��
        int s=max(max(left+root->val,right+root->val),root->val);
        ans=max(max(s,left+right+root->val),ans);//������������ѡ��
        //[5,4,8,11,null,13,4,7,2,null,null,null,1]
        //48 ,�����������55��������������ǲ��Ե��ˡ�������Ϊ����Ӧ�������ҵĺͣ���Ϊ
        //�����ػص��ߣ��ҵļ��㷽�����Ὣ�����������㣬������һ��·���ˡ�����
        return s;
    }
};
/*
 * 1.https://www.cnblogs.com/grandyang/p/4280120.html���˼�������డ���㻹��Ҫѧϰ����
 *   �����Ҿ������Ѿ��ܲ����ˣ��ܹ�AC��˵���һ�����˼·�ģ������ܹ��������Ǻ����������
 * 2.�������������У����Ҫ�����������·������ô�죿�Ҿ����������һ�����Ե�ʱ��ܺõ����Ⱑ��
 *   ����һ������д������������һ��Ҫ��˼·��˼·ֵǮ��
 *   �������뻹�Ǿ������Ǯ�����ã����츴ϰ��ʱ�򿴿������еĽ��
 * */

//10-29
//�ָ�ϰ��һ�£����Ǿ���Ҫ����·�������Ǯ���ò��ˣ�Ҳ���Կ����������еĴ��룬���鰡�����ˡ�

//11-18
/*
 * 1.��ϰ�ܹ��뵽˼·���ݹ��ȥ���㣬�ݹ鷵��������Ҷ��㣬�ж�������ʱ����Ҫ�ж����ֵ�maxֵ
 *   ���ڵ㣬���ڵ�+��ڵ㣬���ڵ�+�ҽڵ㣬���ڵ�+��ڵ�+�ҽڵ�
 * */

//12-25
class Solution2 {
public:
    int ans=INT_MIN;//���ģ�ԭ��[-3]���������Ҫ��0�����˾��ˡ�
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* r){
        if(!r)return 0;
        if(!r->left&&!r->right){
            ans=max(ans,r->val);//���[1]����ֻ��һ���ڵ�Ķ�����
             return r->val;
        }
        int left=dfs(r->left);
        int right=dfs(r->right);
        int now=max(max(left,right)+r->val,r->val);//�ҵ��죬��֪���ˣ����ǲ��ܹ���ģ�
        ans=max(ans,max(now,left+right+r->val));
        return now;//������ص�ʱ��϶���Ҫ�������ڵ�ġ��Ҷ����˰��������������ˣ��ؼ��㲻�ڸ��ڵ�
    }//[5,4,8,11,null,13,4,7,2,null,null,null,1],�����55��Ԥ����48.
    //�Һ����������ˣ��ϵ�����·�϶��ǲ���ƴ�����İ��������ô���ư�
    //Ӧ�����ڷ��ص�ʱ�����
};
/*
 * 1.�������������Լ�Ĺ�ȥ����д����ģ����ǿ����ϴ�д����������֮ǰ�ˣ�Ȼ���д�ˡ�
 *   ��Ȼ�����˸�������⣬���ǹؼ��ĵ��ǰ���������򣬲����й����
 * 2.ʱ��ռ�O(N)������ÿ���ڵ���ʲ����� 2�Ρ��ռ����������£��ռ临�Ӷ���Ҫȡ���ڵݹ���ò�����
 *   ���������ڶ������ĸ߶ȣ������£��������ĸ߶ȵ��ڶ������еĽڵ������
 * */

//2021-6-5
class Solution {
public:
    int ans=INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root){//��rootΪ���ڵ㣬���Ұ���root��ֻ��������һ�ֻroot�����ֵ
        if(!root)return 0;
        int left=dfs(root->left);
        int right=dfs(root->right);
        int m=max(left,right)+root->val;
        int t=max(max(m,left+right+root->val),root->val);
        ans=max(ans,t);
        return max(m,root->val);
    }
};
/*
 * 1.һ��AC����������̫������
 * 2.����Ϊ�ұ�֮ǰ�н����ˣ������dfs��ֱ�ӽ��ж����������Ƿ�Ϊ������Ϊ�ݹ�����ı�׼������д
 *   ���ж����������Ƿ�Ϊ���پ����Ƿ�ݹ飬����࣡
 * */

//9-19
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root){//��rootΪ���ڵ㣬���Ұ���root��ֻ��������һ�ֻroot�����ֵ
        if(!root)return 0;
        int left=max(dfs(root->left),0);//����Ǹ�������Ե�
        int right=max(dfs(root->right),0);
        int maxGain=max(max(left,right)+root->val,root->val);
        int m=max(maxGain,left+right+root->val);//�����һ������������������
        ans=max(ans,m);
        return maxGain;//�ؼ��Ƿ��ص�ʱ��ֻ���Ǹ�or��+��or+��+��
    }
};
int main(){

    return 0;
}
