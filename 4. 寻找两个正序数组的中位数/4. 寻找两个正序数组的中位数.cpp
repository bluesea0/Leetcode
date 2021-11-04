#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月27日下午4:19:56
/*
 * 1.我看到这个题的时候就感觉合并起来？要不然怎么单独找？想不出来，看到题解真的感觉绝了，价值两万！
 *   还需要考虑两个数组长度的奇偶性的问题，就超级麻烦吧，如果是一个数组找中位数，那不就是top-kth的问题嘛
 *   但是这两个怎么考虑就不知道了。
 * 2.官方题解二分法：比较两个数组中第k/2-1位置的元素大小，然后抛弃小的的部分，之后更新k，绝了。
 *   这里k表示第k大的数。
 * */
//class Solution {
//public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        int i=0,j=0,m=nums1.size(),n=nums2.size();
//        int k=(m+n-1)/2;//标记移动的次数
//        while(k&&i<m&&j<n){
//            if(nums1[i]<=nums2[j])i++;
//            else j++;
//            k--;
//        }
//        while(i<m&&k){
//            i++;//如果是数组1还未移动完
//            k--;
//        }
//        while(j<n&&k){
//            j++;
//            k--;
//        }
//        //那这里怎么返回其实还需要很复杂的判断
//        if((m+n)%2==0){//如果是偶数
//            if(i>=m)return (nums2[j]+nums2[j+1])*1.0/2;
//            else if(j>=n) return (nums1[i]+nums1[i+1])*1.0/2;
//            else return (nums1[i]+nums2[j])*1.0/2;
//        }else{//天哪，这个如果是奇数该怎么返回呢？
//            //天哪，不知道怎么返回了，我跪了。
//            if(j>=n)return nums1[i]*1.0;
//            else if(i>=m) return nums2[j]*1.0;
//            else return min(nums1[i],nums2[j])*1.0;
//        }
//    }
//};


//3-24
/*
 * 1.之前尝试写了O(m+n)的解法，当然因为实在是好复杂，我还是没写出来。上面的写法是错的，样本：
 *   [1,2] [-1,3]，这样的话，i指向1，j指向3，然后就只能从两个数组里分别求取，根本不对啊。哭泣。
 * */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int k1=findm(nums1,nums2,0,0,(m+n+1)/2);
        int k2=findm(nums1,nums2,0,0,(m+n+2)/2);
        cout<<k1<<" "<<k2<<endl;
        return (k1+k2)*1.0/2;
    }
    int findm(vector<int>& nums1, vector<int>& nums2,int i,int j,int k){
        if(i>=nums1.size())return nums2[j+k-1];
        if(j>=nums2.size())return nums1[i+k-1];
        if(k==1)return min(nums1[i],nums2[j]);//这个有什么样例吗？
        int idx1=min((int)nums1.size(),i+k/2)-1;//这里我想使用的策略是，如果有一个不足k/2那么就直接比较最后一个
        //之前grand的解法是不足的话，直接忽略掉另一个数组中的前k/2个，但我觉得他写的别扭。
        //那么我这里就不能直接k-k/2了，而应该减去真正的数目。
        int idx2=min((int)nums2.size(),j+k/2)-1;
        if(nums1[idx1]<nums2[idx2])//说明idx1之前的都可以忽略掉
        	return findm(nums1,nums2,idx1+1,j,k-(idx1-i+1));
            //return findm(nums1,nums2,i+k/2,j,k-k/2);//因为我设置了
        else return findm(nums1,nums2,i,idx2+1,k-(idx2-j+1));
        	//return findm(nums1,nums2,i,j+k/2,k-k/2);
    }
};
/*
 * 1.上面AC了，真不错。看了grand解法觉得别扭，所以写了上面的，当超过范围时，直接k减去真正有的数。
 * */

//7-12
/*
 * 1.看来我之前还是没有理解题解，对一个题一定要多看几个题解，掌握不同的思路，理解透彻。
 * 2.转换为从两个数组中选择第k小的元素，利用二分的方法，比较A[k/2-1]和B[k/2-1]直接舍去较小的部分，
 *   较小的值比它小的最多只有k-2值，那么它是第k-1小的，不会是第k小的。
 * */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if((m+n)%2)
            return findM(nums1,nums2,0,0,(m+n)/2+1);
        else return (findM(nums1,nums2,0,0,(m+n)/2)+findM(nums1,nums2,0,0,(m+n)/2+1))*1.0/2;
    }
    int findM(vector<int>& nums1, vector<int>& nums2,int idx1,int idx2,int k){
        if(idx1>=nums1.size())return nums2[idx2+k-1];//return nums2[k-1];//返回出错了，应该+idx啊！
        if(idx2>=nums2.size())return nums1[idx1+k-1];//nums1[k-1];
        if(k==1)return min(nums1[idx1],nums2[idx2]);

        int m=nums1.size(),n=nums2.size();
        int i1=min(idx1+k/2-1,m-1);
        int i2=min(idx2+k/2-1,n-1);
        if(nums1[i1]<=nums2[i2]){
            return findM(nums1,nums2,i1+1,idx2,k-(i1-idx1+1));
        }else return findM(nums1,nums2,idx1,i2+1,k-(i2-idx2+1));
    }
};

//10-1复习
/*
 * 1.上一套十分简洁的代码注意点是，要找的是第k个数，所以在总长度为奇数的时候，要+1
 *   偶数时是第(m+n)/2个数，第+1个数求均值。
 * */
int main(){
	Solution s;
	vector<int> nums1={1};
	vector<int> nums2={2,3,4,5,6};
	cout<<s.findMedianSortedArrays(nums1, nums2);
    return 0;
}
