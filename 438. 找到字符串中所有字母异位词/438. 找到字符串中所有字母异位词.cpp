#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月16日下午4:55:49
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> need;
        unordered_map<char,int> win;
        for(auto c:p)
            need[c]++;
        int left=0,right=0,valid=0;
        vector<int> ans;
        while(right<s.size()){
            char c=s[right];
            if(need.count(c)){
                win[c]++;
                if(win[c]==need[c])
                    valid++;
            }
            //这里的while循环就涉及到一个区间的问题了。左闭右闭？
            while(right-left+1>=p.size()){//这里有没有=？
                if(valid==need.size())
                    ans.push_back(left);
                c=s[left];
                left++;
                if(need.count(c)){
                    if(win[c]==need[c])
                        valid--;
                    win[c]--;
                }
            }
            right++;//我知道了，模板中是将right++放在了上面，所以在while循环的时候就没有+1操作。
        }
        return ans;
    }
};
/*
 * 1.AC了！庆祝顺利会师！！！
 * 2.模板：https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/hua-dong-chuang-kou-ji-qiao-jin-jie
 *
 * */
int main(){

    return 0;
}
