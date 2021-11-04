#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月30日下午4:16:16
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        //这个题感觉没有什么算法思想啊
        if(nums.empty()) return {};
        if(nums.size()==1) return {to_string(nums[0])};//这样返回应该是可以的吧
        int start=0,end=0;//记录开始和结束的下标
        vector<string> ans;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[end]+1)
                end=i;
            else{
                if(start==end)
                    ans.push_back(to_string(nums[start]));
                else
                    ans.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
                start=end=i;
            }
        }
        if(start==end)//天哪for循环结束后还要再来这么一下，挺想吐的。
            ans.push_back(to_string(nums[start]));
        else
            ans.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
        return ans;
    }
};
/*
 * 1.天哪，居然打败了100%，绝了。复杂度：O(n) 不考虑输出的话，空间是O(1)。
 * 2.因为我每次都是和它之前的去比较，就不好，退出循环还得再来一下。
 * public class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> summary = new ArrayList<>();
        for (int i = 0, j = 0; j < nums.length; ++j) {
            // check if j + 1 extends the range [nums[i], nums[j]]
            if (j + 1 < nums.length && nums[j + 1] == nums[j] + 1)//如果到了最后的元素的话，就会直接
                continue;//运行下面的
            // put the range [nums[i], nums[j]] into the list
            if (i == j)
                summary.add(nums[i] + "");
            else
                summary.add(nums[i] + "->" + nums[j]);
            i = j + 1;//i控制start
        }
        return summary;
    }
}
3.官方的解答就写的好好啊。这个方面我还需要再多学习啊。
 * */

//1-10
class Solution2 {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for(int i=0;i<nums.size();i++){
            int j=i;
            while(i+1<nums.size()&&nums[i]+1==nums[i+1])i++;
            if(i==j)ans.emplace_back(to_string(nums[i]));
            else ans.emplace_back(to_string(nums[j])+"->"+to_string(nums[i]));
        }
        return ans;
    }
};
/*
 * 1.我也get了官方简洁的写法~~~
 * */
int main(){

    return 0;
}
