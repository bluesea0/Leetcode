#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��9������12:19:32
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //��ʣ��n-k�ŵ���Сֵ�������������Сֵ
        int left=0,right=0,n=cardPoints.size(),ans=INT_MAX,cur=0;
        int sum=accumulate(cardPoints.begin(),cardPoints.end(),0);
        if(n==k)return sum;
        while(right<n){
            cur+=cardPoints[right];
            if(right-left+1==n-k){
                ans=min(ans,cur);
                cur-=cardPoints[left];
                left++;
            }
            right++;
        }
        return sum-ans;
    }
};
int main(){

    return 0;
}
