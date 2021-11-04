#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��5��22������9:00:17
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        //����ջ
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
 * 1.�ҿ�������������뵽�Ļ���˳�����Ȼ��תvector����ȫû���뵽ջ��˼�룬ջ���Ƚ����������ʵ�ֵ���
 *   ����ջ�ͺ͵�����ˣ��������ջ���ˣ�
 * */
//�������еĵݹ�ⷨ�����ţ����
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
