#include <iostream>
#include<vector>
#include<queue>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//10-20
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head==NULL) return NULL;
//        ListNode* fakeh(0);
        ListNode* fakeh=new ListNode(-1);
        fakeh->next=head;//����ط���ʼ�����������⣬����ô��ʼ���أ�
        ListNode* f=head,*s=fakeh;
        while(f){
            if(f->val==val){
                s->next=f->next;
                break;
            }
            f=f->next;
            s=s->next;
        }
        return fakeh->next;
    }
};
/*
1.����Ĵ���AC�ˣ�Ӧ��û��ʲô�����˰ɡ�
2.�������еĵ�ָ��汾�������½�ͷ�ڵ㣬ѧ���ˡ�
class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        if (head == null) return null;
        if (head.val == val) return head.next;
        ListNode cur = head;
        while (cur.next != null && cur.next.val != val)
            cur = cur.next;
        if (cur.next != null)
            cur.next = cur.next.next;
        return head;
    }
}
*/
int main(){

    return 0;
}
