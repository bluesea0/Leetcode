#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月24日下午1:23:35
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        //但是计算斜率不需要浮点运算的吗？这怎么办？
        for(int i=1;i<coordinates.size();i++){//这里要从1开始，因为如果从0开始的话，0就会被更改为[0,0]
        	//后面的计算就没有意义了。
            coordinates[i][0]-=coordinates[0][0];
            coordinates[i][1]-=coordinates[0][1];
        }
        int A=coordinates[1][1],B=-coordinates[1][0];
        for(int i=2;i<coordinates.size();i++){
            if(A*coordinates[i][0]+B*coordinates[i][1]!=0)
                return false;
        }
        return true;
    }
};
/*
 * 1.这个其实我一开始并不会的，是涉及到数学的知识。两点法表示？一开始相同的计算k，但是那样涉及到除法，浮点数
 *   的运算就比较难。
 * */
int main(){
	Solution s;
	vector<int>
	cout<<s.checkStraightLine(coordinates);
    return 0;
}
