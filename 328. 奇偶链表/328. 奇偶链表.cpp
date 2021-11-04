#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��13������3:02:50
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* h1=head,*h2=head->next,*h3=h2;//ÿ�ζ����������*��
        while(h2){
            h1->next=h2->next;
            h1=h1->next;
            if(h1){
                h2->next=h1->next;
                h2=h2->next;
            }else h2=NULL;
        }
        //��ѭ��һ���
        h1=head;
        while(h1->next)h1=h1->next;
        h1->next=h3;
        return head;
    }
};//AC�ˣ�ʱ��O(n)���ռ�O(1)
/*
 * 1.����������ʱ����������������922����ż�������������⣬��ά��iָ��ż��λ�ã�jָ������λ��
 *   ���������Ļ��Ͳ��ܱ�֤��ż��˳���ˣ�Ȼ���û���뷨���������
 * 2.�������֮���Ȼ����Ȼ���Լ�д��������AC�ˡ�
 * 3.�������Ĵ��룬�˼�д�Ĳž������ҵĴ�����ڵ������ǣ����ܽ����ĿΪż��ʱ��h1��Ϊ���ˣ�
 *   �͵���û�а취��¼ż�������һ���ڵ㣬Ȼ����Ҫ�ٴα����ҵ����˼Ҿ�ֱ���ж�h2��h2->next�����ˡ�
 * */

//11-18
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* h1=head,*h2=head->next,*h3=h2;//ÿ�ζ����������*��
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
 * 1.��Ҳд�������������ˣ�
 * */
int main(){

    return 0;
}
