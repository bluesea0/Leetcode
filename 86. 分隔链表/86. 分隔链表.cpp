#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��4������2:46:22
//class Solution {
//public:
//    ListNode* partition(ListNode* head, int x) {
//        if(!head) return head;
//        ListNode* h1=head,*h2=head;//����Ҫ�ٴ�ע�����Ķ���Ҳ��Ҫ����*
//        while(h2){
//            if(h2->val<x){//��������д�Ļ���3�ͻᱻ�ƶ��������ˣ������Ӱ�
//                swap(h1->val,h2->val);
//                h1=h1->next;
//            }
//            h2=h2->next;
//        }
//        return head;
//    }
//};
/*
 * 1.���ģ���̫���ˣ��������֮ǰ������283�⣬����Ϊ��������һ����һ��ָ����õ�ĩβ��һ��ָ�����
 *   �Ŀ�ͷ�������ֶ������˸��������ü��飬ȴ���ǲ��ɹ����ƶ����ɹ��������ˡ�������������Ҳ�ǲ��Եġ�
 *   �����Ļ��ǲ�һ���ܱ�֤ԭ��˳���
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
};//���չٷ����д������
int main(){

    return 0;
}
