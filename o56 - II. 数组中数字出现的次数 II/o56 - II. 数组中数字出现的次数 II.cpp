#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<cmath>
using namespace std;
//2021年3月23日下午12:47:18
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //数组顺序和那个什么是不同的，从低到高和从高到低
        vector<int> bits(32,0);
        for(auto n:nums){
            for(int i=0;n!=0;i++){
                if(n&1)bits[i]++;
                n=n>>1;
            }
        }
        int ans=0;
        for(int i=0;i<bits.size();i++)
            if(bits[i]%3)ans+=pow(2,i);
        return ans;
    }
};
/*
 * 1.看了评论区的解法才明白了，如果一个数字出现3次，它的二进制每一位也出现的3次。
 *   如果把所有的出现三次的数字的二进制表示的每一位都分别加起来，那么每一位都能被3整除。
 *   我们把数组中所有的数字的二进制表示的每一位都加起来。
 *   如果某一位能被3整除，那么这一位对只出现一次的那个数的这一肯定为0。
 *   如果某一位不能被3整除，那么只出现一次的那个数字的该位置一定为1.
 * */

//6-16
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> count(32,0);
        for(int i=0;i<nums.size();i++){
            int t=nums[i],j=0;
            while(t){
                if(t&1)count[j]+=1;
                t>>=1;
                j++;//这里无论如何j都要++的
            }
        }//统计完所有的数字
        int b=1,ans=0;
        for(int i=0;i<count.size();i++){
            if(count[i]%3)
                ans+=b;
            //i=31时，也就是下一次要退出循环了，但是b还是会左移一位，总共就移动了32次，
            //所以会产生溢出
            if(i!=31)
                b<<=1;//runtime error: left shift of negative value -2147483648 (solution.cpp)
        }
        return ans;
    }
};
/*
 * 1.思路有的，但是写的时候并没有那么顺利。
 * 2.下面是通过位的或运算 | ，来写的，需要从高位开始遍历。
 * */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> count(32,0);
        for(int i=0;i<nums.size();i++){
            int t=nums[i],j=0;
            while(t){
                if(t&1)count[j]+=1;
                t>>=1;
                j++;//这里无论如何j都要++的
            }
        }//统计完所有的数字
        int ans=0;
        // for(int i=0;i<count.size();i++){
        //     if(count[i]%3)
        //         ans=(ans|1);
        //     ans<<=1;
        // }
        //如果要使用或运算来的话，需要从高位开始遍历
        for(int i=31;i>=0;i--){
            ans<<=1;//先移位，不然就会多移一次
            if(count[i]%3)
                ans=(ans|1);
        }
        return ans;
    }
};
int main(){
	Solution s;
	vector<int> nums={3,4,3,3};
	cout<<s.singleNumber(nums);
    return 0;
}
