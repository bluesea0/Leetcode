#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//10-21
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
/*
1.今天只写一下哈希的解法吧，下一次复习的时候写插入后节点的写法，今天时间不太够了。
*/
class Solution {
public:
    //
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        unordered_map<Node*,Node*> mp;//
        Node* h=head;
        Node* nh=new Node(h->val),*cur=nh;//果真就是在这个创建指针的时候出现了问题，语法不熟悉
        mp[h]=nh;
        h=h->next;
        while(h){
            Node* t=new Node(h->val);
            mp[h]=t;//这里忘记建立哈希了。。。//老节点指向新节点。
            cur->next=t;
            cur=cur->next;
            h=h->next;
        }
        cur=nh,h=head;
        while(h){
            if(h->random){
                cur->random=mp[h->random];
            }
            h=h->next;
            cur=cur->next;
        }
        return nh;
    }
};
//下面是一个递归的解法，应该是grand的
class Solution1 {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;//也是在新node和老node之间建立一个hash。
        return helper(head, m);//需要传递一个map参数
    }
    Node* helper(Node* node, unordered_map<Node*, Node*>& m) {
        if (!node) return nullptr;//就返回空
        if (m.count(node)) return m[node];
        Node *res = new Node(node->val, nullptr, nullptr);
        m[node] = res;
        res->next = helper(node->next, m);//这里递归的过程中会先创建完所有的节点
        res->random = helper(node->random, m);//之后再指向random的时候就会比较容易了。
        return res;
    }
};//其实我感觉递归的解法有点难写的，你要明白其中的过程，等下一次复习的时候要写一下递归的解法！

//5-17
/*
 * 1.用哈希从旧节点指向新节点，用于之后的random的保存。还是有点难度的。
 * 2.有O(1)空间的解法我怎么没写？emmmm
 * */

//5-18
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return head;//需要判断链表是否为空
        //空间O(1)的解法
        Node* cur=head;
        while(cur){
            Node* t=new Node(cur->val);
            t->next=cur->next;
            cur->next=t;
            cur=t->next;
        }
        //指向随机指针
        cur=head;
        while(cur){
            Node* nh=cur->next;
            if(cur->random)nh->random=cur->random->next;
            cur=nh->next;
        }
        //拆分链表
        cur=head;
        Node* nh=cur->next,*newhead=cur->next;//注意第二个部分，因为声明的是指针，所以后面也需要*啊！！
        while(nh->next){
            cur->next=cur->next->next;
            nh->next=nh->next->next;
            cur=cur->next;
            nh=nh->next;
        }
        cur->next=NULL;
        return newhead;
    }
};
int main(){

    return 0;
}
