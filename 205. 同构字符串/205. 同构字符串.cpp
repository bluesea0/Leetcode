#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��27������4:45:54
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //ֱ��˼�����ù�ϣ
        unordered_map<char,char> mp;
        unordered_set<char> st;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])==0&&st.count(t[i])==0){//ӳ��Ϊ��ͬ����
                mp[s[i]]=t[i];//�Բ�����߼�����ͦ���ӵİ�
                st.insert(t[i]);
            }
            //�������ˣ�������ab aa���ͻ����a��b��ӳ��Ϊa������������զ����
            //Ҳ���ǻ���������ͬ����ĸӳ��Ϊͬһ����ĸ�����
            else if(mp.count(s[i])!=0&&mp[s[i]]==t[i])continue;
            else if(mp.count(s[i])!=0&&mp[s[i]]!=t[i]||st.count(t[i])!=0) return false;
        }
        return true;
    }
};
//��ȻAC�ˣ���ʵ��Ҳ��̫ȷ���ģ�����е��Ѷȡ�
/*
 * 1.��Ҫ��ĸ֮�����˫��Ĺ�ϵ���ٷ����Ľ���ά�����Ź�ϣ��̫�е����˰���
 *
 * */
int main(){

    return 0;
}
