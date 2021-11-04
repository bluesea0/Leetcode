#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��1��11������3:09:18
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
        //һ��ʼ��û˼·��ֻ�뵽��֮ǰ��ת����ʹ�����ֵ����õ���̰���㷨�������
        //���ò��鼯
    	if(pairs.size()==0)return s;//�������һ���Ծ��ǳ�ʱ������������������⡣
        fa.resize(s.size(),0);
        for(int i=0;i<s.size();i++)
            fa[i]=i;
        for(auto p:pairs){
            // int p1=find(p[0]);//��������Ҫ��ǰ������
            // int p2=find(p[1]);
            // if(p1!=p2)
            merge(p[0],p[1]);//ֱ��merge
        }
        //������ϣ��ϵ���ɲ��鼯����Ԫָ�����ȶ��У����ˣ�ͷһ��֪����
        unordered_map<int,priority_queue<char,vector<char>,greater<char>>> mp;//Ĭ���Ǵ󶥶ѣ�������Ҫ����С����
        for(int i=0;i<s.size();i++){
            int f=find(i);//�ҵ�
            if(mp.count(f))
                mp[f].push(s[i]);//�����ŵ�Ӧ�����ַ���
            else
                //mp[f]=priority_queue<char,vector<char>,greater<char>> q(s[i]);//������ֱ�ӳ�ʼ���𣿱���
            {
            	priority_queue<char,vector<char>,greater<char>> p;
            	p.push(s[i]);
            	mp[f]=p;
            }
        }
        for(int i=0;i<s.size();i++){
            auto& pq=mp[find(i)];//Ӧ�õ�Ҫ���õİɡ�
            s[i]=pq.top();pq.pop();
        }
        return s;
    }
};//���������д��ͨ����35/36����������ʱ�ˣ����˾��ˣ��ҵøĸġ�
//���ҳ��Բ�ʹ�����ȶ��У����Ƕ�����������
class Solution2 {
public:
    int find(int x){
        return fa[x]==x?x:(fa[x]=find(fa[x]));//���飬����ѹ��·���ˡ�AC�ˡ�
    }
    void merge(int i,int j){
        fa[find(i)]=find(j);//������д�����������Ӱ���𣿻��ǳ�ʱ�����ˡ�
    }
    vector<int> fa;
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        //һ��ʼ��û˼·��ֻ�뵽��֮ǰ��ת����ʹ�����ֵ����õ���̰���㷨�������
        //���ò��鼯
        if(pairs.size()==0)return s;
        fa.resize(s.size(),0);
        for(int i=0;i<s.size();i++)
            fa[i]=i;
        for(auto p:pairs){
            // int p1=find(p[0]);//��������Ҫ��ǰ������
            // int p2=find(p[1]);
            // if(p1!=p2)
            merge(p[0],p[1]);//ֱ��merge
        }
        //������ϣ��ϵ���ɲ��鼯����Ԫָ�����ȶ��У����ˣ�ͷһ��֪����
        unordered_map<int,vector<char>> mp;//Ĭ���Ǵ󶥶ѣ�������Ҫ����С����
        for(int i=0;i<s.size();i++){
            int f=find(i);//�ҵ�
            mp[f].emplace_back(s[i]);
        }
        //������mp��Ӧ��vector��������Ԥ�л����У��ǲ�����д�Ĳ��鼯�����⣿
        for(auto &[x,v]:mp){
        	sort(v.begin(),v.end(),greater<char>());//Ĭ���Ǵ�С���󣬵���û�а취pop��ǰ��ģ�ֻ��pop_back�����������һ��
        }
        for(int i=0;i<s.size();i++){
            auto& v=mp[find(i)];//Ӧ�õ�Ҫ���õİɡ�
            s[i]=v.back();v.pop_back();
        }
        return s;
    }
};//��֮ǰ�Ľ��һëһ��������������ô�찡��
/*
 * 1.AC�ˣ�������һ�ζ���д���鼯��Ȼ���ǲȿ��ˣ�find��ʱ����Ϊ�Լ�д��·��ѹ��������û�и�ֵ��fa[x]��
 *   �ǻ�����û�ð�����Ȼ�޸���֮�����������ȶ��е�Ҳ��ͨ����
 * */
int main(){
	Solution2 s;
	vector<vector<int>> pairs={{0,3},{1,2},{0,2}};
	cout<<s.smallestStringWithSwaps("dcab", pairs);
    return 0;
}
