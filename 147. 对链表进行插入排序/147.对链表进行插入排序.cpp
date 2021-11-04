#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月20日下午8:54:33
//class Solution {
//public:
//    ListNode* insertionSortList(ListNode* head) {
//        if(!head||!head->next) return head;
//        ListNode* fh=new ListNode(0);
//        fh->next=head;
//        ListNode*now=head->next;
//        while(now){
//            ListNode* nh=head,*pre=fn;
//            while(now->val>=nh->val&&nh!=now){//需要while循环判断，好难的说！
//                nh=nh->next;
//                pre=pre->next;
//            }
//            if(now!=nh){
//                pre->next=now;
//                nh->next=now->next;//这么写不对啊，我哭了，我不知道怎么办了。。。
//                now->next=nh;
//                now=nh->next;
//            }else
//                now=now->next;
//        }
//        return head;
//    }
//};
/*
 * 1.当然是没写出来，哭泣。需要记录最后一个排好序的节点，然后直接和它比较。
 *   我的大体思路还是对的。pre节点之后再遍历，要插入的节点，以及最后一个节点是不一样的。
 * 2.官方解写的不错。
 * */

//11-22
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        ListNode* order=head,*cur=head->next;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        while(cur){
            if(cur->val>=order->val){
                order=cur;
                cur=cur->next;
            }else{//寻找插入的节点
                ListNode* pre=dummy;
                while(pre->next->val<=cur->val)
                    pre=pre->next;
                ListNode* t=pre->next;
                pre->next=cur;
                order->next=cur->next;//注意这里不是t->next，而是order排好序节点指向下一个，非常重要
                cur->next=t;
                cur=order->next;//这个order该怎么更新啊？
                //这里order应该不动
            }
        }
        return dummy->next;
    }
};
/*
 * 1.官方比我写的更好，更换的时候不需要临时节点t。6啊，因为有prev做控制呢！
 * */

//12-20
/*
 * 感觉有点难，看到这个题还是有点虚的
1.是移动元素？还是对链表节点实际操作呢？
2.问题是next如何更新？
3.我还是不知如何更新，所以我选择不写代码了
4.一个月前做的题目，现在像是没做过，呜呜呜，我哭了。
5.看了代码感觉太绝了！
6.需要有一个元素指向排好序的最后一个元素，下一个要排的元素过来先和order指向的最后位置比较，如果都大于
  它的话，那么就不用排，直接更新最后的排好序的位置为当前。如果是需要排序的话，就正常操作，排序当前之后
  下一个需要排序的就是order的下一个元素位置。（主要还是前半段思路比较难想）
  需要有dummy节点。
 *
 * */
int main(){

    return 0;
}
