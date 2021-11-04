#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��28������6:53:16
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int m=nums.size();
        vector<int> sums(m,0);
        for(int i=0;i<m;i++){//��������������
            //��ô���ۼ����ţ�
            sums[i]+=nums[i];
            if(i>0)sums[i]+=sums[i-1];
        }
        for(int i=0;i<m;i++){
            if(i==0){
                if(sums[m-1]-sums[i]==0)return i;
            }else if(i==m-1){
                if(sums[i-1]==0) return i;
            }else {
                if(sums[i-1]==sums[m-1]-sums[i]) return i;
            }
        }
        return -1;
    }
};
/*
 * 1.AC�ˣ�O(n)
 * 2.ԭ�������ǰ׺�͵Ľⷨ���Ҷ�û��Ӧ�����������ذ���
 *   ���˹ٷ�����֪������ʵ��������һ�������ǰ׺�����������氡������������еĺͣ�Ȼ����һ��sumͳ��
 *   ǰ׺�ͣ���������i��Ԫ��ʱ���ж�sum==total-sum-nums[i]���ɣ����Ǿ��ˣ�
 * */

//2-4
/*
 * 1.�ٸ�ϰ�һ���ֻ��������ҵ����ַ�������¼��ߵ�Ԫ�غͣ���ô�ұߵľͿ��Լ������������total-sum-nums[i]
 * */
int main(){

    return 0;
}
