#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年5月20日下午11:34:14
class Solution {
public:
    void reorderList(ListNode* head) {
        //如果可以用额外空间的话
        if(!head||!head->next)return;
        vector<ListNode*> nodes;
        ListNode* temp=head;
        while(temp){
            nodes.push_back(temp);
            temp=temp->next;
        }
        //设置一个哑节点
        int i=0,j=nodes.size()-1;
        //偶数节点从while退出，奇数个节点从while中的if判断退出
        while(i<j){//这个while循环是抄官解的。我自己没写出来
            nodes[i]->next=nodes[j];//因为存到了vector里，直接使用下标就可以访问，不用再定义指针了。
            i++;
            if(i==j)break;//针对奇数节点
            nodes[j]->next=nodes[i];
            j--;
        }
        nodes[i]->next=NULL;
    }
};
/*
 * 1.下面是空间为O(1)的解法，首先找到链表中点，然后反转后半部分，然后合并两个链表。
 * */
//5-21
class Solution {//真的好难。
public:
    void reorderList(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        //如果是奇数则slow指向正中间的位置，如果是偶数slow指向中间靠后的那个节点
        //利用头插法，反转后半部分链表
        // ListNode* pre=new ListNode();
        // pre->next=slow->next;
        // slow->next=NULL;
        // ListNode* cur=pre->next;
        // while(cur->next){
        //     ListNode* t=cur->next;
        //     cur->next=t->next;
        //     t->next=pre->next;
        //     pre->next=t;
        // }
        //这里反转写的太有问题了，自作聪明以为是反转部分链表用头插法，我绝了，其实实际上是
        //反转整个啊，pre直接指向nullptr就行。
        ListNode* h2=slow->next;
        slow->next=NULL;
        ListNode* pre=NULL,*cur=h2;
        while(cur){
            ListNode* t=cur->next;
            cur->next=pre;
            pre=cur;
            cur=t;
        }
        //此时pre就是后半部分新的头结点
        ListNode*h1=head;
        h2=pre;
        while(h1&&h2){
            //我实在是写不下去了。要真的将两者分开吗？
            ListNode* t1=h1->next;
            ListNode* t2=h2->next;
            h1->next=h2;
            h1=t1;
            h2->next=h1;
            h2=t2;
        }
    }
};

//5-24
//尝试用deque来写，双向队列
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head)return;
        deque<ListNode*> dq;
        ListNode* cur=head;
        while(cur){
            dq.push_back(cur);
            cur=cur->next;
        }
        //cout<<dq.size();
        cur=dq.front();
        dq.pop_front();
        while(!dq.empty()){
            cur->next=dq.back();
            dq.pop_back();
            cur=cur->next;
            if(dq.empty())break;
            cur->next=dq.front();
            dq.pop_front();
            cur=cur->next;
        }
        cur->next=nullptr;//一定要指向null，不然就会报AddressSanitizer: heap-buffer-overflow on address
        //因为最后的节点还指向原来的位置，就会出错！
    }
};
/*
 * 1.AC了，但是遇到了问题！
 * */

//9-19
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return;
        ListNode* fast=head->next,*slow=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* nh=slow->next;
        slow->next=nullptr;
        nh=reverseList(nh);
        combine(head,nh);
    }
    void combine(ListNode * l1,ListNode* l2){
        ListNode* temp;
        while(l1&&l2){
            temp=l1->next;
            l1->next=l2;
            l1=temp;
            temp=l2->next;
            l2->next=l1;
            l2=temp;
        }
    }
    ListNode* reverseList(ListNode* head){
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
 * 1.拆分为两个链表，注意fast初始化为head->next，然后直接slow->next就是nh，
 *   之后合并两个链表也是很神奇。需要有一个temp来暂存后继节点。
 * */
int main(){

    return 0;
}
