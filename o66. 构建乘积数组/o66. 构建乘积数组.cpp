#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年3月7日下午3:00:40
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        //先构建下三角数组，表示每个数之前的乘积结果，然后再构建下三角，这样得到结果
        if(a.empty())return {};
        vector<int> b(a.size(),0);
        b[0]=1;//0之前元素的乘积
        for(int i=1;i<b.size();i++)
            b[i]=b[i-1]*a[i-1];
        int t=a.back();//需要有一个值来累计记录的啊！
        for(int i=b.size()-2;i>=0;i--){
            b[i]*=t;
            t*=a[i];
        }
        return b;
    }
};
/*
 * 1.也是看了题解之后才明白了。
 * */

//6-18
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        //B[i]表示结果向量
        //左向遍历时计算当前数i左边的乘积，右向遍历再将右边的乘积乘进来
        int n=a.size();
        vector<int> B(n,1);
        for(int i=1;i<n;i++)
            B[i]=B[i-1]*a[i-1];
        int temp=1;
        for(int i=n-1;i>=0;i--){
            B[i]*=temp;
            temp*=a[i];
        }
        return B;
    }
};
/*
 * 1.奈斯写出来了，主要是第一次遍历时B[i]保存它左边的到i-1的所有数的结果，在右向遍历的时候再乘以当前数
 *   右边的乘积。
 * */
int main(){
	Solutoin s;
	s.constructArr();
    return 0;
}
