#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��10������3:00:39
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //˼·����map���洢��Ȼ��洢��vector<pair<int,int>>�У���д�����������
        //����ǰk����firstֵ��ʹ��sort����O(nlogn)
        unordered_map<int,int> mp;
        for(int n:nums)
            mp[n]++;
        vector<pair<int,int>> v;//����ֱ����mp��ʼ�����Ҳ²��С�����
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
 * 1.�ҵ���ȻAC�ˣ����Ǹ��ӶȲ�������Ŀ��Ҫ�󣬻�ȥ��֪ͨ�ɡ�
 * 2.���˹ٷ�����⣬�ҲŻ�Ȼ���򰡣�oh��ԭ����������ʹ�öѣ�ֻ��ǰk�����֣�6�ˡ�
 * 3.�����215��topk�ǳ��񣡿����ö�ֻ��k�����ÿ��ŶԳ���Ƶ�ʽ��п��š�̫ţ�ˡ�
 * */

//12-15
class Solution1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //˼·���Գ��ִ���������п��ţ����Ӵ�С���������ǰ����q==k-1����ô�ͷ������Ķ�Ӧ�Ľ��
        //���q<k-1����ô��������ң�����������+�Ҳ���
        unordered_map<int,int> occ;
        for(auto n:nums)
            occ[n]++;
        vector<pair<int,int>> v;
        for(auto o:occ)
            v.emplace_back(make_pair(o.first,o.second));
        int left=0,right=v.size()-1;
        vector<int> ans;
        int target=k;//��Ϊ�������Ҷ�k�������޸ģ�����������Ҫ����
        while(left<right){
            int p=randomSort(v,left,right);
            if(p==k-1)break;
            else if(p>k-1)right=p-1;
            else{//����������Ļ�������Ҫ��k�����޸���
                left=p+1;
                k-=p;
            }
        }
        for(int i=0;i<target;i++)//��Ϊk���Ѿ������ˣ������ģ���ԭ������Ϊ�������
            ans.push_back(v[i].first);
        return ans;
    }
    int randomSort(vector<pair<int,int>>&v,int left,int right){
        int t=rand()%(right-left+1)+left;
        swap(v[right],v[t]);//����
        int p=left-1;
        int a=v[right].second;
        while(left<right){
            if(v[left].second>=a){//�Ҳ�̫ȷ���Ӵ�С�����ʱ������Ҫ��=��
                p++;
                //v[p]=v[left];//��������ǽ�������
                swap(v[p],v[left]);
            }
            left++;
        }
        //����pָ���λ�þ���right��λ�ã�
        swap(v[right],v[p+1]);
        return p+1;
    }
};

//12-16
//�������ö�дһ�¡����ȶ���
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
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&cmp)> pq(cmp);//Ҫ����һ��С����
        //����k��
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
};//AC�ˣ������ĵİ�
int main(){
	vector<int> v={3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
	Solution1 s;
	vector<int> ans=s.topKFrequent(v, 10);
	cout<<"main____\n";
	for(auto a:ans)
		cout<<a<<endl;
    return 0;
}
