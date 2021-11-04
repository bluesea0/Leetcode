#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年10月10日下午11:47:48
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        //rand49=;
        int x=INT_MAX;
        while(x>40){//这里40是<=49的且是10的倍数的最大值。
            x=7*(rand7()-1)+rand7();//[1,49]之间的数
        }
        return x%10+1;//[1,10]可以轮回地生成[2,3,....1]，同理[11,20],[21,30],[31,40]
    }
};
/*
 * 1.其实我不是很明白为何要这么做？目的是尽量地减少对rand7()的调用，
 *   则我们应该尽量保证生成的每个不同的数的生成概率尽可能的大。通过拒绝采样。拒绝剩下的9个数,41-49
 *   这10个数每个的概率为4/49。
 * */
int main(){

    return 0;
}
