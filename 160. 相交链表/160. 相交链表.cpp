#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//10-24����ָoffer52��
/*
1.���û���˼�룬���б�����������һ������β�˵�ʱ���ٴ���һ���ڵ�ͷ�ڵ㿪ʼ�������Ļ�
  �����߹���·��������һ���ġ�
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * h1=headA,*h2=headB;
        while(h1&&h2&&h1!=h2){
            h1=h1->next;
            h2=h2->next;
        }
        if(h1==h2) return h1;//����ȳ��ཻ
        //����������߲��ཻ������ô�жϣ������ȥ������ѭ����
        if(!h1)h1=headB;
        else if(!h2)h2=headA;
        while(h1&&h2){
            h1=h1->next;
            h2=h2->next;
        }
        if(!h1)h1=headA;
        else if(!h2)h2=headB;
        while(h1!=h2&&h1&&h2){
            h1=h1->next;
            h2=h2->next;
        }
        return h1;
    }
};
/*
2.��������д���������룬��һ��������ûͨ�����Ҳ�֪����Ϊʲô������Ϊ���ڿ������������
  ���ཻ��������δ������ǿ����˼Ҹ��Ĵ��룬����ȷʵ�ǰ��������Ļ���h1��h2��Ϊ�գ�
  Ҳ�������ط��ء�
3.grand������һ�������Ľⷨ��Ҳ����ʵ��O(n)��ʱ�临�Ӷȣ�O(1)���ڴ档
*/
class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ha=headA,*hb=headB;
            ka=0,kb=0;
        while(ha){
            ha=ha->next;
            ka++;
        }
        while(hb){
            hb=hb->next;
            kb++;
        }
        ha=headA;hb=headB;
        //�ѽϳ�������ָ���ƶ���������д�ĺ��鷳����
        if(ka>kb){
            int k=ka-kb;
            while(k--)ha=ha->next;
        }else if(ka<kb){
            int k=kb-ka;
            while(k--)hb=hb->next;
        }
        while(ha!=hb){
            ha=ha->next;
            hb=hb->next;
        }
        return ha;
    }
};
/*
4.Yes!AC�ˣ�����д�����ֲ�̫���ķ���ͨ���ˣ��´θ�ϰ���д����
*/

//10-26
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	ListNode *ha=headA,*hb=headB;
    	while(ha!=hb){
    		ha=ha!=NULL?ha->next:headB;
    		hb=hb!=NULL?hb->next:headA;
    	}
    	return ha;
    }};
/*
 * 1.Waao,��������Ҷ��������ļ���AC�ˣ�Ҳ���Ǳ����롣����
 * 2.����ָ�����ջ���ȣ�����ֻ�����������һ��������ڽ��㴦������
 * ��һ��������ڸ��Ե�ĩβ�Ŀսڵ㴦��ȡ� * Ϊʲôһ��������أ���Ϊ����ָ���߹���·����ͬ��
 * ����������ĳ���֮�ͣ�����һ������ȡ�grand�Ľ��⡣
 * �ҵ��ֶ������������ӣ�����ӡ��
 * �ǵģ�������ཻ��ô��ָ��ĩβ���ཻ�Ļ�ָ�򽻵㣬��Ϊ�߹��ĳ�����һ���ġ�
 * */

//5-8��ϰ
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* h1=headA;
        ListNode* h2=headB;
        while(h1!=h2){
            h1=h1==NULL?headB:h1->next;
            h2=h2==NULL?headA:h2->next;
        }
        return h1;
    }
};
/*
 * 1.һ�¾�д���������ǳ��򵥵�����
 * */

int main(){

    return 0;
}
