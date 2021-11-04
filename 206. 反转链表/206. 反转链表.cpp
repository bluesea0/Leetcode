#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//10-22
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 1.��һ��������⻹�����е�Ű������ѡ�
 */
class Solution {
public:
    ListNode* ans=NULL;//��ѡ����һ����Ա������������ڵ㡣
    ListNode* rever(ListNode* node){
        if(!node->next) {
            ans=node;
            return node;
        }
        ListNode* t=rever(node->next);
        t->next=node;
        node->next=NULL;//next�Ͳ�Ҫ��ָ��t�ˡ�
        return node;//���Ƿ���tŶ
    }

    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        rever(head);
        return ans;
    }
};
/*
2.��΢����һ��������1->2->null;
  rever(1):t=rever(2)
    rever(2):return 2;
  t=2;t->next=1;����Ŀǰ1��next��ָ��2�ء�����
3.�۰��أ������AC�ˣ������ĵġ���Ȼ���̺ܿ�����������
4.����дһ�µ����汾��������ָ��Ϳ�����ɣ�����Ҫ���С�
*/
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* s=head,*f=head->next;
        while(f){
            ListNode* t=f->next;//����ָ�벻��������Ҫһ����ʱ�ģ���¼��һ���ڵ㡣
            f->next=s;
            if(s==head)s->next=NULL;
            s=f;f=t;
        }
        return s;
}};
/*
5.yes��AC�ˣ�
6.https://leetcode-cn.com/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-by-leetcode/
  �ٷ�������JAva�汾��
  class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        while (curr != null) {
            ListNode nextTemp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
}//�Ҿ����Һ�����������Ƕ��˸��ж���д�ĸ��Ӽ�࣬������ֻ��һ���ڵ�����������Ҳ
   ����������ָ��һ��null�����Ӽ���ˡ�
7.���ݹ�汾��
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;//����Ǹ�������䰡��666.
        head->next = NULL;
        return newHead;
    }
};
//��������ⷨ��ֻ��ֱ�������ӡ���д�Ӻ�����ֱ�ӷ���β�ڵ���Ϊͷ�ڵ㣬���ˡ����ˡ�
*/

//10-28
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //�ݹ���ô���ؽڵ����ţ�
        if(!head || !head->next) return head;
        ListNode* t=reverseList(head->next);//����ֻ�ڵݹ���ڴ������ã�һֱ���صĶ����µ�head
        head->next->next=head;
        head->next=NULL;//����Ҫ��ֵΪ�գ�����ͷ����next����ָ��ԭ���ģ�����ֻ������⡣
        return t;
}};
//�ݹ����Ҳд�����ˡ����ǲ�����

//12-29
/*
 * 1.����ѧϰ����⣬���������ط�ת�������ˣ���˵˵���Ǹ�ʲô���š������ǡ�
 *   ����Ϊ�Լ�֮ǰ���ˣ�������ĺ��Ѱ���
 * 2.�ٷ�����и��ĵݹ�ⷨ�������ص�һֱ�����newhead�ڵ㣬�м�ֻ��ͨ��head�ı���ָ��ʹ������ָ��
 *   ��ת���µķ��ص�ͷ�����last����ԭ����ͷ����������Ľڵ㡣
 * */

//5-16
/*
 * 1.�þ�û�����͵���Ҳ�벻������ôд�ˣ�����˵�ݹ��ˡ����Ի���Ҫ�ิϰ�ġ�
 * 2.�����汾�У�whileѭ���ж�����curΪ�գ����ؽ����pre��ָ��ԭ�ȵ����ڵ㣬��ת���ͷ��㡣
 * */
int main(){

    return 0;
}
