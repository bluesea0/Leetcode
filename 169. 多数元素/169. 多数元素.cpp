#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��10��28������5:29:24
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //��ֱ�ӵ�˼·��ʹ��map��¼���ֳ��ֵĴ�����֮�����map��>n/2�����ַ���
        //Ħ��ͶƱ�����������������������
        //Ħ��ͶƱ����ʲô���ţ������ˣ�ֻ�ǵô����ˡ�����
        int ans,ct=0;
        for(auto n:nums){
            if(ct==0){
                ans=n;
                ct++;
            }else if(n==ans)ct++;
            else ct--;
        }
        return ans;
    }
};
/*
 * 1.https://leetcode-cn.com/problems/majority-element/solution/duo-shu-yuan-su-by-leetcode-solution/
 *   ����˵�ˣ���ȷ�Խ������������Ҿ�֪�������㷨�Ĺ��̾ͺ��ˡ�
 * */
int main(){

    return 0;
}
