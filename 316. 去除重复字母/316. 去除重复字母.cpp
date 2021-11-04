#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��15������6:33:57
class Solution {
public:
    string removeDuplicateLetters(string s) {
        //�Բۣ����Ҳ̫���˰ɣ���Ȼ˵��402�����ƣ�����Ҳ��ͬ������������Ҫ�ж�ȥ�أ�������Ǹ�
        //�����⣬���ʹ��ջ�Ļ�����ô������1��bca������b������������Ҫȥ�������b����
        //ȥ����һ��b����cab��ȥ�������b��bac��������Ҫȥ�������b����ӵ�ǰ�����ǡ�

        //��ͳ���ظ���ĸ�ĳ��ִ�����Ȼ����˳�����+ջ���洢
        //�����ǣ���������2����3��c������е�ʱ������жϵ�2c�Ƿ��ڣ�����ж��Ƿ��Ѿ���c��������
        //����ѡ��һ��bool�������жϣ�
        unordered_map<char,int> count;
        unordered_map<char,int> visit;//�����Ϊһ��set��������
        for(auto c:s){
            count[c]++;
        }
        for(auto m:count){//��ô����map���ţ�
            visit[m.first]=0;//��¼�Ƿ���ڶ��е���
//            cout<<m.first<<" "<<m.second<<endl;
        }
        vector<char> st;//��ȫ������vecotr��ģ��ջ
        for(auto c:s){
            // char back=st.back();//���ﻹ�治����ô���壬��Ϊÿ��pop_back֮��backָ�붼����
            while(st.size()>0&&c<st.back()&&count[st.back()]>1&&visit[c]==0){
//                cout<<st.back()<<endl;
                visit[st.back()]=0;
                count[st.back()]--;
                st.pop_back();
            }
            if(visit[c]==0){
                st.push_back(c);
                visit[c]=1;
            }else count[c]--;//���bbcaac����������b����
        }
        string ans="";
        for(auto c:st){
            ans+=c;//char��ô���뵽string������ţ�
        }
        return ans;
    }
};
/*
 * 1.YesAC�ˣ�ʱ����O(n)���ռ�ΪO(n)�������޵ġ�
 * 2.visit��������Ϊһ��set����
 * 3.���˹ٷ���⣬���˰���Ϊʲô��д����ô�鷳�أ��˼�����ţ������¼last_occurrence������飬ţ����
 * */

//11-18
/*
 * 1.�ٿ�һ��ٷ����ţ�������İ汾��O(n)��û��ʹ�ù�ϣ���¼����������ʹ�õ���������¼���һ��
 *   ���ֵ�λ�ã�������ֻ����û���ظ��ģ�ѧ���ˡ��´θ�ϰ��Ҫ��дһ�£�
 * */

//12-20
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> occ;
        for(auto c:s)
            occ[c]++;
        vector<char> stk;
        vector<int> v(26,0);
        for(char c:s){
            if(v[c-'a']==1){//����һ������Ҫ�������жϣ��Ѿ����ֹ��ľ�û���ʸ񱻱����ˡ�
                occ[c]--;
                continue;
            }
            while(stk.size()!=0&&c<stk.back()&&occ[stk.back()]>1){
                occ[stk.back()]--;
                v[stk.back()-'a']=0;
                stk.pop_back();
            }
            v[c-'a']=1;
            stk.push_back(c);
        }
        string ans;
        for(auto c:stk)
            ans+=c;
        return ans;
    }//�����˼·������˰���"abacb"���������Ӧ���������abc�������ַ����������acb
    //��Ϊ�ڶ���a�õ�һ��b�����ˡ�
};
/*
 * 1.���ģ�AC�ˣ���̫˧�ˣ�
 * 2.�ҵ����ģ�ԭ��string����push_back��pop_back()��ѧ���ˣ�����������vector�ǿɲ����Ƕ��һ�ٰ���
 * */

//2-17
/*
 * 1.visit[i]=1��ʾ��ǰ���ַ��Ѿ����ŵ�����λ���ˣ��Ͳ��������ˣ����û�еĻ������϶�֮�󻹻ᱻ������
 *   �������һ�㣬�Ա����кܴ�İ���
 * */
int main(){
	Solution s;
	cout<<s.removeDuplicateLetters("cbacdcbc");
    return 0;
}
