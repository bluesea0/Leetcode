#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月3日上午11:59:08
//class Solution {
//public:
//    int countPrimes(int n) {
//        //质数有什么规律吗？难道我要从2-n一个一个去判断？那我肯定超时了吧？我试试。
//        //从1->根号n就可以了
//        if(n==0||n==1||n==2) return 0;//注意啊n==2的时候，是小于，没有等于，所以返回0.
//int ans = 0;//官方写的过程。6啊，比我这个判断好多了。
//for (int i = 2; i < n; ++i) {
//    ans += isPrime(i);
//}
//        int ans=1;
//        for(int i=3;i<n;i++)
//            if(helper(i))
//                ans++;
//        return ans;
//    }
//    bool helper(int n){
//        for(int i=2;i<=int(sqrt(n))+1;i++)//这里的边界我是真的不确定啊。
//            if(n%i==0)//对于7来说，上面=应该加上？
//                return false;
//        return true;
//    }//1500000，超时了。我哭。
//};
/*
 * 1.n最大是5 * 10^6，上面超时的例子是1.5*10^6，差着远呢。总时间复杂度为O(n根号n)
 * 2.官方题解中的暴力枚举都比我强：
 *     bool isPrime(int x) {
        for (int i = 2; i * i <= x; ++i) {这里直接就没有求sqrt，高，实在是高啊！
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }//单次检查复杂度为O(根号n)
    3.线性筛我是真的看不懂，艾什筛倒还可以理解。
 * */

//12-9
class Solution {
public:
    int countPrimes(int n) {
        int ans=0;
        for(int x=2;x<n;x++){
            if(isp(x)){
            	ans++;
            	cout<<x<<endl;
            }
        }
        return ans;
    }
    bool isp(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i==0)
                return false;
        }
        return true;
    }
};
/*
 * 1.按照官方的暴力解法，居然AC了，看了求根还是费时间啊。下面写一下埃氏筛。
 *   呜呜算法已经学了两个小时了，没时间了，得看论文了呀啊。
 * */

//12-10
class Solution1 {
public:
    int countPrimes(int n) {
        vector<int> p(n,1);
        int ans=0;
        for(int i=2;i<n;i++){
            if(p[i]){
                ans++;
                if((long long)i*i<n){//这里一定需要进行判断，否则就算for循环定义j是long long也不行
                    for(long long j=i*i;j<n;j+=i)//这里不应该从2*i开始标记，应该从
                //runtime error: signed integer overflow: 46349 * 46349 cannot be represented in type 'int' (solution.cpp)
                        p[j]=0;
                }
            }
        }
        return ans;
    }
};
/*
 * 1.上面终于AC了，埃氏筛需要从x*x开始标记，因为2*x这些肯定2都已经标记过了！
 * 2.           for (int j = i + i; j < n; j += i) {//那评论区这个写的有问题啊，应该是i*i
                //排除不是质数的数   //那还是应该考虑到溢出的问题。
                signs[j] = false;
            }
    但是为啥人家这么写就对？人家也用的int啊，我用longlong都不行？
   3.以后设置int可能溢出的话，就用判断，而不是生成一个对应的对象，直接用临时变量，就像这样：
   	   if((long long)i*i<n)来判断，就非常好了！
 * */
int main(){
	Solution1 s;
	cout<<s.countPrimes(499979);
    return 0;
}
