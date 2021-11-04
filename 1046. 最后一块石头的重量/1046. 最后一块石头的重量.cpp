#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月30日上午10:07:04
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //这道题居然做过，是在两年前，完全不记得，我记得
        //计算差值数组，并且对差值数组遍历，选择其中非0且不重复的部分
        //不对，我上面的思路不对，它们碰撞的先后顺序是非常有影响的
        //我真是个傻逼，你没看到人家说选择最终的石头吗？？？那就优先队列就好了啊
        if(stones.size()==1)return stones[0];
        priority_queue<int> pq(stones.cbegin(),stones.cend());
        while(pq.size()>1){
            int top1=pq.top();pq.pop();
			int top2=pq.top();pq.pop();
			if(top1==top2)continue;
			else pq.push(top1-top2);
        }
        return pq.empty()?0:pq.top();
    }
};
//AC了，如果要用手写堆，那还真是为难我啊，不过我还挺想试一试的！
int main(){
	Solution s;
	vector<int> stones={2,7,4,1,8,1};
	cout<<s.lastStoneWeight(stones);
    return 0;
}
