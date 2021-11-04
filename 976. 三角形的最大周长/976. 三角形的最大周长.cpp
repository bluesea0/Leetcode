#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年11月29日上午12:08:52
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        //复杂度:O(nlogn),O(1)
        sort(A.begin(),A.end(),greater<int>());
        for(size_t i=0;i+2<A.size();i++){//这里注意是2，不是3。
            if(A[i]<A[i+1]+A[i+2])
                return A[i]+A[i+1]+A[i+2];
        }
        return 0;
    }
};//6 3 3 2
//easy的题目，很简单，
int main(){

    return 0;
}
