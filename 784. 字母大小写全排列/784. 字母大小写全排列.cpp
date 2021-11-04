#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年6月11日下午7:07:04
class Solution {
public:
    vector<string> ans;
    vector<string> letterCasePermutation(string s) {
        //dfs的方法
        string str;
        helper(s,str,0);
        return ans;
    }
    void helper(string& s,string& path,int index){
        if(index==(int)s.size()){
            if(path.size()==s.size())
                ans.push_back(path);
            return;
        }
        for(int i=index;i<(int)s.size();i++){
            if(s[i]>='0'&&s[i]<='9'){
                path.push_back(s[i]);
                helper(s,path,i+1);
                path.pop_back();
            }else{
                char c=s[i];
                path.push_back(tolower(c));
                helper(s,path,i+1);
                path.pop_back();
                path.push_back(toupper(c));
                helper(s,path,i+1);
                path.pop_back();
            }
        }
    }
};
/*
 * 1.AC了，但是我感觉我写的怎么这么垃圾？到底时哪里出了问题？
 * 2.天哪，我终于懂了，完全不用什么for循环的啊，每次调用一次dfs就会去处理一位，太难了，而不用for去控制
 *   每一位，for的作用是什么呢？是导致有的有，有for循环和没有for循环有什么区别呢？有的话会生成各种长度的
 *   这是为什么呢？一定要搞清楚for这里是什么作用，不然下次肯定分不清，之前全排列需要有循环每一位。
 *
 * */
class Solution {
public:
    vector<string> ans;
    vector<string> letterCasePermutation(string s) {
        //dfs的方法
        helper(s,0);
        return ans;
    }
    void helper(string& s,int i){
        if(i==(int)s.size()){
            ans.push_back(s);
            return;
        }
        if(s[i]>'9'){
            s[i]=tolower(s[i]);
            helper(s,i+1);

            s[i]=toupper(s[i]);
            helper(s,i+1);
        }else helper(s,i+1);
        // for(int i=index;i<(int)s.size();i++){
        //     if(s[i]>'9'){//因为最后是2不是字母，所以没有进入函调用种。
        //         s[i]=tolower(s[i]);
        //         helper(s,i+1);

        //         s[i]=toupper(s[i]);
        //         helper(s,i+1);
        //     }else helper(s,i+1);
        // }
    }
};
/*
 *dfs(a1b2,0):dfs(a1b2,1):dfs(a1b2,2):dfs(a1b2,3)
 *                        dfs(a1B2,3):dfs(a1B2,3)
 *            dfs(a1b2,2):dfs(a1b2,3)
 *            dfs(a1B2,2):
 *通过上面的分析可以看出，如果对每一位处理，那么之前在递归时已经处理过了，上层循环再遍历到该位的时候仍然
 *还会再处理一遍，比如说i=1时往后递归i=2被处理了，那么返回后，i=2还会被处理，所以出现重复。
 *2.这个并不是全排列问题，全排列需要字母位置发生变化，这里并不需要，只是大小写字母转换一下，在每位上
 * 做一个操作。不是全排列哦。
 * */
int main(){

    return 0;
}
