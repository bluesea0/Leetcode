#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��12������2:55:42
class Solution {
public:
    int firstBadVersion(int n) {
        long long left=1,right=(long long)n+1;//������Ҫ�����long longǿ��ת����������������ΪĬ��
        //��ת��Ϊint����������ˣ�����Ҫ��ǿ��ת��һ�¡�
        //������������n+1�������������˾��ˡ�
        while(left<right){
            long long mid=left+(right-left)/2;//��ʵ����������int��
            if(isBadVersion(mid))right=mid;
            else left=mid+1;
        }
        return right;
    }
};
/*
 * 1.���˹ٽ�Ľ���һ��������ˣ���������right=n+1����=n�ͺõİ���
 * */

//6-13
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long left=1,right=(long long)n;//������������n+1�������������˾��ˡ�
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(isBadVersion(mid))right=mid-1;
            else left=mid+1;
        }
        return left;//Ѱ����߽磬����left���С�
    }
};
int main(){
	Solution s;
	s.firstBadVersion(2147483647);
    return 0;
}
