#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��7������2:02:03
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //������˼·��������ϣ���ռ���O(n)��
        //˫ָ��˼·������ָ�룬��ָ�����ָ�����һ����·�̣��������ˣ���ô�ʹ��ڻ������򲻴��ڡ�
        if(!head) return false;
        ListNode* fast=head->next,*slow=head;
        while(fast&&fast->next&&fast!=slow){
            slow=slow->next;
            fast=fast->next->next;
        }
        return fast==slow;
    }
};
/*
 * 1.��̫ţ�ˣ�AC�˹���������Ȼֻ��һ��easy�⡣�аɣ���������˵��Ȼ��ζ�����ǵ�������ѡ�
 * */
int main(){

    return 0;
}
