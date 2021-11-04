#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��15������5:25:23
class DList{
public:
    int val,key;//��Ҫ�ټ�һ��key��ֵ������������β���Ƴ�ʱ��ͬ��Ҳ��Ҫȥ������ϣ���е�ֵ������
    //������Ҫ��¼
    DList* left,*right;
    DList():val(0),left(nullptr),right(nullptr){}
    DList(int k,int v):key(k),val(v),left(nullptr),right(nullptr){}
};
class LRUCache {
public:
    int k;
    unordered_map<int,DList*> um;//������Ӧ��ָ��һ�����İ�
    DList* head,*tail;
    //����Cpp��˫���������ʵ�֣���Ҫ�Լ�����һ�����ݽṹ��
    LRUCache(int capacity) {
        k=capacity;//��ʾ����
        head=new DList();//����һ���յĽڵ㣬����Ҫ��new��new���ص���ָ�룿
        //error: assigning to 'DList *' from incompatible type 'DList'
        tail=new DList();
        head->right=tail;//������Ҫ��ָ�ã�����һ��ʼ��remove��ʱ���������սӵ��left/right
        tail->left=head;
    }

    int get(int key) {
        if(um.count(key)){
            moveToHead(um[key]);
            return um[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        //ÿ��put��Ҫ��ͷ�ڵ����
        if(um.count(key)){
            DList* d=um[key];
            d->val=value;
            moveToHead(d);//�����ƶ���ͷ��
        }else{
            um[key]=new DList(key,value);
            insertHead(um[key]);
            if(um.size()>k){
                DList* d=removeTail();//ɾ�����һ���ڵ���ô���ܳ�ΪO(1)�أ�
                um.erase(d->key);
                delete d;//ɾ�����ڵ㣬�����ڴ�й¶
            }
            //�����ˣ���ΪҪ��O(1)���ɾ��β�ڵ㣬����Ҫһ����β�ڵ㣬�������O(n)�ĸ��Ӷ���
        }
    }
    void moveToHead(DList* d){
        //���ģ����鷳����Ҫ���Ǻö�ö�ָ�밡
        // d->left->right=d->right;
        // d->right=d->left;
        // d->left->right=d;
        // d->left=head;
        // head->right=d;
        //���д�������⣬�Ҹо�û������ôд�ģ��϶��Լ��벻������
        removeNode(d);//��Ϊ����
        insertHead(d);
    }

    void removeNode(DList* d){//���������û��������ɾ����node����ֻ�ǽ�����������ȡ�˳���
        d->left->right=d->right;//����ʵ�˿�d��left/right������ָ�������еĽڵ��
        d->right->left=d->left;
    }

    void insertHead(DList* d){
        head->right->left=d;
        d->right=head->right;
        d->left=head;
        head->right=d;
    }

    DList* removeTail(){//��Ҫ���ر�ɾ���Ľڵ㣬Ȼ���ڵ��õ�delete��
        DList* d=tail->left;
        removeNode(d);
        return d;
    }
};
/*
 * 1.Ӧ���½�˫������Ľڵ�DListNode���������������Ĳ��С�
 * 2.ɾ��ʱӦ��ɾ���ڵ㣬�����ڴ�й©��֪ʶ�㣺˫������+��ϣ��
 * 3.�ؼ���˫�������м�ͷ��β�ڵ㣬��������ɾ������O(1)�ˡ�
 * */

//3-24
/*
 * 1.�ٸ�ϰһ�黹�Ǿ��ã�д�ĺ�ţ�ĳ̶ȣ���������Ϊ�˴��������Ƴ�һ���ڵ㣬����ͷ�����������һ���ڵ㲢ɾ��
 *   ���½ڵ�ʱ�����Ƚ�����ԭ�������Ƴ������ٲ���ͷ����ɾ���ڵ�ʱ�������Ľڵ�Ӷ�����ɾ�����ҷ���ɾ����
 *   delete������Ŀռ䡣
 *   ��ԭ�������Ƴ�ʱ�������Žڵ�left��right��ָ���ϵ��
 * */

class ListNode_{
public:
    int key,val;
    ListNode_* pre,*next;
    ListNode_():pre(nullptr),next(nullptr),key(0),val(0){}
    ListNode_(int k,int v):pre(nullptr),next(nullptr),key(k),val(v){}
};
class LRUCache {
public:
    int k;
    unordered_map<int,ListNode_*> um;
    ListNode_* head,*tail;
    LRUCache(int capacity) {
        head=new ListNode_();
        tail=new ListNode_();
        head->next=tail;
        tail->pre=head;
        k=capacity;
    }

    int get(int key) {
        if(um.count(key)==0)return -1;
        ListNode_* cur=um[key];
        putHead(cur);
        return cur->val;
    }
    void putHead(ListNode_* cur){
        if(cur->pre)cur->pre->next=cur->next;
        if(cur->next)cur->next->pre=cur->pre;
        head->next->pre=cur;
        cur->next=head->next;
        head->next=cur;
        cur->pre=head;
    }
    void put(int key, int value) {
        if(um.count(key)){
            um[key]->val=value;
            putHead(um[key]);
            return;
        }
        ListNode_* node=new ListNode_(key,value);//����Ž�ȥ����value���𡣳���2
        um[key]=node;//���˷Ž�ȥ��ϣ�����ˣ�����1
        putHead(node);
        if(um.size()>k){//ɾ����β�ڵ�
            ListNode_* t=tail->pre;
            um.erase(t->key);//ͬʱ�ڹ�ϣ����ɾ����ɾ������3��
            //����Ӧ���Ǹ���key��ɾ�����ҵ��裬����˵�ڵ㵱��ҲҪ�洢keyֵ
            //��Ҫ����ɾ����ʱ���õ���
            t->pre->next=tail;
            tail->pre=t->pre;
            delete t;
        }
    }
};
/*
 * 1.����д�����ˣ������˺ܶ�ط����еģ�����Ϊʲô���ύ��524ms������ֻ�����5%����һ�ε��ύ�ͺ�ţ�İ���
 *   ��һ�������84ms������Ϊʲô�أ�ʲô������ô��Ĳ����أ��ύ������һ�����б�һ��ʱ�䳤��
 * 2.��Ҳ��֪����Ϊʲô����������Ϊ֮ǰ�ľ��ƶ��ڵ�ܼ򵥡�
 * */
int main(){

    return 0;
}
