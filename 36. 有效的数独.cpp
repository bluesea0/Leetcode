#include <bits/stdc++.h>
using namespace std;
//@date: 2022-03-13  22:40 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(9,vector<int>(10,0)),cols(9,vector<int>(10,0));
        //用vector定义三维数组总的来说不太好，所以还是用数组吧直接
        int square[3][3][10];
        memset(square,0,sizeof(square));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int no=board[i][j]-'0';
                    rows[i][no]++;
                    cols[j][no]++;
                    square[i/3][j/3][no]++;
                    if(rows[i][no]>1||cols[j][no]>1||square[i/3][j/3][no]>1)
                        return false;
                }
            }
        }
        return true;
    }
};
/*
1.关键的点是三维数组的定义，以及初始化，memset函数。
*/
int main()
{
   
   return 0;
}
