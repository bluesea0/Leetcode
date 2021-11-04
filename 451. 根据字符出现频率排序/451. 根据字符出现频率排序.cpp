#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��16������3:05:14
class Solution {
public:
    static bool cmp(pair<char,int> a,pair<char,int> b){
        return a.second<b.second;
    }
    string frequencySort(string s) {
        //�ǾͶ�/���ţ���Ŀû��Ҫ���Ȳ��ȶ�
        unordered_map<char,int> um;
        for(auto ss:s)
            um[ss]++;
        vector<pair<char,int>> v;
        for(auto u:um){
        	v.emplace_back(u);
        }
        priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(&cmp)> pq(cmp);
        //�����Ǹ�ɵ�ӣ����������pq��Ȼ��������ţ��в����ɡ�
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
//AC�ˣ���ô����дһ�¿��Ž���ġ�

//12-17
class Solution2 {
public:
    string frequencySort(string s) {
        //��д���ţ��ɴ�С����
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
        if(left<right){//�������ж�
            int p=partition(v,left,right);
            rquickSort(v,left,p-1);//��������
            rquickSort(v,p+1,right);//����˵����д�Ӻ������ǵ�д��
        }
        //��ʵ�������ﵱ��д���У�����Ҫ��дһ���Ӻ����ˣ������е���ջ��
        //���԰�����ͺ�Ȼ��Ƶ�һ�����⣬�漴���ţ�����ÿ���������ʱ�����ѡȡ������
        //����ֻ�е�һ�ηֵ�ʱ�򣿣���
        //��Ȼ�����Լ�֮ǰд�Ķ�����Ե���Ŀ��ţ�˫��Ļ���Ȼ�Ͳ�֪����ôд��

    }
    int partition(vector<pair<char,int>>& v,int left,int right){
        int p=rand()%(right-left+1)+left;
        swap(v[p],v[right]);
        int t=left-1;
        for(int i=left;i<right;i++){//�ж�����û��=�Ű���磡
            if(v[i].second>=v[right].second){
                t++;
                swap(v[t],v[i]);
            }
        }
        swap(v[t+1],v[right]);
        return t+1;
    }
};//AC�ˣ��ǳ����ġ�
int main(){
	Solution2 s;
	cout<<s.frequencySort("tree");
    return 0;
}
