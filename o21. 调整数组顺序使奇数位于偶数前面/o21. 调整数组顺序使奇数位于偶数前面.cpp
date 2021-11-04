#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//10-24
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        while(i<j){
            while(i<j&&nums[i]%2!=0)i++;
            while(i<j&&nums[j]%2==0)j--;
            swap(nums[i],nums[j]);
            i++;j--;
        }
        return nums;
    }
};
/*
1.AC了，没有什么技术含量的题，首位指针，也可以称为对撞指针。
*/
int main(){
    Solution s;
    vector<int> v={2,4,1,3};
    vector<int> c=s.exchange(v);

    for(auto v:c){
        cout<<v<<" ";
    }
    return 0;
}
