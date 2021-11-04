#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月11日下午3:09:18
class Solution {
public:
    int find(int x){
        return fa[x]==x?x:find(fa[x]);
    }
    void merge(int i,int j){
        fa[find(i)]=find(fa[j]);
    }
    vector<int> fa;
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        //一开始看没思路，只想到了之前反转矩阵使其代表值最大用的是贪心算法这个不行
        //利用并查集
    	if(pairs.size()==0)return s;//添加了这一句仍旧是超时，看来不是这个的问题。
        fa.resize(s.size(),0);
        for(int i=0;i<s.size();i++)
            fa[i]=i;
        for(auto p:pairs){
            // int p1=find(p[0]);//那这里我要提前查找吗？
            // int p2=find(p[1]);
            // if(p1!=p2)
            merge(p[0],p[1]);//直接merge
        }
        //建立哈希关系，由并查集代表元指向优先队列（绝了，头一次知道）
        unordered_map<int,priority_queue<char,vector<char>,greater<char>>> mp;//默认是大顶堆，那我想要的是小顶堆
        for(int i=0;i<s.size();i++){
            int f=find(i);//找到
            if(mp.count(f))
                mp[f].push(s[i]);//这里存放的应该是字符了
            else
                //mp[f]=priority_queue<char,vector<char>,greater<char>> q(s[i]);//能这样直接初始化吗？报错
            {
            	priority_queue<char,vector<char>,greater<char>> p;
            	p.push(s[i]);
            	mp[f]=p;
            }
        }
        for(int i=0;i<s.size();i++){
            auto& pq=mp[find(i)];//应该得要引用的吧。
            s[i]=pq.top();pq.pop();
        }
        return s;
    }
};//天哪上面的写法通过了35/36个样例，超时了！绝了绝了，我得改改。
//那我尝试不使用优先队列，而是对它进行排序
class Solution2 {
public:
    int find(int x){
        return fa[x]==x?x:(fa[x]=find(fa[x]));//心碎，忘了压缩路径了。AC了。
    }
    void merge(int i,int j){
        fa[find(i)]=find(j);//天啦我写错了这里？会有影响吗？还是超时，哭了。
    }
    vector<int> fa;
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        //一开始看没思路，只想到了之前反转矩阵使其代表值最大用的是贪心算法这个不行
        //利用并查集
        if(pairs.size()==0)return s;
        fa.resize(s.size(),0);
        for(int i=0;i<s.size();i++)
            fa[i]=i;
        for(auto p:pairs){
            // int p1=find(p[0]);//那这里我要提前查找吗？
            // int p2=find(p[1]);
            // if(p1!=p2)
            merge(p[0],p[1]);//直接merge
        }
        //建立哈希关系，由并查集代表元指向优先队列（绝了，头一次知道）
        unordered_map<int,vector<char>> mp;//默认是大顶堆，那我想要的是小顶堆
        for(int i=0;i<s.size();i++){
            int f=find(i);//找到
            mp[f].emplace_back(s[i]);
        }
        //对所有mp对应的vector排序，我有预感还不行，是不是我写的并查集的问题？
        for(auto &[x,v]:mp){
        	sort(v.begin(),v.end(),greater<char>());//默认是从小到大，但是没有办法pop最前面的？只有pop_back所以排序更改一下
        }
        for(int i=0;i<s.size();i++){
            auto& v=mp[find(i)];//应该得要引用的吧。
            s[i]=v.back();v.pop_back();
        }
        return s;
    }
};//和之前的结果一毛一样啊，天啦可怎么办啊。
/*
 * 1.AC了，不过第一次独立写并查集果然还是踩坑了，find的时候还以为自己写了路径压缩，但是没有赋值给fa[x]，
 *   那还不是没用啊。当然修改了之后上面用优先队列的也能通过。
 * */
int main(){
	Solution2 s;
	vector<vector<int>> pairs={{0,3},{1,2},{0,2}};
	cout<<s.smallestStringWithSwaps("dcab", pairs);
    return 0;
}
