#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��20������8:54:33
//class Solution {
//public:
//    ListNode* insertionSortList(ListNode* head) {
//        if(!head||!head->next) return head;
//        ListNode* fh=new ListNode(0);
//        fh->next=head;
//        ListNode*now=head->next;
//        while(now){
//            ListNode* nh=head,*pre=fn;
//            while(now->val>=nh->val&&nh!=now){//��Ҫwhileѭ���жϣ����ѵ�˵��
//                nh=nh->next;
//                pre=pre->next;
//            }
//            if(now!=nh){
//                pre->next=now;
//                nh->next=now->next;//��ôд���԰����ҿ��ˣ��Ҳ�֪����ô���ˡ�����
//                now->next=nh;
//                now=nh->next;
//            }else
//                now=now->next;
//        }
//        return head;
//    }
//};
/*
 * 1.��Ȼ��ûд��������������Ҫ��¼���һ���ź���Ľڵ㣬Ȼ��ֱ�Ӻ����Ƚϡ�
 *   �ҵĴ���˼·���ǶԵġ�pre�ڵ�֮���ٱ�����Ҫ����Ľڵ㣬�Լ����һ���ڵ��ǲ�һ���ġ�
 * 2.�ٷ���д�Ĳ���
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
            }else{//Ѱ�Ҳ���Ľڵ�
                ListNode* pre=dummy;
                while(pre->next->val<=cur->val)
                    pre=pre->next;
                ListNode* t=pre->next;
                pre->next=cur;
                order->next=cur->next;//ע�����ﲻ��t->next������order�ź���ڵ�ָ����һ�����ǳ���Ҫ
                cur->next=t;
                cur=order->next;//���order����ô���°���
                //����orderӦ�ò���
            }
        }
        return dummy->next;
    }
};
/*
 * 1.�ٷ�����д�ĸ��ã�������ʱ����Ҫ��ʱ�ڵ�t��6������Ϊ��prev�������أ�
 * */

//12-20
/*
 * �о��е��ѣ���������⻹���е����
1.���ƶ�Ԫ�أ����Ƕ�����ڵ�ʵ�ʲ����أ�
2.������next��θ��£�
3.�һ��ǲ�֪��θ��£�������ѡ��д������
4.һ����ǰ������Ŀ����������û�����������أ��ҿ��ˡ�
5.���˴���о�̫���ˣ�
6.��Ҫ��һ��Ԫ��ָ���ź�������һ��Ԫ�أ���һ��Ҫ�ŵ�Ԫ�ع����Ⱥ�orderָ������λ�ñȽϣ����������
  ���Ļ�����ô�Ͳ����ţ�ֱ�Ӹ��������ź����λ��Ϊ��ǰ���������Ҫ����Ļ�������������������ǰ֮��
  ��һ����Ҫ����ľ���order����һ��Ԫ��λ�á�����Ҫ����ǰ���˼·�Ƚ����룩
  ��Ҫ��dummy�ڵ㡣
 *
 * */
int main(){

    return 0;
}
