#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��17������3:01:44
//class Solution {
//public:
//    int findContentChildren(vector<int>& g, vector<int>& s) {
//        //��һ�о�������Ҫͬʱ�����������飬����+˫ָ�룿����ÿһ��gi��Ҫ��s���ҵ��պ�>=gi��ֵ
//        //ͬʱ��֤���û�б��ַ���ȥ�������̰����ʲô��ϵ����
//        //˼·���ֱ�����+���ֲ��ң�O(nlogn+mlogm+nlogm)
//        //�������һ��easy��Ŀ������
//    }
//};
/*
 * 1.��������������⣬���˾��ˣ�����ɵ�ƣ�����ɵ�ơ�
 * 2.����̰���㷨���ֲ����Ž�=��ȫ�����Ž�
 *   ��dp�ǣ�������=�������⡣һ���𣿺����డҲ�ǡ��ֲ����Ž�=��ȫ�����Ž⡣
 * 3.������ľֲ����ţ����ǰѴ�ķָ���θ�ڣ���ʵ��������������һ���ġ�
 * */

//12-18
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());//θ��
        sort(s.begin(),s.end());//����
        int ans=0;
        //�������ɣ������ı��ɷָ�θ������
        int k=g.size()-1;
        for(int i=s.size()-1;i>=0;i--){
            if(g[k]<=s[i])ans++;
            else i++;
            k--;
            if(k<0)break;
        }
        return ans;
    }
};//��Ȼ�ܹ�������д�ĺ������ˡ�����дһ�´�С�ķ���
class Solution2 {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0)return 0;
        sort(g.begin(),g.end());//θ��
        sort(s.begin(),s.end());//����
        int ans=0;
        //��θ�ڿ�ʼ��������С�ķ�
        int k=0;
        for(int i=0;i<g.size();i++){
            if(g[i]<=s[k])ans++;
            else i--;//������Ҫ��Ե���g=[7,8,9,10]��s=[5,6,7,8]����������
            k++;
            if(k==s.size())break;
        }
        return ans;
    }
};//ʵ����̫������д�ģ�
/*
 * 1.��д�Ľⷨ���˼��������������α������̶���ȫ�෴�����˾��ˡ�
 * class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (int i = 0; i < s.size() && j < g.size(); ++i) {
            if (s[i] >= g[j]) ++j;
        }
        return j;
    }
};//���grand�Ľⷨ�治���������ɣ�ͬʱ��θ��Ҳ�ǣ�ֱ�ӿ��������������ߵ�size�����ص���ָ��θ�ڵ�
�±ꡣ
 * */
int main(){

    return 0;
}
