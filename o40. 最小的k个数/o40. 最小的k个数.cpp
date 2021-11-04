#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月11日下午4:28:17
class Solution {
public:
	//复杂度O(nlogk)，O(k)
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        //写一下堆吧，反正代码套路都是一样的。
        vector<int> ans;
        if(k==0)return ans;//没注意看k的范围啊大哥。。。
        priority_queue<int,vector<int>> pq;
        for(int i=0;i<k;i++)
            pq.push(arr[i]);
        for(int i=k;i<arr.size();i++){
            int t=pq.top();//不是front类型
            if(arr[i]<t){
                pq.pop();pq.push(arr[i]);
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
/*
 * 1.之前有用python写的AC了，就没有做这个总结，其实它可以通过堆或快排来实现的？可以用这个来练手嘛
 * 2.使用快排的话，时间期望是O(n)，最坏要分n-1次是O(n2)，空间期望是O(logn)。、
 * 3.下次复习写一下快排吧，应该没有什么难度。
 * */

//5-23
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        //首先用大顶堆来保存
        if(k==0||arr.empty()) return {};//[0,0,0,2,0,5] 0，记得判空
        priority_queue<int,vector<int>> pq;//指明容器类型
        int m=k;
        while(k--){//其实这里乖乖地用for循环就行，不必这么抓马
            pq.push(arr[k]);
        }
        for(int i=m;i<arr.size();i++){
            if(arr[i]<pq.top()){//前面要判断k==0，如果不判断这里pq就为空的,pq.top()不存在会出错。
                pq.pop();
                pq.push(arr[i]);
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
//下面是随机快排解法。
//快排是递归的。
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        //随机快排
        if(k==0||arr.empty())return {};
        rquickSort(arr,k,0,(int)arr.size()-1);
        vector<int> ans;
        for(int i=0;i<k;i++)
            ans.push_back(arr[i]);
        return ans;
    }
    void rquickSort(vector<int>& arr,int k,int left,int right){
        if(left>=right)return;
        int pivot=rand()%(right-left+1)+left;
        //交换pivot和right//这里应该和right交换，因为之后的快排都是以right为基准比较的
        swap(arr[pivot],arr[right]);
        int p=quickSort(arr,left,right);//找到pivot的最终位置
        if(p+1>k)rquickSort(arr,k,left,p-1);
        else if(p+1<k) rquickSort(arr,k,p+1,right);
    }
    int quickSort(vector<int>& arr,int left,int right){
        int p=left-1;
        for(int i=left;i<right;i++){
            if(arr[i]<=arr[right]){
                p++;
                swap(arr[p],arr[i]);//p及其左边保存小于arr[right]的元素
            }
        }
        swap(arr[p+1],arr[right]);
        return p+1;
    }
};
//快排也AC了，不容易，但是我写的这个过程，有问题。没有让各个函数各司其职，对每个函数的功能还有待确认。
/*
 * 1.这个题目和lc215题为镜像题目。
 * 2.应该在主函数中调用rquickSort，它负责返回一个p值即随机化快排之后的下标，和k比较，判断是去往下比较左边
 *   还是右边。rquickSort中产生一个随机数和arr[right]交换，然后调用partion函数，partion函数返回一个下标，即
 *   随机选择的元素最终存放的下标。这是在top-k问题解法中。
 * 3.在快排中，QuickSort调用partition函数，partition函数永远是相同的，返回一个排序好的结果，然后在QuickSort
 *   递归调用排序左右。那么在随机快排中，RandomQuickSort调用randomPartition，randomPartition产生随机数，实际
 *   上还是调用partion函数去划分。所以关键点还是partion这个函数。
 * 4.那么在top-k问题中，main直接调用randomPartition来划分就可以了，然后根据它的返回值来判断是左调用还是右
 *   调用。
 * */
int main(){

    return 0;
}
