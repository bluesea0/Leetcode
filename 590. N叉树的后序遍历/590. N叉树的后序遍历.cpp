#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��10��28������3:32:49
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;
    vector<int> postorder(Node* root) {
        //��дһ�µݹ�İɣ��о��ݹ��ͦ�ѵ��ˡ�
        post(root);
        return ans;
    }
    void post(Node* root){
        if(!root) return;
        for(auto chi:root->children)
            post(chi);
        ans.push_back(root->val);
    }
};//�ݹ鿴�����ܼ򵥾�AC�ˣ�˼���ǣ��ȵݹ鴦�������е��ӽڵ㣬
int main(){

    return 0;
}
