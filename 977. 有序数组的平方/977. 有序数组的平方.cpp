#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��31������3:40:26
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //��ֻ���뵽���򡣡�������˫ָ�����Ŀ����Ϊ���ֻ�
        vector<int> ans;
        for(auto n:nums)
            ans.push_back(n*n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
/*
 * 1.���˹ٷ���⣬��ĺܾ������ˣ��´θ�ϰҪдһ�£�������׶��Ĵ��롣grand�Ľⷨ�Ǻ͹ٷ���������ͬ�ġ�
 * */

//1-5��ϰ
class Solution2 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //�ǵ�����һ��˼·���ҵ������͸����ķֽ��ߣ����ȫ����������ô���ǵ����ģ�ȫ�Ǹ�������
        //�ݼ��ģ�����Ļ��������ٽ��зֱ�ĺϲ���
        //�ڶ���˼·��ͷβ�Ƚϣ�ͷβָ�룬ѡ��ϴ�ķ���
        //��Ϊ�������ֿ϶��ǵ��������������ǵݼ�
        vector<int> ans(nums.size(),0);
        int i=0,j=nums.size()-1;
        for(int k=ans.size()-1;k>=0;k--){
            int ni=nums[i]*nums[i],nj=nums[j]*nums[j];
            if(ni>=nj){
                ans[k]=ni;i++;
            }else{
                ans[k]=nj;j--;
            }
        }
        return ans;
    }
};//���˾��ùٷ��ڶ��ֽⷨд��̫�������ԾͲ�д�ˣ����������ok�ˡ�
int main(){

    return 0;
}
