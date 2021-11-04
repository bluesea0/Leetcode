#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��9��19������5:55:10
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> A,B;
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        A.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x;
        if(B.empty()){
            while(!A.empty()){
                B.push(A.top());
                A.pop();
            }
        }
        x=B.top();
        B.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        if(B.empty()){
            while(!A.empty()){
                B.push(A.top());
                A.pop();
            }
        }
        return B.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        if(A.empty()&&B.empty())return true;
        return false;
    }
};
/*
 * 1.�ǳ��򵥣�ûʲô�Ѷȣ����Ǿ������pop��peek�е������ˡ�
 * */
int main(){

    return 0;
}
