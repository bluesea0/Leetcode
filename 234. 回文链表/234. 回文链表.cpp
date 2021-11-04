#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//10-24
/*
1���������ҵĴ���д����
*/
//class Solution {
//public:
//    bool isPalindrome(ListNode* head) {
//        //��ͬ��ż��������ж��أ�
//        //����ָ�룬���ʵ�ֿ�ı����Ķ���һ����������ôд�������������ˡ�����
//        //��ָ�����ָ��һ��ʼָ����ͬ�ĵ㣬���ǿ�Ҫָ������next����
//        //�����ż���Ļ�����ָ���ָ��None�������Ļ�����ָ���ָ�����һ���ڵ�
//        ListNode* f=head,*s=head;
//        while(f&&f->next){
//            f=f->next->next;
//            s=s->next;
//        }
//        if(f) s=s->next;
//        ListNode* t=head;
//        while(s){//�ҵ��裬�����жϷ��ˡ�������Ϊ�Լ��ܴ�����
//            if(t->val!=s->val)return false;//������Ҫ�ı���ε�ָ��
//            t=t->next;
//            s=s->next;
//        }
//        return true;
//    }
//};//�����ˡ�
/*
2.�о��ü��ֵ����Ⱑ����Ϊ�������ռ䲻��O(1)�Ľⷨ�������Ҳ���ȥ�룬ֱ�ӿ��ɡ�
  https://www.cnblogs.com/grandyang/p/4635425.html�����������4�ֽⷨ������������
  ��ת����û�а�����ԭ��
*/

//1-9
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //����򵥵ľ�������һ����������һ����
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
 * 1.����û�����ǲ�����¡���������Ȼ���ǲ�������ĿҪ��ģ��˼�Ҫ�� O(n) ʱ��� O(1) �ռ�
 * 2.д�����ˣ��������棬����û���ҽ���£�����
 * */
class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        //����ӳ������Ҫ�жϵ��ǣ���β�����жϣ����࿿�������������ж��Ƿ��ǻ���
        //��������������ôʵ���أ�
        //����һ��˼·������ָ�룿���ǿ���ָ������ôʵ�֣������ǵ���ģ��ֲ���ʵ�ֵ���
        //�һ����Ʋ�����������ӣ�ǰ�벿����ô˳����Ȼ�ͺ�벿���ж��أ�
        //��ת��벿�֣����˾���
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
