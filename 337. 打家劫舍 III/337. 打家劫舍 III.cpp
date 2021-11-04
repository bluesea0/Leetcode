#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��1������1:32:43
//class Solution {
//public:
//    int rob(TreeNode* root) {
//        //˼·������һ��������˵�������ֽ�����������ڵ�Ͳ��������ڵ㵫�����ӽڵ㡣
//        //��Ŀǰ���������Ҳ�֪����ôʵ��
//        //Ӧ����Ҫ�ݹ���д���ݹ�Ĺ��̾ͷ������ֽ�����Ҳ��ᣬͶ����
//    }
//};
//��Ȼ��û��д�����˰���

//12-3
class Solution {
public:
    unordered_map<TreeNode*,int> f,g;
    int rob(TreeNode* root) {
        //˼·������һ��������˵�������ֽ�����������ڵ�Ͳ��������ڵ㵫�����ӽڵ㡣
        //��Ŀǰ���������Ҳ�֪����ôʵ��
        //Ӧ����Ҫ�ݹ���д���ݹ�Ĺ��̾ͷ������ֽ�����Ҳ��ᣬͶ����
        if(!root) return 0;
        dfs(root);
        return max(f[root],g[root]);
    }
    void dfs(TreeNode* root){
        if(!root) return;
        //�һ��ǲ���д��������ν��б����أ������g����û�еİ�����ô�󰡡�
        //����������ҹ��ˡ�
        //������⣬�����Ǻ����������û�����
        dfs(root->left);
        dfs(root->right);
        f[root]=root->val+g[root->left]+g[root->right];
        //��Ϊ��map�����û������ؼ��ֵĻ�����ôֱ��������ľ���0��
        g[root]=max(f[root->left],g[root->left])+max(f[root->right],g[root->right]);
        //�������root->left����root->right�Ƿ�Ϊ�յĻ���None������map��ʵ����0�����ص��ġ�
    }
};
//�������ֽⷨ���Ӷȶ�ΪO(n)����ô���澭���ռ��Ż��ģ����Է�����rootֻ�������ӽڵ��й�ϵ��
struct Status{//�������Ҫ�����ⶨ��ġ�
    int select;
    int notSelect;
};
class Solution {
public:
    unordered_map<TreeNode*,int> f,g;
    int rob(TreeNode* root) {
        if(!root) return 0;
        Status s=dfs(root);
        return max(s.select,s.notSelect);
    }
    Status dfs(TreeNode* root){
        if(!root) return{0,0};
        Status l=dfs(root->left);
        Status r=dfs(root->right);
        Status ret;
        ret.select=root->val+l.notSelect+r.notSelect;
        ret.notSelect=max(l.select,l.notSelect)+max(r.select,r.notSelect);
        return ret;
    }
};
//�������ٶ�Ҳ���ӿ��ˡ��ռ临�Ӷ�����O(n)����ʹ�õ�ջ�ռ䣡

//12-22
/*
 * 1.������θ�ϰҲ��΢��Ϊ���ˣ�����Ϊ��max(root->val,left,right,left+right)�أ���ȫû�п��ǵ�ǰ
 *   ���ڵ㱻ѡ�еĻ������������ӽڵ㲻ѡ�У������ĵݹ����������㰡���������е���Ŀ�����´θ�ϰҪд
 *   ���롣
 * 2.����grand�Ľⷨhttps://www.cnblogs.com/grandyang/p/5275096.html��ԭ������Ҫ����ֻ�ܽ���struct
 *   Ҳ������vector<int> res(2,0)���������أ�ѧ���ˡ�
 * */
int main(){

    return 0;
}
