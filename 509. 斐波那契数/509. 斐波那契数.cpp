#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��3������12:08:01
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
//�ǳ��򵥣�AC�ˡ�
class S1{
public:
	int fib(int N) {
	    if (N < 1) return 0;
	    // ����¼ȫ��ʼ��Ϊ 0
	    vector<int> memo(N + 1, 0);
	    // ���д�����¼�ĵݹ�
	    return helper(memo, N);
	}

	int helper(vector<int>& memo, int n) {
	    // base case
	    if (n == 1 || n == 2) return 1;
	    // �Ѿ������
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
        if(mp[i]!=0)//��0��ô�죿
            return mp[i];
        mp[i]=f(i-1)+f(i-2);
        return mp[i];
    }
};//i=3,f(2)+f(1), f(2)=f(1)+f(0),//��Ҳ������д�˳�����
int main(){
	S1 s;
	cout<<s.fib(3);//m[3]=m[2]+m[1],m[2]=m[1]+m[0],//���԰����˼���ôд��ȫ�ǲ�������n==0||n==1�ģ�
    return 0;
}
