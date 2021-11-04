#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��30������10:07:04
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //������Ȼ��������������ǰ����ȫ���ǵã��Ҽǵ�
        //�����ֵ���飬���ҶԲ�ֵ���������ѡ�����з�0�Ҳ��ظ��Ĳ���
        //���ԣ��������˼·���ԣ�������ײ���Ⱥ�˳���Ƿǳ���Ӱ���
        //�����Ǹ�ɵ�ƣ���û�����˼�˵ѡ�����յ�ʯͷ�𣿣����Ǿ����ȶ��оͺ��˰�
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
//AC�ˣ����Ҫ����д�ѣ��ǻ�����Ϊ���Ұ��������һ�ͦ����һ�Եģ�
int main(){
	Solution s;
	vector<int> stones={2,7,4,1,8,1};
	cout<<s.lastStoneWeight(stones);
    return 0;
}
