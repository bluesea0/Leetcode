#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��9��18������2:50:34
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
        //��������ţ�ѡ��һ��������±�
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
//ʵ����������ţ�ȡ���������partion�����о��С�

int main(){

    return 0;
}
