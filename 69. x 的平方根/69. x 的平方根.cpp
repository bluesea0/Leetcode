#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��11������4:32:48
class Solution {
public:
    int mySqrt(int x) {
        //����eֵ����
        if(x==0)return 0;
        int a=exp(0.5*log(x));
        return (long long)(a+1)*(a+1)<=x?a+1:a;
    }
};
class Solution2 {
public:
    int mySqrt(int x) {
        //���ַ�
        if(x==0) return 0;
        int l=0,r=x;
        while(l<=r){//����Ӧ����=��
            int mid=l+(r-l)/2;
            if((long long)mid*mid<=x)
                l=mid+1;
            else r=mid-1;
        }
        return l-1;
    }
};
/*
 * 1.��һ���ⷨ������������㷨�����ٽ���ġ�O(1)
 * 2.�ڶ����Ƕ��ַ��������l��r�Լ�ѭ����������return���������Ҫע��ġ���д��ûʲô���⣬̫���ˣ��Ѿ�ѧ��
 *   ���ֵ��ڻ��ͨ�ˣ�
 * */

//2021-6-7
class Solution {
public:
    int mySqrt(int x) {
        //���ַ�
        if(x==0) return 0;
        int l=1,r=x;
        while(l<=r){//����Ӧ����=��
            int mid=l+(r-l)/2;
            if((long long)mid*mid<=x)
                l=mid+1;
            else r=mid-1;
        }
        return l-1;
    }
};
/*
 * 1.�����ָ�ϰ��һ�£�������д���ֻ���ϰ����<=�����������䣬����࣡
 * */
int main(){

    return 0;
}
