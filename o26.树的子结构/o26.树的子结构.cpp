#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��10��26������3:09:24
/*
 * 1.�ҵ��죬̫�������ˣ��������һ���ύ��14�Σ���ͨ�������������Ӱ���
 * */
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!B) return false;//���BΪ����false����Ϊ��Ŀ�й涨�˿�����������
        if(!A) return false;//��Ϊ��������isSubStructure(A->left,B)�������п���û�����ӽڵ㣬��ôֱ��
        //A->valʱ�ͻ�������ҽ������B���жϣ�AΪ����B��Ϊ�����Ծͷ���false��
        // if(!B||!A) return false;
        //��Ŀ����˵�����������������ӽṹ�����ǵݹ�����ѵ������ж�B�Ƿ�Ϊ����
        //����������ʾ͵�����ì�ܡ�����

        //���������������˵���ǣ������ǰ���ֵ��ô�������ж��ӣ�����Ļ���A����/���ӽڵ��ж�
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
// []��Ӧ�����false�������������ô�죿
// [1,0,1,-4,-3]
// [1,-4] ����ô���ǿ�����������ϣ������ˡ�
//��֪���ˣ�Ŀǰ�������ж��߼����Ǵ�ġ�������ô�죬���ż�����

//5-22
/*
 * 1.[-1,3,2,0]
[],��Ȼ�ǿ����˿����������ϣ�������Ҫһ���Ӻ�����

 * */
//class Solution {
//public:
//    bool isSubStructure(TreeNode* A, TreeNode* B) {
//        if(!B)return false;
//        return isSub(A,B);
//    }
//    bool isSub(TreeNode* A, TreeNode* B){
//        if(!B)return true;//��ʾB�Ѿ�����������
//        //if(!A||A->val!=B->val)return false;//���AΪ��B��Ϊ�� �� ����Ϊ�յ��ǽڵ�ֵ����ͬ��
//        if(!A)return false;
//        return (A->val==B->val&&isSub(A->left,B->left)&&isSub(A->right,B->right))||isSub(A->left,B)||isSub(A->right,B);
//    }
//};
/*
 * 1.�����߼��ж��Ǵ���ģ����[1,0,1,-4,-3]��[1,-4]Ӧ����false�Ŷԣ����ʹ������ķ�����1�Ա����ˣ�����
 *   ����ȥ�ٵ���isSub(A->left,B->left)ʱ�����ڴ�ʱ��ֵ����ͬ��A�����0��B��-4�������ֻ�ת��ȥ����
 *   isSub(A->left,B)����ô��ʱ��������ϣ��Ӷ�����true������&&�ͻ����շ���true������ʵ����B��ԵĲ�����
 *   ��A���������ӽṹ�����Գ����ˡ�
 * 2.���Թؼ���������isSub�����ڣ��������԰�����Ҳ��֪����ô˵�ˡ�
 * 3.�ؼ��ĵ����ڣ���ֻ�е����ڵ�ֵ���ʱ���ܵ���isSubȥ�ݹ���жϡ��������и��ڵ���Ϊ�������ǳ��ţ����Բ���
 *  ���ִ����ж��ӽṹ������
 * */
int main(){

    return 0;
}
