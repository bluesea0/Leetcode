#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��10��1������8:25:02
class Solution {
public:
    int ans;
    int sumNumbers(TreeNode* root) {
        ans=0;
        if(root==nullptr)return 0;
        sumn(root,root->val);
        return ans;
    }
    void sumn(TreeNode* root,int val){
        //if(root==nullptr)return;
        if(root->left==nullptr&&root->right==nullptr){
            ans+=val;
            return;
        }
        if(root->left)sumn(root->left,val*10+root->left->val);
        if(root->right)sumn(root->right,val*10+root->right->val);
    }
};
/*
 * 1.���ǱȽϼ򵥵ģ�һ����AC�ˡ�
 * 2.ʱ�临�ӶȺͿռ临�Ӷȶ���O(n)��ÿ���ڵ����һ�Σ��ռ������ʽ�Ķ�������
 * */
int main(){

    return 0;
}
