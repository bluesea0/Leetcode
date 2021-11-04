#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年6月12日下午12:17:59
class Solution {
public:
    int ans;
    int reversePairs(vector<int>& nums) {
        //利用归并排序
        ans=0;
        if(nums.empty()||nums.size()==1)return ans;
        mergeSort(nums,0,nums.size()-1);
        return ans;
    }
    void mergeSort(vector<int>& nums,int left,int right){
        if(left<right){
            int mid=left+((right-left)>>1);
            mergeSort(nums,left,mid);
            mergeSort(nums,mid+1,right);
            merge(nums,left,mid,right);
        }
    }
    void merge(vector<int>& nums,int left,int mid,int right){
        int i=left,j=mid+1;
        vector<int> temp;
        while(i<=mid&&j<=right){
            if(nums[i]>=nums[j]){
//                ans+=(j-mid);
//                if(nums[i]==nums[j])ans--;//我哭了，我觉得写的没问题啊
            	ans+=(j-mid-1);//计算i对逆序数的贡献
                temp.push_back(nums[j++]);
            }else temp.push_back(nums[i++]);
        }
        while(i<=mid){
        	temp.push_back(nums[i++]);
        	ans+=(j-mid-1);//计算i对逆序数的贡献
        }
        while(j<=right)temp.push_back(nums[j++]);
//        for(int i=0;i<(int)temp.size();i++){
//            nums[left+i]=temp[i];
//        }
//        cout<<ans<<" ans ";
//        for(auto& t:temp)
//        	cout<<t<<" ";
//        cout<<"\n";
        copy(temp.begin(),temp.end(),nums.begin()+left);//直接copy函数
    }
};
/*
 * 1.我想的是当前i如果>j的话，那么就移动j并且添加，但是好像是有一个问题，移动后的j也仍然有可能小于i那么此时
 *   如果再次计算就会重复的，确实，所以我的这种移动方法是不正确的。
 * 2.如果i<=j那么j就一直往后移动，那么i再往后移动比较是否>j如果大于，说明大于j之前的数，可以直接相加，
 *   不对，我还是捋不过来，真的好复杂啊。
 * 3.正确思路：在移动i的时候，需要计算它对逆序数的贡献，那么就是j-mid-1，当然不包括j本身，每次移动i的时候
 *   就计算对逆序对的贡献，当然在移动j的时候也可以计算对逆序对的贡献，inv_count+=(mid-i+1);
 * */

//7-15
/*
 * 1.经过1个月再次复习，还是遇到同样的问题，就是在更新逆序对的ans时，想的还是ans+=(j-mid)，
 *  但是针对这样7 8 ，4 5，就会产生重复计算的问题，j指向4移动时计算了一次4，j指向5移动时又计算了一次4的贡献
 *  最终的结果是ans=3，这样的计算就是乱套的。
 * 2.关键的点是，j如果<i，那么j要放入顺序的部分了，就计算它对逆序对的贡献，既然i的位置>j，那么i及i之后的位置
 *   都会>j，所以全都统计。而且这种方法计算的话，如果遇到 4 5 6 ，1 2 3这样的，i没有遍历完，出去while之后
 *   还要再遍历i放入，此时也不用额外的计算。因为之前移动j的时候已经完全计算过了，可以覆盖所有结果。
 * 3.下面写了，非常丝滑。
 * */
class Solution {
public:
    int ans;
    int reversePairs(vector<int>& nums) {
        //再来写一下，因为只写过一次，不太熟悉。
        //总对归并排序有点恐惧
        if(nums.size()<=1)return 0;
        ans=0;
        mergeSort(nums,0,nums.size()-1);
        return ans;
    }
    void mergeSort(vector<int>& nums,int left,int right){
        if(left<right){
            int mid=left+((right-left)>>1);
            mergeSort(nums,left,mid);
            mergeSort(nums,mid+1,right);
            merge(nums,left,mid,right);
        }
    }
    void merge(vector<int>& nums,int left,int mid,int right){
        int i=left,j=mid+1;
        vector<int> temp;
        while(i<=mid&&j<=right){
            if(nums[i]<=nums[j])
                temp.push_back(nums[i++]);
            else{
                ans+=(mid-i+1);
                temp.push_back(nums[j++]);
            }
        }
        while(i<=mid)temp.push_back(nums[i++]);
        while(j<=right)temp.push_back(nums[j++]);
        for(int i=left;i<=right;i++)
            nums[i]=temp[i-left];
    }
};
int main(){
	Solution s;
	vector<int> nums={1,3,2,3,1};
	s.reversePairs(nums);
    return 0;
}
