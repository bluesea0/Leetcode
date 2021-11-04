#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月8日下午2:01:50
//class Solution {
//public:
//    vector<int> ans;
//    vector<int> splitIntoFibonacci(string S) {
//        //思路：回溯，切分两个数，分别判断。
//        //复杂度怎么分析？我不会啊，回溯要用二叉树吗？log？斗胆O(n^2)一下
//        if(S.size()<=2) return ans;
//        //DFS的话这个外面有for循环吗？参数是什么？
//        //调用dfs的外面肯定要有层for循环的吧？
//        //传递剪切好的字符串还是传递下标呢？
//        //如何实现剪切s3？
//        //这是为什么呢，我明明有思路，但是在代码实现上我写不出来。
//        //那岂不是s1要用一个函数剪切，s2也要用一个函数剪切？
//        //我跪了。
//    }
//};
/*
 * 1.思路就是这么个思路，但是写不出来啊，我记得之前做过一道非常像的！
 * 2.看了grand和官方题解，觉得人家真牛皮。//相似题目306、17、93
 * */

//12-22
/*
 * 1.看到这种题的感受就是头疼，想离婚！但是我相信这种题目是有套路的，只不过我不知道这个套路怎么解决。
 * 2.这道题要考虑的情况实在是多，非得手动运行几个例子你才能真的理解。
 * 3.对可切割的部分做遍历，传入的参数包括当前组成的结果，还要传入start，递归调用前将本轮的加入，之后
 *   再pop，这就是典型的递归啊！
 * */

//12-23
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> out,ans;
        dfs(S,0,out,ans);
        return ans;
    }
    void dfs(string s,int start,vector<int>& out,vector<int>& ans){
        if(!ans.empty())return;//为什么要加这一句呢？//样例分析：123
        //需要有上一句，因为它并不是要求返回所有的结果，只要找到一个就ok
        //这个也相当于一个剪枝的操作。如果是要返回所有的结果，那么就无需这一句了。

        if(start>=s.size()&&out.size()>2){//这里要注意out的长度，否则它会有全部都分到一起的情况，或者只有两个元素。
            ans=out;return;
        }
        for(int i=start;i<s.size();i++){
            string str=s.substr(start,i-start+1);
            if(str.size()>1&&str[0]=='0')break;//如果长度>1且开头是0，那么就break掉
            //不必要再进行遍历了。
            long long cur=stol(str);
            if(cur>INT_MAX)break;//超过整型范围就退出循环
            int len=out.size();
            if(len>1){
                if(cur<(long)out[len-1]+out[len-2])continue;//这里要转换为long吗？
                //signed integer overflow: 2 + 2147483647 cannot be represented in type 'int'，应该就是因为右边相加超过了int的表示范围，所以需要转换为long
                if(cur>(long)out[len-1]+out[len-2])break;
            }
            out.push_back(cur);
            dfs(s,i+1,out,ans);
            out.pop_back();
        }
    }
};//哇啊哦，AC了，那么复杂度如何分析呢？完全不会分析这类回溯剪纸的，考虑最坏的情况，
//那么就是？？想象不出来。
/*
 * 1.O(nlog^2C)，因为只有前两个数是需要确定的，并且在整型范围内，它的长度不应该超过log10C。
 * */
int main(){

    return 0;
}
