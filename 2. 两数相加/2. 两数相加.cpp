#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��9��19������7:20:23
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        ListNode* cur=dummy;
        int pre=0;
        while(l1||l2||pre){
            int t1=(l1==nullptr?0:l1->val);
            int t2=(l2==nullptr?0:l2->val);
            int t=t1+t2+pre;
            pre=t/10;
            t%=10;
            cur->next=new ListNode(t);
            cur=cur->next;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        return dummy->next;
    }
};
/*
 * 1.ͨ�������µĽڵ������еġ����ǱȽϼ򵥰ɣ��������Ҫע��ѭ���жϵ���������Ϊ�������н�λ��
 *  �������߳��Ȳ�һ����
 * */
int main(){

    return 0;
}
