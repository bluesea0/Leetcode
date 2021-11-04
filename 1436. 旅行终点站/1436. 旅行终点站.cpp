#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年10月1日下午8:32:00
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> setA;
        for(auto& p:paths){
            setA.insert(p[0]);
        }
        for(auto& p:paths){
            if(setA.count(p[1])==0)
                return p[1];
        }
        return "";
    }
};
/*
 * 1.这个题我一开始看到的时候没反应过来，还以为是图的题目，是否要建立图，然后遍历？觉得还挺麻烦。
 *   但是看了官方题解之后，原来是这样啊，哎还是自己功力不够！
 * */
int main(){

    return 0;
}
