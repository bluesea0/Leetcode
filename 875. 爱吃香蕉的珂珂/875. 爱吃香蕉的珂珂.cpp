#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月4日下午5:12:15
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        //想吃的尽量慢但是要吃完所有的
        //思路：没有思路，完全不会，嘿嘿。
        int max=piles[0];
        for(auto p:piles)
            if(p>max)max=p;//获取最大值
        int left=1,right=max+1;
        cout<<left<<" "<<right<<endl;
        while(left<right){
            int mid=left+(right-left)/2;
            //那这里还是要遍历数组中的每个数来计算啊
            if(helper(piles,mid,H)){
                right=mid;
            }else left=mid+1;
            cout<<left<<" "<<mid<<" "<<right<<endl;
        }
        return left;
    }
    bool helper(vector<int>& piles,int mid,int H){
        int h=0;
        for(auto p:piles){
            int t=p/mid+((p%mid==0)?0:1);//后半部分要加括号，不然?前半部分都给算判断条件了！
            h+=t;
            if(h>H) return false;
        }
        cout<<h<<endl;
        if(h>H) return false;
        return true;
    }
};
//AC了，我实在是太棒了，从这里我知道了三元运算符原来是这样啊！
//https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/2.5-shou-ba-shou-shua-shu-zu-ti-mu/koko-tou-xiang-jiao
//多亏了大佬的讲解！
/*
 * 时间复杂度：O(NlogW)，其中 N 是香蕉堆的数量，W 最大的香蕉堆的大小。
空间复杂度：O(1)。
 * */

//11-24
/*
 * 1.这次复习关键的问题是为什么返回left，而不是right？但是退出时left==right的？
 *   分析一个样例3 6 7 11，H=8
 *   left=1,right=12;//左闭右开
 *   	mid=6,h=1+1+2+2=6 true
 *   left=1,right=6;
 *   	mid=3,h=1+2+3+4=10 false
 *   left=4,right=6;
 *   	mid=5,h=1+2+2+3=8 true
 *   left=4,right=5;
 *   	mid=4,h=1+2+2+3=8 true
 *   left=4,right=4; return。对的，退出时是相等的，所以返回哪个都一样！
 * */
int main(){
	vector<int> v{3,6,7,11};
	Solution s;
	cout<<s.minEatingSpeed(v, 8);
    return 0;
}
