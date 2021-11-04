#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年5月23日下午4:23:22
class MedianFinder {
public:
    /** initialize your data structure here. */
    //一个堆是大顶堆A，一个堆是小顶堆B，两者包含元素个数要么相同，要么B比A多一个。
    priority_queue<int,vector<int>> A;
    priority_queue<int,vector<int>,greater<int>> B;
    MedianFinder() {

    }

    void addNum(int num) {
        if(A.size()==B.size()){
            //先加入A中，再从A中取出最大的值加入B中
            A.push(num);
            B.push(A.top());A.pop();
        }else{
            //B已经比A多了一个数，那么就先加入到B中然后取最小的数加入A中
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
//没什么问题。
/*
 * 1.关于复杂度：
 * 查找中位数 O(1) ： 获取堆顶元素使用 O(1) 时间；
添加数字 O(logN) ： 堆的插入和弹出操作使用O(logN) 时间。
 添加复杂度只是logn说明，只考虑了这个操作，其实是没有。
 堆排序的复杂度是N*O(logN)，是因为有一个初始建堆的过程，然后根据每个点来调整堆到定义状态。
 在这里只是对堆的操作？所以没有外面*N了。
 * */
int main(){

    return 0;
}
