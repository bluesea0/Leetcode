#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��25������4:45:46
//class Solution {
//public:
//    int regionsBySlashes(vector<string>& grid) {
//        //���Ѱ���һ����������о��ùֵ���Ŀ����ȫû��˼·��ô˵��
//        //�Ҷ��ˣ��Ͱ���������һ�������ж���ͨ����ģ�dfs�Ϳ��ԡ�
//        //���Ӷ���O(N^2)
//        //���ԣ�������ˣ���ô˵�أ�������ռ��ǳ���Ŀռ䣬����ķֲ����ѵ���Ҫͬ��һ������
//        //��˵�����Ҳ����˰���
//
//        //������Ŀtag���в��鼯������ô����������
//    	//��Ϊ���ֻ���ͷ��Ҫ�����ˡ�
//    }
//};
//���������ã�̫ţ�ˣ��ٷ���grand���ֲ�ͬ��˼·�������ٺ���BFS����2����grand�������ص���dfs����3����

class Solution {
public:
    int count=0;
    vector<int> fa;
    int regionsBySlashes(vector<string>& grid) {
        //��ʵ�Ҹо�����Ҫ���ѵ������չ֮���±�Ŀ����ˡ�
        //���鼯���������ҵ�ÿ����չ�ķ����0��λ�õ��±�
        //��Ҫ֪����չ����ܵĿո�����Կ��Ʋ��鼯��
        //��Ϊ��������չ�͸��Ӽ���չ��
        //���Ӽ���չ����Ҫ���������ˣ������ʵ��û�뵽��
        int m=grid.size();
        count=4*m*m;
        fa.resize(count*count);//�����������ô��ʼ����ά�ı�ʾ�أ�
        for(int i=0;i<fa.size();i++)
            fa[i]=i;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                int index=4*(i*m+j);
                if(grid[i][j]=='/'){
                    //�ϲ�0��3  1��2
                    merge(index,index+3);
                    merge(index+1,index+2);
                }else if(grid[i][j]=='\\'){
                    //�ϲ�0��1  2��3
                    merge(index,index+1);
                    merge(index+2,index+3);
                }else{
                    merge(index,index+1);
                    merge(index+1,index+2);
                    merge(index+2,index+3);
                }
                //���Ӽ�ϲ�
                if(i+1<m)merge(index+2,4*(i*m+m+j));//�ϲ�2����һ�����ӵ�0
                if(j+1<m)merge(index+1,4*(i*m+j+1)+3);//�ϲ�1���ұߵ�3
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
 * 1.�۰�Ŷ��AC�ˣ�ʱ����O(n^2*logn)���ռ���O(n^2)
 * 2.��ô����дһ�°��ղ�9���˼·
 * */
class Solution2 {
public:
    vector<vector<int>> matrix;//����һ������
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
 * 1.���dfs��˼·��ܶథ������������Ӷ���ô���أ��Ҳ�̫�ᰥ������O(9m^2)��
 * 2.������˵������
 * */
int main(){

    return 0;
}
