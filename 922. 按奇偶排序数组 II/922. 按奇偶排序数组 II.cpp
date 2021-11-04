#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月12日上午10:59:32
//class Solution {
//public:
//    vector<int> sortArrayByParityII(vector<int>& A) {
//        //思路：首位双指针遍历
//        int i=0,j=A.size()-1;
//        while(i<j){
//            while(i<j&&((i%2==0&&A[i]%2==0)||(i%2==1&&A[i]%2==1)))i++;
//            while(i<j&&((j%2==0&&A[j]%2==0)||(j%2==1&&A[j]%2==1)))j--;
//            swap(A[i],A[j]);
//            i--;j--;
//        }
//        return A;
//    }
//};
/*
 * 1.[2,3,1,1,4,0,0,4,3,3],超时了。是因为i=2指向了1，j=8指向了3，那么它两位就会一直产生交换。。
 *   这个easy的题我还以为我能很快解决呢。。没想到这就卡住了？哭泣！
 *   所以我整个思路就是错的了？我哭死这儿了。。。没有思路了，我又被虐了。
 * 2.看了官方的解法https://leetcode-cn.com/problems/sort-array-by-parity-ii/solution/an-qi-ou-pai-xu-shu-zu-ii-by-leetcode-solution/
 *   牛牛牛，这个问题，在面试时需要问面试官是否可以修改A向量，如果可以那么就原地修改，否则的话就
 *   新建一个向量。绝了。i指向偶数的位置，j指向奇数的位置，绝了绝了。
 * */

//11-13
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        //思路：维护指向奇数位置和偶数位置的两个点
        //在A可以被修改的情况下。
        int j=1;
        for(int i=0;i<A.size();i+=2){//判断偶数位是否满足
            if(A[i]%2!=0){//需要和j指向的位置交换
                while(A[j]%2&&j<A.size())j+=2;
                swap(A[i],A[j]);
            }
        }
        return A;
    }
};
/*
 * 1.按照昨天的思路AC了终于。其实写的时候还是不熟悉，有点恍惚的。需要复习的。
 * */

//11-25
/*
 * 1.这次复习就直接忘了怎么写了，只记得一个指向偶数位置，一个指向奇数位置，但是想的是while嵌套两个
 *   平行的for循环，，，绝了。。。
 * */

//12-20
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int j=1;//我去，还真有点懵哎，不知道如何处理啊！我的天
        for(int i=0;i<A.size();i+=2){
            if(A[i]%2==0)continue;
            while(j<A.size()&&A[j]%2==1)j+=2;
            swap(A[i],A[j]);
        }
        return A;
    }
};
/*
 * 1.还不错哦，AC了，O(n) O(1)吧。
 * */
int main(){
	Solution s;
	vector<int> a={2,3,1,1,4,0,0,4,3,3};
	vector<int> ret=s.sortArrayByParityII(a);
	for(auto aa:ret)
		cout<<aa<<" ";
    return 0;
}
