#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月29日下午2:30:43
//class Solution {
//public:
//    int minimumEffortPath(vector<vector<int>>& heights) {
//        //看到了题目要求中有”最“这个关键词，就让人想到了dp，我觉得用dp是可以解的。
//        //但是为什么题目标签里有并查集？？？
//        int m=heights.size(),n=heights[0].size();
//        vector<vector<int>> dp(m,vector<int>(n,0));
//        for(int i=0;i<m;i++){
//            for(int j=0;j<n;j++){
//                if(i==0&&j==0)continue;
//                if(i==0){//第一行
//                    dp[i][j]=nums[i][j]-nums[i][j-1];//我这个想法是错误的，看了示例3之后
//                    //我默认为一个点来的方向只能上和左，但是其实可以是任何方向。
//                    //可以从下来的。
//                }
//            }
//        }
//    }
//};
/*
 * 1.二分，并查集两种解法，真的好牛，太牛了吧。
 * */


//2-1
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //使用二分法，判定性问题，判定最大经过的边为x时，左上右下两个是否能连通
        int left=0,right=1000000,m=heights.size(),n=heights[0].size();
        int dirX[]={0,0,1,-1},dirY[]={1,-1,0,0};
        while(left<right){
            //使用BFS判断连通性
            int mid=left+(right-left)/2;
            vector<int> visit(m*n,0);//使用i*m+j将二维数组转换为一维的数组
            queue<pair<int,int>> q;//表示i、j坐标
            q.push({0,0});
            visit[0]=1;
            while(!q.empty()){
                auto [x,y]=q.front();//可以这样初始化吗？
                q.pop();
                for(int i=0;i<4;i++){
                    int xx=x+dirX[i];
                    int yy=y+dirY[i];
                    if(xx>=0&&xx<m&&yy>=0&&yy<n&&visit[xx*n+yy]==0&&abs(heights[xx][yy]-heights[x][y])<=mid){
                        visit[xx*n+yy]=1;//表示已被访问过
                        q.push({xx,yy});
                    }
                }
            }
            if(visit.back()){//妈呀，要求最小，不是最大
                right=mid;
            }else left=mid+1;
        }
        return left;
    }
};
/*
 * 1.Yes,AC了，但是也是磕磕绊绊。时间复杂度O(logmn*logc).
 * 2.需要注意的点：如果将二维展开为一维的话，那么计算一维的坐标是xx*n+yy，确实是，一开始我想错了！
 *   如果是xx*m+yy的话那就是按列来求了，就不是这个用法了。绝了。
 *   还要总结一下queue和pair一起出现的时候的用法。
 * 3.明天写一下并查集写法。
 * */

//2-2
class Solution {
public:
    vector<int> fa;
    int minimumEffortPath(vector<vector<int>>& heights) {
        //保存边，根据边长排序，然后依次加入集合中，判断00和n-1 n-1是否连通，连通的话就返回当前
        //边的权重
        int m=heights.size(),n=heights[0].size();
        vector<tuple<int,int,int>> edges;//tuple是尖括号
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){//这里加入的算是单向边的
                if(i>0)edges.emplace_back(i*n+j,(i-1)*n+j,abs(heights[i][j]-heights[i-1][j]));
                if(j>0)edges.emplace_back(i*n+j,i*n+j-1,abs(heights[i][j]-heights[i][j-1]));
            }
        }
        //这个排序函数怎么写来着？
        auto cmp=[](const auto& a,const auto& b){//自定义函数，自定义类型即可。
            return get<2>(a)<get<2>(b);
        };
        sort(edges.begin(),edges.end(),cmp);
        fa.resize(m*n,0);
        for(int i=0;i<fa.size();i++)
            fa[i]=i;
        for(auto& [a,b,c]:edges){
            merge(a,b);
            if(connect(0,m*n-1))return c;
        }
        return 0;
    }
    void merge(int x,int y){//寻找并压缩路径
        int fx=find(x);
        int fy=find(y);
        if(fx==fy)return;
        fa[fx]=fy;
    }
    int find(int x){
        return fa[x]==x?x:(fa[x]=find(fa[x]));
    }
    bool connect(int x,int y){
        int fx=find(x);
        int fy=find(y);
        if(fx==fy)return true;
        return false;
    }
};
/*
 * 1.写了并查集版本的，这里用到了tuple来存储边，需要理解它的操作，以及cmp函数的写法。
 * 2.矩阵形成图的边权计算方法。
 * */
int main(){
	queue<pair<int,int>> q;
	q.push(1,2);
	q.push(make_pair(1,2));
	q.emplace(1,2);
    return 0;
}
