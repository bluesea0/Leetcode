#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月15日下午5:25:23
class DList{
public:
    int val,key;//还要再加一个key的值，将它从链表尾部移除时，同样也需要去除掉哈希表中的值，所以
    //这里需要记录
    DList* left,*right;
    DList():val(0),left(nullptr),right(nullptr){}
    DList(int k,int v):key(k),val(v),left(nullptr),right(nullptr){}
};
class LRUCache {
public:
    int k;
    unordered_map<int,DList*> um;//这里是应该指向一个结点的吧
    DList* head,*tail;
    //但是Cpp中双向链表如何实现？需要自己定义一个数据结构吗？
    LRUCache(int capacity) {
        k=capacity;//表示容量
        head=new DList();//创建一个空的节点，这里要是new？new返回的是指针？
        //error: assigning to 'DList *' from incompatible type 'DList'
        tail=new DList();
        head->right=tail;//这里需要先指好，否则一开始在remove的时候会遇到求空接点的left/right
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
        //每次put都要从头节点插入
        if(um.count(key)){
            DList* d=um[key];
            d->val=value;
            moveToHead(d);//将它移动到头部
        }else{
            um[key]=new DList(key,value);
            insertHead(um[key]);
            if(um.size()>k){
                DList* d=removeTail();//删除最后一个节点怎么搞能成为O(1)呢？
                um.erase(d->key);
                delete d;//删除掉节点，避免内存泄露
            }
            //明白了，因为要在O(1)完成删除尾节点，就需要一个假尾节点，否则就是O(n)的复杂度了
        }
    }
    void moveToHead(DList* d){
        //天哪，好麻烦，需要考虑好多好多指针啊
        // d->left->right=d->right;
        // d->right=d->left;
        // d->left->right=d;
        // d->left=head;
        // head->right=d;
        //这个写的有问题，我感觉没看过怎么写的，肯定自己想不出来的
        removeNode(d);//分为两步
        insertHead(d);
    }

    void removeNode(DList* d){//这个函数并没有真正地删除掉node，而只是将它从链表中取了出来
        d->left->right=d->right;//但其实此刻d的left/right都还是指向链表中的节点的
        d->right->left=d->left;
    }

    void insertHead(DList* d){
        head->right->left=d;
        d->right=head->right;
        d->left=head;
        head->right=d;
    }

    DList* removeTail(){//需要返回被删除的节点，然后在调用点delete掉
        DList* d=tail->left;
        removeNode(d);
        return d;
    }
};
/*
 * 1.应该新建双向链表的节点DListNode，我这个类名字起的不行。
 * 2.删除时应该删除节点，避免内存泄漏。知识点：双向链表+哈希。
 * 3.关键在双向链表有假头和尾节点，这样增加删除都是O(1)了。
 * */

//3-24
/*
 * 1.再复习一遍还是觉得，写的很牛的程度，将函数分为了从链表中移除一个节点，插入头部，返回最后一个节点并删除
 *   更新节点时，首先将它从原链表中移出来，再插入头部；删除节点时，将最后的节点从队列中删除并且返回删除掉
 *   delete掉申请的空间。
 *   从原链表中移除时还保存着节点left和right的指针关系。
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
        ListNode_* node=new ListNode_(key,value);//这里放进去的是value好吗。出错2
        um[key]=node;//忘了放进去哈希表中了，出错1
        putHead(node);
        if(um.size()>k){//删除队尾节点
            ListNode_* t=tail->pre;
            um.erase(t->key);//同时在哈希表中删除，删除出错3，
            //这里应该是根据key来删除，我的妈，所以说节点当中也要存储key值
            //主要是在删除的时候用到。
            t->pre->next=tail;
            tail->pre=t->pre;
            delete t;
        }
    }
};
/*
 * 1.终于写出来了，遇到了很多地方不行的，但是为什么我提交了524ms，而且只打败了5%，上一次的提交就很牛的啊，
 *   上一个代码才84ms，这是为什么呢？什么导致这么大的差异呢？提交了两次一次运行比一次时间长。
 * 2.我也不知道是为什么，可能是因为之前的就移动节点很简单。
 * */
int main(){

    return 0;
}
