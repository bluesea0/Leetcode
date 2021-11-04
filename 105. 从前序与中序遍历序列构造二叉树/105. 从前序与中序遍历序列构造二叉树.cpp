#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年10月30日下午7:16:23
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //思路：前序遍历中的每一个点都作为根节点，在中序遍历中找到对应的位置，
        //递归构造左右子树
        TreeNode* root=build(preorder,inorder,0,0,inorder.size()-1);
        return root;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int pre,int left,int right){
    	if(pre<0 || pre>=preorder.size()||left>right) return NULL;//第三个判断主要是针对[1,2][1,2]样本
        //上面其实pre不会出现0的啊。。。
    	if(left==right){
            TreeNode* t=new TreeNode(inorder[left]);
            return t;
    }
        int p=left;
       while(inorder[p]!=preorder[pre])p++;
       TreeNode* root=new TreeNode(preorder[pre]);
       root->left=build(preorder,inorder,pre+1,left,p-1);
       root->right=build(preorder,inorder,pre+p-left+1,p+1,right);//第三个参数出现问题
       return root;
    }
};
/*
 * 1.当中写的时候遇到了很多小问题。。。面试的话肯定会留下不好的印象。。。不过还是AC了。。
 * 2.第二阶段：使用哈希表存储inorder节点和对应的下标。
 * */
class Solution1 {//时间复杂度O(n)，空间也是，存储哈希表。上面那种遍历的话，时间复杂度应该也更高了。
public:
    unordered_map<int,int> mp;//使用哈希来存储之后从44ms到24ms，牛批。
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=build(preorder,inorder,0,0,inorder.size()-1);
        return root;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int pre,int left,int right){
    	if(left>right) return NULL;//这里只需要一个判断即可。这个退出条件很值钱啊。
//        if(left==right){//但其实我这个判断是有点多余的啊。
//            TreeNode* t=new TreeNode(inorder[left]);
//            return t;
//    }
        int p=mp[preorder[pre]];
       TreeNode* root=new TreeNode(preorder[pre]);
       root->left=build(preorder,inorder,pre+1,left,p-1);//如果left==right的话，这两个都会返回空的。
       root->right=build(preorder,inorder,pre+p-left+1,p+1,right);
       return root;
    }
};
/*
 * 3.居然还能有迭代的解法？难以想象。我还是明天复习吧，今天没精力了。
 * 4.明天一定要花5分钟看一下讲解视频！为什么评论区这么好评如潮？？！！
 * */

//12-25
/*
 * 1.关键的点有三：①中序遍历可以建立哈希表映射下标，省去遍历的时间；
 * ②建树pre点在preorder中的计算更新；③返回条件是left<right返回null即可。
 * 2.反正感觉这次复习还挺有收获的。
 * */

//5-22
class Solution {
public:
    unordered_map<int,int> um;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int m=preorder.size();
        for(int i=0;i<inorder.size();i++){
            um[inorder[i]]=i;//假设树中无重复元素
        }
        return build(preorder,inorder,0,m-1,0,m-1);
    }
    TreeNode* build(vector<int>& preorder,vector<int>& inorder,int pre1,int pre2,int in1,int in2){
        if(pre1>pre2) return NULL;
        TreeNode* root=new TreeNode(preorder[pre1]);
        int index=um[preorder[pre1]];
        int left_num=index-in1;
        int right_num=in2-index;
        root->left=build(preorder,inorder,pre1+1,pre2-right_num,in1,index-1);
        root->right=build(preorder,inorder,pre1+left_num+1,pre2,index+1,in2);
        return root;
    }
};
/*
 * 1.手写了一下，基本没什么问题。
 * 2.迭代的话简单说一下思路：前序遍历，从根节点root开始，只要有左子节点，就一直会往左下方走，直到最左下角。
 * 而中序遍历，是从最左下角往上（示例中的4-5-8-9-3），如果碰到节点有右子节点，则会转向（示例中的8-10）。
 因此，代码中的if块是用前序数组一直构建左子树，如果碰到了inorder[inorderIndex]，表示到了左下角，
 这时就需要往上走并处理右子树，也就是while代码块。
我是每太看懂，太难了。
 * */


int main(){

    return 0;
}
