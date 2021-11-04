#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��13������2:11:19
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans=0,m=grid.size();
        if(grid[0][0]==1||grid[m-1][m-1]==1)return -1;//û�뵽��������[0][0]�������İ���
        queue<pair<int,int>> que;
        que.push({0,0});
        grid[0][0]=1;
        //�Ǿ���Ҫ��8����ͬ�ķ���
        int dir_X[]={-1,-1,0,1,1,1,0,-1};
        int dir_Y[]={0,1,1,1,0,-1,-1,-1};
        while(!que.empty()){
            int len=que.size();
            for(int k=0;k<len;k++){
                int x=que.front().first,y=que.front().second;
                que.pop();//���ֶԶ��еĲ����������ر���Ϥ����
                if(x==m-1&y==m-1)return ans+1;
                for(int i=0;i<8;i++){//��8�������ƶ�
                    int tx=x+dir_X[i];
                    int ty=y+dir_Y[i];
                    if(tx>=0&&tx<m&&ty>=0&&ty<m&&grid[tx][ty]==0){
                        que.push({tx,ty});
                        grid[tx][ty]=1;//ֻҪpush��ȥ�˾�Ϊ1
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
/*
 * 1.û��ʲô�����Ѷȣ�ʱ����O(mn)�����ǿռ��أ�O(m+n)���ǵģ���ΪBFS��չ��ౣ�����һ��+һ�еĵ㣬�Ǿ���
 *   m+n��
 * 2.
 * */
int main(){

    return 0;
}
