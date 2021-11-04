#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年9月19日下午7:20:23
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        ListNode* cur=dummy;
        int pre=0;
        while(l1||l2||pre){
            int t1=(l1==nullptr?0:l1->val);
            int t2=(l2==nullptr?0:l2->val);
            int t=t1+t2+pre;
            pre=t/10;
            t%=10;
            cur->next=new ListNode(t);
            cur=cur->next;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        return dummy->next;
    }
};
/*
 * 1.通过创建新的节点来进行的。还是比较简单吧，这里就需要注意循环判断的条件，因为最后可能有进位。
 *  可能两者长度不一样。
 * */
int main(){

    return 0;
}
