#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月3日下午3:29:12
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //这样的话就不必处理边界情况了。
    	//复杂度是O(n)O(1)。
        int i=0,j=int(numbers.size())-1;//强制类型转换是怎么做的来着？
        // high = numbers.size() - 1; 官方是直接-1的。
        while(i<j){
            int s=numbers[i]+numbers[j];
            if(s==target) return {i+1,j+1};
            else if(s<target)i++;
            else j--;
        }
        return {};
    }
};
//当然是非常简单的一道题了，easy题目。

int main(){

    return 0;
}
