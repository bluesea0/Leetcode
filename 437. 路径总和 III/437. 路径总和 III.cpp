#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��10��27������3:56:09
/*
 * 1.�ҿ��������ĸо����ǣ��ȵݹ��ҳ������Ե�Ҷ����·����Ȼ������ǰ׺��+��ϣ����⡣
 * 2.̫Ű�ˣ�Ű�����ˣ���������ﰡ����������������߽����ȥ���������ҾͲ����ˡ�
 * */
//class Solution {
//public:
//    int ans=0,sum;
//    int pathSum(TreeNode* root, int sum) {
//        if(!root) return 0;
//        this->sum=sum;
//        vector<int> path;
//        dfs(root,path);
//        return ans;
//    }
//    void dfs(TreeNode* root,vector<int> path){//�����������ʱ��Դ����û���ֵ���������ʡ�
//        path.push_back(root->val);//�Ҿ��ô��ݵĲ������ã��Ͳ���pop�˰ɡ�
//        if(!root->left && !root->right){
//            ans+=helper(path);//��ִ�в�����һ����������Ϊʲô��
//            //�ҵ��죬�����Ļ��������������ͻ��ظ��㰡�������ҳ��ײ����ˡ�
//        }else{
//            if(root->left) dfs(root->left,path);//�����˻��㣬���������Ϊ�հ����
//            if(root->right) dfs(root->right,path);
//        }
//        path.pop_back();
//    }//ΪʲôҪ��ô���ң�ΪʲôΪʲôΪʲô�ء�����
//    int helper(vector<int>& path){
//        unordered_map<int,int> mp;
//        int ret=0,s=0;
//        for(auto p:path){
//            s+=p;
//            if(mp.count(s-sum)!=0)ret+=mp[s-sum];
//            mp[s]+=1;
//        }
//        cout<<ret<<endl;
//        return ret;
//    }
//};

//10-29
/*
 * 1.����ʱû��AC�Ĵ��룬����Ҳ����˼·�Ľᾧ����һ��ʼ���뷨�����ҳ�ÿ����Ҷ����·����Ȼ���·��
 *   ����������ǰ׺��+��ϣ�������������ظ�����·���ģ������и���5 3���ظ��ˡ�
 * 2.ǰ��д��ʱ��һֱ���벻��helper����������ŷ��֣�����Ϊif(!root->left)??����ɵ�ƣ������Ļ�
 *   �ղ�Ϊ�氡�����Ż��ȥ�ж����氡��������
 * 3.����grand�Ľⷨ��https://www.cnblogs.com/grandyang/p/6007336.html�����Ǿ���ѧ���ˣ�ԭ������ôд��
 *   ���˵ڶ��ֽⷨ���Ҿ�˵��϶����õ�ǰ׺��+�����İ���
 *   �����ֽⷨҲ�������ġ�
 * 4.ʱ�ո��Ӷȣ��о�����O(n)��
 * */
int main(){
	unordered_map<int,int> mp;
	int res=mp[1];//�����ӻ���û���ϣ��һ���Ϊ�ܼ����ء�����
	cout<<res<<" "<<mp[1];
    return 0;
}
