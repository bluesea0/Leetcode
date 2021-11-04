#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//10-24
/*
1。下面是我的错误写法，
*/
//class Solution {
//public:
//    bool isPalindrome(ListNode* head) {
//        //不同奇偶长度如何判断呢？
//        //快慢指针，如何实现快的比慢的多走一倍？代码怎么写啊？好像忘记了。。。
//        //快指针和慢指针一开始指向相同的点，还是快要指向慢的next？？
//        //如果是偶数的话，快指针会指向None，奇数的话，慢指针会指向最后一个节点
//        ListNode* f=head,*s=head;
//        while(f&&f->next){
//            f=f->next->next;
//            s=s->next;
//        }
//        if(f) s=s->next;
//        ListNode* t=head;
//        while(s){//我的妈，我这判断反了。。还以为自己很聪明。
//            if(t->val!=s->val)return false;//所以需要改变后半段的指向？
//            t=t->next;
//            s=s->next;
//        }
//        return true;
//    }
//};//哭泣了。
/*
2.感觉好棘手的问题啊。因为有其他空间不是O(1)的解法，但是我不想去想，直接看吧。
  https://www.cnblogs.com/grandyang/p/4635425.html，这里给出了4种解法，我慢慢看。
  反转过后没有把它复原。
*/

//1-9
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //那最简单的就是用另一个数组来存一下呗
        vector<int> data;
        while(head){
            data.push_back(head->val);
            head=head->next;
        }
        int n=data.size();
        for(int i=0;i<n/2;i++){
            if(data[i]!=data[n-i-1])return false;
        }
        return true;
    }
};
/*
 * 1.看到没，就是不讲武德。。。。当然这是不符合题目要求的，人家要求 O(n) 时间和 O(1) 空间
 * 2.写出来了，就在下面，看到没，我讲武德！！！
 * */
class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        //首先映入眼帘要判断的是，首尾收缩判断，互相靠近，这样才能判断是否是回文
        //但是在链表中怎么实现呢？
        //看到一个思路，快慢指针？但是快慢指针又怎么实现？链表是单向的，又不能实现倒退
        //我还是绕不过来这个弯子，前半部分怎么顺其自然和后半部分判断呢？
        //反转后半部分，绝了绝了
        ListNode *fast=head,*slow=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *pre=NULL,*cur=slow;
        while(cur){
            ListNode *t=cur->next;
            cur->next=pre;
            pre=cur;
            cur=t;
        }
        while(pre&&head){
            if(pre->val!=head->val)return false;
            pre=pre->next;
            head=head->next;
        }
        return true;
    }
};
int main(){

    return 0;
}
