#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年9月18日上午2:50:34
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        quickSort(nums,0,n-1);
        return nums;
    }
    void quickSort(vector<int>& nums,int left,int right){
        if(left<right){
            int p=partion(nums,left,right);
            quickSort(nums,left,p-1);
            quickSort(nums,p+1,right);
        }
    }
    int partion(vector<int>& nums,int left,int right){
        //随机化快排，选择一个随机的下标
        int x=rand()%(right-left+1)+left;
        swap(nums[x],nums[right]);
        int p=left-1;
        for(int i=left;i<right;i++){
            if(nums[i]<=nums[right]){
                p++;
                swap(nums[i],nums[p]);
            }
        }
        swap(nums[p+1],nums[right]);
        return p+1;
    }
};
//实现随机化快排，取随机数就在partion函数中就行。

int main(){

    return 0;
}
