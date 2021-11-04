#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年10月27日下午9:49:31
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)return "";
        string ans=strs[0];
        for(int i=1;i<strs.size();i++){
            int j=0,k=0,count=0;
            while(j<ans.size()&&k<strs[i].size()&&ans[j]==strs[i][k]){
                j++;
                k++;
                count++;
            }
            if(count==0)return "";
            else ans=ans.substr(0,count);
        }
        return ans;
    }
};
/*
 * 1.虽然这是个easy级别的题目，但是感觉写起来好不规整啊这个代码，不漂亮。
 *   复杂度的话，假设平均长度为m，共有n个字符串，那么在最坏情况下，就是所有字符串都一样，那么就是O(mn)
 * 2.评论区看到一种说法是，排序后求最大最小，那可以一次遍历获取到最大最小，然后比较。
 * */
int main(){

    return 0;
}
