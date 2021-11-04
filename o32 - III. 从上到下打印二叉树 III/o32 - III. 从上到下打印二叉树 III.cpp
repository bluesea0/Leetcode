#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年5月22日下午4:52:46
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> t;
            int len=q.size();
            while(len--){
                TreeNode* f=q.front();q.pop();
                t.push_back(f->val);
                if(f->left)q.push(f->left);
                if(f->right)q.push(f->right);
                //if(ans.size()%2)reverse(t.begin(),t.end());//这里你怎么放在循环内了？
            }
            if(ans.size()%2)reverse(t.begin(),t.end());
            ans.push_back(t);
        }
        return ans;
    }
};
/*
 * 1.首先我使用了最朴素的思想，就是反转向量。但是注意要放在while循环外面啊。
 * 2.下面看看双端队列的结构。
 * */
//评论区给出的python版本的写法。
//class Solution:
//    def levelOrder(self, root: TreeNode) -> List[List[int]]:
//        if not root: return []
//        res, deque = [], collections.deque([root])
//        while deque:
//            tmp = collections.deque()//将中间存储结果的使用双向队列，然后根据奇偶来确定从头入还是尾入
//            for _ in range(len(deque))://实际上的层次遍历放入的顺序还是不变的。
//                node = deque.popleft()
//                if len(res) % 2: tmp.appendleft(node.val) # 偶数层 -> 队列头部
//                else: tmp.append(node.val) # 奇数层 -> 队列尾部
//                if node.left: deque.append(node.left)
//                if node.right: deque.append(node.right)
//            res.append(list(tmp))//这里直接将它作为返回结果，但是在C++中类型是不容的吧？
//        return res

int main(){

    return 0;
}
