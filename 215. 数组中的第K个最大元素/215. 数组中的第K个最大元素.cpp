#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月7日下午4:00:54
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //思路：使用大顶堆保存元素，在弹出时去重
        priority_queue<int> pq;
        if(nums.size()==0)return 0;
        for(auto n:nums)
            pq.push(n);
        int ans=pq.top();
        //卧槽，我想错了！！！人家是第k大的数，那就要小顶堆也不对吧。
        //卧槽，我干脆死掉吧，我理解错题意了，人家是不让去重。。不是第k个不同的元素！绝了！
        while(k--){//我唯一不确定的就是pq的这些操作函数是否是对的。。。
            ans=pq.top();
            pq.pop();
        }
        return ans;
    }
};
/*
 * 1.我不讲武德。直接用优先级队列了。官方评论区中直接手撕堆代码，绝了，而且说这个是面试要求的！我要学
 * 2.看了grand的解法，我才发现，就算是不讲武德的写法，我也是属于辣鸡那一类的！
 *class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; ++i) {
            q.pop();
        }
        return q.top();
    }
};//摊手!
 * */

//12-9
class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //使用随机化快排来完成
        //随机化选择一个放到它该放的位置，之后判断这个位置==k？
        //<k的话left=p+1，>k的话right=p-1
        if(nums.size()==0)return 0;
        int left=0,right=nums.size()-1;
        k=nums.size()-k;
        while(left<right){
            int p=partition(nums,left,right);
            if(p==k)return nums[p];
            else if(p<k) left=p+1;
            else right=p-1;//接下去就只排一半就可以了
        }
        //那么这个外面返回什么呢？削微有点尴尬了。
        return nums[left];//相等的时候会退出
    }
    int partition(vector<int>&nums,int left,int right){
        int p=rand()%(right-left+1)+left;//[left,right]
        swap(nums[right],nums[p]);
        return quickSort(nums,left,right);
    }
    int quickSort(vector<int>&nums,int left,int right){
        int x=nums[right];
        int p=left-1;
        for(int i=left;i<right;i++){
            if(nums[i]<=x){
                p++;
                swap(nums[p],nums[i]);
            }
        }
        swap(nums[p+1],nums[right]);
        return p+1;
    }
};
/* 1.随机化快排我AC了，太开心了！！它的时间代价的期望是 O(n)，
 *   递归使用栈空间的空间代价的期望为O(logn)
 * 2.接下来要尝试使用堆排序来做。
 * */

//12-14
//感觉手写堆排序就是想让我死。
/*
 * 1.那么我来手动运行一下吧。例子：[3,2,1,5,6,4]
 *  i=2: max(2,5):larget=5,nums[2]=4,i=5,nums[5]=1;=>[3 2 4 5 6 1]
 *  i=1: max(1,5):larget=3,larget=4,A[i]=A[1]=6,i=4,A[4]=2,
 *  经过我上面的手写，我发现，确实啊，不太行啊。这种堆还是就可视化比较方便的！
 * */
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //先建堆
        //从倒数的第一个非叶节点开始
        int m=nums.size()-1;
        for(int i=nums.size()/2-1;i>=0;i--){
            maxHeap(i,m,nums);//这个下标还挺难搞的啊
        }
        for(auto n:nums)
        	cout<<n<<" ";
        cout<<endl;
        for(int i=1;i<k;i++){
            //将首个0和最后一个互换
            swap(nums[0],nums[m-i+1]);
            maxHeap(0,m-i,nums);
            for(auto n:nums)
            	cout<<n<<" ";
            cout<<endl;
        }
        return nums[0];
    }

    void maxHeap(int i,int end,vector<int>& nums){//这个的目的是调整第i个元素到合适的位置
        int t=nums[i];//index指向的是最终要放置的位置
        for(int largest=2*i+1;largest<=end;largest=2*largest+1){//largest继续去调整交换的那个子树
            if(largest!=end&&nums[largest]<nums[largest+1])largest++;
            if(nums[largest]>t){//调整第i个元素到合适的位置，所以这里都和t比较。
                nums[i]=nums[largest];
                i=largest;
            }else break;
        }
        nums[i]=t;
    }
};
int main(){
	Solution2 s;
	vector<int> v={2,1};
	s.findKthLargest(v, 2);
    return 0;
}
