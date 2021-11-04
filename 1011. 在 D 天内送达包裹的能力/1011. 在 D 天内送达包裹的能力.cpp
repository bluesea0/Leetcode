#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月4日下午7:55:45
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        //这怎么用二分啊？left和right的初始化都不知道怎么做
        //也不能用sum来初始化吧，因为那样对第一个样例才得到11，是不对的啊，啊想看题解，
        //完全想不出来，怎么个二分法？
        //看了题解，就这？关键是这个left和right的确定啊。。。。
        int max=weights[0],sum=0;
        for(auto w:weights){
            if(w>max)max=w;
            sum+=w;
        }
        int left=max,right=sum+1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(helper(weights,mid,D))
                right=mid;//尝试减小运载能力
            else left=mid+1;
        }
        return left;
    }
    bool helper(vector<int>& weights, int mid,int D){

    }
    // bool helper(vector<int>& weights, int mid,int D){//这个辅助判断函数还有点难度啊
    //     int d=0;//啊这个怎么判断啊，好难的啊。
    //     for(auto w:weights){
    //         d+=w;
    //         if(d>D){
    //             D--;
    //             d=w;
    //         }else if(d==D){D--;d=0;}
    //         if(D<0) return false;
    //     }
    //     return true;
    // }
};
//看了https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/2.5-shou-ba-shou-shua-shu-zu-ti-mu/koko-tou-xiang-jiao
/*
 * 1.看了教程之后才明白怎么用二分，挺难的。
 * 2.判断是否能够运完这个函数也难，我没写出来。。。。哭泣。
 * */
int main(){

    return 0;
}
