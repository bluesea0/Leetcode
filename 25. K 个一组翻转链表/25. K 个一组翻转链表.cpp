#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��9��13������1:11:39
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr)return head;
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode*pre=dummy,*end=dummy;
        //ListNode* cur=head;//������һƬ������ͷ�巨����ô�壿
        //��ôȥ�ֶ��أ�
        while(end!=nullptr){
            for(int i=0;i<k&&end!=nullptr;i++)
                end=end->next;
            if(end==nullptr)break;
            ListNode* start=pre->next;
            ListNode* next=end->next;
            end->next=nullptr;
            pre->next=reverse(start);
            start->next=next;
            pre=start;
            end=start;
        }
        return dummy->next;
    }
    ListNode* reverse(ListNode* head){
        //��ת��������
        ListNode* pre=nullptr,*cur=head;
        while(cur){
            ListNode* next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
};
/*
 * 1.�������֮�󣬷��ֹؼ��ĵ�Ҫ��˼·������pre��next���֮ǰ��֮��Ľڵ㣬��ʼ��ʱpre��end��һ��
 *   start��end��Ƿ�ת�Ĳ��֣�ע���ڷ�ת�Ӻ���֮ǰ��end->next=nullptr;��ֱ������֮�ʺðɣ�
 *   һֱ��������ط�ָ��᲻��ָ������ţ�ֱ�Ӹ�ֵΪ�գ��Ӻ����з�ת�Ͳ���Ӱ�쵽����
 * */
int main(){

    return 0;
}
