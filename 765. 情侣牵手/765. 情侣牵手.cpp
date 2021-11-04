#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��14������4:40:22
/*
 * 1.���������ʵ�뵽�˲��鼯�������벻��������ô�ã��������������һЩ��ans��ÿ����ͨ�����Ĵ�С-1��
 *   ��������������������ۡ�
 * */

//2-15
class Solution {
public:
    vector<int> fa;
    int minSwapsCouples(vector<int>& row) {
        //�ò��鼯��һ��
        int total=row.size()/2;
        fa.resize(total,0);
        for(int i=0;i<total;i++)
            fa[i]=i;
        //�������ϲ�
        for(int i=0;i<row.size();i+=2){
            int x=row[i]/2;//����2��Ϊ��ȷ���������ĸ�group
            int y=row[i+1]/2;
            merge(x,y);
        }
        unordered_map<int,int> um;
        for(int i=0;i<total;i++){
            //���ﻹҪ�ٲ�ѯһ�£�
            fa[i]=find(i);
            um[fa[i]]++;
        }
        int ans=0;
        for(const auto& [k,v]:um){
            ans+=(v-1);
        }
        return ans;
    }
    void merge(int x,int y){//������merge������һ��ÿ������ָ����ڵ��һ����
        //[5,4,2,6,3,1,0,7] �����ó�����fa������[0,3,2,0]�ͳ����˴���
        //���ˣ�ÿ�ζ�Ҫ�ٲ�ѯһ�£�
        int fx=find(x);
        int fy=find(y);
        if(fx==fy)return;
        fa[fx]=fy;
    }
    int find(int i){
        return fa[i]==i?i:(fa[i]=find(fa[i]));
    }
};//������дһ��BFS

//3-25
/*
 * 1.�����Ŀ�����е��Ѷȵģ�����ÿ��������Ϊһ��ģ���ô������ÿ����ͨ�Ӽ��µĸ�����ʱ����ͨ����ϣ����ͳ��
 *   �ģ���Ȼ���Ҫ�����ж��ٸ���ͨ�Ļ����ǿ�����һ����������¼����merge��ʱ��--��
 * */
int main(){

    return 0;
}
