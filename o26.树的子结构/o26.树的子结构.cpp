#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年10月26日下午3:09:24
/*
 * 1.我的天，太不容易了，这道题我一共提交了14次，才通过。。。绝绝子啊。
 * */
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!B) return false;//如果B为空则false，因为题目中规定了空树不是子数
        if(!A) return false;//因为后面会调用isSubStructure(A->left,B)，所以有可能没有左子节点，那么直接
        //A->val时就会出错，并且结合上面B的判断，A为空且B不为空所以就返回false。
        // if(!B||!A) return false;
        //题目当中说空树不是任意树的子结构，但是递归出口难道不是判断B是否为空吗？
        //上面这个疑问就导致了矛盾。。。

        //下面这条返回语句说的是：如果当前相等值那么就特殊判断子，否则的话从A的左/右子节点判断
        //
        return (A->val==B->val&&isSub(A->left,B->left)&&isSub(A->right,B->right))||isSubStructure(A->left,B)||isSubStructure(A->right,B);
    }
    bool isSub(TreeNode* A, TreeNode* B){
        if(!B) return true;
        if(!A) return false;
        return A->val==B->val&&isSub(A->left,B->left)&&isSub(A->right,B->right);
    }
};
// [-1,3,2,0]
// []，应该输出false啊，那我这可怎么办？
// [1,0,1,-4,-3]
// [1,-4] ，怎么老是卡在这个样例上，我吐了。
//我知道了，目前我整个判断逻辑都是错的。。。怎么办，好着急啊。

//5-22
/*
 * 1.[-1,3,2,0]
[],仍然是卡在了空树的用例上，所以需要一个子函数。

 * */
//class Solution {
//public:
//    bool isSubStructure(TreeNode* A, TreeNode* B) {
//        if(!B)return false;
//        return isSub(A,B);
//    }
//    bool isSub(TreeNode* A, TreeNode* B){
//        if(!B)return true;//表示B已经被访问完了
//        //if(!A||A->val!=B->val)return false;//如果A为空B不为空 或 都不为空但是节点值不相同。
//        if(!A)return false;
//        return (A->val==B->val&&isSub(A->left,B->left)&&isSub(A->right,B->right))||isSub(A->left,B)||isSub(A->right,B);
//    }
//};
/*
 * 1.上述逻辑判断是错误的，针对[1,0,1,-4,-3]，[1,-4]应该是false才对，如果使用上面的方法，1对比上了，但是
 *   接下去再调用isSub(A->left,B->left)时，由于此时根值不相同，A这边是0，B是-4，所以又会转而去调用
 *   isSub(A->left,B)，那么此时就能配对上，从而返回true，经过&&就会最终返回true，但是实际上B配对的并不是
 *   在A中完整的子结构，所以出错了。
 * 2.所以关键的问题在isSub不能在？？？可以啊。我也不知道怎么说了。
 * 3.关键的点在于，【只有当根节点值相等时才能调用isSub去递归地判断】，反正有根节点作为基点在那撑着，所以不会
 *  出现错误判断子结构的现像。
 * */
int main(){

    return 0;
}
