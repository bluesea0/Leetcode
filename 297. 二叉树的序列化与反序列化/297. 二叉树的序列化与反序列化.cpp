#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年5月19日上午11:59:51
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
    TreeNode* deserialize(string data) {//天啦反序列化真的不太知道怎么写啊
        //这里恍惚了，不知道怎么写。
        //原来是需要再写一个递归函数
        //C++中的string有split函数吗
        int start=0;
        //vector<string> tr;
        queue<string> tr;
        while(data.find(",",start)!=string::npos){
            int t=data.find(",",start);
            tr.push(data.substr(start,t-start));//天啦，又记错了，这里substr是长度
            start=t+1;//经过我的观察这里不能用vector啊！！！
        }
        return helper(tr);
    }
    TreeNode* helper(queue<string>& tr){//但是这里又怎么确保start的下标不越界呢？
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
 * 1.没想到自己这道题还没做，听朱说他面试遇到了这道题。他说层次遍历，但让他写所以我过来偷偷刷一下。
 * 2.在写的时候，只用#分开的话，是不足以再反序列化的，所以需要加“，”，这是我第一点欠考虑的，
 *   在反序列化时需要一个辅助函数，进行递归，递归参数的传递，需要用queue，通过引用传递并且pop，或者是像grand
 *   那样istringstream用字符串流，但这个我并不熟悉，看到评论区有用queue的；总之学到了。挺难的还。接下来要看看
 *   层次遍历该如何实现。
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
            //这样写是错的，顺序就乱了，
            //所以入队和打印出来的先后顺序该是怎么样？
            //那么应该入队的时候就打印，而不是出队
            else s+="#,";//s+=to_string("#,");是错的，因为并不是int型的！
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
        //vector<string> nodes;//不能用向量，因为你层次遍历的时候用的是队列
        //那么现在在通过遍历结果去反过来构造树的时候肯定仍要利用到队列了
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
            //天哪这接下去该怎么些啊？？？这层次遍历可是要分支的，我懵了。
            //不会写了，好有挫败感啊。不过我好像之前没有写过这个题型。
            //看了题解发现，原来构建好的节点也需要入队列，需要借助队列，我就说如果单独这样倒腾，
            //那肯定是遍历不过来的，控制不住层次遍历的发散的。
        }
        return root;
    }
};
/*
 * 1.天哪，AC了，太不容易了吧。日了。总结一下就是我想哭啊。
 * 2.关键点：入队时打印；遍历结果用队列存储，并且通过层次构造的节点也通过队列存储！牛的。复习+写54分钟这个。
 * */
int main(){

    return 0;
}
