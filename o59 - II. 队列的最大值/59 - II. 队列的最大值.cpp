#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��3��22������8:47:24
class MaxQueue {
public:
    queue<int> q;
    deque<int> dq;
    MaxQueue() {
        //����queue�洢Ԫ��
        //deque�������ϸ�ݼ����д洢���ֵ
        //����Ҫ�洢�±�
    }

    int max_value() {//O(1)
        if(q.empty())return -1;
        return dq.front();
    }

    void push_back(int value) {//O(n)�����Ǿ�̯Ҳ��O(1)
        q.push(value);
        while(!dq.empty()&&dq.back()<value)dq.pop_back();
        dq.push_back(value);
    }

    int pop_front() {//O(1)
        if(q.empty())return -1;
        int a=q.front();
        q.pop();
        if(a==dq.front())dq.pop_front();
        return a;
    }
};
/*
 * 1.AC�ˡ�
 * */
int main(){
	MaxQueue* obj = new MaxQueue();
	cout<<obj->max_value();
	obj->push_back(2);
	obj->push_back(1);
	cout<<obj->max_value();
	cout<<obj->pop_front();
	cout<<obj->max_value();
    return 0;
}
