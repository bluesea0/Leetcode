#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��5��22������4:52:46
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
                //if(ans.size()%2)reverse(t.begin(),t.end());//��������ô����ѭ�����ˣ�
            }
            if(ans.size()%2)reverse(t.begin(),t.end());
            ans.push_back(t);
        }
        return ans;
    }
};
/*
 * 1.������ʹ���������ص�˼�룬���Ƿ�ת����������ע��Ҫ����whileѭ�����氡��
 * 2.���濴��˫�˶��еĽṹ��
 * */
//������������python�汾��д����
//class Solution:
//    def levelOrder(self, root: TreeNode) -> List[List[int]]:
//        if not root: return []
//        res, deque = [], collections.deque([root])
//        while deque:
//            tmp = collections.deque()//���м�洢�����ʹ��˫����У�Ȼ�������ż��ȷ����ͷ�뻹��β��
//            for _ in range(len(deque))://ʵ���ϵĲ�α��������˳���ǲ���ġ�
//                node = deque.popleft()
//                if len(res) % 2: tmp.appendleft(node.val) # ż���� -> ����ͷ��
//                else: tmp.append(node.val) # ������ -> ����β��
//                if node.left: deque.append(node.left)
//                if node.right: deque.append(node.right)
//            res.append(list(tmp))//����ֱ�ӽ�����Ϊ���ؽ����������C++�������ǲ��ݵİɣ�
//        return res

int main(){

    return 0;
}
