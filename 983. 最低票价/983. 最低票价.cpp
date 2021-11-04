#include <iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<string.h>
using namespace std;
//10-22
/*
1.当然是不会了，看这种题都感觉掉头发，这种题出来的目的就是为了让人掉头发吧？促进植发产业的发展。
2.之前看过一次，当时看和现在看的感觉是一样的，凉凉的感觉。
*/
//class Solution {
//public:
//    int mincostTickets(vector<int>& days, vector<int>& costs) {
//        //太难了，如果在面试的时候遇到，我就直接跪吧，说我不会，你就是想让我掉头发！
//        //出这种题就是跟我有仇！摆明了说！！！气！好难！
//        //出这种题就是想让我死！
//        return 0;
//    }
//};
//下面是力扣官方的第一个解法，我还是不太明白
//class Solution1 {
//    unordered_set<int> dayset;
//    vector<int> costs;
//    int memo[366] = {0};
//
//public:
//    int mincostTickets(vector<int>& days, vector<int>& costs) {
//        this->costs = costs;
//        for (int d: days) {
//            dayset.insert(d);
//        }
//        memset(memo, -1, sizeof(memo));
//        return dp(1);
//    }
//
//    int dp(int i) {
//        if (i > 365) {
//            return 0;
//        }
//        if (memo[i] != -1) {
//            return memo[i];
//        }
//        if (dayset.count(i)) {
//            memo[i] = min(min(dp(i + 1) + costs[0], dp(i + 7) + costs[1]), dp(i + 30) + costs[2]);
//        } else {
//            memo[i] = dp(i + 1);
//        }
//        return memo[i];
//    }
//};
/*
1.按照上面的过程来分析一个例子吧，要不然真的还是觉得悬在空中，对这道题可能理解不那么深刻。
  [1,2,3,4,5,6,7,8,9,10,30,31]，[2,7,15]
  memo[31]=min(2,7,15)=2
  memo[30]=min(2+2,0+7,0+15)=4
  memo[11~29]=memo[30]=4
  memo[10]=min(dp(11)+2,dp(17)+7,dp(40)+15)=min(4+2,4+7,0+15)=6
  memo[9]=min(dp(10)+2,dp(16)+7,dp(39)+15)=min(6+2,4+7,0+15)=8//9、10、30、31都是单独买一天
  memo[8]=min(dp(9)+2,dp(15)+7,dp(38)+15)=min(8+2,4+7,0+15)=10
  memo[7]=min(dp(8)+2,dp(14)+7,dp(37)+15)=min(10+2,4+7,0+15)=11//表示要买一张7天的，比每天都买一张1天/2元的更便宜！
  memo[6]=min(dp(7)+2,dp(13)+7,dp(36)+15)=min(11+2,4+7,0+15)=11//在第6天买7天的票
  memo[5]=min(dp(6)+2,dp(12)+7,dp(35)+15)=min(11+2,4+7,0+15)=11//在第5天买7天的票
  memo[4]=11//在第4天买7天的票
  memo[3]=min(dp(4)+2,dp(10)+7,dp(33)+15)=min(11+2,6+7,0+15)=13//可以第三天单独买，然后4-10买个7天的票，也可以3-9
  //买个7天的票，第10天买个单独的一天票，注意7天票是3-9，而不是3-10。
  memo[2]=min(dp(3)+2,dp(9)+7,dp(32)+15)=min(13+2,8+7,0+15)=15//现在就有三种买票的策略了。
  memo[1]=min(dp(2)+2,dp(8)+7,dp(31)+15)=min(15+2,10+7,2+15)=17//其实也是有三种买票策略。
  分析完感觉这个真是一个极好的样例啊！！！
2.dp[i]表示的是从第i天到第365天（一年的结束）最小花费的数目，从后往前进行dp。真的绝绝子！
*/
/*
3.因为上面的中，每次都会调用dp[i]=dp[i+1]=dp[i+2]这样子，就很麻烦，所以就定义了新的dp数组
  令dp(i) 表示能够完成从第days[i] 天到最后的旅行计划的最小花费，真的是聪明绝顶啊！
  再感叹，我是废物five
*/

//10-24
/*
1.我来写一下？我感觉我还是写不出来。。。
*/
class Solution {
	//我真的是不太懂了。
	//这样初始化的方式是绝对没有问题的。按我真的不懂了，这个暂且按下不表吧。
//    vector<int> dp2(366,-1);//error: expected identifier before numeric constant为什么这里就会报错呢
	int dp2[366]={-1};
    unordered_set<int> day;
    vector<int> cost;
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(auto d:days)
            day.insert(d);
        this->cost=costs;//这里要用this指针
        memset(dp2,-1,sizeof(dp2));
        return mincost(1);
    }

    int mincost(int i){
        if(i>365)return 0;
        if(dp2[i]!=-1)return dp2[i];
        if(day.count(i)){
            dp2[i]=min(mincost(i+1)+cost[0],min(mincost(i+7)+cost[1],mincost(i+30)+cost[2]));
        }else{
            dp2[i]=mincost(i+1);//对不需要出行的日期就需要一直往下遍历
        }
        return dp2[i];
    }
};
//上面的代码AC了。

//10-26
/*
 * 1.学习另一种没有重复计算的解法。上面的话需要考虑每一天，不论输入days的长度是多少。
 * 2.看了官方给的解法，谁不说一句绝呢？
 * https://leetcode-cn.com/problems/minimum-cost-for-tickets/solution/zui-di-piao-jie-by-leetcode-solution/
 * 太牛皮了。
 * */

//10-27
class Solution1 {
public:
	vector<int> costs,mins,days;
	int day[3]={1,7,30};
    int mincostTickets(vector<int>& days, vector<int>& costs) {
    	this->costs=costs;
    	this->days=days;
    	mins.resize(days.size(),-1);//初始化为什么呢？我不确定。
    	//因为现在是求一个最小值，那么初始化为较大的值？但是那样会不会溢出？
//    	cout<<mins.size()<<" "<<days.size()<<endl;//这两个size是一样的啊。
    	return dp(0);

    }
    int dp(int i){
    	if(i>=days.size()){
    		return 0;
    	}
    	if(mins[i]!=-1) return mins[i];
    	//之前求长度用sizeof(a)，你是个大傻子啊。。。还得学一下sizeof的基本知识。
    	int k=i;
    	for(int j=0;j<3;j++){//啊怎么初始化呢。。。
    		for(;days[i]+day[j]>days[k]&&k<days.size();k++){}//这样的话是不是就获取不了k了，k是for内部的东西。
    		if(mins[i]==-1)
    			mins[i]=dp(k)+costs[j];
    		else
    			mins[i]=min(mins[i],dp(k)+costs[j]);
    	}
    	return mins[i];
}};//为什么我和官方答案写的几乎一致，但是我报了heap-buffer-overflow的错误？？？？？
//我真的找不出来问题，在哪，是数组出现了问题？是我的for循环需要改成while？那我改成while试试
//还是不行，我明天再看吧，今天实在是没有精力了，被它搞得精疲力尽。

int main(){
//    unordered_set<int> st;//是否会保持插入的顺序？
//    for(int i=0;i<5;i++){
//        st.insert(i);
//    }
//    st.insert(4);
//    for(auto s:st)
//        cout<<s<<" ";
    Solution1 s;
    vector<int> days={1,4,6,7,8,20};
    vector<int> costs={2,7,15};
    cout<<s.mincostTickets(days,costs);
//	vector<int> dp(100,-1);
//	for(auto d:dp)
//		cout<<d<<" ";
//	int a[4]={-1};//-1 0 0 0 说明这样只初始化了第一个，我还以为是所有的。
//	memset(a,-1,sizeof(a));
//	for(auto aa:a)
//		cout<<aa<<" ";
    return 0;
}
