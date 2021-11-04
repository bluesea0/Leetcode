#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月5日下午11:42:27
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //枚举高，找出其左右的最近的小于它的高度
        int ans=0;
        for(int i=0;i<heights.size();i++){
            int left=i,right=i;
            while(left>0&&heights[left-1]>=heights[i])left--;
            while(right+1<heights.size()&&heights[right+1]>=heights[i])right++;
            ans=max(ans,heights[i]*(right-left+1));
        }
        return ans;
    }
};
/*
 * 1.这个枚举高的解法超时了，87/96，O(n^2)的解法通不过。
 * 2.主要的思想就是找到它的左右边界！找到左右小于它的高度，就能确定宽度了！因为高度定了，就是它本身！
 * 3.
 * */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0,m=heights.size();
        vector<int> left(m,0),right(m,0);
        vector<int> stack;
        for(int i=0;i<m;i++){//忽然想到了一个关键的问题？如果是=呢？
        //=肯定不是
            while(!stack.empty()&&heights[stack.back()]>=heights[i])stack.pop_back();
            if(stack.empty()) left[i]=-1;
            else left[i]=stack.back();
            stack.push_back(i);
        }
        //怎么重新把stack置为空，还是说新定义一个？
        stack.resize(0);
        for(int i=m-1;i>=0;i--){
            while(!stack.empty()&&heights[stack.back()]>=heights[i])stack.pop_back();
            if(stack.empty())right[i]=m;//表示一直到末尾都没有找到比它小的
            else right[i]=stack.back();
            stack.push_back(i);
        }
        for(int i=0;i<m;i++){
            ans=max(ans,(right[i]-left[i]-1)*heights[i]);
        }
        return ans;
    }
};
int main(){

    return 0;
}
