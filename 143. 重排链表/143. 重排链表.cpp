#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��5��20������11:34:14
class Solution {
public:
    void reorderList(ListNode* head) {
        //��������ö���ռ�Ļ�
        if(!head||!head->next)return;
        vector<ListNode*> nodes;
        ListNode* temp=head;
        while(temp){
            nodes.push_back(temp);
            temp=temp->next;
        }
        //����һ���ƽڵ�
        int i=0,j=nodes.size()-1;
        //ż���ڵ��while�˳����������ڵ��while�е�if�ж��˳�
        while(i<j){//���whileѭ���ǳ��ٽ�ġ����Լ�ûд����
            nodes[i]->next=nodes[j];//��Ϊ�浽��vector�ֱ��ʹ���±�Ϳ��Է��ʣ������ٶ���ָ���ˡ�
            i++;
            if(i==j)break;//��������ڵ�
            nodes[j]->next=nodes[i];
            j--;
        }
        nodes[i]->next=NULL;
    }
};
/*
 * 1.�����ǿռ�ΪO(1)�Ľⷨ�������ҵ������е㣬Ȼ��ת��벿�֣�Ȼ��ϲ���������
 * */
//5-21
class Solution {//��ĺ��ѡ�
public:
    void reorderList(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        //�����������slowָ�����м��λ�ã������ż��slowָ���м俿����Ǹ��ڵ�
        //����ͷ�巨����ת��벿������
        // ListNode* pre=new ListNode();
        // pre->next=slow->next;
        // slow->next=NULL;
        // ListNode* cur=pre->next;
        // while(cur->next){
        //     ListNode* t=cur->next;
        //     cur->next=t->next;
        //     t->next=pre->next;
        //     pre->next=t;
        // }
        //���ﷴתд��̫�������ˣ�����������Ϊ�Ƿ�ת����������ͷ�巨���Ҿ��ˣ���ʵʵ������
        //��ת��������preֱ��ָ��nullptr���С�
        ListNode* h2=slow->next;
        slow->next=NULL;
        ListNode* pre=NULL,*cur=h2;
        while(cur){
            ListNode* t=cur->next;
            cur->next=pre;
            pre=cur;
            cur=t;
        }
        //��ʱpre���Ǻ�벿���µ�ͷ���
        ListNode*h1=head;
        h2=pre;
        while(h1&&h2){
            //��ʵ����д����ȥ�ˡ�Ҫ��Ľ����߷ֿ���
            ListNode* t1=h1->next;
            ListNode* t2=h2->next;
            h1->next=h2;
            h1=t1;
            h2->next=h1;
            h2=t2;
        }
    }
};

//5-24
//������deque��д��˫�����
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head)return;
        deque<ListNode*> dq;
        ListNode* cur=head;
        while(cur){
            dq.push_back(cur);
            cur=cur->next;
        }
        //cout<<dq.size();
        cur=dq.front();
        dq.pop_front();
        while(!dq.empty()){
            cur->next=dq.back();
            dq.pop_back();
            cur=cur->next;
            if(dq.empty())break;
            cur->next=dq.front();
            dq.pop_front();
            cur=cur->next;
        }
        cur->next=nullptr;//һ��Ҫָ��null����Ȼ�ͻᱨAddressSanitizer: heap-buffer-overflow on address
        //��Ϊ���Ľڵ㻹ָ��ԭ����λ�ã��ͻ����
    }
};
/*
 * 1.AC�ˣ��������������⣡
 * */

//9-19
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return;
        ListNode* fast=head->next,*slow=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* nh=slow->next;
        slow->next=nullptr;
        nh=reverseList(nh);
        combine(head,nh);
    }
    void combine(ListNode * l1,ListNode* l2){
        ListNode* temp;
        while(l1&&l2){
            temp=l1->next;
            l1->next=l2;
            l1=temp;
            temp=l2->next;
            l2->next=l1;
            l2=temp;
        }
    }
    ListNode* reverseList(ListNode* head){
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
 * 1.���Ϊ��������ע��fast��ʼ��Ϊhead->next��Ȼ��ֱ��slow->next����nh��
 *   ֮��ϲ���������Ҳ�Ǻ����档��Ҫ��һ��temp���ݴ��̽ڵ㡣
 * */
int main(){

    return 0;
}
