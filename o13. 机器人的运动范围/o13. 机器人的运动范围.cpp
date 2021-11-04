#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-10
/*
1.DFS�ⷨ���Ͼ����뵽�ġ�
*/
class Solution {
private:
    bool fun(int m, int n, int k){
        int s=0;
        while(m){s+=m%10;m/=10;}
        while(n){s+=n%10;n/=10;}
        return s<=k;
    }
    void dfs(int m, int n, int k,int& ans,vector<vector<bool>>& visit){//��Ĳ�ȷ����ά������ô����
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
        //����һ��visit���飬��ΪҪ���������ƶ�
//        int visit[m][n]={0};//������ô��ʼ���𡣡���//������ѡ���ά����
        vector<vector<bool>> visit(m,vector<bool>(n));
        int ans=0;
//        for(int i=0;i<m;i++){//��Ϊ�еĲ��ɴ������Ŀ��˵���Ǵ�ԭ������ġ�
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
2.AC�ˣ����ǹ�Ȼ�ֿ�����ͬһ���ط�����Ϊ�Ǵ�00�������еĵ���Ȼ���ϵ��ǲ��ɴ����дһ��BFS+�ٷ�����ѧϰ��
*/

//5-22
/*
 * 1.������ᵽ������ͨ�Ķ�����ͨ����߹������ϱ��������ʣ����ԾͲ����ĸ����򣬶�ֱ���������ҷ��ʼ��ɡ�
 * */
class Solution {
public:
    int movingCount(int m, int n, int k) {
        //ֱ��BFS
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
                if(x<m&&y<n&&vis[x][y]==0&&helper(x,y,k)){//Ҫ�ж��±�ϲ��Ϸ�����������������һ�Σ�����
                //dfs�ж��ǵ��жϣ�bfs������ô���������أ�
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
 * 1.���ģ�����dfs�лῼ�ǵ��ظ����ʣ�Ϊʲô��bfs��Ϳ��ǲ�����������������У������
 *0 1
1 0
1 1
1 1
2 0
2 1
2 1
2 1
9
���Կ���11���������Σ��ֱ��Ǵ�01��10��ʼ�ġ�������Ҫ����ظ������Ҿ�Ȼ���Ҳ�������ʲô���⡣����
2.����˵Ϊʲô��Ҫ����ϰBFS����Ϊ�Լ���Ϊ��д��ʵ����д��ʱ��������ܶ����⡣�ܽ�һ�£�
  bfs������չʱҪ��dfsһ���ж��±��Ƿ���Ч��
  bfs���ʽڵ�ʱҪ��dfsһ�������Ƿ��ظ����ʣ��Ƿ�ֱ���޸ķ��ʹ���Ԫ�ػ�����vis��������ǣ�
 * */
int main(){
    Solution2 s;
    cout<<s.movingCount(3,2,17);//��Ȼ�ֿ�������ͬ������������
//    int j[2]={1,0};
//    cout<<j;//�����ӡ����ָ�롣
    return 0;
}
