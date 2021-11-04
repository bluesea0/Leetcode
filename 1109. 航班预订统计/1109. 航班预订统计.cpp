#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月16日下午3:48:35
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        //对差分数组i加10的话，相当于对res中i及之后的所有都加10
        vector<int> diff(n,0),res(n,0);
        for(const auto& b:bookings){
            int x=b[0]-1;
            diff[x]+=b[2];
            if(b[1]<n)diff[b[1]]-=b[2];
        }
        res[0]=diff[0];
        for(int i=1;i<n;i++){
            res[i]=diff[i]+res[i-1];//由差分数组反推结果数组
        }
        return res;
    }
};

//3-24
/*
 * 1.差分数组，diff[i]=res[i]-res[i-1]，区间更新，单点查询，将对区间的操作改为对差分数组的点更新，降低时间
 *   复杂度，对[i,j]的更新a，转换为对diff[i]+a，对diff[j+1]-a。
 * */
int main(){

    return 0;
}
