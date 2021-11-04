#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年9月15日下午10:08:31
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
        k%=n;//注意这里需要处理
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
 * 1.先计算长度，没什么大问题。
 * */
int main(){

    return 0;
}
