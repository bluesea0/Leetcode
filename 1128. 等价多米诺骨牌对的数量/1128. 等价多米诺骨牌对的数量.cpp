#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��26������2:07:19
class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        //�ڱȽ�֮ǰ�Ƚ����ڲ���Ԫ��
        if(a[0]>a[1])swap(a[0],a[1]);
        if(b[0]>b[1])swap(b[0],b[1]);
        if(a[0]<b[0])return true;
        else if(a[0]==b[0])return a[1]<b[1];//����Ҫ������жϣ�
        return false;//���ұ����������أ�
    }
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        sort(dominoes.begin(),dominoes.end(),cmp);//Ĭ�ϲ�����С������
        //Ĭ�������ų��������⣬ǰ��������[1,2],[2,1]�������źð�
        // sort(dominoes.begin(),dominoes.end(),[](){});//����Ҳ���У���Ϊֻ�˵��˵�һ��
        int res=0,m=dominoes.size();
        //���ҾͲ������ˣ���������ŵ�3���Ļ�����ô����ô�����أ�
        //����3�ԣ��⣿
        // for(auto p:dominoes)
        //     cout<<p[0]<<" "<<p[1]<<endl;
        for(int i=0;i+1<m;i++){
            int t=0;
            while(i+1<m&&((dominoes[i][0]==dominoes[i+1][0]&&dominoes[i][1]==dominoes[i+1][1])||(dominoes[i][0]==dominoes[i+1][1]&&dominoes[i][1]==dominoes[i+1][0]))){
                i++;t++;
            }
            while(t){
                res+=t;
                t--;
            }
        }
        return res;
    }
};
/*
 * 1.�������ҷǳ������˼·����ľ��ܴ�����⿴�����㷨ˮƽ���������㷨ˮƽ̫���˰ɡ�����
 *  ��Ϊ�����������[[2,1],[5,4],[3,7],[6,2],[4,4],[1,8],[9,6],[5,3],[7,4],[1,9],[1,1],[6,6],[9,6],[1,3],
 *  [9,7],[4,7],[5,1],[6,5],[1,6],[6,1],[1,8],[7,2],[2,4],[1,6],[3,1],[3,9],[3,7],[9,1],[1,9],[8,9]]
 *  ����֮��Ĳ��ֽ����1 1   1 3    1 6    1 6    1 8   1 8    1 9   1 9   2 1   2 4   3 1  3 7  3 7
 *  �����˰ɣ�13 ��31�����ͱȲ����������ҵ�������ʲô�ء�����ʵҲ���Ըĵģ�ȫ������ɵ�һ��Ԫ�ش󣬵ڶ���Ԫ��С��
 * 2.��д��cmp����֮����ͨ���ˣ��ҵ�cmp����һ��ʼд�������⣡��ģ� �����ϣ������ѧ���㶫����
 *   �ҵĽⷨ���Ӷ�������ĸ��Ӷ�O(nlogn)��
 * 3.�����и��ܴ�������ǣ���ʵ��Ҳע�⵽��1 <= dominoes[i][j] <= 9����Ŀ���ģ������Ҳ�֪����ô�ð�����˵
 *   ����ô�ã��ҿ����˶���
 *   ���������û�������Χ�Ļ������ù�ϣ����ͳ�ƣ����˾��ˣ��԰�����ϣ���Ǹ�pair������ˣ��´θ�ϰ��Ҫ��
 *   дһ�£������������
 * 4.�ٷ���ƴ���γɵ������ķ�����ͦ�����Ĺ��������ԡ�
 *
 * */
class Solution2 {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> nums(100,0);
        int res=0;
        for(auto p:dominoes){
            int t=p[0]<p[1]?(p[0]*10+p[1]):(p[1]*10+p[0]);//��*10��С*10����һ���ġ�
            res+=nums[t];//�����ӡ����µ�˳�����Ǿ���
            nums[t]++;
        }
        return res;
    }
};

//1-27
//class Solution {
//public:
//    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
//        unordered_map<pair<int,int>,int> um;
//        int res=0;
//        for(auto d:dominoes){
//            auto p1=make_pair(d[0],d[1]);
//            auto p2=make_pair(d[1],d[0]);
//            if(um.count(p1)){
//                res+=um[p1];
//                um[p1]+=1;
//            }else if(um.count(p2)){
//                res+=um[p2)];
//                um[p2]+=1;
//            }else um[p2]==1;
//        }
//        return res;
//    }
//};
/*
 * 1.����Ĵ����Ǵ���ģ�map������pair��Ϊkey�����Ҫ�õĻ�����Ҫ���hash��������̫����
 * 2.�����˵�ģ�ʹ�ù�ϣ��Ӧ���ǻ�ȡkey֮��Ҳ���ǽ�һ��*10+��һ�����������������ˡ�
 * */
int main(){

    return 0;
}
