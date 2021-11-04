#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年9月23日上午12:12:22
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
 * 1.这个比较简单，因为重复的不删除，是会保留一个的。82题是这个的升级。
 * */
int main(){

    return 0;
}
