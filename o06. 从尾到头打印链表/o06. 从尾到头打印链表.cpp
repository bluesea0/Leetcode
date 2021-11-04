#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年5月22日上午9:00:17
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        //基于栈
        stack<ListNode*> stk;
        while(head){
            stk.push(head);
            head=head->next;
        }
        vector<int> ans;
        while(!stk.empty()){
            ans.push_back(stk.top()->val);
            stk.pop();
        }
        return ans;
    }
};
/*
 * 1.我看到这道题首先想到的还是顺序遍历然后反转vector，完全没有想到栈的思想，栈是先进后出，可以实现倒序。
 *   所以栈就和倒序绑定了！倒序倒叙和栈绑定了！
 * */
//评论区中的递归解法，真的牛批。
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if(!head)
            return {};
        vector<int> a=reversePrint(head->next);
        a.push_back(head->val);
        return a;
    }
};
int main(){

    return 0;
}
