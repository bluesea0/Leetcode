#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��5��22������4:24:28
class MinStack {
public:
    /** initialize your data structure here. */
    //˼·����һ�������ջ��������ֵ���ǵݼ�ջ��
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
 * 1.һ����AC�ˣ�ûʲô���⡣
 * */
int main(){

    return 0;
}
