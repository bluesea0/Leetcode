#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��3��23������5:34:37
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        //��Ҫһ���ݹ麯�����㷵�������ĸ߶�
        //���ѭ����Ƕ�������е�����
        return balance(root)>=0;
    }
    int balance(TreeNode* root){
        if(!root)return 0;
        int left=balance(root->left);
        int right=balance(root->right);
        if(left==-1||right==-1||abs(left-right)>1)
            return -1;
        return max(left,right)+1;
    }
};
/*
 * 1.�������ȫ����easy���������Ϊ��һ��ʼ����ȫ�㲻��˼·����Ϊ��ȷ������Ҫ����ʲô���϶�Ҫ��һ����������
 *   �����ĸ߶ȣ��������������Ҫ���ز���ֵ���ҾͲ����ˡ����˽���֮�����Զ����µģ����ظ����㡣
 *   ��ʵ�ҵ�˼·���Ե����ϵؼ��������ĸ߶ȡ�
 * */

//6-12
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        //corner case��������ƽ���������

        return balance(root)==-1?false:true;
    }
    int balance(TreeNode* root){
        if(!root)return 0;
        int left=balance(root->left);
        int right=balance(root->right);
        if(left==-1||right==-1||abs(right-left)>1)return -1;//��������������һ����ƽ��
        return max(left,right)+1;
    }
};
/*
 * 1.��֮ǰд��һ�������ⲻ��
 * */
int main(){

    return 0;
}
