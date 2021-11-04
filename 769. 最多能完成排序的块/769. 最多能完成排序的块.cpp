#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月1日下午9:03:29
//这个我一看，那当然是不会了，没防出去啊。
//看了官方题解才明白思路，只需要检查前k个的最大值是否为k。如果是就+1可以切分。
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0,ma=0;
        for(size_t i=0;i<arr.size();i++){
            ma=max(ma,arr[i]);
            if(ma==i)ans++;
        }
        return ans;
    }
};
//AC了，但是并不光彩。

//12-22
//今天复习了一下，当然已经不会了。。。
int main(){

    return 0;
}
