#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年6月5日下午11:33:33
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //我只想到了借用优先队列来。
        //auto cmp=[](const ListNode* a,const ListNode* b){return a->val>b->val;};
        //auto cmp=[](const ListNode*& a,const ListNode*& b){return a->val>b->val;};//不能用const，是错的！OMG
        auto cmp=[](ListNode*& a, ListNode*& b){return a->val>b->val;};
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);
        ListNode* head=new ListNode();
        ListNode* cur=head;
        // for(int i=0;i<lists.size();i++){
        //     pq.push(lists[i]);//这样写太繁琐了，而且没有判空！
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
 * 1.这道题学到了很多：
 *   1.auto用法，用它来定义一个函数，匿名函数。结合decltype来初始化优先级队列。
 *   2.因为需要小顶堆，所以是greater，cmp中重写的是>运算符，这个是要注意的，如果要大顶堆重写的话
 *     应该是<运算符，也就是默认的less。
 *   3.cmp函数中参数不能是const的，否则会报错，是否是因为如果const就排序过程中不能改变iter迭代器
 *     指向？但为了效率需要传递&引用。
 *   4.声明对象时，也用了pq(cmp)，用的是这个构造函数，来重写>运算符的函数。
 *   5.for循环时，直接用auto，就不用求size了，在cpp11中就可以用，更加简洁。
 * 2.仍然需要写一下归并排序。
 * */

//6-10
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //使用归并解法
        int n=lists.size();
        if(n==0) return nullptr;
        return mergeSort(lists,0,n-1);//这里到底合并后怎么返回呢？OMG子
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
        //单独合并两个链表
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
 * 1.归并排序也AC了，其实非常简单，嘿嘿，开心呢。终于面试的时候我可以说我对归并排序了解了。
 *   其实就是有一个二分的，有一个合的过程。
 * */
int main(){

    return 0;
}
