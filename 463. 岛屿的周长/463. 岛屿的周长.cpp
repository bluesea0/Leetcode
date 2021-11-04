#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��10��30������1:23:00
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        //˼·���������ж�1���������ң�����Ǳ�Ե��1�������+1/+2
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        if(n==0) return 0;//������������ʱ��
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                if(i==0 || grid[i-1][j]==0) ans++;//��
                if(i==m-1 || grid[i+1][j]==0) ans++;//��
                if(j==0 || grid[i][j-1]==0) ans++;
                if(j==n-1 || grid[i][j+1]==0) ans++;
            }
        }
        return ans;
    }
};
/*
 * 1.ÿ��һ�⣬AC�ˣ����Ǹ�easy����Ŀ���ѡ������õĵ����ķ���������grand�Ľⷨ�������ĵ�һ��һ���ģ�
 * 2.��������һ��easy���⣬����DFS�Ľⷨ�Ҿ�Ȼһʱ���벻������ôд��������Ҫдһ��DFS�ˡ�
 * */
//class Solution {
//public:
//    int ans=0;
//    int islandPerimeter(vector<vector<int>>& grid) {
//        //DFS��
//        if(grid.size()==0)return 0;
//        if(grid[0].size()==0) return 0;//��Ҫ��һ�¹ٷ���û��д����ж�
//        for(int i=0;i<grid.size();i++)
//            for(int j=0;j<grid[0].size();j++){
//                if(grid[i][j]==1){
//                    dfs(i,j,grid);break;
//                }
//            }
//        return ans;
//    }
//    int dfs(int i,int j,vector<vector<int>> &grid;){//��ô�ж��أ���Ȼ���ˡ�
//        if(i<0 || j<0 || i>=grid.size()|| j>=grid[0].size()) return 0;
//        //���ж�����
//        if(i==0 || grid[i-1][j])ans++;//���Ѱ����ⷽ����ôת����������
//        //�Բ�������Ĳ����ˡ�����д�������Ƿ��
//    }
//};
/*
 * 1.DFS��˼����ʲô�أ�ȥ�ݹ���㣬�ȼ��������ǰ���Ǽ���Ȼ����ȥ�ݹ����������жϣ�
 *   ���ص�ֵ���������Һ͵�ǰ����ӣ��е���ɡ�
 * */
class Solution1 {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        //DFS��
        if(grid.size()==0)return 0;
        if(grid[0].size()==0) return 0;//��Ҫ��һ�¹ٷ���û��д����ж�
        int ans=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    ans=dfs(i,j,grid);break;
                }
            }
        return ans;
    }
    int dfs(int i,int j,vector<vector<int>> &grid){//��ô�ж��أ���Ȼ���ˡ�
        int m=grid.size(),n=grid[0].size();
        if(i<0 || j<0 || i>=m|| j>=n|| grid[i][j]==2||grid[i][j]==0) return 0;
        //���ж�����
        int ans=0;
        if(i==0 || grid[i-1][j]==0)ans++;//���Ѱ����ⷽ����ôת��
        //�Բ�������Ĳ����ˡ�����д�������Ƿ��
        if(i==m-1 || grid[i+1][j]==0)ans++;
        if(j==0 || grid[i][j-1]==0) ans++;
        if(j==n-1 || grid[i][j+1]==0) ans++;
        grid[i][j]=2;
        //����ݹ�ȥ�ж�
        //C++�������Ч�Ŀ����������ҵķ����أ�
        int dirX[]={0,0,1,-1},dirY[]={1,-1,0,0};
        for(int k=0;k<4;k++){
            ans+=dfs(i+dirX[k],j+dirY[k],grid);
        }
        return ans;
    }
};//Yes,AC�ˣ�������˼·֮��о���������ģ�
//��ȥ������һ�¹ٷ��Ľ���˼�д�Ĳ�������������
/*
 *         if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) {//����ֻ�ж�0�Ļ���
            return 1;//����Ǳ߽������0����ôֱ�ӷ��ء�
        }
        if (grid[x][y] == 2) {//�����2���򷵻�0�����ˣ�
            return 0;
        }

�������ж��Ƿ񷵻أ��ⲻ�ͱ��ҵ�ţ�������𡣡���
 * */

//12-4��ϰ
class Solution {
    constexpr static int dx[4] = {0, 1, 0, -1};
    constexpr static int dy[4] = {1, 0, -1, 0};
public:
    int dfs(int x, int y, vector<vector<int>> &grid, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) {
            return 1;//Խ��Ļ�����0�ģ��ͷ���1
        }
        if (grid[x][y] == 2) {//���Ѿ����ʹ���1����ô�ͷ���0
            return 0;
        }
        grid[x][y] = 2;
        int res = 0;
        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            res += dfs(tx, ty, grid, n, m);
        }
        return res;
    }
    int islandPerimeter(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ans += dfs(i, j, grid, n, m);
                }
            }
        }
        return ans;
    }
};
/*
 * 1.��һ�¹ٷ�����⡣
 * 2.���ڸ�ϰ����˼·��ʱ���Ȼֻ�뵽��DFS��û���뵽BFS���в�������͡��Ѿ��ܽᵽ�����ˡ�
 * 3.�Ҿ����ҵ�DFS�������뻹�ǲ�Ҫ���ˣ�����ѧϰ�ٷ����İɡ�
 * 4.����ʱ�临�ӶȲ���ʲôO(n^2)������O(mn)�;�����صġ�
 * 5.�´θ�ϰ�Ļ�����дһ�´����ˡ�
 * */

//12-25
//�ٷ��Ľ�д����������������������ŵĴ��룬����θ�ϰ��û��д��������θ�ϰ��û���뵽�����õ���
//ֱ���뵽����dfs����ʵ�����ϻ���ʱ��͵�����ok�˰������ࡣ
int main(){

    return 0;
}
