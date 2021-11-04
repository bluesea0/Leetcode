#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月30日下午3:48:44
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //天哪，有些难
        //如果按照start从小到大排序，那么如果当前区间和之前的交集了，但是有可能后一个和当前的也有交集，那什么时候才能把这些有交集的区间加入呢？
        //是不是要同时记录start和end的位置？
        if(intervals.size()==0)return {};//空的话应该是可以这么返回的吧
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0],end=intervals[0][1];
        vector<vector<int>> ans;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=end){
                //end=intervals[i][1];
                end=max(end,intervals[i][1]);//[[1,4],[2,3]]，有可能全包啊
            }else{
                //说明没有交集，那就把之前形成的区间加入
                ans.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};
/*
 * 1.因为435题，我复习了好几次，都忘记了思路，所以今天复习完了之后就赶紧来做做区间题目，加深印象。
 *   时间复杂度O(nlogn)，空间是O(logn) 即为排序所需要的空间复杂度。
 * 2.        vector<vector<int>> res{intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back()[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        grand的这个写法绝了啊。先把第0个放进去，然后就以那个判断，就不会像我还要再多写一句push_back()
 * */
int main(){

    return 0;
}
