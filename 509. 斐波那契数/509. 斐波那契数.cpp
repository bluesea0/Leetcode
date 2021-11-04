#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月3日上午12:08:01
class Solution {
public:
    int fib(int N) {
        if(N==0||N==1) return N;
        N-=1;
        int u=0,v=1,f=1;
        while(N--){
            f=u+v;
            u=v;
            v=f;
        }
        return f;
    }
};//0 1 1 2 3 5   N=3,N=2,
//非常简单，AC了。
class S1{
public:
	int fib(int N) {
	    if (N < 1) return 0;
	    // 备忘录全初始化为 0
	    vector<int> memo(N + 1, 0);
	    // 进行带备忘录的递归
	    return helper(memo, N);
	}

	int helper(vector<int>& memo, int n) {
	    // base case
	    if (n == 1 || n == 2) return 1;
	    // 已经计算过
	    if (memo[n] != 0) return memo[n];
	    memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
	    return memo[n];
	}
};
class Solution1 {
public:
    unordered_map<int,int> mp;
    int fib(int N) {
        if(N==0||N==1)return N;
        return f(N);
    }
    int f(int i){
        if(i==1||i==2) return 1;
        if(mp[i]!=0)//那0怎么办？
            return mp[i];
        mp[i]=f(i-1)+f(i-2);
        return mp[i];
    }
};//i=3,f(2)+f(1), f(2)=f(1)+f(0),//我也纠结着写了出来。
int main(){
	S1 s;
	cout<<s.fib(3);//m[3]=m[2]+m[1],m[2]=m[1]+m[0],//不对啊，人家这么写完全是不会遇到n==0||n==1的！
    return 0;
}
