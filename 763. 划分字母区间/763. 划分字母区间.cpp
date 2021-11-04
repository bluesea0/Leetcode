#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月11日下午3:52:45
//class Solution {
//public:
//    vector<int> partitionLabels(string S) {
//        //我的疑问是有可能给定一个字符串它不能分？
//        //abac，哦，明白了，每个都能分，都想让每个部分最短，但是最短不能让另一个子串中
//        //包含和之前一样的字母。
//        //有点难度啊。
//    }
//};
class Solution {
public:
    vector<int> partitionLabels(string S) {
        //使用贪心的思想，先遍历每次记录最后的位置
        vector<int> vec(26,-1);
        for(int i=0;i<S.size();i++)
            vec[S[i]-'a']=i;
        int end=-1,start=0;
        vector<int> ans;
        for(int i=0;i<S.size();i++){
            end=max(end,vec[S[i]-'a']);//我这种写法是错误的，我还是没理解
            if(end==i){//说明遍历到了正好
                ans.push_back(end-start+1);
                start=end+1;
            }
        }
        return ans;
    }
};
/*
 * 1.AC了，开心心。贪心算法+双指针。
 * */
int main(){
	Solution s;
	s.partitionLabels("ababcbacadefegdehijhklij");
    return 0;
}
