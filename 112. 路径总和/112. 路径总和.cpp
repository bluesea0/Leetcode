#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//10-23
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(!root->left&&!root->right){//�����һ�㱼��뵽�Ƿ������sum���жϣ����<0�ˣ�
                //��ֱ�ӷ���false�������벻�У���Ϊ�п��ܻ���ָ����İ���
            if(sum-root->val==0){
                return true;//����ֱ��return sum-root->val==0���ɣ�������Щ�ж�
            }
            return false;
        }
        if(root->left&&hasPathSum(root->left,sum-root->val)) return true;
        if(root->right&&hasPathSum(root->right,sum-root->val)) return true;
        return false;
    }
};
/*
1.һ����AC���ȽϿ��ġ�
2.���Ӷȣ�O(N)������ N �����Ľڵ�������ÿ���ڵ����һ�Ρ�
  O(H)������ H�����ĸ߶ȡ��ռ临�Ӷ���Ҫȡ���ڵݹ�ʱջ�ռ�Ŀ�����
  �����£���������״���ռ临�Ӷ�Ϊ O(N)��
  ƽ����������ĸ߶���ڵ����Ķ�������أ��ռ临�Ӷ�ΪO(logN)��
3.����BFS����ʵ�����벻��BFS����ôЩ���Դ��տա����츴ϰʱ��Ҫ����113һ��
*/

//10-27��ѧϰһ��BFS�ⷨ
/*
 * 1.����BFS�Ľⷨ��˭��˵һ���������أ��������ģ����������зֱ��¼�ڵ�Ͷ�Ӧ�ĺͣ�����
 *   �´θ�ϰдһ�£�Ӧ��Ҳ�ǲ��ѵġ�
 * */

int main(){

    return 0;
}
