#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月4日下午2:46:22
//class Solution {
//public:
//    ListNode* partition(ListNode* head, int x) {
//        if(!head) return head;
//        ListNode* h1=head,*h2=head;//这里要再次注意后面的定义也需要加上*
//        while(h2){
//            if(h2->val<x){//但是这样写的话，3就会被移动到后面了，绝绝子啊
//                swap(h1->val,h2->val);
//                h1=h1->next;
//            }
//            h2=h2->next;
//        }
//        return head;
//    }
//};
/*
 * 1.天哪，我太蠢了，我做这个之前刚做了283题，还以为是像数组一样，一个指向处理好的末尾，一个指向处理好
 *   的开头，但是手动运行了给的样例好几遍，却还是不成功，移动不成功，我醉了。就算它是数组也是不对的。
 *   这样的话是不一定能保证原来顺序的
 * */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small=new ListNode(0);
        ListNode* ds=small;
        ListNode* big=new ListNode(0);
        ListNode* db=big;
        while(head){
            if(head->val<x){
                small->next=head;
                small=small->next;
            }else{
                big->next=head;
                big=big->next;
            }
            head=head->next;
        }
        small->next=db->next;
        big->next=NULL;
        return ds->next;
    }
};//按照官方题解写出来的
int main(){

    return 0;
}
