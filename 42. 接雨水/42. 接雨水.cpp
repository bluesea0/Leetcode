#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
////2021年2月13日下午9:52:14
//class Solution {
//public:
//    int trap(vector<int>& height) {
//        //没什么思路，单调栈？但是如何单调呢？单调递减栈，但是可能会存在重复计算的问题。
//        //如果按照加入弹出，就可能会存在这个问题的。
//    }
//};
//class Solution {
//public:
//    int trap(vector<int>& height) {
//        //单调栈，对每个元素在它右边找到>=它的柱子，然后顺序计算。
//        //单调递减栈
//        //但是还是会遇到重复计算的问题啊，怎么才能不重复计算呢？
//        //看到标签里还有动态规划，想了想，我也不会这道，绝望子。
//        vector<int> stack;
//        for(int i=0;i<height.size();i++){
//            if(height[i]==0)continue;
//            if(stack.empty()||height[stack.back()]>)
//        }
//    }
//};
class Solution {
public:
    int trap(vector<int>& height) {
        //先写一版最简单的
        //题眼是：对每一根柱子找到它左右最大值的较小值，对于每个柱子都计算出可以盛水的大小
        //两次遍历：一次找到左边的最大值；一次找到右边的最大值
        int n=height.size(),max_left=0,max_right=0;
        vector<int> left(n,0);
        for(int i=0;i<n;i++){
            left[i]=max_left;
            max_left=max(height[i],max_left);
        }
        vector<int> right(n,0);
        for(int i=n-1;i>=0;i--){
            right[i]=max_right;
            max_right=max(max_right,height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int x=min(right[i],left[i]);//这里是取最小值
            if(x>height[i])ans+=(x-height[i]);
        }
        return ans;
    }
};
/*
[0,1,0,2,1,0,1,3,2,1,2,1]

[0,0,1,1,2,2,2,2,3,3,3,3] left
[3,3,3,3,3,3,3,2,2,2,1,0] right
[0,0,1,0,1,2,1,0,0,1,0,0] res
1.这个解法官方答案写的比我好，它是直接计算i左边（包括i）的最大值，i右边（包括i）的最大值，这样在计算结果
  的时候就更加简单了。
2.单调栈的解法和这个不同，是计算横着的长条，而这个方法是针对每个柱子竖条来计算的。
*/
class Solution2 {
public:
    int trap(vector<int>& height) {
        vector<int> stack;
        //虽然说这里用单调栈，但如果是等于呢？该怎么处理？
        int ans=0;
        for(int i=0;i<height.size();i++){
            while(!stack.empty()&&height[stack.back()]<height[i]){
                int top=stack.back();
                stack.pop_back();
                if(!stack.empty()){//需要计算长和宽，获取其乘积作为结果
                    int h=min(height[stack.back()],height[i])-height[top];
                    //相等的，进来但是h会为0
                    ans+=h*(i-stack.back()-1);
                }
            }
            stack.push_back(i);
        }
        return ans;
    }
};//还有双指针的解法下次复习写。
/*
 * 1.官方题解和我写的差不多，也是将相等的值放进去，要注意如果栈为空时的判断
 * */

//2-15
class Solution3 {
public:
    int trap(vector<int>& height) {
        //双指针，分别从左向右，从右向左遍历
        int left=0,right=height.size()-1,max_left=-1,max_right=-1;//这两个max怎么初始化？
        int ans=0;
        while(left<right){
            if(height[left]<height[right]){//反正做这种题都会被相等的情况所困惑！
                if(height[left]>max_left)max_left=height[left];
                else{
                    ans+=(max_left-height[left]);//如果相等那就是0，无所谓了
                }
                left++;
            }else{//左右最长的较短值相等的话，那就左右都可以了
                if(height[right]>max_right)max_right=height[right];//如果一直增长的话那盛不了水
                else ans+=(max_right-height[right]);
                right--;
            }
            cout<<ans;
        }
        cout<<endl;
        return ans;
    }
};//双指针的也AC了，太棒了吧！

//3-6复习
/*
 * 1.能够顺利想到第一种方法，两次遍历，题眼为需要对每个柱子找到左边最大值，右边最大值，通过两者min值计算
 * 2.单调栈的方法有点迷糊，非严格递减栈，入栈之后的上一个元素就是它的左边界，出栈的条件是当前元素比它小，将
 *   栈顶元素弹出时计算，左边界为上一个元素，右边界为更小的元素
 * 3.双指针的解法没有想到，它是从第一个方法优化而来，其实是首尾指针，如果left<right，那么结果必定由left决定，
 *   反之由right，挺厉害的。
 * */

//9-19
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())return 0;
        stack<int> stk;
        int ans=0;
        for(int i=0;i<height.size();i++){
//            if(stk.empty()||height[i]<=height[stk.top()]){
//                stk.push(i);continue;
//            }//其实这个地方不必有，如果不弹栈的话，那么直接最后push进去就行。
            while(!stk.empty()&&height[stk.top()]<height[i]){
                int k=stk.top();
                stk.pop();
                if(stk.empty())break;
                int h=min(height[stk.top()],height[i])-height[k];
                ans+=(h*(i-stk.top()-1));
            }
            stk.push(i);
        }
        return ans;
    }
};
int main(){
	vector<int> a={0,1,2,1};
	Solution2 s2;
	Solution3 s3;
	cout<<s2.trap(a)<<endl;
	cout<<s3.trap(a);
    return 0;
}
