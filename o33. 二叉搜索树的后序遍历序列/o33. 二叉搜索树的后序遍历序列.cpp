#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-8
class Solution {
public:
    //O(n2),O(n)
    bool verifyPostorder(vector<int>& postorder) {
        //Ҫ���ö��������������ʣ���߱ȸ�С���ұ߱ȸ���
        //�϶���Ҫ�ݹ飬�����Ҳ�ȷ��Ҫдһ���Ӻ�����
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
        if(left>=right)return true;//�ݹ����
        int m=left;
        while(m<right&&postorder[m]<postorder[right])m++;
        int p=m;
        while(p<right&&postorder[p]>postorder[right])p++;
        if(p!=right)return false;//˵��������BST����
        return verify(postorder,left,m-1)&&verify(postorder,m,right-1);//�������������
        //����m��
    }
};
/*
 * 1.���ǻ���Щʱ��ģ�ֻ��ݹ飬���������
 * */
int main(){
    Solution s;
    vector<int> pp={1,6,3,2,5};
//    cout<<pp<<endl;
    cout<<s.verifyPostorder(pp)<<endl;
    return 0;
}
