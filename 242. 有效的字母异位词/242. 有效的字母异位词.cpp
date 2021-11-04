#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月22日下午10:24:48
class Solution {
public:
    bool isAnagram(string s, string t) {
        //分别建立两个hash，然后比较两个哈希是否相同
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> ms;
        for(auto c:s)
            ms[c]++;//这样肯定是从0开始加的啊
        for(auto c:t){
            if(ms.count(c)==0)return false;
            ms[c]--;
        }
        //再遍历ms中每个关键字是否都为0
        for(auto m:ms){
        	if(m.second!=0)return false;
        }
        return true;
        //天哪怎么判断呢，比较关键字都相同，而且如何同时遍历两个map？我跪了。
        //也不能只建立s的哈希，然后用t去判断，因为可能不在其中？那就直接返回啊
    }
};
/*
 * 1.AC了，一开始我真是个憨批，怎么说呢，我去判断first是否为0？绝了。first是关键字啊。
 * */

//12-20
/*
 * 1.今天复习才注意到还有进阶，如果是Unicode字符怎么办，它可能一个字符对应多个字节，也就是一个字节
 *   表示不了字符，可能要两个字节,2^16那种来表示，所以就需要用哈希表来表示。
 * 2.下次复习要重写一下代码，我这个太丑了。
 * */
int main(){
	Solution s;
	cout<<s.isAnagram("anagram", "nagaram");
    return 0;
}
