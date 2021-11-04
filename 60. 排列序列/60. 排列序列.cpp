#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年6月10日下午1:50:32
class Solution {
public:
    string getPermutation(int n, int k) {
        //那么就其实蛮简单的吧
        vector<int> nums(n);
        for(int i=0;i<n;i++)
            nums[i]=i+1;
        while(--k)next_permutation(nums.begin(),nums.end());
        string s;
        for(auto& n:nums)
            s.push_back(n+'0');
        return s;
    }
};
/*
 * 1.投机取巧了一下，直接用了库函数解题，如果不是，那么就直接用31题的那个下一个全排列也ok的吧。
 * 2.直接把31题的复制过去也行。
 * */
int main(){

    return 0;
}
