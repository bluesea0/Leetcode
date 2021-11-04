#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月10日下午3:13:26
//class Solution {
//public:
//    int subarraysWithKDistinct(vector<int>& A, int K) {
//        //思路：O(n^2)
//        int left=0,right=0,ans=0;
//        //unordered_set<vector<int>> us;
//        //是ok的吧
//        unordered_map<int,int> um;
//        while(right<A.size()){
//            char c=A[right];
//            if(um.size()==K&&um.count(c)==0){//==0是为了保证最长
//                //缩小left
//                while(um.size()==K){
//                    ans++;
//                    cout<<left<<" "<<right-1<<endl;
//                    if(--um[A[left]]==0)um.erase(A[left]);
//                    left++;
//                }
//            }
//            um[c]++;
//            right++;
//        }
//        while(um.size()==K){//说明还有未移除的
//            ans++;
//            if(--um[A[left]]==0)um.erase(A[left]);
//            left++;
//        }
//        return ans;
//    }
//};
/*
 * 1.我本来是上面写的，但是第一个样例A = [1,2,1,2,3], K = 2都不对，发现了是因为这样只是在右边界确定的情况
 *   下，缩小左边界，但是右边界小的时候满足条件的都没计算在内。
 * 2.将问题转换为：最多包含K个不同的字符-最多包含k-1不同的字符=恰好包含k个不同的字符，res += right - left
 * 3.
 * */
int main(){

    return 0;
}
