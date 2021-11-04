#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��3��4������9:50:42
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int m=envelopes.size();
        vector<int> dp(m,1);
        cout<<m;
        sort(envelopes.begin(),envelopes.end(),[](const auto& a,const auto& b){
        	return a[0]<b[0];//���ģ�������ҵ����sort����д�Ĳ��԰���������=�ŵģ�
        	//���ڷ�����bug���ڣ�ԭ��cmp����������=�ŵİ���
        });
        int ans=1;
        for(int i=1;i<m;i++){
            for(int j=0;j<i;j++){
                if(envelopes[i][0]>envelopes[j][0]&&envelopes[i][1]>envelopes[j][1])
                    dp[i]=max(dp[i],dp[j]+1);
            }
            if(dp[i]>ans)ans=dp[i];
        }
        return ans;//������Ŀ�������������д���ˣ������ٸ�ϰһ���ӡ�
    }
};
/*
 * 1.�����޸���cmp����֮��ķ��ؽ�<=��Ϊ<��ѧ����һ��֪ʶ�㰡��
 * 2.ʱ����O(n^2)������е������ǽ�0ά����1ά��������ֻ����һά��������������ˡ�
 * 3.�����������������Ҳ�����ö��ֵķ�����д��f[j]��ʾ����������г���Ϊjʱ����Сֵ
 * */
class Solution2 {//���չٽ��д��
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int m=envelopes.size();
        vector<int> dp(m,1);
        sort(envelopes.begin(),envelopes.end(),
        [](const vector<int>& a,const vector<int>& b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);});
        int ans=1;
        for(int i=1;i<m;i++){
            for(int j=0;j<i;j++){
                if(envelopes[j][1]<envelopes[i][1])
                    dp[i]=max(dp[i],dp[j]+1);
            }
            if(dp[i]>ans)ans=dp[i];
        }
        return ans;//������Ŀ�������������д���ˣ������ٸ�ϰһ���ӡ�
    }
};

//����̰��+���ֵĽⷨ�����Ҳ̫���˰ɣ�����
class Solution3 {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> d;
        sort(envelopes.begin(),envelopes.end(),
        [](const vector<int>& a,const vector<int>& b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
        });
        d.push_back(envelopes[0][1]);
        for(int i=1;i<envelopes.size();i++){
            if(envelopes[i][1]>d.back())d.push_back(envelopes[i][1]);
            else{
                int j=lower_bound(d.begin(),d.end(),envelopes[i][1])-d.begin();
                d[j]=envelopes[i][1];
            }
        }
        return d.size();
    }
};
/*
 * 1.����ֻ��dp�Ļ�����ʱ����1000+ms�����������40ms�����˾��˰�������
 * */
int main(){
	Solution s;
	vector<vector<int>> a={{15,8},{2,20},{2,14},{4,17},{8,19},{8,9},{5,7},{11,19},{8,11},{13,11},{2,13},{11,19},{8,11},{13,11},{2,13},{11,19},{16,1},{18,13},{14,17},{18,19}};
	cout<<s.maxEnvelopes(a);
    return 0;
}
