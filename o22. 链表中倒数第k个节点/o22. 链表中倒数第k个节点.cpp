#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年5月17日上午9:58:20
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        // ListNode* dummy=new ListNode();
        // dummy->next=head;
        // while(--k){
        //     dummy=dummy->next;
        // }
        // return dummy->next;
        //不对不对，是倒数，上面写的这是正序数
        ListNode* fast=head,*slow=head;
        while(k--){
            fast=fast->next;
        }
        if(!fast)return head;
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        return slow->next;
    }
};
int main(){

    return 0;
}
