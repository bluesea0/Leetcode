#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��16������3:48:35
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        //�Բ������i��10�Ļ����൱�ڶ�res��i��֮������ж���10
        vector<int> diff(n,0),res(n,0);
        for(const auto& b:bookings){
            int x=b[0]-1;
            diff[x]+=b[2];
            if(b[1]<n)diff[b[1]]-=b[2];
        }
        res[0]=diff[0];
        for(int i=1;i<n;i++){
            res[i]=diff[i]+res[i-1];//�ɲ�����鷴�ƽ������
        }
        return res;
    }
};

//3-24
/*
 * 1.������飬diff[i]=res[i]-res[i-1]��������£������ѯ����������Ĳ�����Ϊ�Բ������ĵ���£�����ʱ��
 *   ���Ӷȣ���[i,j]�ĸ���a��ת��Ϊ��diff[i]+a����diff[j+1]-a��
 * */
int main(){

    return 0;
}
