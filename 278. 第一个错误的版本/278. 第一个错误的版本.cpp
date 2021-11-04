#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月12日下午2:55:42
class Solution {
public:
    int firstBadVersion(int n) {
        long long left=1,right=(long long)n+1;//这里需要后面的long long强制转换，否则它还是认为默认
        //先转换为int，但是溢出了，所以要先强制转换一下。
        //天啦，遇到了n+1溢出的情况，绝了绝了。
        while(left<right){
            long long mid=left+(right-left)/2;//其实这里大可以用int。
            if(isBadVersion(mid))right=mid;
            else left=mid+1;
        }
        return right;
    }
};
/*
 * 1.看了官解的解答，我还是稚嫩了，根本不用right=n+1，就=n就好的啊。
 * */

//6-13
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long left=1,right=(long long)n;//天啦，遇到了n+1溢出的情况，绝了绝了。
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(isBadVersion(mid))right=mid-1;
            else left=mid+1;
        }
        return left;//寻找左边界，返回left就行。
    }
};
int main(){
	Solution s;
	s.firstBadVersion(2147483647);
    return 0;
}
