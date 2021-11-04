#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年5月22日上午8:46:39
class Solution {
public:
    string replaceSpace(string s) {
        if(s.empty())return s;
        int start=0;
        string news="";
        while(s.find(" ",start)!=string::npos){
            int t=s.find(" ",start);
            news+=s.substr(start,t-start)+"%20";
            start=t+1;
        }
        news+=s.substr(start);//这里说明，substr是默认取到末尾的，如果start超过了长度，就不做操作。
        return news;
    }
};
/*
 *1.
 * */
//评论区的解法：
class Solution {
public:
    string replaceSpace(string s) {     //字符数组
        string array;   //存储结果

        for(auto &c : s){   //遍历原字符串
            if(c == ' '){//遇到空格字符的话，就放入两个%20。
                array.push_back('%');//void push_back (char c);函数原型，只能push进去char。
                array.push_back('2');
                array.push_back('0');
            }
            else{
                array.push_back(c);
            }
        }
        return array;
    }
};
int main(){

    return 0;
}
