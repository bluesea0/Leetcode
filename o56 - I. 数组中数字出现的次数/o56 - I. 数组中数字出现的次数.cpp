#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年3月23日下午5:53:10
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int all=nums[0];//这里初始化为0，会有影响吗？
        //不会，同0异1，如果原来是0异或0还是0，如果原来是1，异或0还是1
        for(int i=1;i<nums.size();i++)
            all^=nums[i];
        int b=1;//第一个不为0的位置
        while((all&b)==0)b<<=1;//这里一定要加括号，因为&操作优先级低！

        int n1=0,n2=0;//该怎么初始化呢？
        //直接初始化为0，是与操作，肯定不会有影响。
        for(int n:nums){
            if(n&b)
                n1^=n;
            else n2^=n;
        }
        cout<<n1<<n2;
        return {n1,n2};
    }
};
/*
 * 1.在涉及到位操作时，一定要考虑优先级的问题，尤其是在判断或者赋值中！位操作优先级低。
 * 2.将数据按照异或结果的位进行分组。
 * */

//6-16
/*
 * 1.今天复习这道题，就想不起来思路了，只知道异或，但是具体怎么搞呢？看了评论区才明白。
 *  比如样本4 1 4 6，总体异或之后得到010，我一开始在想根据什么分？如果根据当前位为1，那有可能是三个1
 *  的结果，所以就没想通。
 *  但是这个关注的是两个不同的数，可以根据结果位为1，表示这两个只出现一次的数在这个位上肯定不一样，
 *  所以就可以根据这其中一个不同的位将数字划分为两组，相同的数对应的位肯定相同，被划分在同一个组里，
 *  并且异或之后结果为0，所以不用care。
 * */
int main(){
	Solution s;
	vector<int> nums={1,2,5,2};
	s.singleNumbers(nums);
    return 0;
}
