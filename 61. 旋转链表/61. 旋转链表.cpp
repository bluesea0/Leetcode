#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��9��15������10:08:31
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr) return head;
        int n=0;
        ListNode* cur=head;
        while(cur){
            n++;
            cur=cur->next;
        }
        if(k%n==0)return head;
        k%=n;//ע��������Ҫ����
        cur=head;

        for(int i=1;i<n-k;i++){
            cur=cur->next;
        }
        ListNode* nh=cur->next;
        cur->next=nullptr;
        cur=nh;
        while(cur->next){
            cur=cur->next;
        }
        cur->next=head;
        return nh;
    }
};
/*
 * 1.�ȼ��㳤�ȣ�ûʲô�����⡣
 * */
int main(){

    return 0;
}
