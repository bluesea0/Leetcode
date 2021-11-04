#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-8
class Solution {
public:
    //O(n2),O(n)
    bool verifyPostorder(vector<int>& postorder) {
        //要利用二叉搜索树的性质，左边比根小，右边比根大。
        //肯定是要递归，但是我不确定要写一个子函数吗？
        return verify(0,postorder.size()-1,postorder);
    }
private:
    bool verify(int fr,int to,vector<int>& post){
        if(fr>=to) return true;
        int m=fr;
        while(m<to && post[m]<post[to]) m++;
        int p=m;
        while(p<to && post[p]>post[to]) p++;
        if(p!=to) return false;
        return verify(fr,m-1,post) && verify(m,to-1,post);
    }
};

//5-22
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.empty()) return true;
        int m=postorder.size();
        return verify(postorder,0,m-1);
    }
    bool verify(vector<int>&postorder,int left,int right){
        if(left>=right)return true;//递归出口
        int m=left;
        while(m<right&&postorder[m]<postorder[right])m++;
        int p=m;
        while(p<right&&postorder[p]>postorder[right])p++;
        if(p!=right)return false;//说明不符合BST定义
        return verify(postorder,left,m-1)&&verify(postorder,m,right-1);//后面的右子树是
        //包含m的
    }
};
/*
 * 1.还是花了些时间的，只会递归，不会迭代。
 * */
int main(){
    Solution s;
    vector<int> pp={1,6,3,2,5};
//    cout<<pp<<endl;
    cout<<s.verifyPostorder(pp)<<endl;
    return 0;
}
