#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��5��22������8:46:39
class Solution {
public:
    string replaceSpace(string s) {
        if(s.empty())return s;
        int start=0;
        string news="";
        while(s.find(" ",start)!=string::npos){
            int t=s.find(" ",start);
            news+=s.substr(start,t-start)+"%20";
            start=t+1;
        }
        news+=s.substr(start);//����˵����substr��Ĭ��ȡ��ĩβ�ģ����start�����˳��ȣ��Ͳ���������
        return news;
    }
};
/*
 *1.
 * */
//�������Ľⷨ��
class Solution {
public:
    string replaceSpace(string s) {     //�ַ�����
        string array;   //�洢���

        for(auto &c : s){   //����ԭ�ַ���
            if(c == ' '){//�����ո��ַ��Ļ����ͷ�������%20��
                array.push_back('%');//void push_back (char c);����ԭ�ͣ�ֻ��push��ȥchar��
                array.push_back('2');
                array.push_back('0');
            }
            else{
                array.push_back(c);
            }
        }
        return array;
    }
};
int main(){

    return 0;
}
