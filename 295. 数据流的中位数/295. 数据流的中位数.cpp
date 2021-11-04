#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��5��23������4:23:22
class MedianFinder {
public:
    /** initialize your data structure here. */
    //һ�����Ǵ󶥶�A��һ������С����B�����߰���Ԫ�ظ���Ҫô��ͬ��ҪôB��A��һ����
    priority_queue<int,vector<int>> A;
    priority_queue<int,vector<int>,greater<int>> B;
    MedianFinder() {

    }

    void addNum(int num) {
        if(A.size()==B.size()){
            //�ȼ���A�У��ٴ�A��ȡ������ֵ����B��
            A.push(num);
            B.push(A.top());A.pop();
        }else{
            //B�Ѿ���A����һ��������ô���ȼ��뵽B��Ȼ��ȡ��С��������A��
            B.push(num);
            A.push(B.top());B.pop();
        }
    }

    double findMedian() {
        if(!B.empty()&&A.size()==B.size())
            return (A.top()+B.top())*1.0/2;
        else if (!B.empty())
            return B.top()*1.0;
        return -1.0;
    }
};
//ûʲô���⡣
/*
 * 1.���ڸ��Ӷȣ�
 * ������λ�� O(1) �� ��ȡ�Ѷ�Ԫ��ʹ�� O(1) ʱ�䣻
������� O(logN) �� �ѵĲ���͵�������ʹ��O(logN) ʱ�䡣
 ��Ӹ��Ӷ�ֻ��logn˵����ֻ�����������������ʵ��û�С�
 ������ĸ��Ӷ���N*O(logN)������Ϊ��һ����ʼ���ѵĹ��̣�Ȼ�����ÿ�����������ѵ�����״̬��
 ������ֻ�ǶԶѵĲ���������û������*N�ˡ�
 * */
int main(){

    return 0;
}
