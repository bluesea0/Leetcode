#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��9��3������7:12:56
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    //vector<int> vis;����������������ǲ�֪��ͼ���ж��ٸ��ڵ�ģ�
    //���Ծ��޷���ʼ����Сresize������ѡ����map�ɡ�
    unordered_map<Node*,Node*> um;
    Node* cloneGraph(Node* node) {
        //�ȱ����ڵ㣬�ٿ�¡����ô����ж��Ƿ�Ϊ���أ�
        if(node==nullptr)//��Կ�ͼ
            return node;
        //����ʵ�ڱ�����ʱ�������neighbors����Ϊ�գ��ͻ�ֱ����forѭ�����ﲻ�����ˡ�
        if(um.count(node))return um[node];
        Node* t=new Node(node->val);
        um[node]=t;
        for(auto& ng:node->neighbors){
            t->neighbors.emplace_back(cloneGraph(ng));
        }
        return t;
    }
};
/*
 * /**
 * 1.ͷһ��������ͼ���⣬ ����val���ھ�������
 * 2.DFS�ȱ���ͷ��㣬�ٱ��������ӽڵ㡣���波��һ��BFSд����
 * /3.BFS���Ѱ���̫������˰ɣ�������Ŷ��
 * */
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        queue<Node*> q;
        unordered_map<Node*,Node*> um;
        Node* t=new Node(node->val);
        //t->neighbors=node->neighbors;//����ֱ��push����neighbor����Ϊ��Ҫ��¡��̫���ˣ���Ҫ��ϰ��

        um[node]=t;
        q.push(node);
        while(!q.empty()){
            Node* top=q.front();
            q.pop();
            for(auto& ng:top->neighbors){
                if(!um.count(ng)){
                    t=new Node(ng->val);
                    um[ng]=t;
                    q.push(ng);
                }
                um[top]->neighbors.emplace_back(um[ng]);
            }
        }
        return um[node];
    }
};


int main(){

    return 0;
}
