#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年10月30日下午8:59:57
//class Solution {
//public:
//    unordered_map<int,int> mp;
//    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
//        //那这个就涉及到为什么如何处理前序和后序了
//        //前根遍历的第一个和后根遍历的最后一个肯定是总根节点。
//        for(int i=0;i<post.size();i++){
//            mp[post[i]]=i;
//        }
//        TreeNode* t=new TreeNode(pre[0]);//这个和之前还不一样，这个是给了一个根节点了
//        build(t,pre,post,1,pre.size()-1,0,post.size()-2);
//        return t;
//    }
//    void build(TreeNode*& root,vector<int>& pre, vector<int>& post，int index,int left,int right){
//        if(index>pre.size()||left>right) return;
//        int p=mp[pre[index]];//写不下去了啊，这里要根据它创建一个根节点？然后呢？
//        //那需要是上面中的参数root指向left指向当前？那么right指向谁呢？
//        //关键问题是
//        root->left=放弃。
//    }
//};//太难了。
/*
 * 1.看了https://www.cnblogs.com/grandyang/p/10909191.html的讲解，绝了，原来是这样，这个也有栈的解法
 *   明天学习.
 * */
class Solution {
public:
    unordered_map<int,int> mp;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        for(int i=0;i<post.size();i++){
            mp[post[i]]=i;
        }
        return build(pre,post,0,pre.size()-1,0,post.size()-1);
    }
    TreeNode* build(vector<int>& pre, vector<int>& post,int preL,int preR,int postL,int postR){
        if(preL>preR||postL>postR) return NULL;
        TreeNode* t=new TreeNode(pre[preL]);
        if(preL==preR) return t;//卧槽，人家直接判断返回了！
        int p=mp[pre[preL+1]],len=p-postL+1;//但是如果长度只有1怎么办？那不就访问越界了？
        t->left=build(pre,post,preL+1,preL+len,postL,p);
        t->right=build(pre,post,preL+len+1,preR,p+1,postR);
        //害，还是不知道左右子树的长度怎么控制啊？放弃。烦。
        //咋就这么难呢？不想看人家怎么写的，为什么我就写不出来？
        return t;
    }
};
//AC了，当然还是差点放弃，可以判断直接返回！太牛了！
//复杂度：官方给的是O(n^2)?我就不太明白了，为什么呢？为啥不是n呢？已经在评论区提问了。
//105和106都是O(n)的啊，每个节点构建一次咯。

//12-25
/*
 * 1.看到这个就很烦恼，我确实是没什么思路想逃避，不想做这道题。
只知道前根是  根左右，  后根是  根右左， 那么接下去呢？
除了总的根节点能确定，左右子节点都是混在一起的啊，那么要依据哪一个去构建呢？
   2.https://www.cnblogs.com/grandyang/p/10909191.html 讲的非常好
	preorder -> [1] [2,4,5] [3,6,7]
	postorder -> [4,5,2] [6,7,3] [root]
	在一段序列中，前序的根节点一定是出现在后序遍历的最后一个，在左子树和右子数中都遵循着这个规律！
	太厉害了。下次复习一定要写代码！
 * */


int main(){

    return 0;
}
