#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-16
/*
1.这个是剑指offer第16题。
2.感觉好难啊，我之前做过，也复习过，但是还是感觉不会，是快速幂？二分？二分不也会重复计算吗？
3.快速幂是奇数次*偶数次幂？我真的不会，大脑一片空白，我只知道顺序乘。
4.递归比较好些，迭代的思想是对指数的二进制拆分。
5.其实还是蛮难的，明天需要手写一下，等到自己写的代码能够AC了之后，再把它添加到记忆曲线中。
*/
//10-17
class Solution {
public:
    //O(\log n)，即为递归的层数。
    //O(logn)，即为递归的层数。这是由于递归的函数调用会使用栈空间。
	double pow_(double x,int n){
        if(n==0) return 1.0;
        double r=pow_(x,n/2);
        return n%2==0?r*r:r*r*x;
    }
    double myPow(double x, int n) {
        long long N=n;
        if(x==1.0)return x;
        return n>0?pow_(x,N):1.0/pow_(x,-N);
    }
};
/*
1.1.00000
-2147483648,会有这样的样本输入。
2.00000
-2147483648，还有这样的，存心是不让我用int？但是人家给定的就是用int来表示的啊。
n 是 32 位有符号整数，其数值范围是[−231,231− 1]。这不说明int可以吗？反正我不懂了。
果然，看了官方解法，换成了long long类型的，
3.下面来写一下迭代版本的快速幂，主要是对
*/
class Solution1 {
public:
    //O(\log n)，即为对 nn 进行二进制拆分的时间复杂度。
    //O(1)
    double pow_(double x, int n){
        double con=x,res=1;
        long long N=n;
        while(N){
            if(N%2){//理解了，因为每次也都是/2，和上面递归的是类似的。
                res*=con;
            }
            con*=con;//这里x的幂次对应着二进制位数
            N/=2;
        }
        return res;
    }
    double myPow(double x, int n) {
        long long N=n;
        return n>0?pow_(x,N):1.0/pow_(x,-N);
}};
/*
4.也AC了。
*/

//5-22
/*
 * 1.1.00000
-2147483648 这次写还是遇到了int不能表示-n，也就是2147483648的情况。
2.关于这个越界的处理，需要注意。
 * */
class Solution2 {
public:
    double myPow(double x, int n) {
        //是否需要考虑x的正负？
        //对于n来说，需要考虑正负
        //特殊情况都该怎么处理？
        if(x==0)return 0;
        if(n==0)return 1;
        long long N=n;//传进来的时候就需要转换
        //为了避免2^31方出现。
        return n>0?fun(x,N):1.0/fun(x,-N);
    }
    double fun(double x,long long n){
        double res=1.0;
        while(n){
            if(n&1)res*=x;
            x*=x;
            n>>=1;
        }
        return res;
    }
};
//下面写一下递归版本：
class Solution {
public:
    double myPow(double x, int n) {
        if(x==0)return 0;
        if(n==0)return 1;
        long long N=n;
        return n>0?fun(x,N):1.0/fun(x,-N);
    }
    double fun(double x,long long n){
        if(n==1)return x;
        double s=fun(x,n/2);
        return n&1?x*s*s:s*s;
    }
};
int main(){
    Solution2 s;
    cout<<s.myPow(1,-2147483648);
    return 0;
}
