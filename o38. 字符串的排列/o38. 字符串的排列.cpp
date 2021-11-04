#include <iostream>
#include<vector>
#include<queue>
#include<cstring>//这里也包含strlen。
#include <map>
#include<unordered_set>
using namespace std;
//10-10
/*
1.我记得这个有两种解法，一种是DFS，另一种是交换法，我觉得交换法可能更好，我今天写一下交换法。
2.最终解法是通过map来实现的，那么我再试一下通过set呢？好麻烦，之后再说吧，有机会再写一下
 通过DFS和set。
*/
class Solution {
private:
    void permu(int index,vector<string>& ans,string &s){//我真的对这个控制不太理解。
        if(index==s.size()){
            //难道还要建个中间变量再放进去？
            ans.push_back(s);//这里又有一个问题char数组如何转换为string呢？
            return;
        }
        map<char,int> mp;//所以这里是在当前定义
        for(int i=index;i<s.size();i++){
            //C++中string可以通过下标访问吗？应该要转换为char数组
//            if(i!=index && s[i]==s[index]) continue;
            if(mp.count(s[i])) continue;
            else mp.insert(pair<char,int>(s[i],1));
            char t=s[i];//C++中难道就没有更快的交换值的方法了吗？
            s[i]=s[index];
            s[index]=t;//一定要注意这里是index+1啊。。。
            permu(index+1,ans,s);
            //再交换回来。。。。真是麻烦啊。
            t=s[i];
            s[i]=s[index];
            s[index]=t;
        }

    }

public:
    vector<string> permutation(string s) {
        vector<string> ans;
        permu(0,ans,s);//返回char*
        return ans;
    }
};
/*没有AC.
上面通过我的if判断输出结果：
abc
acb
bac
cba
说明根本就没起到去重的效果，这是为什么呢？我看了人家的代码忽然想到人家判重都是用dict的，这种真的
不行吗？

递归调用层次：
如果内部使用permu(i+1,ans,s)的调用过程：
(0,[],abc):
index=0,i=0,abc://a和a自己交换
    (1,[],abc):
    index=1,i=1,abc://b和b自己交换
        (2,[],abc):index=2,i=2,abc://c和c自己交换
            (3,[abc],abc)
            返回 //再次调用函数，通过递归条件返回
        返回////for循环结束return
    index=1,i=2,acb://b和c交换         注：在这里实际上就出现了差别，在这里应该调用(2,[abc],acb)，但之后是b和b位置交换，结果没产生不同
        (3,[abc],acb)
        返回 //调用函数，通过递归条件返回
    交换回来abc
    返回//for循环结束return
index=0,i=1,bac://交换a和b
    (1,[abc,acb],bac):
    index=1,i=1,bac://交换a和a
        (2,[abc,acb,bac],bac)//
		index=2,i=2,bac://交换c和c
			(3,[abc,acb,bac],bac)
			返回  ////调用函数，通过递归条件返回
		返回 //for循环结束return
	交换回来bac
	index=1,i=2,bac://交换a和c
		(3,[abc,acb,bac],bca):
		返回  ////调用函数，通过递归条件返回
	交换回来bca
	返回 //for循环结束return  至此结果中包含：[abc,acb,bac,bca]
index=0，i=2，bca：//交换b和a
///啊啊啊啊我分析不出来了，绝了绝了，我崩溃了，我脑内的cpu宕机了，反正就记住内部调用的时候是index+1，不是
 * i+1就好了，实在是这个分析过程太难了，我放弃了。
 * 为什么选择index+1递归，可以这么理解，因为是选择index及其后面任意一个数和index进行了交换，意思是
 * 目前只处理到了index，那么后面的函数该处理index+1部分了。
*/
/*
1.但是提交了之后和python卡在了同样的样例上，"kzfxxx"，因为这个重复的太多无法处理了吧。
所以还是用字典比较合适。
*/

//10-26今天复习再写一下吧。
class Solution2 {
public:
	vector<string> ans;
    vector<string> permutation(string s) {
    	//忽然脑子一片空白。。。
    	per(0,s);
    	return ans;
    }
    void per(int index,string s){
    	if(index==s.size()){//我写的时候是怎么回事？脑子不在线吗，编译报了好多错误。
    		ans.push_back(s);
    		return;
    	}
    	unordered_set<char> st;
    	for(int i=index;i<s.size();i++){
    		if(st.count(s[i])!=0)continue;
    		st.insert(s[i]);

    		swap(s[i],s[index]);
    		per(index+1,s);
    		swap(s[i],s[index]);
    	}
    }
};
/*
 * 1.Yes!AC了！应该基本上掌握了这道题吧？
 * 2.https://blog.csdn.net/qq_15711195/article/details/96746659
 *   上面这个链接中给出来的解答，控制去重用的是vector插入时查询判断、使用set存储答案。
 * */

//5-23
/*
 * 1.经过我观察评论区的解法，有两种：
 *  ①使用set来记录重复，并且递归后有swap回去的步骤；
 *  ②直接使用if(start!=i&&s[i]==s[start])continue;条件来判断是否重复，但是没有swap的过程。
 *  这两种方法都完全可以AC，第一种方法代码如上，第二种方法代码如下：
 * */
class Solution {
public:
    vector<string> ans;
    vector<string> permutation(string s) {
        //复杂度怎么计算呢？
        sort(s.begin(),s.end());
        helper(s,0);
        return ans;
    }
    void helper(string s,int start){
        if(start==s.size()){
            ans.push_back(s);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(start!=i&&s[i]==s[start])continue;//排除重复的字母
            swap(s[i],s[start]);
            helper(s,start+1);
            //swap(s[i],s[start]);
        }
    }
};
/*
 * 3.经过我的理解是，第一种是比较宏观的过程，宏观来记录是否重复，所以是正常的全排列的过程，有swap也有swap回去
 *   ，这是在没有重复的情况下，可以参考lc46题。
 *  然而如果是针对有重复的情况，在交换的过程中来判断的话，就不必swap回去了，这个怎么说我不好解释，但你记住
 *  在有重复元素时这两种就好了，要么用set+正常，要么判断+不swap回来+函数传值，当然通过判断的话，还要sort！
 *  所以就还是直接用set好了，而且是局部set，不是全局set。
 * 4.关于上面的复杂度的计算：O(N*N!)N的阶乘级别的。其中N！是形成各个结果的时间，N是复制到ans中的时间。
 * */

//6-11
/*
 * 1.所以我今天又来总结了，对于全排列问题，如果没有重复数字，那么dfs和swap方法都好说，没什么难点，
 *   但是针对存在重复数字的，排序后dfs就用个vis数字来去重，swap用是否和index相等来去重，并且不能
 *   交换回来，否则去重失效。当然也可以用set，只不过效率不高。
 * */
class Solution {
public:
    vector<int> vis;
    vector<string> ans;
    vector<string> permutation(string s) {
        //写一下dfs版本
        vis.resize(s.size(),0);
        sort(s.begin(),s.end());
        string str;
        dfs(s,str);
        return ans;
    }
    void dfs(string& s,string& path){
        if(path.size()==s.size()){
            ans.emplace_back(path);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(vis[i]||(i>0&&s[i]==s[i-1]&&vis[i-1]==0))continue;
            path.push_back(s[i]);
            vis[i]=1;
            dfs(s,path);
            path.pop_back();
            vis[i]=0;
        }
    }
};
/*
 * 1.全排列就先考虑dfs就ok。
 * */
int main(){
    Solution2 s;
    string ss="abc";
//    cout<<s.permutation(ss);//啊，向量不能直接输出！
    vector<string> re=s.permutation(ss);
    for(int i=0;i<re.size();i++){
        cout<<re[i]<<endl;
    }
    return 0;
}
