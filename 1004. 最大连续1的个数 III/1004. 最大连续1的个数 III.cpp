#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月5日下午4:12:05
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        //转换为窗口中最多只能有k个0
        int left=0,right=0,ct=0,max1=0,ans=0;
        while(right<A.size()){//草，我都懵了，到底该怎么更新？有没有一个确定点的模板啊？
            if(A[right])ct++;//我乱了，这就是没掌握好模板的代价吗？
            max1=max(ct,max1);
            if(right-left+1-max1>K){
                if(A[left])ct--;
                left++;
            }
            ans=max(ans,right-left+1);//这次我也学聪明了，就把答案更新放在外面。
            right++;
        }
        return ans;
    }
};
/*
 * 1.和424题非常像，都是在检查left之后，也就是每次更新right时更新ans，如果想在更新left时更新那么，
 *   就会有很多问题导致答案不不正确。
 * 2.https://www.cnblogs.com/grandyang/p/6376115.html，这个写的很牛逼，我上面写的其实也对
 *   class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, zero = 0, left = 0, k = 1;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) ++zero;//直接记录0的个数
            while (zero > k) {
                if (nums[left++] == 0) --zero;//缩小窗口的时候判断是否是0
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
因为这道题其实和字符还是不一样，这里只有0、1两个。
 * */
int main(){

    return 0;
}
