#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��5��17������1:25:22
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        //˫ָ��
        ListNode* fast=head,*slow=head;
        while(k--){
            fast=fast->next;
        }
        if(!fast)return head->next;
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};
int main(){

    return 0;
}
