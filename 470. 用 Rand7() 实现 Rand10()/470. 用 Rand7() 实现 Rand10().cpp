#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��10��10������11:47:48
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        //rand49=;
        int x=INT_MAX;
        while(x>40){//����40��<=49������10�ı��������ֵ��
            x=7*(rand7()-1)+rand7();//[1,49]֮�����
        }
        return x%10+1;//[1,10]�����ֻص�����[2,3,....1]��ͬ��[11,20],[21,30],[31,40]
    }
};
/*
 * 1.��ʵ�Ҳ��Ǻ�����Ϊ��Ҫ��ô����Ŀ���Ǿ����ؼ��ٶ�rand7()�ĵ��ã�
 *   ������Ӧ�þ�����֤���ɵ�ÿ����ͬ���������ɸ��ʾ����ܵĴ�ͨ���ܾ��������ܾ�ʣ�µ�9����,41-49
 *   ��10����ÿ���ĸ���Ϊ4/49��
 * */
int main(){

    return 0;
}
