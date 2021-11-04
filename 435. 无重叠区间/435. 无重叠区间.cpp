#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��19������5:55:03
//class Solution {
//public:
//    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//        //�϶�����Ҫ�������򣬵���Ҫɾ������α�ʾ�أ������ʾ����ɾ���ˣ�
//        //���ǲ�̫�ᣬ������ô�㰡���ҿޡ�
//        //���̫���ˣ��ҿ��ٷ������Ҳ�ǿ��ķǳ��Ժ����Դ���·�ĸо���
//    }
//};
//̫���ˣ��ⷨ����dp:���/�յ㣬̰��:��㡢�յ�


//12-24
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //ת��Ϊ����ж��ٸ���������⡣
        if(intervals.size()==0)return 0;
        sort(intervals.begin(),intervals.end());
        vector<int> dp(intervals.size(),1);

        for(int i=1;i<dp.size();i++){
            for(int j=0;j<i;j++){
                if(intervals[j][1]>intervals[i][0])continue;
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        return intervals.size()-dp.back();
    }
};//����AC��һ�Σ���Ȼ̫�������ˣ��������Ӷ���O(n^2)��ֻ������5%��
/*
 * 1.�����ظ����ж������ǣ�ǰһ�������end>��ǰ�����begin��
 * 2.ladong�ĽⷨҲ�Ǻ�������������˼·��Ȼ���ʣ���������Ҳ����˼������end�����򣬲������ص�������
 *   ѡ��end��С�ģ�������̰�ģ��ܹ��γ����ŵĽ��
 *   grand��˼·�ǰ���start���򣬲�����һ��preָ��֮ǰ�����䣬�����ǰ�������start<֮ǰ��end����ô
 *   �����ص������жϣ����ߵ�end�ĸ���С��ѡ��end��С���Ǹ���
 * */

//12-30
/*
 * 1.��ʵ�ڿ���grand�Ľⷨ�ǣ���������μ�¼�����ģ���Ȼ˵��pre
 * ��Ҫ�д����е��ж�if (intervals[i][1] < intervals[last][1]) last = i;
 * ��Ϊ������[1,5][1,6][2,3][3,4]����������������С��ʱ�򷴶�������Ŀ����
 * 2.˼·�������ܹ�������γɶ��ٸ����䣬����������Ŀ��ȥ���͵õ�������Ҫ�Ƴ��ġ�
�ȶ��������򣬶�ÿ���������������֮ǰ��ÿ�����ж��Ƿ��н��棬start<end��ȡ���ֵ�����Ӷ�O(n^2)
���ģ�O(n)�Ľⷨ�Ҷ������ˡ�
	3.��ladong�Ľⷨ˼·�������󲻳�������ô���İ���
	  ����end��С��������ѡ��start�ϴ�ģ����Ǹо����˼·������
	  ��end�Ӵ�С��Ȼ��ȡСend�ǲ��Եģ�����[1,5][1,6][2,3][3,4]���ܷ���������
	  ʹ��end��С���󣬵õ����Ǳ������������Ŀ��
 * */

//12-31
class Solution2 {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //�����ǰ���start����
        if(intervals.empty()) return 0;
        sort(intervals.begin(),intervals.end());
        //�����ǰstart<end���ͱ���end��С��ֵ
        int res=0,end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<end){
                res++;
                end=min(end,intervals[i][1]);
            }else
                end=intervals[i][1];
        }
        return res;
    }
};//����start����O(n) O(1)

class Solution3 {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //����end��С�������򣬵��������ȷ��������γɶ��ٸ�����
        //��������һ��ǲ��죬˼·��̫�������
        if(intervals.empty()) return 0;
        sort(intervals.begin(),intervals.end(),
        [](vector<int> a,vector<int> b){return a[1]<b[1];});
        int m=1,end=intervals[0][1];
        //�ؼ���Ҫ������һ��
        //�����ǰ��֮ǰ�������н��棬��ô�϶���������ǰ����Ϊ֮ǰ��������̣���������Ŀռ���࣡
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=end){//������������������䶼����
            //��Ϊ�������󣬶��Һ�֮ǰ�����佻���ˣ�ѡ����֮ǰ������
                m++;
                end=intervals[i][1];
            }
        }
        return intervals.size()-m;
    }
};
/*
 * 1.���ģ������̫���ˣ���Ŀ��
 * */

//1-6
/*
 * 1.�������start�����С�����������ص��ģ���ô����endֵ�ϴ������
 * 2.�������end�����С������ô�������ص������䣬��ôֱ��������ǰ��Ҳ����endֵ�ϴ�ġ�
 * 3.��֮���������򷽷����Ǵ�С���󣬴�ǰ�����������������������endֵ�ϴ�ģ��Ը��������¸���Ŀռ䡣
 * */
int main(){

    return 0;
}
