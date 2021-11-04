#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年9月21日下午10:57:01
class Solution {
public:
    int longestSubstring(string s, int k) {
        int res=0;
        for(int i=1;i<=26;i++){
            int left=0,right=0,ct=0;//ct记录当前窗口字符串的种类数
            vector<int> chars(26,0);//记录范围内的字符个数
            while(right<s.size()){
                bool flag=true;//每次窗口变动的时候都要判断
                chars[s[right]-'a']++;
                if(chars[s[right]-'a']==1)ct++;
                right++;
                while(ct>i){//当前种类超过了最多的种类数
                    chars[s[left]-'a']--;
                    if(chars[s[left]-'a']==0)ct--;
                    left++;
                }
                //判断窗口内是否有不符合条件的
                for(int j=0;j<26;j++){
                    if(chars[j]>0&&chars[j]<k){
                        flag=false;break;
                    }
                }
                if(flag)res=max(res,right-left);
            }
        }
        return res;
    }
};
/*
 * 1.参考grand的写来来的，首先枚举滑窗内能有的字符种类的值，然后滑窗内根据这个去遍历。
 *   其实我不是很明白这个原理。滑窗内要记录有多少种字符符合要求，即计数>k的。
 * 2.如果是正常思路的话，就需要枚举每一个字符串，是n2级别的，并且统计滑窗内的字符种类及个数。
 * */
int main(){

    return 0;
}
