#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��30������3:48:44
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //���ģ���Щ��
        //�������start��С����������ô�����ǰ�����֮ǰ�Ľ����ˣ������п��ܺ�һ���͵�ǰ��Ҳ�н�������ʲôʱ����ܰ���Щ�н�������������أ�
        //�ǲ���Ҫͬʱ��¼start��end��λ�ã�
        if(intervals.size()==0)return {};//�յĻ�Ӧ���ǿ�����ô���صİ�
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0],end=intervals[0][1];
        vector<vector<int>> ans;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=end){
                //end=intervals[i][1];
                end=max(end,intervals[i][1]);//[[1,4],[2,3]]���п���ȫ����
            }else{
                //˵��û�н������ǾͰ�֮ǰ�γɵ��������
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
 * 1.��Ϊ435�⣬�Ҹ�ϰ�˺ü��Σ���������˼·�����Խ��츴ϰ����֮��͸Ͻ�������������Ŀ������ӡ��
 *   ʱ�临�Ӷ�O(nlogn)���ռ���O(logn) ��Ϊ��������Ҫ�Ŀռ临�Ӷȡ�
 * 2.        vector<vector<int>> res{intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back()[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        grand�����д�����˰����Ȱѵ�0���Ž�ȥ��Ȼ������Ǹ��жϣ��Ͳ������һ�Ҫ�ٶ�дһ��push_back()
 * */
int main(){

    return 0;
}
