#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月7日下午2:02:03
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //正常的思路：建立哈希，空间是O(n)了
        //双指针思路：快慢指针，快指针比慢指针多走一倍的路程，如果相等了，那么就存在环，否则不存在。
        if(!head) return false;
        ListNode* fast=head->next,*slow=head;
        while(fast&&fast->next&&fast!=slow){
            slow=slow->next;
            fast=fast->next->next;
        }
        return fast==slow;
    }
};
/*
 * 1.我太牛了！AC了哈哈哈，虽然只是一道easy题。行吧，评论区都说索然无味，就是道简单题而已。
 * */
int main(){

    return 0;
}
