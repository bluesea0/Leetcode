#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��6��5������11:33:33
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //��ֻ�뵽�˽������ȶ�������
        //auto cmp=[](const ListNode* a,const ListNode* b){return a->val>b->val;};
        //auto cmp=[](const ListNode*& a,const ListNode*& b){return a->val>b->val;};//������const���Ǵ�ģ�OMG
        auto cmp=[](ListNode*& a, ListNode*& b){return a->val>b->val;};
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);
        ListNode* head=new ListNode();
        ListNode* cur=head;
        // for(int i=0;i<lists.size();i++){
        //     pq.push(lists[i]);//����д̫�����ˣ�����û���пգ�
        //     //lists[i]=lists[i]->next;
        // }
        for(auto h:lists){
            if(h)pq.push(h);
        }

        while(!pq.empty()){
            ListNode* t=pq.top();
            pq.pop();
            cur->next=t;
            cur=cur->next;
            if(t->next)pq.push(t->next);
        }
        cur->next=nullptr;
        return head->next;
    }
};
/*
 * 1.�����ѧ���˺ࣺܶ
 *   1.auto�÷�������������һ���������������������decltype����ʼ�����ȼ����С�
 *   2.��Ϊ��ҪС���ѣ�������greater��cmp����д����>������������Ҫע��ģ����Ҫ�󶥶���д�Ļ�
 *     Ӧ����<�������Ҳ����Ĭ�ϵ�less��
 *   3.cmp�����в���������const�ģ�����ᱨ���Ƿ�����Ϊ���const����������в��ܸı�iter������
 *     ָ�򣿵�Ϊ��Ч����Ҫ����&���á�
 *   4.��������ʱ��Ҳ����pq(cmp)���õ���������캯��������д>������ĺ�����
 *   5.forѭ��ʱ��ֱ����auto���Ͳ�����size�ˣ���cpp11�оͿ����ã����Ӽ�ࡣ
 * 2.��Ȼ��Ҫдһ�¹鲢����
 * */

//6-10
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //ʹ�ù鲢�ⷨ
        int n=lists.size();
        if(n==0) return nullptr;
        return mergeSort(lists,0,n-1);//���ﵽ�׺ϲ�����ô�����أ�OMG��
    }
    ListNode* mergeSort(vector<ListNode*>& lists,int left,int right){
        if(left<right){
            int mid=left+((right-left)>>1);
            ListNode* l=mergeSort(lists,left,mid);
            ListNode* r=mergeSort(lists,mid+1,right);
            return merge(lists,l,r);
        }
        return lists[left];
    }
    ListNode* merge(vector<ListNode*>& lists,ListNode* l,ListNode* r){
        //�����ϲ���������
        ListNode *head=new ListNode(),*cur=head;
        while(l&&r){
            if(l->val<=r->val){
                cur->next=l;
                l=l->next;
            }else{
                cur->next=r;
                r=r->next;
            }
            cur=cur->next;
        }
        if(l)cur->next=l;
        else cur->next=r;
        return head->next;
    }
};
/*
 * 1.�鲢����ҲAC�ˣ���ʵ�ǳ��򵥣��ٺ٣������ء��������Ե�ʱ���ҿ���˵�ҶԹ鲢�����˽��ˡ�
 *   ��ʵ������һ�����ֵģ���һ���ϵĹ��̡�
 * */
int main(){

    return 0;
}
