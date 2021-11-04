#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��10��26������4:34:19
//class Solution {
//public:
//    ListNode* reverseBetween(ListNode* head, int m, int n) {
//        //����е��Ѷȣ���ԽдԽ�ң�ԽдԽ�¡�����
//        //�ҷ����ˡ�
//        ListNode* f=head;
//        ListNode* pre=new ListNode(0),*nh=pre;
//        pre->next=head;
//        int k=m;
//        while(--k){
//            f=f->next;
//            pre=pre->next;
//        }
//        ListNode* s=f->next;
//        ListNode* t=NULL;
//        for(int i=m;i<n;i++){
//            t=s->next;
//            s->next=f;
//            f=s;
//            s=t;
//        }
//        pre->next->next=t;
//        f->next=pre;
//        return nh->next;
//    }
//};//ûд������
/*
 * 1.̫���ˣ���ͷ��Ҫ�����ˡ�
 * 2.���˹ٷ����ĵ����Ĵ��룬ţ�����ˣ���̫6�ˣ�˼·����������Ҫ�Ǳ���4���ڵ㣬m�ڵ��m֮ǰ��һ���ڵ�
 *   n�ڵ��n�ڵ�֮��Ľڵ㡣�����Ҫ���۵ľ���mǰһ���ڵ��Ƿ�Ϊ�գ�Ϊ�����ʾ��ͷ��ʼ��ת�ˡ�ţţţ��
 * 3.����Ҫ��һ�·�ת����ĵݹ�汾���������ǳ�˧����
 * */

//10-27
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	if(!head||!head-next) return head;
    	ListNode* pre=NULL,*pm=head,*pn=NULL,*last=NULL;//��ʵ������γ�ʼ���������ʡ�
    	while(m>1){
    		pre=pm;
    		pm=pm->next;
    		//Ϊʲô�Ҿ��ǲ���д�ء�������
    		//����ô��ô���ء�
    		m--;n--;
    	}
    	pn=pm;
    	last=pn->next;
    	while(n>1){
    		ListNode* t=last->next;
    		last->next=pn;
    		pn=last;last=t;
    		n--;//�����������ɲ���Ҫ��ѭ�����𡣡���
    	}
    	if(pre==NULL)head=pn;
    	else pre->next=pn;
    	pm->next=last;
    	return head;
    }};
/*
 * 1.�۰�Ŷ��AC�ˣ���һ��Ҳ�������ҿɴ������أ�������һ��ɾ͸��ˡ�
 * 2.����û��ʱ���ˣ��Ѿ�����������Сʱ�������ˣ�����Ҳ�Ḵϰ�������Ҿ�����ѧϰ�ݹ顣
 * */

//12-25
/*
 * 1.��ô˵�أ�˼·�������Ұ����о��Լ���д������������pm��pnָ��ֱ�ָ��ͷ�ͽ�β
 *   Ȼ��pm��pre��t=pm->next����Щ�ڵ㶼����ô����ָ���أ��Ҳ�֪����
 * */

//12-27
/*
 * 1.������ʱ�����������ԭ���ǿ����õݹ鷴ת�İ�����ȫû�뵽�����õݹ顣����û�����밡��
 * 2.���������������˵�ͷ�������ҿ����������ڣ���ʵֻҪ�ܶ���ת��������ģ���ô���Ҳ�Ƚϼ��ˡ�
 *   ��Ҫ�ľ���Ҫ����pre�ڵ㣬pm�ڵ�Ҳ��Ҫ��¼�������Ҫ��������next�ڵ㵽���棻
 *   ��pn�ڵ�ķ�ת���֣���ʵ�������ķ�ת��һ���ģ���Ҫ����һ����ʱ�ڵ�t����ô���յĽ������ָ����last
 *   �ж�pre�Ƿ�Ϊ�գ����϶�pn�Ƿ���Ϊͷ��㡣������Ҫ�ĵ�������ѭ���Ŀ��ơ�
 * 3.�ݹ�汾��ladong�Ľⷨ��������������ת��head��ͷ��n���ڵ㣺
 *
 * ListNode successor = null; // �����ڵ� //��Ϊ����תȫ�������ܱ�֤ͷ���֮���ָ��ա�

// ��ת�� head Ϊ���� n ���ڵ㣬�����µ�ͷ���
ListNode reverseN(ListNode head, int n) {
    if (n == 1) {
        // ��¼�� n + 1 ���ڵ�
        successor = head.next;
        return head;
    }
    // �� head.next Ϊ��㣬��Ҫ��תǰ n - 1 ���ڵ�
    ListNode last = reverseN(head.next, n - 1);

    head.next.next = head;
    // �÷�ת֮��� head �ڵ�ͺ���Ľڵ�������
    head.next = successor;
    return last;//���ص��Ƿ�ת֮���ͷ���
}
��ô��ת������Ҫ������
ListNode reverseBetween(ListNode head, int m, int n) {
    // base case
    if (m == 1) {
        return reverseN(head, n);
    }
    // ǰ������ת����㴥�� base case
    head.next = reverseBetween(head.next, m - 1, n - 1);
    return head;//ע�����ﷵ�ص���head��reverseBetween������õ��ǵݹ���ڵ�reverseN����ô����head.next
    //�ͻ�ָ��ת֮���ͷ��㣬�������Ļ������Ƿ���head��head.nextָ���Ҳ��ԭ����ָ��Ҳ����˵����Ӱ��
    m֮ǰ�Ľڵ�nextָ��
    4.�ݹ�͵���ʱ�临�Ӷȶ���O(n)������ǰ�ߵĿռ���O(n)������ΪO(1)��
}
 * */

//5-17
/*
 * 1.��ϰ���ٷ�����ͷ�巨���ǳ�amazing�Ľⷨ����Ҫѧϰ��
 * */
class Solution {
public:
    ListNode* successor=NULL;//�ͷ�ת��������ĵݹ鲻ͬ��������Ҫһ����̽ڵ�
    ListNode* reverseN(ListNode*head,int n){
        //��ͷ�ڵ�ݹ鷴תn���ڵ�
        if(n==1){
            successor=head->next;
            return head;
        }
        ListNode* nh=reverseN(head->next,n-1);
        head->next->next=head;
        head->next=successor;//ָ���̣�������NULL
        return nh;//���ط�ת���ͷ���
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==1){
            return reverseN(head,right);
        }
        head->next=reverseBetween(head->next,left-1,right-1);//һֱ�ݹ�ָ����һ���ڵ㡣
        return head;
    }
};
/*
 * 1.��д��һ�µݹ顣
 * 2.OMGд������ͷ�巨��̫���ˣ�Ҫ�ิϰ��
 * */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //ͷ�巨,pre�ڵ�һֱ���䣬curһֱָ��ת���ֵ�ͷ��next�ڱ���ʱ��ı�
        ListNode* pre=new ListNode();
        pre->next=head;
        ListNode* dummy=pre;
        while(--left){
            pre=pre->next;
            right--;
        }
        ListNode* cur=pre->next;
        while(--right){
            ListNode* next=cur->next;
            cur->next=next->next;
            next->next=pre->next;
            pre->next=next;
        }
        return dummy->next;
    }
};
int main(){

    return 0;
}
