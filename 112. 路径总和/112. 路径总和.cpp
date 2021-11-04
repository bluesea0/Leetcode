#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//10-23
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(!root->left&&!root->right){//这里我恍惚间想到是否可以用sum来判断，如果<0了，
                //就直接返回false，后来想不行，因为有可能会出现负数的啊。
            if(sum-root->val==0){
                return true;//这里直接return sum-root->val==0即可，就少了些判断
            }
            return false;
        }
        if(root->left&&hasPathSum(root->left,sum-root->val)) return true;
        if(root->right&&hasPathSum(root->right,sum-root->val)) return true;
        return false;
    }
};
/*
1.一下子AC，比较开心。
2.复杂度：O(N)，其中 N 是树的节点数。对每个节点访问一次。
  O(H)，其中 H是树的高度。空间复杂度主要取决于递归时栈空间的开销，
  最坏情况下，树呈现链状，空间复杂度为 O(N)。
  平均情况下树的高度与节点数的对数正相关，空间复杂度为O(logN)。
3.还有BFS，我实在是想不出BFS该怎么些？脑袋空空。明天复习时，要加上113一起。
*/

//10-27，学习一下BFS解法
/*
 * 1.看了BFS的解法，谁不说一声绝绝子呢，蛮厉害的，用两个队列分别记录节点和对应的和，绝。
 *   下次复习写一下，应该也是不难的。
 * */

int main(){

    return 0;
}
