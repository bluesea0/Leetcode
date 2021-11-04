#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��3������1:05:50
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;//�����ģ��ǴӸ��ڵ㵽Ҷ�ӽڵ㣬�ҿ��ˡ�
        return mind(root);
    }
    int mind(TreeNode* root){
        if(!root->left&&!root->right) return 1;
        int left=INT_MAX,right=INT_MAX;
        if(root->left&&root->right){
            left=mind(root->left);
            right=mind(root->right);
        }else if(!root->left)
            right=mind(root->right);
        else if(!root->right)
            left=mind(root->left);
        return min(left,right)+1;
    }
};//��д���������밡��AC�ˡ���ֻ������5%������
//�������ı�������O(n)����������������O(logn)
//�ٷ�д�ĵݹ�úÿ�������Ҫѧϰ���´θ�ϰҪд�ģ�
//��ô�����������أ�BFS��ôд��
class Solution1 {
public:
    int minDepth(TreeNode* root) {
        //BFS�Ļ�˼·��ʲô�أ���ÿ���㶹Ҫ��һ��pair����¼������ȣ�
        //�������һ��Ҷ����ˣ���ֱ��return�ˣ�
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,1));//que.emplace(root, 1);ԭ���ǿ���ֱ��push�İ�������Ҫ()<>
        while(!q.empty()){
            TreeNode* f=q.front().first;
            int L=q.front().second;q.pop();
            if(!f->left&&!f->right)return L;//���������Ҷ���
            if(f->left)q.push(make_pair(f->left,L+1));
            if(f->right)q.push(make_pair(f->right,L+1));
        }
        return 0;//ֻ�������Ե�return�ˡ�
    }
};//�����ҵ�BFS�ⷨ���ٶȸ������ٷ����ҵĽⷨ��һ���ģ�����!
/*
 * �ݹ�ⷨ��https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/solution/li-jie-zhe-dao-ti-de-jie-shu-tiao-jian-by-user7208/
 * �����������ţ����
 * class Solution {
    public int minDepth(TreeNode root) {
        if(root == null) return 0;
        int m1 = minDepth(root.left);
        int m2 = minDepth(root.right);
        //1.������Ӻ��Һ�����Ϊ�յ������ֱ�ӷ���m1+m2+1
        //2.�������Ϊ�գ����ؽ�С���+1
        return root.left == null || root.right == null ? m1 + m2 + 1 : Math.min(m1,m2) + 1;
    }
}
�˼Ҽ���һ�£�ѧ���ˡ�
 * */
int main(){

    return 0;
}
