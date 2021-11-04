#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月31日下午2:58:40
//class Solution {
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        //如果只记录窗口的最大值，那么关键的问题是，如果最大值的窗口地方过了，怎么去判断
//        //次大值呢？我刚刚想到用堆，但是不行，因为弹出时并不那个啥啊。也只能弹出一个值
//        //并不能选择弹出哪个啊
//        //忽然想到了单调栈
//        //也不能用单调栈，要移走的left有可能压在栈底弹不出来，绝了绝了，还挺难的啊这题
//        //是不是只需要记录次大值就行了？好乱啊，因为left要移走，
//        //我稍微写一下吧
//        int cm=nums[0],cm2=nums[0],left=0,right=0;
//        while(right<nums.size()){
//            int r=nums[right++];
//            if(r>cm)cm=r;
//            else if(r==cm)cm2=r;//记录次大值
//            else if(r>cm2)cm2=r;
//            if(right-left>=k){
//                //开始缩小左窗口
//                int l=nums[left++];
//                if(l==cm)cm=cm2;
//                //cm2怎么更新呢？真可怜
//                //我不会了，因为left指向1，但是它又被移走了。。。这可怎么办啊。用一个数组来随时
//                //sort吗？我不会了。
//            }
//        }
//    }
//};
/*
 * 1.确实不知道怎么做，感觉这个题目其实考的不是滑动窗口的知识点啊，为什么会出现在滑窗的总结里？奇奇怪怪
 *   不过这个做过的人还蛮多的，我觉得我有必要掌握它！
 * 2.看了官方给的题解，真的好绝啊，双向队列和dp解法，用left和right记录最值，尤其是这个left和right的计算，绝
 * */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //思路：用left和right分别记录窗口的最大值
    	cout<<"here";//这个也打印不出来？？绝了。
        int m=nums.size();
        if(m<=1) return nums;
        vector<int> left(m,0),right(m,0);


        //left[0]=nums[0],right[m-1]=nums[m-1];
        for(int i=0;i<m;i++){
            if(i%k==0)left[i]=nums[i];
            else left[i]=max(left[i-1],nums[i]);
        }
        for(int i=m-1;i>=0;i--){//我是傻逼吗？我这里还i++。。。真是傻逼了。
            if((i+1)%k==0||i==m-1)right[i]=nums[i];
            else right[i]=max(right[i+1],nums[i]);//但是这里会越界可怎么整啊
        }
//        for(int i=0;i<ans.size();i++){
//            ans[i]=max(left[i+k-1],right[i]);
//        }
        vector<int> ans(m-k+1,0);
        for(int i=0;i<ans.size();i++){
        	ans[i]=max(left[i+k-1],right[i]);
        }
        return ans;
    }
};
/*
 * 1.上面AC了，绝了，一直自动退出不知道怎么回事，倒序遍历还要i++那可不就越界了吗？
 * 2.官解中第一种解法也是不错，不是说移动了窗口就要把左边的数据移出去，而是再遇到它最大的时候移出去，
 *   并且优先队列中存的是pair，包括下标的。
 * 3.下次复习学习第二种解法。
 * */

//3-21
/*
 * 1.今天做这道题我才意识到以上的方法只是很巧的方法，并不是面试官想听到的常规的解法。我之前确实是有点投机取巧
 *   了，这次应该是用大顶堆来解决。
 * */
class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //优先队列怎么初始化来着？
        priority_queue<pair<int,int>> pq;//默认是vector<pair<int,int>>吧
        vector<int> ans;
        for(int i=0;i<k;i++)
            pq.push(make_pair(nums[i],i));//这样的话会默认按照第一个元素从大到小排序
        ans.push_back(pq.top().first);
        for(int i=k;i<nums.size();i++){
            //这里要注意pq不能为空，否则会陷入死循环
            while(!pq.empty()&&pq.top().second<=i-k)pq.pop();
            pq.push(make_pair(nums[i],i));
            ans.push_back(pq.top().first);
        }
        //cout<<ans.size();
        return ans;
    }
};
/*
 * 1.AC了，这才是常规做法好吗。时间：O(nlogn)最坏情况当数组为单调递增，那么for循环需要循环n次放入，每放入一个
 *   元素的复杂度为logn，空间：O(n)最坏情况下是优先队列存储所有元素。
 * 2.明天继续写一下单调队列的解法。
 * */

//6-16
/*
 * 1.天哪不是单调栈，是单调队列！从头出的，绝了绝了，那我一下子就懂了
 * 2.单调队列要用双向的deque。
 * */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //使用非严格递减的单调队列
        //queue<pair<int,int>> q;
        deque<pair<int,int>> q;
        for(int i=0;i<k;i++){
            //如果遇到了大于等于的，那么可以弹，因为当前就是之前的替代品了。
            while(!q.empty()&&q.back().first<nums[i]){
                q.pop_back();//注意这里是和back比较啊，同时也是从back插入
            }
            q.push_back(make_pair(nums[i],i));
        }
        vector<int> ans;
        ans.push_back(q.front().first);
        for(int i=k;i<nums.size();i++){
            //弹出不在当前窗口的值
            while(!q.empty()&&q.front().second<=i-k)q.pop_front();
            //while(!q.empty()&&nums[i]>q.front().first)q.pop();
            //从后面弹出小于当前元素的值
            while(!q.empty()&&nums[i]>q.back().first)q.pop_back();
            q.push_back(make_pair(nums[i],i));
            ans.push_back(q.front().first);
        }
        return ans;
    }
};
/*
针对样例[1,3,1,2,0,5] 3
正确结果[3,3,2,5]
如果使用单向弹出的队列，也就是只弹头，并不能保证是单调的！所以需要用deque！
*/
int main(){
//	Solution2 s;
//	vector<int> nums={1,-1};
//	s.maxSlidingWindow(nums, 1);
	string s="  ab ";
	int index=-1;
	while(s.find(" ",index+1)!=string::npos){
		index=s.find(" ",index+1);
		cout<<index<<"\n";
	}
    return 0;
}
