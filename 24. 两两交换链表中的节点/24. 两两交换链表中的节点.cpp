#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��5��21������4:49:57
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //�����汾��
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode* h1=head,*pre=dummy;//ʹ�������ڵ���ת����pre->h1->h2ת��֮��pre->h2->h1��
        while(h1&&h1->next){//�Դ˵���
            ListNode* h2=h1->next;
            h1->next=h2->next;
            h2->next=h1;
            pre->next=h2;
            pre=h1;
            h1=h1->next;
        }
        return dummy->next;
    }
};
//�ݹ�汾��
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) return head;
        //ListNode *nh=swapPairs(head->next); //�����Ǵ���ģ��ֲ��Ƿ�ת����
        //������ôд����Զ���صĵ���ͷ��㣬��ʵ�ʲ�����
        ListNode* nh=head->next;
        head->next=swapPairs(head->next->next);
        nh->next=head;
        return nh;
    }
};//�ݹ���һ��ʼûд������˼·���ˣ�������������ţƤ��

int main(){

    return 0;
}
