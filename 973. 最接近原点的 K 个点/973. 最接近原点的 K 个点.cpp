#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月9日下午1:35:23
class Solution {
public:
	//时间O(nlogn)，空间O(logn)排序所需的额外空间。
    static bool comp(const vector<int>& a,const vector<int>& b){//这里要传引用，否则有值复制的过程
        return a[0]*a[0]+a[1]*a[1]<b[0]*b[0]+b[1]*b[1];//会导致超时!
    }//这里要使用static，形参中就没有this指针了。
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        //这是一道排序的题目，可以重写sort的排序规则
        sort(points.begin(),points.end(),comp);
        // vector<vector<int>> ans;//其实这么返回也没问题
        // for(int i=0;i<K;i++)
        //     ans.push_back(points[i]);
        // return ans;
        return {points.begin(),points.begin()+K};//原来可以这么返回
    }
};
/*
 * 1.AC了！但是遇到了一个坑！我提交了两次都是超时！comp中不传递引用就会超时！
 * 2.当然还有其他的解法，我记得遇到过类似的题目，快速排序的思想，这个我绝对遇到过的，
 * 3.优先队列，这个我还不太行。
 * 4.快排我写一下。
 * 5.哇啊哦，快排也AC了，虽然写的很辣鸡吧，但是就感觉快排也是有套路的呀！多写写！
 * */
class Solution {
public:
    // 时间：期望为 O(n)，最坏 O(n^2)，空间:期望为O(logn), O(n).都是在划分n-1次时达到的
    void quick(vector<vector<int>>& points,int left,int r){
        if(left>=r)return;//这里到底有没有=？
        int i=left,j=r;
        vector<int> k=points[i];
        while(i<j){//有等号吗？应该有，要不然就判断不了i和j所指向的了。
            while(i<j&&(pow(points[j][0],2)+pow(points[j][1],2)>pow(k[0],2)+pow(k[1],2))) j--;//关键点真的是从后往前走啊！
            while(i<j&&(pow(points[i][0],2)+pow(points[i][1],2)<=pow(k[0],2)+pow(k[1],2))) i++;
            //交换i/j
            //但是如果i==j了，这里的交换就可能产生越界。。。
            swap(points[i][0],points[j][0]);
            swap(points[i][1],points[j][1]);
        }
        //退出时应该是i==j
        // points[i][0]=k[0];
        // points[i][1]=k[1];
        swap(points[i][0],points[left][0]);//这里更改改变的不是引用？
        swap(points[i][1],points[left][1]);
        quick(points,left,i-1);
        quick(points,i+1,r);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        //利用快排的思想
        //其实我有点害怕，好像还没写成过快排。。。
        //单独写一个函数？因为是要递归的啊
        quick(points,0,points.size()-1);
        return {points.begin(),points.begin()+K};
    }
};//下次复习要写一下用优先队列的，也就是堆。
//这个与剑指offer40最小的k个数，46将数组翻译为最小的数，都很相似！
int main(){

    return 0;
}
