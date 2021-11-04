#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��10��29������2:47:01
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};//AC�ˡ�����ѧϰBFS��

//2021-6-12
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            int len=q.size();
            while(len--){
                TreeNode* t=q.front();
                q.pop();
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            ans++;
        }
        return ans;
    }
};
/*
 * 1.corner caseû���ǰ���ָ��Ϊ����ô�죿�㶼���������offerû�˰����ټ��ɡ�
 *  ���Һö����ĵط�д���ˣ����ǲ���û�����ӣ������ύ֮ǰһ��Ҫ�������ֶ������ˣ���ͨ�����ڿ���corner
 *  case����������Ǯ��
 * */
int main(){

    return 0;
}
