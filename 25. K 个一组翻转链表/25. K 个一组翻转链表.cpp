#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年9月13日上午1:11:39
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr)return head;
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode*pre=dummy,*end=dummy;
        //ListNode* cur=head;//脑子中一片浆糊，头插法？怎么插？
        //怎么去分段呢？
        while(end!=nullptr){
            for(int i=0;i<k&&end!=nullptr;i++)
                end=end->next;
            if(end==nullptr)break;
            ListNode* start=pre->next;
            ListNode* next=end->next;
            end->next=nullptr;
            pre->next=reverse(start);
            start->next=next;
            pre=start;
            end=start;
        }
        return dummy->next;
    }
    ListNode* reverse(ListNode* head){
        //反转整条链表
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
 * 1.看了题解之后，发现关键的点要是思路清晰，pre和next标记之前和之后的节点，初始化时pre和end在一起。
 *   start和end标记反转的部分，注意在反转子函数之前，end->next=nullptr;简直是神来之笔好吧！
 *   一直都被这个地方指针会不会指错而困扰，直接赋值为空，子函数中反转就不会影响到它。
 * */
int main(){

    return 0;
}
