#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月13日下午3:02:50
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* h1=head,*h2=head->next,*h3=h2;//每次都忘了这里的*啊
        while(h2){
            h1->next=h2->next;
            h1=h1->next;
            if(h1){
                h2->next=h1->next;
                h2=h2->next;
            }else h2=NULL;
        }
        //再循环一遍吧
        h1=head;
        while(h1->next)h1=h1->next;
        h1->next=h3;
        return head;
    }
};//AC了，时间O(n)，空间O(1)
/*
 * 1.看到这道题的时候，我在想的是昨天的922按奇偶排序数组的这道题，想维护i指向偶数位置，j指向奇数位置
 *   但是这样的话就不能保证奇偶的顺序了，然后就没有想法，遂放弃。
 * 2.看了题解之后恍然大悟，然后自己写了上述的AC了。
 * 3.看了题解的代码，人家写的才绝好吗，我的代码存在的问题是，当总结点数目为偶数时，h1就为空了，
 *   就导致没有办法记录偶数的最后一个节点，然后需要再次遍历找到，人家就直接判断h2和h2->next，绝了。
 * */

//11-18
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* h1=head,*h2=head->next,*h3=h2;//每次都忘了这里的*啊
        while(h2&&h2->next){
            h1->next=h2->next;
            h1=h1->next;
            h2->next=h1->next;
            h2=h2->next;
        }
        h1->next=h3;
        return head;
    }
};
/*
 * 1.我也写出来这个简洁版的了！
 * */
int main(){

    return 0;
}
