#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��9��17������1:32:40
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //��һ��Ϊ��
        if(head==nullptr||head->next==nullptr)return head;
        ListNode* fast=head,*slow=head;
        while(fast->next&&fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* nh=slow->next;
        slow->next=nullptr;
       return  merge(sortList(head),sortList(nh));//ע������ĵ��ã�
    }//merge�Ǻϲ�����sort�Ľ����ʵ�ֵģ�ţ����

    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* dummy=new ListNode();
        ListNode* cur=dummy;
        while(l1&&l2){
            if(l1->val<l2->val){
                cur->next=l1;
                l1=l1->next;
            }else{
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        if(l1)cur->next=l1;
        else cur->next=l2;
        return dummy->next;
    }
};
int main(){

    return 0;
}
