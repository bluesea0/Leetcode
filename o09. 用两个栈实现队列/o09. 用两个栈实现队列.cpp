#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��5��22������10:03:40
class CQueue {
public:
    stack<int> A,B;
    CQueue() {
    }

    void appendTail(int value) {
        A.push(value);
    }

    int deleteHead() {
        if(B.empty()){
            while(!A.empty()){
                B.push(A.top());
                A.pop();
            }
        }
        if(!B.empty()){
            int a=B.top();
            B.pop();
            return a;
        }
        return -1;
    }
};
/*
 * 1.�Ƚϼ򵥣�һ����������Ԫ�أ�һ������ɾ��Ԫ�ء�
 * */
int main(){

    return 0;
}
