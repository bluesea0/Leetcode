#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-10
/*
1.DFS解法马上就能想到的。
*/
class Solution {
private:
    bool fun(int m, int n, int k){
        int s=0;
        while(m){s+=m%10;m/=10;}
        while(n){s+=n%10;n/=10;}
        return s<=k;
    }
    void dfs(int m, int n, int k,int& ans,vector<vector<bool>>& visit){//真的不确定二维数组怎么传递
        ans+=1;
        visit[m][n]=true;
//        int x[]={0,0,1,-1},y[]={-1,1,0,0};
        int x[]={0,1},y[]={1,0};
        for(int i=0;i<sizeof(x)/sizeof(x[0]);i++){
            int xx=m+x[i],yy=n+y[i];
            if(xx>=0 && yy>=0 && xx<visit.size() && yy<visit[0].size() && !visit[xx][yy] && fun(xx,yy,k))
                dfs(xx,yy,k,ans,visit);
        }
    }
public:
    int movingCount(int m, int n, int k) {
        //定义一个visit数组，因为要上下左右移动
//        int visit[m][n]={0};//可以这么初始化吗。。。//算了我选择二维向量
        vector<vector<bool>> visit(m,vector<bool>(n));
        int ans=0;
//        for(int i=0;i<m;i++){//因为有的不可达！！！题目里说了是从原点出发的。
//            for(int j=0;j<n;j++){
//                if(!visit[i][j] && fun(i,j,k))
//                    dfs(i,j,k,ans,visit);
//            }
//        }
        dfs(0,0,k,ans,visit);
        return ans;
    }
};
/*
2.AC了，但是果然又卡在了同一个地方，因为是从00出发，有的点虽然符合但是不可达。明天写一下BFS+官方代码学习。
*/

//5-22
/*
 * 1.题解中提到所有连通的都可以通过左边过来和上边来过访问，所以就不必四个方向，而直接向下向右访问即可。
 * */
class Solution {
public:
    int movingCount(int m, int n, int k) {
        //直接BFS
        queue<pair<int,int>> q;
        q.push({0,0});
        int dirX[]={0,1},dirY[]={1,0};
        int ans=1;
        vector<vector<int>> vis(m,vector<int>(n,0));
        vis[0][0]=1;
        while(!q.empty()){
            auto [xx,yy]=q.front();
            q.pop();
            for(int i=0;i<2;i++){
                int x=xx+dirX[i];
                int y=yy+dirY[i];
                if(x<m&&y<n&&vis[x][y]==0&&helper(x,y,k)){//要判断下标合不合法啊！！！又忘记了一次！！！
                //dfs中都记得判断，bfs这里怎么就老忘记呢？
                    q.push({x,y});
                    vis[x][y]=1;
                    ans++;
                }
            }
        }
        return ans;
    }
    bool helper(int x,int y,int k){
        int s=0;
        while(x){s+=(x%10);x/=10;}
        while(y){s+=(y%10);y/=10;}
        return s<=k;
    }
};
/*
 * 1.天哪，我在dfs中会考虑到重复访问，为什么在bfs里就考虑不到啊，下面的例子中，输出：
 *0 1
1 0
1 1
1 1
2 0
2 1
2 1
2 1
9
可以看到11被放了两次，分别是从01和10开始的。所以需要标记重复啊！我居然都找不出来是什么问题。。。
2.所以说为什么我要多练习BFS，因为自己以为会写，实际上写的时候会遇到很多问题。总结一下：
  bfs向外扩展时要和dfs一样判断下标是否有效！
  bfs访问节点时要和dfs一样考虑是否重复访问，是否直接修改访问过的元素或者用vis数据做标记！
 * */
int main(){
    Solution2 s;
    cout<<s.movingCount(3,2,17);//果然又卡在了相同的样例。。。
//    int j[2]={1,0};
//    cout<<j;//这里打印的是指针。
    return 0;
}
