#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年5月22日下午4:24:28
class MinStack {
public:
    /** initialize your data structure here. */
    //思路，用一个额外的栈来保存最值，非递减栈。
    stack<int> A,B;
    MinStack() {
    }

    void push(int val) {
        A.push(val);
        if(B.empty())B.push(val);
        else if(val<=B.top())B.push(val);
    }

    void pop() {
        if(!A.empty()){
            int v=A.top();A.pop();
            if(v==B.top())B.pop();
        }
    }

    int top() {
        if(!A.empty())return A.top();
        return -1;
    }

    int getMin() {
        if(!B.empty())return B.top();
        return -1;
    }
};
/*
 * 1.一下自AC了，没什么问题。
 * */
int main(){

    return 0;
}
