#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年11月25日下午2:21:44
class Solution {
public:
    string sortString(string s) {
        //思路：对字符串遍历模拟过程，
        //首先对字符串从小到大排序？要用哈希？将重复的部分抽出来？反过来进行排序。
        //复杂度O(Cnlogn)m是重复的次数，nlogn是排序复杂度，n最大也只是26.
        // 空间是O(c)，当然也有排序所需的O(logn)
        //以后都要先分析完思路+复杂度之后再写代码，这样真的更专业
        unordered_map<char,int> um;
        for(auto c:s)
            um[c]++;
        string ans="";
        bool flag=true;//默认开始是升序
        while(true){
        	string temp="";
            for(auto& p:um){//maya，需要引用啊!
                if(p.second!=0){
                    temp+=p.first;
                    p.second--;//难道这个并不能改变？
                }
            }
            if(temp.size()==0)return ans;//说明全都访问过了
            if(flag)//这里我怎么if(bool)了，有病病？
                sort(temp.begin(),temp.end());
            else
                sort(temp.begin(),temp.end(),greater<char>());
            cout<<temp<<endl;
            flag=!flag;//转换？？？？bool=!bool;有病病
            ans+=temp;
        }
    }
};
/*
1.分析leetcode，
 c=1,d=1,e=3,l=1,o=1,t=1
 cdelotee
2.看这道题真的感觉傻逼逼说的就是我吧，怎么就把排序都放到for循环里了？
3.上面的AC了，我目前觉得这道题easy以上，medium未满。
4.官方题解给出的是：桶计数。看了官方题解我才知道我是弱智呜呜呜。
  因为只包含字符串，所以直接建立桶，正反遍历放入。学到了。
*/

//12-20
class Solution {
public:
    string sortString(string s) {
        vector<int> occ(26,0);//记录对应字符出现的次数
        for(auto c:s)
            occ[c-'a']++;
        string ans="";
        while(ans.size()<s.size()){//天哪，有这个循环复杂度怎么算嘛！
            for(int i=0;i<26;i++){
                if(occ[i]==0)continue;
                ans+=(i+'a');//也可以换成push_back
                occ[i]--;
            }
            for(int i=25;i>=0;i--){
                if(occ[i]==0)continue;
                ans+=(i+'a');
                occ[i]--;
            }
        }
        return ans;
    }
};
/*
 * 1.AC了。时间：复杂度我不会算啊
 * 2.通过这道题，我发现我已经培养了对输入只有小写字符串的题目的直觉！就是用vector<int> occ(26,0)！
 *   来代替哈希，绝了！
 * 3.看了一下题解，原来正宗的说法是，桶计数啊
 * 4.   for (char &ch : s) {
            num[ch - 'a']++;
        }//题解的for循环用的是引用啊，学到了。
   5.绝了，看了官方给的复杂度分析：O(|C||s|)，其中C表示字符集中，字符中的个数，|s|为字串长度。
     它考虑的是最坏的情况，是所有字符都是同一个，那么就得来回地遍历！绝了绝了！直呼绝了！
 * */
int main(){
	Solution s;
	cout<<s.sortString("rat");
//	string a="bca";
//	sort(a.begin(),a.end(),greater<char>());//cba
//	cout<<a;
    return 0;
}
