#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��29������2:30:43
//class Solution {
//public:
//    int minimumEffortPath(vector<vector<int>>& heights) {
//        //��������ĿҪ�����С������ؼ��ʣ��������뵽��dp���Ҿ�����dp�ǿ��Խ�ġ�
//        //����Ϊʲô��Ŀ��ǩ���в��鼯������
//        int m=heights.size(),n=heights[0].size();
//        vector<vector<int>> dp(m,vector<int>(n,0));
//        for(int i=0;i<m;i++){
//            for(int j=0;j<n;j++){
//                if(i==0&&j==0)continue;
//                if(i==0){//��һ��
//                    dp[i][j]=nums[i][j]-nums[i][j-1];//������뷨�Ǵ���ģ�����ʾ��3֮��
//                    //��Ĭ��Ϊһ�������ķ���ֻ���Ϻ��󣬵�����ʵ�������κη���
//                    //���Դ������ġ�
//                }
//            }
//        }
//    }
//};
/*
 * 1.���֣����鼯���ֽⷨ����ĺ�ţ��̫ţ�˰ɡ�
 * */


//2-1
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //ʹ�ö��ַ����ж������⣬�ж���󾭹��ı�Ϊxʱ���������������Ƿ�����ͨ
        int left=0,right=1000000,m=heights.size(),n=heights[0].size();
        int dirX[]={0,0,1,-1},dirY[]={1,-1,0,0};
        while(left<right){
            //ʹ��BFS�ж���ͨ��
            int mid=left+(right-left)/2;
            vector<int> visit(m*n,0);//ʹ��i*m+j����ά����ת��Ϊһά������
            queue<pair<int,int>> q;//��ʾi��j����
            q.push({0,0});
            visit[0]=1;
            while(!q.empty()){
                auto [x,y]=q.front();//����������ʼ����
                q.pop();
                for(int i=0;i<4;i++){
                    int xx=x+dirX[i];
                    int yy=y+dirY[i];
                    if(xx>=0&&xx<m&&yy>=0&&yy<n&&visit[xx*n+yy]==0&&abs(heights[xx][yy]-heights[x][y])<=mid){
                        visit[xx*n+yy]=1;//��ʾ�ѱ����ʹ�
                        q.push({xx,yy});
                    }
                }
            }
            if(visit.back()){//��ѽ��Ҫ����С���������
                right=mid;
            }else left=mid+1;
        }
        return left;
    }
};
/*
 * 1.Yes,AC�ˣ�����Ҳ�ǿĿİ��ʱ�临�Ӷ�O(logmn*logc).
 * 2.��Ҫע��ĵ㣺�������άչ��Ϊһά�Ļ�����ô����һά��������xx*n+yy��ȷʵ�ǣ�һ��ʼ������ˣ�
 *   �����xx*m+yy�Ļ��Ǿ��ǰ��������ˣ��Ͳ�������÷��ˡ����ˡ�
 *   ��Ҫ�ܽ�һ��queue��pairһ����ֵ�ʱ����÷���
 * 3.����дһ�²��鼯д����
 * */

//2-2
class Solution {
public:
    vector<int> fa;
    int minimumEffortPath(vector<vector<int>>& heights) {
        //����ߣ����ݱ߳�����Ȼ�����μ��뼯���У��ж�00��n-1 n-1�Ƿ���ͨ����ͨ�Ļ��ͷ��ص�ǰ
        //�ߵ�Ȩ��
        int m=heights.size(),n=heights[0].size();
        vector<tuple<int,int,int>> edges;//tuple�Ǽ�����
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){//�����������ǵ���ߵ�
                if(i>0)edges.emplace_back(i*n+j,(i-1)*n+j,abs(heights[i][j]-heights[i-1][j]));
                if(j>0)edges.emplace_back(i*n+j,i*n+j-1,abs(heights[i][j]-heights[i][j-1]));
            }
        }
        //�����������ôд���ţ�
        auto cmp=[](const auto& a,const auto& b){//�Զ��庯�����Զ������ͼ��ɡ�
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
    void merge(int x,int y){//Ѱ�Ҳ�ѹ��·��
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
 * 1.д�˲��鼯�汾�ģ������õ���tuple���洢�ߣ���Ҫ������Ĳ������Լ�cmp������д����
 * 2.�����γ�ͼ�ı�Ȩ���㷽����
 * */
int main(){
	queue<pair<int,int>> q;
	q.push(1,2);
	q.push(make_pair(1,2));
	q.emplace(1,2);
    return 0;
}
