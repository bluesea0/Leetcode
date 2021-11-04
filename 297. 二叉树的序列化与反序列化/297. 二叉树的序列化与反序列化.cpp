#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��5��19������11:59:51
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "#,";
        string left=serialize(root->left);
        string right=serialize(root->right);
        return to_string(root->val)+","+left+right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {//���������л���Ĳ�̫֪����ôд��
        //�������ˣ���֪����ôд��
        //ԭ������Ҫ��дһ���ݹ麯��
        //C++�е�string��split������
        int start=0;
        //vector<string> tr;
        queue<string> tr;
        while(data.find(",",start)!=string::npos){
            int t=data.find(",",start);
            tr.push(data.substr(start,t-start));//�������ּǴ��ˣ�����substr�ǳ���
            start=t+1;//�����ҵĹ۲����ﲻ����vector��������
        }
        return helper(tr);
    }
    TreeNode* helper(queue<string>& tr){//������������ôȷ��start���±겻Խ���أ�
        string val=tr.front();
        tr.pop();
        if(val=="#")return NULL;
        TreeNode* r=new TreeNode(stoi(val));
        r->left=helper(tr);
        r->right=helper(tr);
        return r;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
/*
 * 1.û�뵽�Լ�����⻹û��������˵����������������⡣��˵��α�����������д�����ҹ���͵͵ˢһ�¡�
 * 2.��д��ʱ��ֻ��#�ֿ��Ļ����ǲ������ٷ����л��ģ�������Ҫ�ӡ������������ҵ�һ��Ƿ���ǵģ�
 *   �ڷ����л�ʱ��Ҫһ���������������еݹ飬�ݹ�����Ĵ��ݣ���Ҫ��queue��ͨ�����ô��ݲ���pop����������grand
 *   ����istringstream���ַ�������������Ҳ�����Ϥ����������������queue�ģ���֮ѧ���ˡ�ͦ�ѵĻ���������Ҫ����
 *   ��α��������ʵ�֡�
 * */

//5-21
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string s="";
        if(!root)return s;
        q.push(root);
        s+=to_string(root->val)+",";
        while(!q.empty()){
            TreeNode* top=q.front();
            q.pop();
            if(top->left){
                s+=to_string(top->left->val)+",";
                q.push(top->left);
            }
            //����д�Ǵ�ģ�˳������ˣ�
            //������Ӻʹ�ӡ�������Ⱥ�˳�������ô����
            //��ôӦ����ӵ�ʱ��ʹ�ӡ�������ǳ���
            else s+="#,";//s+=to_string("#,");�Ǵ�ģ���Ϊ������int�͵ģ�
            if(top->right){
                q.push(top->right);
                s+=to_string(top->right->val)+",";
            }
            else s+="#,";
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="")return NULL;
        int start=0;
        //vector<string> nodes;//��������������Ϊ���α�����ʱ���õ��Ƕ���
        //��ô������ͨ���������ȥ��������������ʱ��϶���Ҫ���õ�������
        queue<string> q;
        while(data.find(",",start)!=string::npos){
            int t=data.find(",",start);
            q.push(data.substr(start,t-start));
            start=t+1;
        }
        // for(int i=0;i<nodes.size();i++){
        // }
        TreeNode* root=new TreeNode(stoi(q.front()));
        q.pop();
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!q.empty()){
            string l=q.front();q.pop();
            string r=q.front();q.pop();
            TreeNode* node=nodes.front();nodes.pop();
            if(l!="#"){
                TreeNode* left=new TreeNode(stoi(l));
                node->left=left;
                nodes.push(left);
            }
            if(r!="#"){
                TreeNode* right=new TreeNode(stoi(r));
                node->right=right;
                nodes.push(right);
            }
            //���������ȥ����ôЩ�����������α�������Ҫ��֧�ģ������ˡ�
            //����д�ˣ����д�ܸа��������Һ���֮ǰû��д��������͡�
            //������ⷢ�֣�ԭ�������õĽڵ�Ҳ��Ҫ����У���Ҫ�������У��Ҿ�˵��������������ڣ�
            //�ǿ϶��Ǳ����������ģ����Ʋ�ס��α����ķ�ɢ�ġ�
        }
        return root;
    }
};
/*
 * 1.���ģ�AC�ˣ�̫�������˰ɡ����ˡ��ܽ�һ�¾�������ް���
 * 2.�ؼ��㣺���ʱ��ӡ����������ö��д洢������ͨ����ι���Ľڵ�Ҳͨ�����д洢��ţ�ġ���ϰ+д54���������
 * */
int main(){

    return 0;
}
