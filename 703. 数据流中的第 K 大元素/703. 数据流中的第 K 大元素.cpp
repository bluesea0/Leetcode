#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月11日上午1:40:53
class KthLargest {
public:
    priority_queue<int> big;//默认是大顶堆
    priority_queue<int,vector<int>,greater<int>> small;//小顶堆
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        if(nums.empty()) return ;

        for(auto n:nums)
            big.push(n);
        for(int i=0;i<k&&!big.empty();i++){//这里出现了问题，针对下面的样例，nums可能为空。
            small.push(big.top());
            big.pop();//[[2,[0]],[-1],[1],[-2],[-4],[3]]
            //还有这样的样例，太令人害怕了吧。
        }
    }
   //["KthLargest","add","add","add","add","add"]
//[[1,[]],[-3],[-2],[-4],[0],[4]]
//针对这样的样例，一开始是没有的啊
    int add(int val) {
        if(small.empty()||small.size()<K){
            small.push(val);
        }else{
            if(val<=small.top()){//针对上上个样本，这里还要控制size
                big.push(val);
            }else{
                big.push(small.top());
                small.pop();
                small.push(val);
            }
        }
        return small.top();
    }
};
/*
 * 1.上面的终于AC了，我提交了好几次好几次啊！我哭了我的妈，轻敌了，以为是个easy没想到很多坑啊！
 *   我都没有考虑到！回家等消息吧。而且样例出来之后，以为自己改好了就提交了，实际上还是存在问题！
 * 2.时间复杂度，构造函数：O(nlogn)，add函数：O(logn)
 * 3.卧槽，我被暴击了，我看了官方题解，原来只需要一个优先队列就可以了啊，我哭死了，怎么回事！
 *   如果size>k，那么就pop，学到了。
 * */

//2-13
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int K=0;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int i=0;i<nums.size();i++){
            if(i<k)pq.push(nums[i]);
            else if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }

    int add(int val) {
        if(pq.size()<K)pq.push(val);
        else{
            if(val>pq.top()){
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};
/*
 * 1.AC了，精神水平有所提高。
 * 2.关键是小顶堆，保存前k个大的值。
 * */
int main(){
	vector<int> nums={0};
	KthLargest kl(2,nums);
	vector<int> a={-1,1,-2,-4,3};
	for(auto n:a)
		cout<<kl.add(n)<<endl;
    return 0;
}
