#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��5������4:12:05
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        //ת��Ϊ���������ֻ����k��0
        int left=0,right=0,ct=0,max1=0,ans=0;
        while(right<A.size()){//�ݣ��Ҷ����ˣ����׸���ô���£���û��һ��ȷ�����ģ�尡��
            if(A[right])ct++;//�����ˣ������û���պ�ģ��Ĵ�����
            max1=max(ct,max1);
            if(right-left+1-max1>K){
                if(A[left])ct--;
                left++;
            }
            ans=max(ans,right-left+1);//�����Ҳѧ�����ˣ��ͰѴ𰸸��·������档
            right++;
        }
        return ans;
    }
};
/*
 * 1.��424��ǳ��񣬶����ڼ��left֮��Ҳ����ÿ�θ���rightʱ����ans��������ڸ���leftʱ������ô��
 *   �ͻ��кܶ����⵼�´𰸲�����ȷ��
 * 2.https://www.cnblogs.com/grandyang/p/6376115.html�����д�ĺ�ţ�ƣ�������д����ʵҲ��
 *   class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, zero = 0, left = 0, k = 1;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) ++zero;//ֱ�Ӽ�¼0�ĸ���
            while (zero > k) {
                if (nums[left++] == 0) --zero;//��С���ڵ�ʱ���ж��Ƿ���0
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
��Ϊ�������ʵ���ַ����ǲ�һ��������ֻ��0��1������
 * */
int main(){

    return 0;
}
