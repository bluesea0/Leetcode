#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��5��20������12:33:14
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next)return NULL;//ֻ��һ���ڵ�fast�޷��ƶ�����Ҫ�ж�
        ListNode* slow=head,*fast=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)break;
        }
        if(fast!=slow)return NULL;
        ListNode* m=fast;
        slow=head;
        while(slow!=m){
            slow=slow->next;
            m=m->next;
        }
        return slow;
    }
};
int main(){

    return 0;
}
