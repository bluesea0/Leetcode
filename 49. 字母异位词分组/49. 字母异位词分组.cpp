#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��16������2:19:07
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;
        for(auto s:strs){
            string cs=s;
            sort(cs.begin(),cs.end());
            um[cs].emplace_back(s);
        }
        vector<vector<string>> ans;
        for(auto u:um){
            ans.emplace_back(u.second);
        }
        return ans;
    }
};//AC�ˣ�֮ǰ��������˼·��
//���Ӷ�:O(nklogk),n���ִ�����,k������ĳ��ȡ�O(nk).�ռ�������ˡ�
//��ȻҲ����ʹ�ö���ĸ��������Ϊ��������ȫ����Сд��ĸ
/*
 * 1.https://www.cnblogs.com/grandyang/p/4385822.html �ĵڶ��ֽⷨ������˼�����������������γ�
 *   ������key������дһ�¡�
 * */

//12-17
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;
        for(auto s:strs){
            vector<int> v(26,0);
            string t="";
            for(auto c:s)v[c-'a']++;
            for(int i=0;i<26;i++){
                if(v[i]==0)continue;
                t+=string(1,i+'a')+to_string(v[i]);//����������i+'a'��������
                //string(5+"a")���ģ�������ʲô��û�С�����
                //cout<<5+"a";Ҳʲô��û�У�int+stringû��������ҡ�����
            }
            um[t].emplace_back(s);
        }
        vector<vector<string>> ans;
        for(auto u:um)
            ans.emplace_back(u.second);
        return ans;
    }
};//AC�ˣ����������е�����
int main(){

    return 0;
}
