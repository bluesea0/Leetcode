#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include <typeinfo>
using namespace std;
//2020��12��27������5:13:55
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> c2s;
        unordered_map<string,char> s2c;
        int start=0;
        //���ģ���û��ע�⵽���Ҳ��˫�������
        for(int i=0;i<pattern.size();i++){
            int end=s.find(" ",start);//��Ϊ�����һ��������û�пո�ָ��ˣ����Ի����npos
            if(end==string::npos&&start>s.size())return false;//�����жϳ���������
            //��������������ж������Ⱑ����Ȼend�Ѿ�=��npos����ô����κ�start������ϵ������
            else if(end==string::npos)end=s.size();
            string str=s.substr(start,end-start);
            if((c2s.count(pattern[i])!=0&&c2s[pattern[i]]!=str)||(s2c.count(str)!=0&&s2c[str]!=pattern[i]))return false;
            c2s[pattern[i]]=str;
            s2c[str]=pattern[i];
            start=end+1;
        }
        //���棬��������������
        //"aaa"
        //"aa aa aa aa" Ҳ����˵sû�б�����
        return start==s.size()+1;
        //"jquery"
        //"jquery" ��������ʲô��������throwing an instance of 'std::out_of_range'
    }
};
//���ģ�����AC�ˣ����۵������˿ޣ��ύ����β�ͨ������ؼҵ���Ϣ��
/*
 * 1.���˹ٷ����˼·�ǲ��ģ�����û����find������
 * */

//12-29
/*
 * 1.��Ҫ���ڵĵ����pattern��str�ĳ��Ȳ�ƥ�䣬p����ƥ��str��str̫�̲���ƥ��p���ֱ���Ҫ�жϡ�
 *   ǰ����Ҫ�жϱ�����p֮��ָ��str��ָ�����Ƿ�ĩβ��
 *   ������Ҫ�ж��Ƿ��Ҳ���end��
 * */
int main(){
	cout<<typeid(string::npos).name();
    return 0;
}
