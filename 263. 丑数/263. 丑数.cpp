#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-15��Ҳ̫���ˡ�
class Solution {
public:
    bool isUgly(int num) {
        if(num==0) return false;//0���ǳ�����
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
