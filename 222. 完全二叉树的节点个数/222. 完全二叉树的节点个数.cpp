#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��24������11:01:15
class Solution {
public:
    int countNodes(TreeNode* root) {
        //˼·����Ȼ��ʾ����ȫ����������ô����ֻҪ֪�����ĸ߶Ⱥ����һ��Ľڵ���Ŀ��ok��
        //������˵�Ϳ����ö�������⡣���ն�������˼·���ǲ����
        //�ݹ���߲�α���������queue
        if(!root)return 0;
        int left=countNodes(root->left);
        int right=countNodes(root->right);
        return left+right+1;
    }
};
/*
 * 1.AC�ˣ������Ǽ򵥵İ취��������ȥ����Ϣ�ɡ��ݹ�Ͳ�ε�ʱ�临�Ӷȶ���O(n)��
 * 2.������⣬��ʹ���˶��ַ�����ȷ���������ĸ߶ȣ�Ȼ����ݹ�ʽȷ���ڵ㷶Χ�����ö��ֲ��ң����ñ��
 *   �Ķ�����λ��ʾ��������������
 * 3.�´θ�ϰҪдһ�£���д������
 * */

//11-28
//class Solution {
//public:
//    int countNodes(TreeNode* root) {
//        //������ȫ�����������ʣ��������+����
//        //���Ӷȣ�O(log^2 n) O(1)
//        if(!root) return 0;
//        int level=0;//�������
//        TreeNode* r=root;
//        while(r){
//            r=r->left;
//            level++;
//        }
//        int yu=pow(2,level);//������Ĳ����ˡ�����
//        // int left=2**level,right=2**(level+1);
//        int left=pow(2,level),right=pow(2,level+1);
//        //���ֲ���
//        while(left<right){
//            int mid=left+(right-left)/2;
//            TreeNode *t=root;
//            // while(mid!=1){
//            //     if(mid&1)//�����ƶ�д���ˣ�Ӧ���ǴӸ�λ��ʼ�ģ�
//            //         t=t->left;
//            //     else
//            //         t=t->right;
//            //     mid>>=1;
//            // }
//            //�����λ���������԰�
//            int l=level;
//            mid<<=1;
//            while(l--){
//                if(mid&yu)//ÿ��&��Ӧ�ö������λ��
//                    t=t->left;
//                else t=t->right;
//                mid<<=1;
//            }
//            if(!t)//����Ӧ���жϵ���ָ�밡
//                right=mid;
//            else
//                left=mid+1;//����Ӧ�õ���ʲô���ţ�
//                //��������Ļ���mid+1û�еĻ���զ����
//                //��ôreturn��ʱ����Ҫע���ˣ�
//        }
//        return left-1;
//    }
//};
/*
 * 1.��������ûд�������������룬��Ϊ�Ҳ�֪���ڱ��������ӽڵ��ʱ����λ�ȡ����λ֮��ÿλ��1/0ֵ��
 *  ˭���˲�ֱ��һ�������أ�
 * */
class Solution2 {
public:
    int countNodes(TreeNode* root) {
       if(!root) return 0;
       int level=0;//�������
       TreeNode* r=root;
    //    while(r){//�����ˣ�������level����������ˡ�������
    //        r=r->left;
    //        level++;
    //    }
        while(r->left){
            r=r->left;
            level++;
        }
        if(level==0)return 1;//�ҵĴ����������ж�֮���AC�ˣ����ҿ����
        //Ӧ������Ϊ��û�к������õĹ��̰ɡ�
       int left=1<<level,right=1<<(level+1);
       //��ֻ�и��ڵ��ʱ��level=0, left=1,right=2���ͻ����ѭ��
       //�����ڹٷ����Ĵ����У�left=1��right=1���Ͳ������ѭ������Ӧ�ö������ȫ�������ڵ����
       //���е�������⡣���ˣ��ҵĸ������û���⣬ֻ��������������ҿ��ģ�ֻ����˫�յ�
       while(left<right){
           int mid=left+(right-left)/2;
           //�����ж��Ƿ����
           TreeNode *t=root;
           int p=1<<(level-1);
           while(t&&p>0){//�һ��Ǿ������ﲻ�ÿ��ƣ���Ϊ������ȫ������
           //���ģ�����Ҫ����p>0��������ֻ�ж�p���У���Ϊ��level=0��ʱ��
           //p����1<<-1���Ǹ�ʲô������
                if(!(p&mid))//�����ˣ�����̫��ѧ���ˡ�
                    t=t->left;
                else t=t->right;
                p>>=1;
           }
            if(t)left=mid+1;
            else right=mid;
       }
       return left-1;//��ʵ����û��ʲô����ġ�
    }
};
//��ϰʱ��һ��ladong�Ľⷨ��https://zhuanlan.zhihu.com/p/112077293


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
            //������ô����λ���㣬�������ס���ˡ�����
            //����
            //���level=1�Ļ�����ô�������ѭ������������Ͳ�Ҫ����-2�ˡ�
            int t=level-1;
            while(t--){//mid&(1<<t)==0
                if(((mid>>t)&1)==0)r=r->left;
                else r=r->right;
            }
            if(!r)right=mid;
            else left=mid+1;//���ǵ���ѭ���ֵ�left��right������ԭ��
        }
        return left-1;//��Ȼ������д�ģ����level=1�Ļ��Ϳ϶����У�
    }
};
/*
 * 1.�ҵ��죬��θ�ϰ���Ҫ���ҵ�Ѫ�۸��Ϳ��ˣ���������Ϊ���λ���㣬����������֣���ʵ���Ǻ���֮ǰ
 * ȷ���Ĺ�����һ����[left,right)����ҿ���Ѫ���ѿգ������ˡ����λ�����ҿɵ��ܽ��ܽᡣ
 * */

//1-6
/*
 * 1.���츴ϰ��ס��λ��������ݣ���ʵlevelӦ�ô�0��ʼ�����ִ�0��ʼ����һ�£���ok�ġ�
 * 2.ʱ�临�Ӷȣ�O(logn*logn)����һ������Զ��ַ�����ڵ㣬�ڶ���������ܽڵ�ġ�
 *   �ռ�O(1)
 * */
int main(){


    return 0;
}
