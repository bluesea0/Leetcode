#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��3��21������11:26:50
class Solution {
public:
    string reverseWords(string s) {
        //����find����
        //�⵽������find����ֱ�ӱ������У�������
        string ans;
        // int index=0;
        // while(s.find(" ",index)!=string::npos){
        //     int t=s.find(" ",index);
        // }
        //�ƺ�����findֱ��forѭ��������
        int i=0,m=s.size();
        while(i<m){
            while(s[i]==' '&&i<m)i++;//int��size_type����ֱ�ӱȽ�
            if(i==m)break;
            int j=i;
            while(s[i]!=' '&&i<m)i++;
            ans=" "+s.substr(j,i-j)+ans;
        }
        //�����ˣ�C++�����ַ������鷳����һ�㶼û��py���
        //��Ҫ������ִ��������   ��
        return ans.size()==0?"":ans.substr(1);//ȥ����ͷ�Ŀո�
    }
};
/*
 * 1.AC�ˣ�̫���ˣ������ҿ�����ĿҪ��O(1)����ռ临�Ӷ�ԭ�ؽⷨ��erase����̫���ˡ�
 * 2.�ٽ��и�������reverse������ͨ��idx��ȥ���ո񣬲���ʶ������ʵ���λ��ֱ�ӽ����ֵ����ٷ�ת������
 * */

//6-16
/*
 * 1.�����ַ����Ķ�ͦ����ġ�
 * 2.ͨ��i����ȥ��ǰ���ո�Ȼ�������ո�֮�����ҵ��ʣ��ҵ�֮��substr��
 * */

//9-27
class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        while(s[i]==' ')i++;
        s=s.substr(i);
        i=s.size()-1;
        while(s[i]==' ')i--;
        s=s.substr(0,i+1);
        //��ȥ�����ײ���ĩβ�Ŀո�
        if(s.size()==0)return "";
        int index=0;
        s+=" ";
        string res,temp;
        for(int i=0;i<s.size();i++){
            // if(s[i]==' '&&s[i-1]!=' '){//������һ���ո����
            //     string temp=s.substr(pre,i);
            //     res=temp+res;
            //     pre=//����дpre���ü�¼������Ϊ�����ж���ո�pre���ÿ��ƣ�����
            // }
            if(s[i]==' '&&s[i-1]==' '){//���������ո񣬵ڶ����ո񲻴���
                continue;
            }else if(s[i]==' '){
                res=" "+temp+res;
                temp="";
            }else temp+=s[i];//������ͨ�ַ����
        }
        return res.substr(1);
    }
};
int main(){
	Solution s;
	cout<<s.reverseWords("  ");
    return 0;
}
