#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年3月22日下午11:22:21
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        //滑动窗口
        int cur=0,left=1,right=1,n=target/2+1;//官解也写的是这个边界，太开心了！
        vector<vector<int>> ans;
        while(right<=n){//这个右边界应该是可以再缩小的吧？
            cur+=right;

            while(cur>=target){
                if(cur==target&&right-left>=1){
                    vector<int> temp;
                    for(int i=left;i<=right;i++)
                        temp.push_back(i);
                    ans.push_back(temp);
                }
                cur-=left;
                left++;
            }
            right++;
        }
        return ans;
    }
};
/*
 * 1.AC了，百分百，开心死了。时间：O(target)，空间：O(1)。
 * */
int main(){
	Solution s;
	cout<<s.findContinuousSequence(12);
    return 0;
}
