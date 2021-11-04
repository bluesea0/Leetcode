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
1.����ֻдһ�¹�ϣ�Ľⷨ�ɣ���һ�θ�ϰ��ʱ��д�����ڵ��д��������ʱ�䲻̫���ˡ�
*/
class Solution {
public:
    //
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        unordered_map<Node*,Node*> mp;//
        Node* h=head;
        Node* nh=new Node(h->val),*cur=nh;//����������������ָ���ʱ����������⣬�﷨����Ϥ
        mp[h]=nh;
        h=h->next;
        while(h){
            Node* t=new Node(h->val);
            mp[h]=t;//�������ǽ�����ϣ�ˡ�����//�Ͻڵ�ָ���½ڵ㡣
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
//������һ���ݹ�Ľⷨ��Ӧ����grand��
class Solution1 {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;//Ҳ������node����node֮�佨��һ��hash��
        return helper(head, m);//��Ҫ����һ��map����
    }
    Node* helper(Node* node, unordered_map<Node*, Node*>& m) {
        if (!node) return nullptr;//�ͷ��ؿ�
        if (m.count(node)) return m[node];
        Node *res = new Node(node->val, nullptr, nullptr);
        m[node] = res;
        res->next = helper(node->next, m);//����ݹ�Ĺ����л��ȴ��������еĽڵ�
        res->random = helper(node->random, m);//֮����ָ��random��ʱ��ͻ�Ƚ������ˡ�
        return res;
    }
};//��ʵ�Ҹо��ݹ�Ľⷨ�е���д�ģ���Ҫ�������еĹ��̣�����һ�θ�ϰ��ʱ��Ҫдһ�µݹ�Ľⷨ��

//5-17
/*
 * 1.�ù�ϣ�Ӿɽڵ�ָ���½ڵ㣬����֮���random�ı��档�����е��Ѷȵġ�
 * 2.��O(1)�ռ�Ľⷨ����ôûд��emmmm
 * */

//5-18
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return head;//��Ҫ�ж������Ƿ�Ϊ��
        //�ռ�O(1)�Ľⷨ
        Node* cur=head;
        while(cur){
            Node* t=new Node(cur->val);
            t->next=cur->next;
            cur->next=t;
            cur=t->next;
        }
        //ָ�����ָ��
        cur=head;
        while(cur){
            Node* nh=cur->next;
            if(cur->random)nh->random=cur->random->next;
            cur=nh->next;
        }
        //�������
        cur=head;
        Node* nh=cur->next,*newhead=cur->next;//ע��ڶ������֣���Ϊ��������ָ�룬���Ժ���Ҳ��Ҫ*������
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
