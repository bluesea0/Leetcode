#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��15������4:06:39
//class Solution {
//public:
//    int removeStones(vector<vector<int>>& stones) {
//        //��̫�ᣬ��ȻҪ�Ƴ������ô���Ǳ������٣�
//        //�뵽����dp��̰�ģ�����dp[i]���ܱ�ʾʲô�أ�
//        //���뵽����������ϣ��ֱ𱣴��к��ж�Ӧ��λ�ã�����Ҳ�����ܱ�֤�Ƴ�ʯ���������
//    }
//};
/*
 * 1.��ȷʵ�ǲ�̫�У��Ҹ����벻�����鼯��˼·�����ҵ��衣
 * */
class Solution {
public:
    unordered_map<int,int> fa;
    int count=0;
    int removeStones(vector<vector<int>>& stones) {
        //ԭ��father��������ù�ϣ�����һ���Ϊֻ����������ʾ���Ǹõö�󰡡�
        for(int i=0;i<stones.size();i++){
            merge(stones[i][0]+10001,stones[i][1]);
        }
        return stones.size()-count;
    }
    void merge(int i,int j){
        int fi=find(i);
        int fj=find(j);
        if(fi==fj)return;
        fa[fi]=fj;
        count--;//�ϲ���һ����ͨ����
        //if(fi!=fj)res--;//����ô�����أ���������п�����i��j������ȣ�
        //����i��jͬ����һ�����꣬���ҾͲ������ˣ����׸���ô�����أ�
    }
    int find(int x){
        if(fa.count(x)==0){
            count++;
            return fa[x]=x;
        }//���û�еĻ����Ǿͽ���ӳ��
        return fa[x]==x?x:(fa[x]=find(fa[x]));
    }
};//ͦ�ѵģ��ҵ��裬����Աա�
/*
 * 1.���������궼�ϲ���һ�𣬲������������������Ҳ�м��ɡ�����û�������飬��Ϊ����Ŀ���Ǻܴ�ģ�
 *   �����ù�ϣ����涨����fa���顣����������������ÿ����һ���ڵ㣬������+1�����ϲ���ʱ��-1.���ˡ�
 *   �������ͬ����һ����ͨ��������ô�ͷ��ء�
 * */
int main(){

    return 0;
}
