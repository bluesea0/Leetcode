#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年3月7日下午3:14:52
class Solution {
public:
    int add(int a, int b) {
        //???不会，只能想到是不是用位运算？？？
        return a+b;
    }
};
/*
分析代码:3+1=4样例
a=0011
b=0001
c=(0001)<<1=0010
a=0010
b=0010
——————————
a=0010
b=0010
c=(0010)<<1=0100
a=0000
b=0100
———————————
a=0000
b=0100
c=0000
a=0100
b=0000
*/

class Solution {
public:
    int add(int a, int b) {
        //知识点：0和1按位相加，非进位和是异或的结果，进位和是与左移一位的结果，
        //用a表示异或的结果，b表示与的结果，循环条件的判断是b是否为0
        //使用循环来模拟进位加法？这个我就不太明白了。
        while(b!=0){
            int h=(unsigned int)(a&b)<<1;//进位
            //这里-1+2出现了问题，这个这个
            ////C++中负数不支持左移位，因为结果是不定的
            a^=b;
            b=h;
        }
        return a;
    }
};
/*
 * 1.按照题解写的，反正知识点get到了一个，就是0和1按位相加，非进位和是异或的结果，进位和是与左移一位的结果。
 * */
int main(){

    return 0;
}
