#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��5������3:06:09
//class Solution {
//public:
//    int equalSubstring(string s, string t, int maxCost) {
//        //ת��Ϊ�����������������
//        vector<int> cost(s.size(),0);
//        for(int i=0;i<s.size();i++){
//            cost[i]=abs(s[i]-t[i]);
//        }
//        int left=0,right=0,cur=0,ans=0;
//        while(right<cost.size()){
//            cur+=cost[right];
//            while(cur>=maxCost){//�ƶ���ָ�룬����������ѭ���ǲ��Եģ���Ϊ����=k���п����и����
//            //��������>k�����ǲ���=k
//                if(cur==maxCost)//���ԣ���ôд���ǲ��ԣ���������2��˵Ҳ����<=k
//                    ans=max(ans,right-left+1);
//                cur-=cost[left];
//                left++;
//                if(cur<maxCost)
//                    ans=max(ans,right-left+1);
//            }//���ģ���Ȼ��ʶ����д���ѭ����������ѭ���������ʾ��3������ɵ��
//            //��һ��0�ͻ�һֱ����ȥ
//            //���Թؼ������������ô�ƶ�leftָ�룿
//            right++;
//        }
//        return ans;
//    }
//};
/*
 * 1.����һֱ�ھ�����ô���ƶ�left��ʱ����£�����ʵ���ϸ�����û���Ǹ�ɶ�����������ˡ�
 * 2.����right��ʱ��Ҳ������Ȼ���£�
 * */
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        //ת��Ϊ�����������������
        vector<int> cost(s.size(),0);
        for(int i=0;i<s.size();i++){
            cost[i]=abs(s[i]-t[i]);
        }
        int left=0,right=0,cur=0,ans=0;
        while(right<cost.size()){
            cur+=cost[right];
            while(cur>maxCost){
                cur-=cost[left];
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};
int main(){

    return 0;
}
