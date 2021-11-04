#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��9��19������1:12:00
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char,char> mp;
        mp[']']='[';
        mp['}']='{';
        mp[')']='(';
        for(auto& c:s){
            if(mp.count(c)==0)
                stk.push(c);
            else if(!stk.empty()&&stk.top()==mp[c]){
                stk.pop();
            }else return false;
        }
        return stk.empty();
    }
};
//�Ƚϼ򵥣�ע�⺯���ĵ��á�
int main(){

    return 0;
}
