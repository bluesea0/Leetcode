#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��9��23������12:12:22
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        ListNode* pre=head,*cur;
        while(pre->next){
            cur=pre->next;
            if(pre->val==cur->val){
                pre->next=cur->next;
                delete cur;
            }else pre=pre->next;
        }
        return head;
    }
};
/*
 * 1.����Ƚϼ򵥣���Ϊ�ظ��Ĳ�ɾ�����ǻᱣ��һ���ġ�82���������������
 * */
int main(){

    return 0;
}
