#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-20
//class Solution {
//public:
//    vector<int> printNumbers(int n) {
//        long long x=pow(10,n);
//        vector<int> v;
//        for(int i=1;i<x;i++)//O(10^n)
//            v.push_back(i);
//        return v;
//    }
//};
/*
1.上面的AC了，其实我不知道这个题有什么意义？主要的考察点是什么呢？
2.原来是大数问题啊，我还是要学习一下的。
https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/solution/mian-shi-ti-17-da-yin-cong-1-dao-zui-da-de-n-wei-2/
全排列法+对首位0过滤
https://blog.csdn.net/qq_15711195/article/details/94651798
上面这个是C++版本的，
*/

//5-22
/*
 * 1.尝试一下如果是打印string的话。通过全排列来写。
 * */
class Try {
public:
    void printNumbers(int n) {
        vector<string> ans;
        string s="";
//        for(int i=1;i<=n;i++){
//        	printN(ans,s,i);
//        }
        printN(ans,s,n);//注意这里不需要for循环，因为n会一直调用下去直到字符串长度为n。
        //再将ans数组转换为int即可
        for(int i=0;i<(int)ans.size();i++){
        	cout<<ans[i]<<" ";
        	if(i%10==0)cout<<"\n";
        }
    }
    void printN(vector<string>& ans,string& s,int len){
    	if((int)s.size()==len){
    		ans.push_back(s);
    		return;
    	}
    	for(int i=0;i<10;i++){
    		s.push_back(i+'0');
    		printN(ans,s,len);
    		s.pop_back();
    	}
    }
};

int main(){
    Try t;
    t.printNumbers(2);
    return 0;
}
