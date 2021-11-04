#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月10日下午3:00:39
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //思路：用map来存储，然后存储到vector<pair<int,int>>中，再写规则对其排序
        //输入前k个的first值。使用sort排序，O(nlogn)
        unordered_map<int,int> mp;
        for(int n:nums)
            mp[n]++;
        vector<pair<int,int>> v;//可以直接用mp初始化吗？我猜不行。。。
        for(auto m:mp)
            v.emplace_back(make_pair(m.first,m.second));
        sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b){return a.second>b.second;});
        vector<int> ans;
        for(int i=0;i<k;i++)
            ans.push_back(v[i].first);
        return ans;
    }
};
/*
 * 1.我的虽然AC了，但是复杂度不符合题目的要求，回去等通知吧。
 * 2.看了官方的题解，我才恍然大悟啊！oh！原来是这样！使用堆，只存前k的那种，6了。
 * 3.这个和215题topk非常像！可以用堆只存k个；用快排对出现频率进行快排。太牛了。
 * */

//12-15
class Solution1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //思路：对出现次数数组进行快排，按从大到小排序，如果当前划分q==k-1，那么就返回左侧的对应的结果
        //如果q<k-1，那么再往左侧找；否则包含左侧+右侧找
        unordered_map<int,int> occ;
        for(auto n:nums)
            occ[n]++;
        vector<pair<int,int>> v;
        for(auto o:occ)
            v.emplace_back(make_pair(o.first,o.second));
        int left=0,right=v.size()-1;
        vector<int> ans;
        int target=k;//因为内容中我对k进行了修改，所以这里需要保持
        while(left<right){
            int p=randomSort(v,left,right);
            if(p==k-1)break;
            else if(p>k-1)right=p-1;
            else{//如果是这样的话，就需要对k做出修改了
                left=p+1;
                k-=p;
            }
        }
        for(int i=0;i<target;i++)//因为k我已经剪掉了！！天哪！！原来是因为这个啊。
            ans.push_back(v[i].first);
        return ans;
    }
    int randomSort(vector<pair<int,int>>&v,int left,int right){
        int t=rand()%(right-left+1)+left;
        swap(v[right],v[t]);//交换
        int p=left-1;
        int a=v[right].second;
        while(left<right){
            if(v[left].second>=a){//我不太确定从大到小排序的时候这里要有=吗？
                p++;
                //v[p]=v[left];//大哥这里是交换啊！
                swap(v[p],v[left]);
            }
            left++;
        }
        //最终p指向的位置就是right的位置？
        swap(v[right],v[p+1]);
        return p+1;
    }
};

//12-16
//今天来用堆写一下。优先队列
class Solution2 {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> occ;
        for(auto n:nums)
            occ[n]++;
        vector<pair<int,int>> v;
        for(auto o:occ)
            v.emplace_back(o);
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&cmp)> pq(cmp);//要构建一个小顶堆
        //先入k个
        for(int i=0;i<k;i++){
            pq.push(v[i]);
        }
        for(int i=k;i<v.size();i++){
            auto top=pq.top();
            if(top.second<v[i].second){
                pq.pop();
                pq.push(v[i]);
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};//AC了，蛮开心的吧
int main(){
	vector<int> v={3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
	Solution1 s;
	vector<int> ans=s.topKFrequent(v, 10);
	cout<<"main____\n";
	for(auto a:ans)
		cout<<a<<endl;
    return 0;
}
