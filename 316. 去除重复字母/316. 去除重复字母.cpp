#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月15日下午6:33:57
class Solution {
public:
    string removeDuplicateLetters(string s) {
        //卧槽，这个也太难了吧，虽然说和402题相似，但是也不同啊，这里你想要判断去重，这个就是个
        //大问题，如果使用栈的话，那么对样例1，bca，又来b，那这样就是要去除后面的b啊，
        //去除第一个b就是cab，去除后面的b，bac，明显是要去除后面的b如果从当前来考虑。

        //先统计重复字母的出现次数，然后再顺序遍历+栈来存储
        //问题是，对于样例2，第3个c进入队列的时候如何判断第2c是否在，如何判断是否已经有c进入了呢
        //这里选择一个bool数组来判断？
        unordered_map<char,int> count;
        unordered_map<char,int> visit;//这个改为一个set啊！！！
        for(auto c:s){
            count[c]++;
        }
        for(auto m:count){//怎么遍历map来着？
            visit[m.first]=0;//记录是否存在队列当中
//            cout<<m.first<<" "<<m.second<<endl;
        }
        vector<char> st;//完全可以用vecotr来模拟栈
        for(auto c:s){
            // char back=st.back();//这里还真不能这么定义，因为每次pop_back之后back指针都会变的
            while(st.size()>0&&c<st.back()&&count[st.back()]>1&&visit[c]==0){
//                cout<<st.back()<<endl;
                visit[st.back()]=0;
                count[st.back()]--;
                st.pop_back();
            }
            if(visit[c]==0){
                st.push_back(c);
                visit[c]=1;
            }else count[c]--;//针对bbcaac这种连续的b样例
        }
        string ans="";
        for(auto c:st){
            ans+=c;//char怎么加入到string里的来着？
        }
        return ans;
    }
};
/*
 * 1.YesAC了！时间是O(n)，空间为O(n)，是有限的。
 * 2.visit可以设置为一个set啊。
 * 3.看了官方题解，绝了啊，为什么我写的这么麻烦呢！人家真是牛批，记录last_occurrence这个数组，牛批！
 * */

//11-18
/*
 * 1.再看一遍官方解答，牛批，它的版本是O(n)，没有使用哈希表记录次数，而是使用的向量来记录最后一次
 *   出现的位置；队列中只保存没有重复的，学到了。下次复习需要手写一下！
 * */

//12-20
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> occ;
        for(auto c:s)
            occ[c]++;
        vector<char> stk;
        vector<int> v(26,0);
        for(char c:s){
            if(v[c-'a']==1){//这里一进来就要给它个判断，已经出现过的就没有资格被遍历了。
                occ[c]--;
                continue;
            }
            while(stk.size()!=0&&c<stk.back()&&occ[stk.back()]>1){
                occ[stk.back()]--;
                v[stk.back()-'a']=0;
                stk.pop_back();
            }
            v[c-'a']=1;
            stk.push_back(c);
        }
        string ans;
        for(auto c:stk)
            ans+=c;
        return ans;
    }//我这个思路还真错了啊！"abacb"，这个样本应该输出的是abc，我这种方法输出的是acb
    //因为第二个a让第一个b弹出了。
};
/*
 * 1.天哪，AC了，我太帅了！
 * 2.我的天哪，原来string就有push_back和pop_back()，学到了！我这里再用vector那可不就是多此一举啊！
 * */

//2-17
/*
 * 1.visit[i]=1表示当前的字符已经被放到最终位置了，就不操作它了，如果没有的话，它肯定之后还会被弹出的
 *   理解了这一点，对本题有很大的帮助
 * */
int main(){
	Solution s;
	cout<<s.removeDuplicateLetters("cbacdcbc");
    return 0;
}
