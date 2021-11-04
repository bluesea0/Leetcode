#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//10-22
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 1.猛一看到这个题还真是有点慌啊。好难。
 */
class Solution {
public:
    ListNode* ans=NULL;//我选择了一个成员变量来保存根节点。
    ListNode* rever(ListNode* node){
        if(!node->next) {
            ans=node;
            return node;
        }
        ListNode* t=rever(node->next);
        t->next=node;
        node->next=NULL;//next就不要再指向t了。
        return node;//不是返回t哦
    }

    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        rever(head);
        return ans;
    }
};
/*
2.稍微分析一个样例：1->2->null;
  rever(1):t=rever(2)
    rever(2):return 2;
  t=2;t->next=1;但是目前1的next还指向2呢。。。
3.哇啊呜，上面的AC了，蛮开心的。虽然过程很坎坷。。。。
4.下面写一下迭代版本，用两个指针就可以完成，不需要队列。
*/
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* s=head,*f=head->next;
        while(f){
            ListNode* t=f->next;//两个指针不够，还需要一个临时的，记录下一个节点。
            f->next=s;
            if(s==head)s->next=NULL;
            s=f;f=t;
        }
        return s;
}};
/*
5.yes，AC了！
6.https://leetcode-cn.com/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-by-leetcode/
  官方解答给的JAva版本：
  class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        while (curr != null) {
            ListNode nextTemp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
}//我觉得我和它的区别就是多了个判断它写的更加简洁，就算是只有一个节点的情况，这里也
   进行了重新指向一个null，更加简洁了。
7.简洁递归版本：
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;//这个是个神仙语句啊，666.
        head->next = NULL;
        return newHead;
    }
};
//看到这个解法我只能直呼绝绝子。不写子函数，直接返回尾节点作为头节点，绝了。绝了。
*/

//10-28
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //递归怎么返回节点来着？
        if(!head || !head->next) return head;
        ListNode* t=reverseList(head->next);//这里只在递归出口处有作用，一直返回的都是新的head
        head->next->next=head;
        head->next=NULL;//这里要赋值为空，否则头结点的next还是指向原来的，会出现环的问题。
        return t;
}};
//递归的我也写出来了。真是不错啊。

//12-29
/*
 * 1.今天学习这道题，我连迭代地反转都给忘了！你说说你是个什么人呐。夺笋那。
 *   还以为自己之前会了，但是真的很难啊！
 * 2.官方题解中给的递归解法，它返回的一直是最后newhead节点，中间只是通过head改变了指向，使得逆向指。
 *   反转后新的返回的头结点是last，而原来的头结点变成了最后的节点。
 * */

//5-16
/*
 * 1.好久没看，就迭代也想不起来怎么写了，更别说递归了。所以还是要多复习的。
 * 2.迭代版本中，while循环判断条件cur为空，返回结果是pre，指向原先的最后节点，反转后的头结点。
 * */
int main(){

    return 0;
}
