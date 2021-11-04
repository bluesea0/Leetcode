#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月3日下午7:54:13
//class Solution {
//public:
//    bool validMountainArray(vector<int>& A) {
//        //忽然有点懵，那么就遍历吧，我一直在纠结怎么写这道题最简单？
//        //如何判断存在上升？如何判断存在下降，并且在下降之后就不能有上升？
//        // bool up=true,down=true;
//        bool up=true;
//        for(int i=0;i<A.size()-1;i++){//其实不能全遍历完的，如果到不符合的地方就要return的
//            if(A[i]==A[i+1])return false;//一开始就是降
//            if(up&&A[i]>A[i+1]) up=false;//好麻烦啊，我的思路不清晰啊。
//            else if(!up&&A[i]<A[i+1]) return false;//草，本来是想精简地写，反正我不会了。
//        }//看到题解说用双指针？但是次奥。不会。。。呜呜呜。
//        return true;
//    }
//};
/*
 * 1.怎么说呢，感觉自己就是个菜鸡，大哭。
 * 2.先升后降，找到i点，i==0||i==N-1就形不成山峰，然后从i再往后找。
 * 2.思路2是分别从左往右和从右往左遍历，
 * */
//11-4
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        //从前往后遍历升序
        if(A.size()==0) return false;
        int i=0;
        while(i<A.size()-1)//如果A是空向量的话，那么就不能调用size()函数，会报错，所以之前要加判断
            if(A[i]<A[i+1])i++;
            else break;
        if(i==0||i==A.size()-1) return false;
        //从i往后遍历降序
        while(i<A.size()-1)
            if(A[i]>A[i+1])i++;
            else break;
        return i==A.size()-1;//判断是否到了末尾。
    }
};
//AC了，
int main(){

    return 0;
}
