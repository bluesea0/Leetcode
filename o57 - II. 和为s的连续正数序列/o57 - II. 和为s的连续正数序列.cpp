#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��3��22������11:22:21
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        //��������
        int cur=0,left=1,right=1,n=target/2+1;//�ٽ�Ҳд��������߽磬̫�����ˣ�
        vector<vector<int>> ans;
        while(right<=n){//����ұ߽�Ӧ���ǿ�������С�İɣ�
            cur+=right;

            while(cur>=target){
                if(cur==target&&right-left>=1){
                    vector<int> temp;
                    for(int i=left;i<=right;i++)
                        temp.push_back(i);
                    ans.push_back(temp);
                }
                cur-=left;
                left++;
            }
            right++;
        }
        return ans;
    }
};
/*
 * 1.AC�ˣ��ٷְ٣��������ˡ�ʱ�䣺O(target)���ռ䣺O(1)��
 * */
int main(){
	Solution s;
	cout<<s.findContinuousSequence(12);
    return 0;
}
