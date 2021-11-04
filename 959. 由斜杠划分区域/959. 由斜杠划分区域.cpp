#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月25日下午4:45:46
//class Solution {
//public:
//    int regionsBySlashes(vector<string>& grid) {
//        //好难啊，一看到这种题感觉好怪的题目，完全没有思路怎么说，
//        //我懂了，就把它看作是一个矩阵，判断连通区域的，dfs就可以。
//        //复杂度是O(N^2)
//        //不对，我想简单了，怎么说呢，它这个空间是抽象的空间，抽象的分布，难道还要同化一个矩阵
//        //来说明？我不懂了啊。
//
//        //看了题目tag，有并查集，这怎么并啊？？？
//    	//难为我胖虎，头发要掉完了。
//    }
//};
//看了题解觉得，太牛了，官方和grand两种不同的思路，先扩再合用BFS，扩2个；grand扩增像素点用dfs，扩3个。

class Solution {
public:
    int count=0;
    vector<int> fa;
    int regionsBySlashes(vector<string>& grid) {
        //其实我感觉最主要的难点就是扩展之后下标的控制了。
        //并查集的做法是找到每个扩展的方框后0的位置的下标
        //需要知道扩展后的总的空格个数以控制并查集。
        //分为格子内扩展和格子间扩展。
        //格子间扩展不需要条件，绝了，这个其实我没想到。
        int m=grid.size();
        count=4*m*m;
        fa.resize(count*count);//天哪这里该怎么初始化二维的表示呢？
        for(int i=0;i<fa.size();i++)
            fa[i]=i;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                int index=4*(i*m+j);
                if(grid[i][j]=='/'){
                    //合并0、3  1、2
                    merge(index,index+3);
                    merge(index+1,index+2);
                }else if(grid[i][j]=='\\'){
                    //合并0、1  2、3
                    merge(index,index+1);
                    merge(index+2,index+3);
                }else{
                    merge(index,index+1);
                    merge(index+1,index+2);
                    merge(index+2,index+3);
                }
                //格子间合并
                if(i+1<m)merge(index+2,4*(i*m+m+j));//合并2和下一个格子的0
                if(j+1<m)merge(index+1,4*(i*m+j+1)+3);//合并1和右边的3
            }
        }
        return count;
    }
    void merge(int i,int j){
        int fi=find(i);
        int fj=find(j);
        if(fi==fj)return ;
        fa[fi]=fj;
        count--;
    }
    int find(int x){return fa[x]==x?x:(fa[x]=find(fa[x]));}
};
/*
 * 1.哇啊哦，AC了，时间是O(n^2*logn)，空间是O(n^2)
 * 2.那么我来写一下按照补9格的思路
 * */
class Solution2 {
public:
    vector<vector<int>> matrix;//创建一个矩阵
    int regionsBySlashes(vector<string>& grid) {
        int m=grid.size();
        matrix.resize(3*m,vector<int>(3*m,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='/'){
                    matrix[i*3][j*3+2]=1;
                    matrix[i*3+1][j*3+1]=1;
                    matrix[i*3+2][j*3]=1;
                }else if(grid[i][j]=='\\'){
                    matrix[i*3][j*3]=1;
                    matrix[i*3+1][j*3+1]=1;
                    matrix[i*3+2][j*3+2]=1;
                }
            }
        }
        int res=0;
        for(int i=0;i<3*m;i++){
            for(int j=0;j<3*m;j++){
                if(matrix[i][j]==0){
                    dfs(i,j);
                    res++;
                }
            }
        }
        return res;
    }
    void dfs(int x,int y){
        if(x<0||y<0||x>=matrix.size()||y>=matrix.size()||matrix[x][y]==1)return;
        matrix[x][y]=1;
        dfs(x-1,y);
        dfs(x+1,y);
        dfs(x,y-1);
        dfs(x,y+1);
    }
};
/*
 * 1.这个dfs的思路快很多哎。但是这个复杂度怎么看呢？我不太会哎。那是O(9m^2)？
 * 2.正常来说，就是
 * */
int main(){

    return 0;
}
