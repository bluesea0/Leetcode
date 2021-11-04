#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年10月28日下午3:32:49
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
        //先写一下递归的吧，感觉递归就挺难的了。
        post(root);
        return ans;
    }
    void post(Node* root){
        if(!root) return;
        for(auto chi:root->children)
            post(chi);
        ans.push_back(root->val);
    }
};//递归看起来很简单就AC了，思想是：先递归处理完所有的子节点，
int main(){

    return 0;
}
