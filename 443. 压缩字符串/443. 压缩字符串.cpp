#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年10月29日下午4:28:29
class Solution {
public:
    int compress(vector<char>& chars) {
        int index=0,n=chars.size(),start=0;
        for(int i=0;i<n;i++){
            if(i!=n-1&&chars[i]==chars[i+1])continue;
            if(i==start){//说明只有一个字符出现
                chars[index++]=chars[i];
                start++;//["a","a","a","a","a","b"]
                //说明这里仍然需要操作的
            }else{
                string t=to_string(i-start+1);
                chars[index++]=chars[i];
                for(int i=0;i<t.size();i++){
                    chars[index++]=t[i];
                }
                start=i+1;
            }
        }
        return index;
    }
};
/*
 * 1.AC了，但是仍然需要复习，写的时候还是走了些弯路，不知道是不是最优解。
 *   看了题解，觉得我写的很不错！还挺整洁的！开心！很棒！
 * */
int main(){

    return 0;
}
