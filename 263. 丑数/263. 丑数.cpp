#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-15这也太简单了。
class Solution {
public:
    bool isUgly(int num) {
        if(num==0) return false;//0不是丑数。
        int nums[]={2,3,5};
        for(auto n:nums){
            while(num%n==0){
                num/=n;
            }
            if(num==1)break;
        }
        return num==1;
    }
};
int main(){
    Solution s;
    cout<<s.isUgly(8);
    return 0;
}
