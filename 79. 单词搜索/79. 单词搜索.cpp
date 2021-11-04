#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年5月22日上午11:18:34
class Solution {
public:
    int dirX[4]={0,0,-1,1},dirY[4]={1,-1,0,0};//定义为成员变量的时候它不会推断的大小，需要填写数组的具体大小
    //否则会报错。
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]&&dfs(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board,string word,int x,int y,int k){
        if(k==word.size())return true;//这个应该放到最前面，否则都会返回false了。
        if(x<0||y<0||x>=board.size()||y>=board[0].size()||board[x][y]!=word[k])
            return false;

        char c=board[x][y];
        board[x][y]='#';
        for(int i=0;i<4;i++){
            int xx=x+dirX[i];
            int yy=y+dirY[i];
            if(dfs(board,word,xx,yy,k+1))
                return true;
        }
        board[x][y]=c;
        return false;
    }
};
/*
 * 1.在牛客中要自己测试输入。
 * */
int main(){

    return 0;
}
