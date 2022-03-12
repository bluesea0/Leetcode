#include <bits/stdc++.h>
using namespace std;
//@date: 2022-02-28  23:04
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        // 注：words中单词长度相同
        int nums = words.size();
        int len = words[0].size();
        unordered_map<string, int> mp1;
        for (auto w : words)
            mp1[w]++;
        // 判断所有子串
        vector<int> ans;
        for (int i = 0; i + nums * len <= s.size(); i++)
        { //判断每个i开头
            //这里需要加等号，因为可能正好和words中所有单词长度相同
            unordered_map<string, int> mp2;
            int j = i;
            for (j = i; j + len <= s.size(); j += len)
            { //表示从j开始截取一个len长度的word
                string str = s.substr(j, len);
                if (mp1.count(str))
                {
                    mp2[str]++;
                    if (mp2[str] > mp1[str])
                        break;
                }
                else
                    break;
            }
            if (j == i + nums * len)
                ans.push_back(i);
        }
        return ans;
    }
};
/*
1.这道题很难，不看题解根本没思路，代码还是按着评论区里给的写出来的。牛死了。得复习。
 滑窗+哈希，对每个子串判断，窗口相当于从i到末尾，并且统计窗口内的字符串，牛啊牛啊。学到了。
 
*/
int main()
{

    return 0;
}
