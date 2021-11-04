#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月4日下午4:35:47
class Solution {
public:
    vector<int> fa;
    vector<double> weight;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //好难啊，看过两次题解，我要开始挑战自己了！
        unordered_map<string,int> um;
        //先对equations的字符建立
        int ct=0;
        for(auto& eq:equations){
            if(um.count(eq[0])==0)um[eq[0]]=ct++;
            if(um.count(eq[1])==0)um[eq[1]]=ct++;
        }
        //下面建立并查集
        fa.resize(ct);
        weight.resize(ct,1.0);
        for(int i=0;i<fa.size();i++)
            fa[i]=i;
        for(int i=0;i<equations.size();i++){
            int x=um[equations[i][0]];
            int y=um[equations[i][1]];
            merge(x,y,values[i]);//将两者建立联系合并
        }
        vector<double> ans;
        for(int i=0;i<queries.size();i++){
            double res=-1.0;//妈呀，这里的res也应该是double的啊，我哭了！！！
            if(um.count(queries[i][0])&&um.count(queries[i][1])){
                //两者要在一个并查集里才能确认关系的
                res=connect(um[queries[i][0]],um[queries[i][1]]);
            }
            ans.push_back(res);
        }
        // for(int i=0;i<fa.size();i++){
        //     cout<<fa[i]<<" "<<weight[i]<<endl;
        // }
        return ans;
    }
    void merge(int x,int y,double value){
        int fx=find(x);
        int fy=find(y);
        //这里需要考虑，如果已经在一个集合中了怎么办？
        if(fx==fy)return;
        fa[fx]=fy;
        weight[fx]=weight[y]*value/weight[x];
    }
    int find(int x){//寻找的时候压缩路径
        if(x!=fa[x]){
            int origin=fa[x];
            fa[x]=find(fa[x]);//更改father的时候，对应的权重也要更改。
            weight[x]*=weight[origin];
        }
        return fa[x];
    }
    double connect(int x,int y){
        int fx=find(x);//这里在查找的时候还是会压缩路径？
        int fy=find(y);
        if(fx==fy){
            // cout<<weight[x]<<" "<<weight[y]<<endl;
            return weight[x]/weight[y];
        }
        return -1.0;
    }
};
/*
 * 1.带权重的并查集！太难了，零神都说难！那肯定不容易的！
 * 2.有个很大的问题就是，这里用到了double，在刷题过程中，其实这个用的不多，所以我这里就出现问题了
 *   res我居然初始化成了int型，那可不就保存不了double吗！！！
 * 3.复杂度：O((N+Q)logA)，N是输入方程长度，Q是查询长度，A是方程中不同字符个数。O(A)空间
 *   在考虑复杂度的时候我居然没有开率Q，只想到了N。。。
 * */
int main(){

    return 0;
}
