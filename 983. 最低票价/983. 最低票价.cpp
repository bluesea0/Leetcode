#include <iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<string.h>
using namespace std;
//10-22
/*
1.��Ȼ�ǲ����ˣ��������ⶼ�о���ͷ���������������Ŀ�ľ���Ϊ�����˵�ͷ���ɣ��ٽ�ֲ����ҵ�ķ�չ��
2.֮ǰ����һ�Σ���ʱ�������ڿ��ĸо���һ���ģ������ĸо���
*/
//class Solution {
//public:
//    int mincostTickets(vector<int>& days, vector<int>& costs) {
//        //̫���ˣ���������Ե�ʱ���������Ҿ�ֱ�ӹ�ɣ�˵�Ҳ��ᣬ����������ҵ�ͷ����
//        //����������Ǹ����г𣡰�����˵�������������ѣ�
//        //���������������������
//        return 0;
//    }
//};
//���������۹ٷ��ĵ�һ���ⷨ���һ��ǲ�̫����
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
1.��������Ĺ���������һ�����Ӱɣ�Ҫ��Ȼ��Ļ��Ǿ������ڿ��У�������������ⲻ��ô��̡�
  [1,2,3,4,5,6,7,8,9,10,30,31]��[2,7,15]
  memo[31]=min(2,7,15)=2
  memo[30]=min(2+2,0+7,0+15)=4
  memo[11~29]=memo[30]=4
  memo[10]=min(dp(11)+2,dp(17)+7,dp(40)+15)=min(4+2,4+7,0+15)=6
  memo[9]=min(dp(10)+2,dp(16)+7,dp(39)+15)=min(6+2,4+7,0+15)=8//9��10��30��31���ǵ�����һ��
  memo[8]=min(dp(9)+2,dp(15)+7,dp(38)+15)=min(8+2,4+7,0+15)=10
  memo[7]=min(dp(8)+2,dp(14)+7,dp(37)+15)=min(10+2,4+7,0+15)=11//��ʾҪ��һ��7��ģ���ÿ�춼��һ��1��/2Ԫ�ĸ����ˣ�
  memo[6]=min(dp(7)+2,dp(13)+7,dp(36)+15)=min(11+2,4+7,0+15)=11//�ڵ�6����7���Ʊ
  memo[5]=min(dp(6)+2,dp(12)+7,dp(35)+15)=min(11+2,4+7,0+15)=11//�ڵ�5����7���Ʊ
  memo[4]=11//�ڵ�4����7���Ʊ
  memo[3]=min(dp(4)+2,dp(10)+7,dp(33)+15)=min(11+2,6+7,0+15)=13//���Ե����쵥����Ȼ��4-10���7���Ʊ��Ҳ����3-9
  //���7���Ʊ����10�����������һ��Ʊ��ע��7��Ʊ��3-9��������3-10��
  memo[2]=min(dp(3)+2,dp(9)+7,dp(32)+15)=min(13+2,8+7,0+15)=15//���ھ���������Ʊ�Ĳ����ˡ�
  memo[1]=min(dp(2)+2,dp(8)+7,dp(31)+15)=min(15+2,10+7,2+15)=17//��ʵҲ����������Ʊ���ԡ�
  ������о��������һ�����õ�������������
2.dp[i]��ʾ���Ǵӵ�i�쵽��365�죨һ��Ľ�������С���ѵ���Ŀ���Ӻ���ǰ����dp����ľ����ӣ�
*/
/*
3.��Ϊ������У�ÿ�ζ������dp[i]=dp[i+1]=dp[i+2]�����ӣ��ͺ��鷳�����ԾͶ������µ�dp����
  ��dp(i) ��ʾ�ܹ���ɴӵ�days[i] �쵽�������мƻ�����С���ѣ�����Ǵ�����������
  �ٸ�̾�����Ƿ���five
*/

//10-24
/*
1.����дһ�£��Ҹо��һ���д������������
*/
class Solution {
	//������ǲ�̫���ˡ�
	//������ʼ���ķ�ʽ�Ǿ���û������ġ�������Ĳ����ˣ�������Ұ��²���ɡ�
//    vector<int> dp2(366,-1);//error: expected identifier before numeric constantΪʲô����ͻᱨ����
	int dp2[366]={-1};
    unordered_set<int> day;
    vector<int> cost;
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(auto d:days)
            day.insert(d);
        this->cost=costs;//����Ҫ��thisָ��
        memset(dp2,-1,sizeof(dp2));
        return mincost(1);
    }

    int mincost(int i){
        if(i>365)return 0;
        if(dp2[i]!=-1)return dp2[i];
        if(day.count(i)){
            dp2[i]=min(mincost(i+1)+cost[0],min(mincost(i+7)+cost[1],mincost(i+30)+cost[2]));
        }else{
            dp2[i]=mincost(i+1);//�Բ���Ҫ���е����ھ���Ҫһֱ���±���
        }
        return dp2[i];
    }
};
//����Ĵ���AC�ˡ�

//10-26
/*
 * 1.ѧϰ��һ��û���ظ�����Ľⷨ������Ļ���Ҫ����ÿһ�죬��������days�ĳ����Ƕ��١�
 * 2.���˹ٷ����Ľⷨ��˭��˵һ����أ�
 * https://leetcode-cn.com/problems/minimum-cost-for-tickets/solution/zui-di-piao-jie-by-leetcode-solution/
 * ̫ţƤ�ˡ�
 * */

//10-27
class Solution1 {
public:
	vector<int> costs,mins,days;
	int day[3]={1,7,30};
    int mincostTickets(vector<int>& days, vector<int>& costs) {
    	this->costs=costs;
    	this->days=days;
    	mins.resize(days.size(),-1);//��ʼ��Ϊʲô�أ��Ҳ�ȷ����
    	//��Ϊ��������һ����Сֵ����ô��ʼ��Ϊ�ϴ��ֵ�����������᲻�������
//    	cout<<mins.size()<<" "<<days.size()<<endl;//������size��һ���İ���
    	return dp(0);

    }
    int dp(int i){
    	if(i>=days.size()){
    		return 0;
    	}
    	if(mins[i]!=-1) return mins[i];
    	//֮ǰ�󳤶���sizeof(a)�����Ǹ���ɵ�Ӱ�����������ѧһ��sizeof�Ļ���֪ʶ��
    	int k=i;
    	for(int j=0;j<3;j++){//����ô��ʼ���ء�����
    		for(;days[i]+day[j]>days[k]&&k<days.size();k++){}//�����Ļ��ǲ��Ǿͻ�ȡ����k�ˣ�k��for�ڲ��Ķ�����
    		if(mins[i]==-1)
    			mins[i]=dp(k)+costs[j];
    		else
    			mins[i]=min(mins[i],dp(k)+costs[j]);
    	}
    	return mins[i];
}};//Ϊʲô�Һ͹ٷ���д�ļ���һ�£������ұ���heap-buffer-overflow�Ĵ��󣿣�������
//������Ҳ��������⣬���ģ���������������⣿���ҵ�forѭ����Ҫ�ĳ�while�����Ҹĳ�while����
//���ǲ��У��������ٿ��ɣ�����ʵ����û�о����ˣ�������þ�ƣ������

int main(){
//    unordered_set<int> st;//�Ƿ�ᱣ�ֲ����˳��
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
//	int a[4]={-1};//-1 0 0 0 ˵������ֻ��ʼ���˵�һ�����һ���Ϊ�����еġ�
//	memset(a,-1,sizeof(a));
//	for(auto aa:a)
//		cout<<aa<<" ";
    return 0;
}
