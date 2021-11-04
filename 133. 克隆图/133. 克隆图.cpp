#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年9月3日下午7:12:56
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
    //vector<int> vis;但是用这个，事先是不知道图中有多少个节点的，
    //所以就无法初始化大小resize，还是选择用map吧。
    unordered_map<Node*,Node*> um;
    Node* cloneGraph(Node* node) {
        //先遍历节点，再克隆，那么如何判断是否为空呢？
        if(node==nullptr)//针对空图
            return node;
        //但其实在遍历的时候如果点neighbors向量为空，就会直接在for循环那里不出来了。
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
 * 1.头一次做这种图的题， 包括val和邻居向量。
 * 2.DFS先遍历头结点，再遍历它的子节点。下面尝试一下BFS写法。
 * /3.BFS好难啊，太难理解了吧，哭唧唧哦。
 * */
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        queue<Node*> q;
        unordered_map<Node*,Node*> um;
        Node* t=new Node(node->val);
        //t->neighbors=node->neighbors;//不能直接push它的neighbor，因为是要克隆，太难了，需要复习。

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
