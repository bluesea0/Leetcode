#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//10-24，剑指offer52题
/*
1.利用环的思想，进行遍历，当其中一个到达尾端的时候，再从另一个节点头节点开始，这样的话
  总体走过的路径长度是一样的。
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * h1=headA,*h2=headB;
        while(h1&&h2&&h1!=h2){
            h1=h1->next;
            h2=h2->next;
        }
        if(h1==h2) return h1;//处理等长相交
        //但是如果两者不相交那你怎么判断？会出不去函数死循环吗？
        if(!h1)h1=headB;
        else if(!h2)h2=headA;
        while(h1&&h2){
            h1=h1->next;
            h2=h2->next;
        }
        if(!h1)h1=headA;
        else if(!h2)h2=headB;
        while(h1!=h2&&h1&&h2){
            h1=h1->next;
            h2=h2->next;
        }
        return h1;
    }
};
/*
2.上面是我写的垃圾代码，第一个样例都没通过，我不知道是为什么啊，因为我在考虑如果是两个
  不相交的链表，如何处理，但是看了人家给的代码，发现确实是啊，那样的话就h1和h2都为空，
  也会正常地返回。
3.grand给出了一个正常的解法，也可以实现O(n)的时间复杂度，O(1)的内存。
*/
class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ha=headA,*hb=headB;
            ka=0,kb=0;
        while(ha){
            ha=ha->next;
            ka++;
        }
        while(hb){
            hb=hb->next;
            kb++;
        }
        ha=headA;hb=headB;
        //把较长的链表指针移动，啊，那写的好麻烦啊。
        if(ka>kb){
            int k=ka-kb;
            while(k--)ha=ha->next;
        }else if(ka<kb){
            int k=kb-ka;
            while(k--)hb=hb->next;
        }
        while(ha!=hb){
            ha=ha->next;
            hb=hb->next;
        }
        return ha;
    }
};
/*
4.Yes!AC了，上面写的这种不太简洁的方法通过了，下次复习简洁写法。
*/

//10-26
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	ListNode *ha=headA,*hb=headB;
    	while(ha!=hb){
    		ha=ha!=NULL?ha->next:headB;
    		hb=hb!=NULL?hb->next:headA;
    	}
    	return ha;
    }};
/*
 * 1.Waao,上面根据我对昨天代码的记忆AC了，也就是背代码。。。
 * 2.两个指针最终会相等，而且只有两种情况，一种情况是在交点处相遇，
 * 另一种情况是在各自的末尾的空节点处相等。 * 为什么一定会相等呢，因为两个指针走过的路程相同，
 * 是两个链表的长度之和，所以一定会相等。grand的讲解。
 * 我得手动分析两个例子，加深印象。
 * 是的，如果不相交那么就指向末尾，相交的话指向交点，因为走过的长度是一样的。
 * */

//5-8复习
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* h1=headA;
        ListNode* h2=headB;
        while(h1!=h2){
            h1=h1==NULL?headB:h1->next;
            h2=h2==NULL?headA:h2->next;
        }
        return h1;
    }
};
/*
 * 1.一下就写出来啦，非常简单的啦。
 * */

int main(){

    return 0;
}
