#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��5��21������5:44:54
class Solution {
public:
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        path(root,"");
        return ans;//������Ҫ����ֵ��
    }
    void path(TreeNode* r,string s){
        if(!r)return;
        if(!r->left&&!r->right){
            s+=to_string(r->val);
            ans.push_back(s);
            return;
        }
        path(r->left,s+to_string(r->val)+"->");
        path(r->right,s+to_string(r->val)+"->");
    }
};
/*
 * 1.AC�ˣ����ⲻ�󣬵���̫�ֲ��ˣ��Һ������ύʱ��ȫ���Կ������ģ����������۾����ڴ���ɡ�
 *  ���ڴ����б�ǳ�������
 * */
int main(){

    return 0;
}
