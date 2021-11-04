#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月24日上午11:01:15
class Solution {
public:
    int countNodes(TreeNode* root) {
        //思路：既然提示是完全二叉树，那么所以只要知道树的高度和最后一层的节点数目就ok？
        //正常来说就可以用二分来求解。按照二叉树的思路我是不会的
        //递归或者层次遍历，利用queue
        if(!root)return 0;
        int left=countNodes(root->left);
        int right=countNodes(root->right);
        return left+right+1;
    }
};
/*
 * 1.AC了，但是是简单的办法。。。回去等消息吧。递归和层次的时间复杂度都是O(n)。
 * 2.看了题解，它使用了二分法，先确定二叉树的高度，然后根据公式确定节点范围，利用二分查找，再用编号
 *   的二进制位表示左右子树遍历。
 * 3.下次复习要写一下，能写出来吗？
 * */

//11-28
//class Solution {
//public:
//    int countNodes(TreeNode* root) {
//        //利用完全二叉树的性质，求出层数+二分
//        //复杂度：O(log^2 n) O(1)
//        if(!root) return 0;
//        int level=0;//求出层输
//        TreeNode* r=root;
//        while(r){
//            r=r->left;
//            level++;
//        }
//        int yu=pow(2,level);//啊我真的不会了。。。
//        // int left=2**level,right=2**(level+1);
//        int left=pow(2,level),right=pow(2,level+1);
//        //二分查找
//        while(left<right){
//            int mid=left+(right-left)/2;
//            TreeNode *t=root;
//            // while(mid!=1){
//            //     if(mid&1)//这里移动写错了，应该是从高位开始的！
//            //         t=t->left;
//            //     else
//            //         t=t->right;
//            //     mid>>=1;
//            // }
//            //这里的位操作好烧脑啊
//            int l=level;
//            mid<<=1;
//            while(l--){
//                if(mid&yu)//每次&的应该都是最高位的
//                    t=t->left;
//                else t=t->right;
//                mid<<=1;
//            }
//            if(!t)//这里应该判断的是指针啊
//                right=mid;
//            else
//                left=mid+1;//这里应该等于什么来着？
//                //如果这样的话，mid+1没有的话可咋整？
//                //那么return的时候需要注意了？
//        }
//        return left-1;
//    }
//};
/*
 * 1.上面是我没写出来的垃圾代码，因为我不知道在遍历左右子节点的时候如何获取除高位之外每位的1/0值。
 *  谁看了不直呼一声辣鸡呢？
 * */
class Solution2 {
public:
    int countNodes(TreeNode* root) {
       if(!root) return 0;
       int level=0;//求出层输
       TreeNode* r=root;
    //    while(r){//我死了，这里求level方法都求错了。。。。
    //        r=r->left;
    //        level++;
    //    }
        while(r->left){
            r=r->left;
            level++;
        }
        if(level==0)return 1;//我的代码加了这个判断之后就AC了，而且快多了
        //应该是因为我没有函数调用的过程吧。
       int left=1<<level,right=1<<(level+1);
       //当只有根节点的时候，level=0, left=1,right=2，就会进入循环
       //但是在官方给的代码中，left=1，right=1，就不会进入循环！我应该对这个完全二叉树节点个数
       //还有点错误的理解。绝了，我的个数理解没问题，只不过不能用左闭右开的，只能用双闭的
       while(left<right){
           int mid=left+(right-left)/2;
           //下面判断是否可行
           TreeNode *t=root;
           int p=1<<(level-1);
           while(t&&p>0){//我还是觉得这里不用控制，因为它是完全二叉树
           //天哪，这里要控制p>0，而不是只判断p就行，因为当level=0的时候，
           //p就是1<<-1？是个什么东西？
                if(!(p&mid))//我悟了，这里太有学问了。
                    t=t->left;
                else t=t->right;
                p>>=1;
           }
            if(t)left=mid+1;
            else right=mid;
       }
       return left-1;//其实我是没有什么问题的。
    }
};
//复习时看一下ladong的解法：https://zhuanlan.zhihu.com/p/112077293


//12-21
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int level=1;
        TreeNode* r=root;
        while(r->left){
            r=r->left;
            level++;
        }
        if(level==1)return 1;
        int left=1<<(level-1),right=(1<<level);
        while(left<right){
            int mid=left+(right-left)/2;
            r=root;
            //天哪怎么进行位运算，这个可难住我了。。。
            //好难
            //如果level=1的话，那么不会进入循环，所以这里就不要担心-2了。
            int t=level-1;
            while(t--){//mid&(1<<t)==0
                if(((mid>>t)&1)==0)r=r->left;
                else r=r->right;
            }
            if(!r)right=mid;
            else left=mid+1;//还是得遵循二分的left和right的设置原则
        }
        return left-1;//忽然发现我写的，如果level=1的话就肯定不行？
    }
};
/*
 * 1.我的天，这次复习真的要把我的血槽给掏空了！！！就因为这个位运算，还有这个二分，其实就是和你之前
 * 确定的规则是一样的[left,right)左闭右开。血槽已空，我死了。这个位运算我可得总结总结。
 * */

//1-6
/*
 * 1.今天复习记住了位运算的内容，其实level应该从0开始，我又从0开始跑了一下，是ok的。
 * 2.时间复杂度：O(logn*logn)，第一个是针对二分法计算节点，第二个是针对跑节点的。
 *   空间O(1)
 * */
int main(){


    return 0;
}
