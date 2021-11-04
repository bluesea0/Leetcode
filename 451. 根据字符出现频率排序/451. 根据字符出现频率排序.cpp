#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月16日下午3:05:14
class Solution {
public:
    static bool cmp(pair<char,int> a,pair<char,int> b){
        return a.second<b.second;
    }
    string frequencySort(string s) {
        //那就堆/快排，题目没有要求稳不稳定
        unordered_map<char,int> um;
        for(auto ss:s)
            um[ss]++;
        vector<pair<char,int>> v;
        for(auto u:um){
        	v.emplace_back(u);
        }
        priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(&cmp)> pq(cmp);
        //我真是个傻子，建立了这个pq居然不往里面放？有病病吧。
        for(auto p:v)
            pq.push(p);
        string ans="";
        for(int i=0;i<v.size();i++){
            auto top=pq.top();
            pq.pop();
            ans+=string(top.second,top.first);
            cout<<ans<<endl;
        }
        return ans;
    }
};
//AC了，那么明天写一下快排解决的。

//12-17
class Solution2 {
public:
    string frequencySort(string s) {
        //手写快排，由大到小排序
        unordered_map<char,int> occ;
        for(auto ss:s)
            occ[ss]++;
        vector<pair<char,int>> v;
        for(auto o:occ)
            v.emplace_back(o);
        rquickSort(v,0,v.size()-1);
        string ans="";
        for(auto p:v)
            ans+=string(p.second,p.first);
        return ans;
    }
    void rquickSort(vector<pair<char,int>>& v,int left,int right){
        if(left<right){//这里有判断
            int p=partition(v,left,right);
            rquickSort(v,left,p-1);//调用自身
            rquickSort(v,p+1,right);//所以说，改写子函数还是得写。
        }
        //其实就在这里当场写就行，不必要再写一个子函数了，还得有调用栈？
        //不对啊，这就忽然设计到一个问题，随即快排，是在每次子排序的时候都随机选取函数吗？
        //还是只有第一次分的时候？？？
        //忽然发现自己之前写的都是针对单侧的快排，双侧的还忽然就不知道怎么写了

    }
    int partition(vector<pair<char,int>>& v,int left,int right){
        int p=rand()%(right-left+1)+left;
        swap(v[p],v[right]);
        int t=left-1;
        for(int i=left;i<right;i++){//判断这里没有=号啊大哥！
            if(v[i].second>=v[right].second){
                t++;
                swap(v[t],v[i]);
            }
        }
        swap(v[t+1],v[right]);
        return t+1;
    }
};//AC了，非常开心。
int main(){
	Solution2 s;
	cout<<s.frequencySort("tree");
    return 0;
}
