#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月12日下午3:01:14
//class Solution {
//public:
//    int openLock(vector<string>& deadends, string target) {
//        //思路：BFS，从0000开始进入队列，并记录步数。
//        queue<string> q;
//        unordered_set<string> set;
//        for(auto d:deadends)
//            set.insert(d);//不是insert？
//        int ret=0;
//        q.push("0000");//这样写超时了怎么办？第二个样例就超时了。。。哭泣。不会了。
//        while(!q.empty()){
//            int len=q.size();
//            while(len--){
//                string top=q.front();q.pop();
//                if(top==target) return ret;
//                //对每一位都上调下调
//                for(int i=0;i<4;i++){
//                    string u=up(top,i);
//                    if(set.count(u)==0)q.push(u);
//                    string d=down(top,i);
//                    if(set.count(d)==0)q.push(d);
//                }
//            }
//            ret++;
//        }
//        return -1;
//    }
//    string up(string s,int index){
//        if(s[index]=='9')
//            s[index]='0';
//        else
//            s[index]=(s[index]-'0'+1)+'0';
//        return s;
//    }
//    string down(string s,int index){
//        if(s[index]=='0')
//            s[index]='9';
//        else
//            s[index]=(s[index]-'0'-1)+'0';
//        return s;
//    }
//};//超时了，凉凉。
/*
 * 1.oh我的天，怪不得我第二个样例都没通过，因为它会返回的啊，0000->1000，但是在处理1000的时候down
 *   会变为0000这样就重复了。。。。傻了吧。
 * */
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        //思路：BFS，从0000开始进入队列，并记录步数。
        queue<string> q;
        unordered_set<string> set;
        unordered_set<string> visit;
        for(auto d:deadends)
            set.insert(d);//不是insert？
        int ret=0;
        q.push("0000");//
        if(set.count("0000"))return -1;
        visit.insert("0000");//这样就忽略了0000可能在deadends中啊！！！
        while(!q.empty()){
            int len=q.size();
            while(len--){
                string top=q.front();q.pop();
                if(top==target) return ret;
                //对每一位都上调下调
                for(int i=0;i<4;i++){
                    string u=up(top,i);
                    if(set.count(u)==0&&visit.count(u)==0){
                        q.push(u);
                        visit.insert(u);
                    }
                    string d=down(top,i);
                    if(set.count(d)==0&&visit.count(d)==0){
                        q.push(d);
                        visit.insert(d);
                    };
                }
            }
            ret++;
        }
        return -1;
    }
    string up(string s,int index){
        if(s[index]=='9')
            s[index]='0';
        else
            s[index]=(s[index]-'0'+1)+'0';
        return s;
    }
    string down(string s,int index){
        if(s[index]=='0')
            s[index]='9';
        else
            s[index]=(s[index]-'0'-1)+'0';
        return s;
    }
};
/*
 * 2.我的天，AC了，不容易啊。。。
 * 3.还有双向BFS？这道题没有办法用吧？卧槽，居然可以，那从target也转换？但是你怎么知道两者不是越转
 *   距离越远呢？
 * 4.蛮厉害的，需要用到两个集合，来判断当前扩散的是否在对方的集合里，如果在说明可以扩展到。
 * */

//11-18
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        //思路：BFS，从0000开始进入队列，并记录步数。
        unordered_set<string> dead,visit;
        unordered_set<string> us1({"0000"}),us2({target});
        for(auto d:deadends)
            dead.insert(d);
        if(dead.count("0000"))return -1;
        if(target=="0000") return 0;//我这么写就需要额外的判断，因为一进for循环就会直接操作更改了
        int ans=0;
        while(!us1.empty()){
            if(us1.size()>us2.size()){
                auto t=us1;
                us1=us2;
                us2=t;
            }
            unordered_set<string> us3;
            for(string pwd:us1){
                for(int i=0;i<4;i++){
                    string u=up(pwd,i);
                    if(dead.count(u)==0){
                        if(us2.count(u)) return ans+1;
                        if(visit.count(u)==0){
                            us3.insert(u);
                            visit.insert(u);
                        }
                    }
                    string d=down(pwd,i);
                    if(dead.count(d)==0){
                        if(us2.count(d)) return ans+1;
                        if(visit.count(d)==0){
                            us3.insert(d);
                            visit.insert(d);
                        }
                    }
                }
            }
            us1=us3;
            ans++;
        }
        return -1;
    }
};
/*
 * 1.双向BFS我是这么完成的，和教程里不一样，教程里是遍历的时候就会判断是否重合，或者是是否在dead中
 *   的都会放进set里，而我由于想控制空间的使用大小，因为dead是在500范围内？那也不多？所以就多了不少
 *   重复的代码。
 *   https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/bfs-kuang-jia
 *   觉得这个教程写的蛮不错的，先不着急不让dead进入，更加简洁。
 * 2.像127题，应该不能先入再判断，因为允许的字母是少的，经过26个字母变换会占用更多的空间，不划算？
 * */
int main(){

    return 0;
}
