#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��3��26������1:44:35
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int> res;
        helper(res,1,n,k);
        return ans;
    }
    void helper(vector<int>& res,int start,int end,int k){
        //�Ҳ�֪�����push��pop��˳����������ġ�
        //����ο��ƣ��ڲ�����res�Ƿ������start������ѭ����push��pop����Ӧ����ô���ƣ�
        //������˵�����ǣ�push��popӦ����ʲôʱ����
        if(res.size()==k){
            ans.push_back(res);return;
        }
        for(int i=start;i<=end;i++){
            res.push_back(i);
            helper(res,i+1,end,k);
            res.pop_back();
        }
    }
};
/*
 * 1.ͦ�ѵģ����ǿ��˽���֮���д�����ģ�������ǻ����㷨����Ҫ�ܽ�һ��������⣬�Ǹ��Ƚϴ�����⡣
 * */
int main(){

    return 0;
}
