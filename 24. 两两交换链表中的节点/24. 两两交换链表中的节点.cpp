#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年5月21日下午4:49:57
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //迭代版本：
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode* h1=head,*pre=dummy;//使用三个节点来转换，pre->h1->h2转化之后pre->h2->h1，
        while(h1&&h1->next){//以此迭代
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
//递归版本：
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) return head;
        //ListNode *nh=swapPairs(head->next); //这里是错误的，又不是反转链表，
        //上面这么写是永远返回的点是头结点，但实际并不是
        ListNode* nh=head->next;
        head->next=swapPairs(head->next->next);
        nh->next=head;
        return nh;
    }
};//递归我一开始没写出来，思路错了，但看了题解觉得牛皮。

int main(){

    return 0;
}
