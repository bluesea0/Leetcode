#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年10月26日下午4:34:19
//class Solution {
//public:
//    ListNode* reverseBetween(ListNode* head, int m, int n) {
//        //真的有点难度，我越写越乱，越写越懵。。。
//        //我放弃了。
//        ListNode* f=head;
//        ListNode* pre=new ListNode(0),*nh=pre;
//        pre->next=head;
//        int k=m;
//        while(--k){
//            f=f->next;
//            pre=pre->next;
//        }
//        ListNode* s=f->next;
//        ListNode* t=NULL;
//        for(int i=m;i<n;i++){
//            t=s->next;
//            s->next=f;
//            f=s;
//            s=t;
//        }
//        pre->next->next=t;
//        f->next=pre;
//        return nh->next;
//    }
//};//没写出来。
/*
 * 1.太难了，我头发要掉光了。
 * 2.看了官方给的迭代的代码，牛批死了！！太6了，思路清晰啊！主要是保存4个节点，m节点和m之前的一个节点
 *   n节点和n节点之后的节点。最后主要讨论的就是m前一个节点是否为空，为空则表示从头开始反转了。牛牛牛。
 * 3.明天要看一下反转链表的递归版本。看起来非常帅啊。
 * */

//10-27
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	if(!head||!head-next) return head;
    	ListNode* pre=NULL,*pm=head,*pn=NULL,*last=NULL;//其实这里如何初始化存在疑问。
    	while(m>1){
    		pre=pm;
    		pm=pm->next;
    		//为什么我就是不会写呢。。。。
    		//我怎么这么蠢呢。
    		m--;n--;
    	}
    	pn=pm;
    	last=pn->next;
    	while(n>1){
    		ListNode* t=last->next;
    		last->next=pn;
    		pn=last;last=t;
    		n--;//忘了这个，你可不是要死循环了吗。。。
    	}
    	if(pre==NULL)head=pn;
    	else pre->next=pn;
    	pm->next=last;
    	return head;
    }};
/*
 * 1.哇啊哦，AC了！我一点也不蠢，我可聪明了呢！终于有一点成就感了。
 * 2.今天没有时间了，已经看了两个半小时的力扣了，明天也会复习到，那我就明天学习递归。
 * */

//12-25
/*
 * 1.怎么说呢，思路超级混乱啊。感觉自己手写不出来，是有pm和pn指针分别指向开头和结尾
 *   然后pm、pre、t=pm->next，这些节点都该怎么更改指向呢？我不知道。
 * */

//12-27
/*
 * 1.看题解的时候我真的忘了原来是可以用递归反转的啊，完全没想到可以用递归。。。没往那想啊！
 * 2.迭代过程真是让人掉头发啊。我看明白了终于，其实只要能懂反转整个链表的，那么这个也比较简单了。
 *   主要的就是要保留pre节点，pm节点也需要记录，最后需要调整它的next节点到后面；
 *   在pn节点的反转部分，其实和正常的反转是一样的，需要借助一个临时节点t，那么最终的结果就是指向了last
 *   判断pre是否为空，来断定pn是否作为头结点。还有重要的点是两个循环的控制。
 * 3.递归版本：ladong的解法真是厉害啊，反转以head开头的n个节点：
 *
 * ListNode successor = null; // 后驱节点 //因为不反转全部，不能保证头结点之后就指向空。

// 反转以 head 为起点的 n 个节点，返回新的头结点
ListNode reverseN(ListNode head, int n) {
    if (n == 1) {
        // 记录第 n + 1 个节点
        successor = head.next;
        return head;
    }
    // 以 head.next 为起点，需要反转前 n - 1 个节点
    ListNode last = reverseN(head.next, n - 1);

    head.next.next = head;
    // 让反转之后的 head 节点和后面的节点连起来
    head.next = successor;
    return last;//返回的是反转之后的头结点
}
那么反转部分需要借助：
ListNode reverseBetween(ListNode head, int m, int n) {
    // base case
    if (m == 1) {
        return reverseN(head, n);
    }
    // 前进到反转的起点触发 base case
    head.next = reverseBetween(head.next, m - 1, n - 1);
    return head;//注意这里返回的是head，reverseBetween如果调用的是递归出口的reverseN，那么它的head.next
    //就会指向反转之后的头结点，而正常的话，就是返回head，head.next指向的也是原来的指向，也就是说不会影响
    m之前的节点next指向。
    4.递归和迭代时间复杂度都是O(n)，但是前者的空间是O(n)，后者为O(1)。
}
 * */

//5-17
/*
 * 1.复习，官方给了头插法，非常amazing的解法，我要学习。
 * */
class Solution {
public:
    ListNode* successor=NULL;//和反转整个链表的递归不同，这里需要一个后继节点
    ListNode* reverseN(ListNode*head,int n){
        //从头节点递归反转n个节点
        if(n==1){
            successor=head->next;
            return head;
        }
        ListNode* nh=reverseN(head->next,n-1);
        head->next->next=head;
        head->next=successor;//指向后继，而不是NULL
        return nh;//返回反转后的头结点
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==1){
            return reverseN(head,right);
        }
        head->next=reverseBetween(head->next,left-1,right-1);//一直递归指向下一个节点。
        return head;
    }
};
/*
 * 1.又写了一下递归。
 * 2.OMG写出来了头插法，太绝了，要多复习！
 * */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //头插法,pre节点一直不变，cur一直指向反转部分的头，next在遍历时会改变
        ListNode* pre=new ListNode();
        pre->next=head;
        ListNode* dummy=pre;
        while(--left){
            pre=pre->next;
            right--;
        }
        ListNode* cur=pre->next;
        while(--right){
            ListNode* next=cur->next;
            cur->next=next->next;
            next->next=pre->next;
            pre->next=next;
        }
        return dummy->next;
    }
};
int main(){

    return 0;
}
